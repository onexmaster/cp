// Created by Tanuj Jain
#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
#define pb push_back
#define mp make_pair
typedef long long ll;
typedef pair<int,int> pii;
template<class T> using oset=tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
const int INF = 0x3f3f3f3f;
int knight_moves[8][2]={{-2,-1},{-1,-2},{1,-2},{2,-1},{-2,1},{-1,2},{1,2},{2,1}};
int moves[4][2]={{0,1},{0,-1},{1,0},{-1,0}};
struct custom_hash {
    static uint64_t splitmix64(uint64_t x) {
        // http://xorshift.di.unimi.it/splitmix64.c
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }

    size_t operator()(uint64_t x) const {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
};
string findsum(string str1, string str2)
{
	 if (str1.length() > str2.length()) 
        swap(str1, str2); 
  
    // Take an empty string for storing result 
    string str = ""; 
  
    // Calculate length of both string 
    int n1 = str1.length(), n2 = str2.length(); 
  
    // Reverse both of strings 
    reverse(str1.begin(), str1.end()); 
    reverse(str2.begin(), str2.end()); 
  
    int carry = 0; 
    for (int i=0; i<n1; i++) 
    { 
        // Do school mathematics, compute sum of 
        // current digits and carry 
        int sum = ((str1[i]-'0')+(str2[i]-'0')+carry); 
        str.push_back(sum%10 + '0'); 
  
        // Calculate carry for next step 
        carry = sum/10; 
    } 
  
    // Add remaining digits of larger number 
    for (int i=n1; i<n2; i++) 
    { 
        int sum = ((str2[i]-'0')+carry); 
        str.push_back(sum%10 + '0'); 
        carry = sum/10; 
    } 
  
    // Add remaining carry 
    if (carry) 
        str.push_back(carry+'0'); 
  
    // reverse resultant string 
    reverse(str.begin(), str.end()); 
  
    return str; 
}
int main()
{
	ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

	#ifndef ONLINE_JUDGE
	freopen("inputf.in","r",stdin);
	freopen("outputf.in","w",stdout);
	#endif

	int t;
	cin>>t;
	string st;
	cin>>st;
	int mid=t/2;
	//cout<<mid<<endl;
	//if middle ele is not a 0
	if(st[mid]!='0')
	{
		if(t%2==0)
		{
			cout<<findsum(st.substr(0,mid),st.substr(mid,t-mid));
		}
		else
		{
			//check on mid-1 or mid+1;
			//cout<<st.substr(0,mid)<<" "<<st.substr(mid,t-mid)<<endl;
			string ans1=findsum(st.substr(0,mid),st.substr(mid,t-mid));
			string ans2=findsum(st.substr(0,mid+1),st.substr(mid+1,t-mid+1));
			//cout<<st.substr(0,mid+1)<<" "<<st.substr(mid+1,t-mid+1)<<endl;
			if(int(ans1.length())>int(ans2.length()))
				cout<<ans2;
			else if(int(ans1.length())>int(ans2.length()))
				cout<<ans1;
			else 
			{
				if(ans1<ans2)
					cout<<ans1;
				else
					cout<<ans2;
			}

		}
	}
	else
	{
		//if it is 0
		//try the firs possible cut from mid to right and the first possible cut on
		//left and take the min
		int temp=mid;
		while(st[temp]=='0')
			temp++;
		int temp2=mid;
		while(st[temp2]=='0')
			temp2--;
		//cout<<temp<<" "<<temp2<<endl;
		//cout<<st.substr(0,temp)<<" "<<st.substr(temp,t-temp)<<endl;
		string ans1=findsum(st.substr(0,temp),st.substr(temp,t-temp));
		//cout<<st.substr(0,temp2)<<" "<<st.substr(temp2,t-temp2)<<endl;
		string ans2=findsum(st.substr(0,temp2),st.substr(temp2,t-temp2));
			//cout<<st.substr(0,mid+1)<<" "<<st.substr(mid+1,t-mid+1)<<endl;
		//cout<<ans1<<" "<<ans2<<endl;
			if(int(ans1.length())>int(ans2.length()))
				cout<<ans2;
			else if(int(ans1.length())<int(ans2.length()))
				cout<<ans1;
			else 
			{
				if(ans1<ans2)
					cout<<ans1;
				else
					cout<<ans2;
			}


	}

}