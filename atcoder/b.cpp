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
bool ispalin(string &st, int l, int h)
{
	int low=l;
	int high=h;
	bool flag=false;
	while(low<high)
	{
		cout<<st[low]<<" "<<st[high]<<endl;
		if(st[low]!=st[high])
		{
			return false;
		}
		else
		{
			low++;
			high--;
		}
	}
	return true;
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

	string input;
	cin>>input;
	//cout<<input;
	bool f1=ispalin(input,0,input.size()-1);
	//cout<<f1<<endl;
	bool f2=ispalin(input,0,(input.size()-1)/2-1);
	//cout<<f2<<endl;
	bool f3=ispalin(input,(input.size()+3)/2-1,input.size()-1);
	//cout<<f3<<endl;

	
	if(f1 && f2 && f3)
		cout<<"Yes"<<endl;
	else
		cout<<"No"<<endl;
		
}