//Does not work-Gives wrong answer 
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
string bfs(int n)
{
	if(n==6)
		return "6";
	if(n==8)
		return "8";
	vector<string>dp1(n);
	vector<string>dp2(n);
	
	dp1[8%n]="8";
	queue<int>q;
	//q.push(6%n);
	q.push(8%n);
	while(!q.empty())
	{
			int curr_rem=q.front();
			q.pop();
			if(curr_rem==0)
			{
				break;	
			}
			string curr_string=dp1[curr_rem];
			if(curr_string[curr_string.size()-1]=='6')
			{
				int new_rem=(curr_rem*10+6)%n;
			if(dp1[new_rem].empty())
			{
				q.push(new_rem);
				dp1[new_rem]=dp1[curr_rem]+'6';
			}
			
			}
		else
		{
			
			for(int digit : {6,8})
			{
				int new_rem=(curr_rem*10+digit)%n;
				if(dp1[new_rem].empty() || dp1[new_rem]>(dp1[curr_rem]+char('0'+digit)))
				{
					q.push(new_rem);
					dp1[new_rem]=dp1[curr_rem]+char('0'+digit);
				}
			}	
		}
	}
	queue<int>q1;
	dp2[6%n]="6";
	q1.push(6%n);
	while(!q1.empty())
	{
		int curr_rem=q1.front();
		q1.pop();
		if(curr_rem==0)
			break;
		else
		{
			int new_rem=(curr_rem*10+6)%n;
			if(dp2[new_rem].empty())
			{
				q1.push(new_rem);
				dp2[new_rem]=dp2[curr_rem]+'6';
			}
		}

	}
	if(dp1[0].empty() && dp2[0].empty())
		return "-1";
	else
	{
		if(dp1[0].empty())
			return dp2[0];
		else if(dp2[0].empty())
			return dp1[0];
		else
		{
			int s=dp1[0].size();
			int t=dp2[0].size();
			if(s==t)
				return min(dp1[0],dp2[0]);
			else if(s<t && s<200)
				return dp1[0];
			else if(t<s && t<200)
				return dp2[0];
			else
				return "-1";
		}
	}
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
	//int t=1;
	while(t--)
	{
		int n;
		cin>>n;
		cout<<bfs(n)<<endl;
		//t++;
	}
	
}