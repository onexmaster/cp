// Created by Tanuj Jain
#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
using namespace std::chrono; 
#define pb push_back
#define mp make_pair
#define vi vector<int>
typedef long long ll;
typedef pair<int,int> pii;


//build the suffix array and the string required for backward search
string backward_search;
//suffix array
vector<int>SA;
void suffix_array(string s)
{
	//Time Complexity of this function is O(nlog^2n), can be made O(nlogn) by using linear sorting method like bucket sort
	//Space Complexity: O(n) where n is the size of the string 

	//Algorthm Similar to Manber And Myers
	s+="$";
	int n=s.size();
	vector<int>c(n);
	SA.resize(n,0);
	//for k==0
	vector<pair<char,int>>a(n);
	for(int i=0;i<n;i++)
		a[i]={s[i],i};
	sort(a.begin(),a.end());
	for(int i=0;i<n;i++)
		SA[i]=a[i].second;
	//give a new class/bucket
	c[SA[0]]=0;
	for(int i=1;i<n;i++)
	{
		//if strings same assign the same class/bucket
		if(a[i].first==a[i-1].first)
			c[SA[i]]=c[SA[i-1]];
		else
			c[SA[i]]=c[SA[i-1]]+1;
	}
	//for transitons
	int k=0;
	//run this till 2^k < size of text
	while((1<<k)<n)
	{
		//contains as left part, pair of two equivalnce classes and second element is index of the string
		vector<pair<pair<int,int>,int>>a(n);
		for(int i=0;i<n;i++)
			a[i]={{c[i],c[i+(1<<k)%n]},i};
		sort(a.begin(),a.end());
		for(int i=0;i<n;i++)
			SA[i]=a[i].second;
	//assing the equivalnce classes or bucket
	c[SA[0]]=0;
	for(int i=1;i<n;i++)
	{
		if(a[i].first==a[i-1].first)
			c[SA[i]]=c[SA[i-1]];
		else
			c[SA[i]]=c[SA[i-1]]+1;
	}
	k++;
	}
	//If you want to see the strings of the suffix array uncomment the below line
	//s+=s;

	//print the suffix array and the strings and also build the backward search string  
	for(int i=0;i<n;i++)
	{
		if(SA[i]==0)
			backward_search+="$";
		else
			backward_search+=s[SA[i]-1];

		//print the suffix array strings
		//cout<<SA[i]<<" "<<s.substr(SA[i],n-SA[i])<<endl;
	}


	//This string will be used for the backward search algorithm
	//cout<<backward_search<<endl;
		
}

//build the C array, which gices the number of chars smaller than c in the string
int C[126];
void build_C(string s)
{
	//Time Complexity - O(n);
	//space Complexity -O(1);
	s+="$";
	vector<int>occ(126,0);
	int n=s.size();
	//find the occ of each char in string 
	for(int i=0;i<n;i++)
		occ[s[i]-NULL]++;
	C[0]=occ[0];
	//build a prefix function
	//C[i]holds the value for the number of chars which are smaller than c[i+1]
	for(int i=1;i<126;i++)
	{
		C[i]=C[i-1]+occ[i];
	}
	//C[c-1] gives the number of chars smaller than the current char

	//print the prefix table or the C[] table 
	// for(int i=0;i<126;i++)
	// cout<<i<<" "<<C[i]<<endl;
	// cout<<endl;
}


//Wavelet function
//Build the wavelet tree and the query function 
const int N=3e5;
int backward_search_string_array[N];
struct wavelet_tree{
	//Every Node in wavelet tree has 
	int lo, hi;
	wavelet_tree *l, *r;
	vi b;
 
	//nos are in range [x,y]
	//array indices are [from, to)
	wavelet_tree(int *from, int *to, int x, int y){
		lo = x, hi = y;
		if(lo == hi or from >= to) return;
		int mid = (lo+hi)/2;
		auto f = [mid](int x){
			return x <= mid;
		};
		//b[i] stores the number of elements that will go to the left subtree basically the number of elements smaller than mid
		b.reserve(to-from+1);
		b.pb(0);
		for(auto it = from; it != to; it++)
			b.pb(b.back() + f(*it));


		//see how lambda function is used here	
		//stable partition divides the array into elements smaller than pivot on left and others to right and returns iterator to the second half
		//this is the A array[]
		//since we are using pointer we need not build a new duplicate array
		auto pivot = stable_partition(from, to, f);
		//build the left half
		l = new wavelet_tree(from, pivot, lo, mid);
		//build the right half
		r = new wavelet_tree(pivot, to, mid+1, hi);
	}


	//count of nos in [l, r] equal to k
	//Query time:  O(log(max(A)) , where max(A) is the maximum element in the array A[].(here it is 27)
	int count(int l, int r, int k) {
		//base case
		if(l > r or k < lo or k > hi) return 0;
		//leaf node always has value equal to k 
		if(lo == hi) return r - l + 1;
		//if k less than equal to mid then answer is in left half 
		//else the answer is in right half
		int lb = b[l-1], rb = b[r], mid = (lo+hi)/2;
		if(k <= mid) return this->l->count(lb+1, rb, k);
		return this->r->count(l-lb, r-rb, k);
	}
};


void queries(int n, wavelet_tree T)
{
	//run this for the queries
	int q;
	cin>>q;
	while(q--)
	{
		string P;
		cin>>P;
		int p=P.size()-1;
		int sp=1;
		int ep=n;
	
		while(sp<=ep && p>=0)
		{
			char c=P[p];
			int pos_for_C=(c-NULL-1);
			int pos_for_wave=(c-'a'+1);
			if(sp==1)
				//occ (L,0,c) is 0
				sp=C[pos_for_C]+1;
			else
				sp=C[pos_for_C] + T.count(1,sp-1,pos_for_wave) + 1;
			
			ep=C[pos_for_C] + T.count(1,ep,pos_for_wave);
			p--;
		}
		if(ep<sp)
			cout<<"Pattern Not Found"<<endl;
		else 
			cout<<"Pattern Found"<<endl;
	}

	
}

void explain(int n, wavelet_tree T)
{
	string P;
	cin>>P;
	int p=P.size()-1;
	int sp=1;
	int ep=n;
	int x=1;
	
	while(sp<=ep && p>=0)
	{
		cout<<"Iteration :"<<x<<endl;
		cout<<"Initial sp and ep "<<sp<<" "<<ep<<endl;
		char c=P[p];
		int pos_for_C=(c-NULL-1);
		int pos_for_wave=(c-'a'+1);
		cout<<"We are looking for character:"<<c<<endl;
		cout<<"Number of chars smaller than current char are "<<C[pos_for_C]<<endl;
		int count_sp=0;
		int count_ep=0;
		if(sp==1)
			sp=C[pos_for_C]+1;
		else
		{
			count_sp=T.count(1,sp-1,pos_for_wave);
			sp=C[pos_for_C] + T.count(1,sp-1,pos_for_wave) + 1;
		}
		count_ep=T.count(1,ep,pos_for_wave);	
		ep=C[pos_for_C] + T.count(1,ep,pos_for_wave);
		
		cout<<"occ value for sp "<<count_sp<<endl;
		cout<<"Occ value for ep "<<count_ep<<endl;
		cout<<endl;
		p--;
		x++;
	}
	//ep-sp+1 gives us the number of times the pattern occurs in the text
	//to get the index of the pattern in the string we can look up the suffix array from sp->ep
	//print the index where the pattern is present in the string
	cout<<sp<<" "<<ep<<endl;
	if(ep<sp)
		cout<<"Pattern Not Found"<<endl;
	else
	{
		cout<<"Number of times Pattern found is : "<<ep-sp+1<<" "<<"times and at indices:"<<endl;
		for(int i=sp-1;i<ep;i++)
			cout<<SA[i]+1<<endl;	
	}
}

//Main function 
int main()
{
	//only works for lowercase string can be adapted to make it work for both
	ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

	#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif

	string s;
	cin>>s;
	//This functions takes the string, builds the suffix array and from the suffix array
	//build the 'L' string used by the backward search algorithm
	suffix_array(s);


	//The oracle Function
	//where C[c] gives the number of occ of chars which are alphabetically smaller then c in the string
	//occ functions give the number of times a char 'c' occurs in L[1,i]

	build_C(s);

	//build the wavelet function of the backward string for the occ function
	//before building the wavelet function change the string to array format with the following mapping

	//easier way of masking
	//$-0
	//a-1 etc
	int n=backward_search.size();
	//leave the a[0]=0 for building the wavelet tree
	//wavelet tree starts from index 1
	for(int i=1;i<=n;i++)
	{
		if(backward_search[i-1]=='$')
			continue;
		else
			backward_search_string_array[i]=(backward_search[i-1]-'a'+1);
	}
	//print the backward_search string_array
	// for(int i=1;i<=n;i++)
	// 	cout<<backward_search_string_array[i]<<" ";

	//build the wavelet tree of this array 
	clock_t start,end;
	start=clock();
	wavelet_tree T(backward_search_string_array+1,backward_search_string_array+n+1, 0, 27);
	end=clock();
	double time_taken = double(end - start) / double(CLOCKS_PER_SEC); 
    cout << "Time taken by Wavelet program is : " << fixed  
         << time_taken << setprecision(5); 
    cout << " sec " << endl; 
	//Run the actual Algorithm now 

	//run this for the explanation part
	//explain(n,T); 

	//run for queries
	start=clock();
	queries(n,T);
	end=clock();
	 time_taken = double(end - start) / double(CLOCKS_PER_SEC); 
    cout << "Time taken by queries program is : " << fixed  
         << time_taken << setprecision(5); 
    cout << " sec " << endl; 
	


}