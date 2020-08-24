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
int func(int x,vector<int>a)
{
	int sum=0;
	for(int i=0;i<a.size();i++)
	{
		if(a[i]<=x)
			sum+=2;
		else
			sum+=3;

	}
	return sum;
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

	int n;
	cin>>n;
	vector<int>a(n);
	for(int i=0;i<n;i++)
		cin>>a[i];
	int m;
	cin>>m;
	vector<int>b(m);
	for(int i=0;i<m;i++)
		cin>>b[i];
	int low=0;
	int high=max(*max_element(a.begin(),a.end()),*max_element(b.begin(),b.end()));
	int ans=-1;
	int max_a_score=-1;
	int max_b_score=-1;
	int sub=INT_MIN;
	int idx=-1;
	int mid=0;
	while(low<=high)
	{
		mid=low+(high-low)/2;
		int a_score=func(mid,a);
		int b_score=func(mid,b);
		if(a_score-b_score>=sub && a_score>b_score)
		{ 
			max_a_score=max(max_a_score,a_score);
			max_b_score=max(max_b_score,b_score);
			sub=a_score-b_score;
			high=mid-1;
		}
		else
		{
			low=mid+1;
		}
	}
	//if their score is -1 them mid holds the take the lowest value from b with which we can divide the points
	if(max_a_score==-1 && max_b_score==-1)
	{
		cout<<"HERE"<<endl;
		int x=*min_element(b.begin(),b.end());
		max_a_score=0;
		max_b_score=0;
		for(int i=0;i<a.size();i++)
		{
			if(a[i]>=x)
				max_a_score+=3;
			else
				max_a_score+=2;
		}
		for(int i=0;i<b.size();i++)
		{
			if(b[i]<=x)
				max_b_score+=3;
			else
				max_b_score+=2;
		}
	}
	cout<<max_a_score<<":"<<max_b_score;

}