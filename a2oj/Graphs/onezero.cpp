//Watch Errichto's Video for this solution 
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
//Brief Intro
/*
 	dp vector stores the string which is formed and the queue stores the remainder 
 	we are bascially adding a 0/1 at the end of each number and finding the remainder and if we get it as 0 
 	we return the ans and if not we keep on finding the answer by adding a 0 or a 1 at the end adn finding its remainder
 	If  when we add a 0 we get (curr_rem*10+0)%n and when we add a 1 we get (curr_rem*10+1)%n nd if this remainder
 	is not yet been added in the tree/ not been visisted, add it and enter the number in dp
 	//For each number we can get at max n coz we have n remainders for each number.  
*/
string bfs(int n)
{
	if(n==1)
		return "1";
	vector<string>dp(n);
	dp[1]="1";
	queue<int>q;
	q.push(1);
	while(!q.empty())
	{
		int curr_rem=q.front();
		q.pop();
		if(curr_rem==0)
			return dp[curr_rem];
		for(int digit: {0,1})
		{
			int new_rem=(curr_rem*10+digit) %n;
			if(dp[new_rem].empty())
			{
				q.push(new_rem);
				dp[new_rem]=dp[curr_rem]+char('0'+digit);
			}
		}

	}
	return "";
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
	while(t--)
	{
		int n;
		cin>>n;
		cout<<bfs(n)<<endl;
	}
	
}