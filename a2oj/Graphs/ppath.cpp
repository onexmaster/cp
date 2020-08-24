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
const int MAXN=1e6;
unordered_set<string>f_p;
char moves[10]={'0','1','2','3','4','5','6','7','8','9'};
void sieve()
{
	bool primes[MAXN];
	memset(primes,true,sizeof(primes));
	//false means it is a prime number and true means it is not a prime number
	for(int i=2;i*i<=9999;i++)
	{
		if(primes[i])
		{
			for(int j=i*i;j<=9999;j+=i)
				primes[j]=false;
		}
	}
	for(int i=1000;i<=9999;i++)
		if(primes[i])
			f_p.insert(to_string(i));
}
int bfs(string start, string end)
{
	if(start==end)
		return 0;
		queue<string>q;
		q.push(start);
		int step=0;
		unordered_set<string>vis;
		vis.insert(start);
		while(!q.empty())
		{
			int curr_size=q.size();
			for(int i=0;i<curr_size;i++)
			{
				string curr=q.front();
				//cout<<curr<<endl;
				q.pop();
				if(curr==end)
				{
					return step;
				}
				for(int j=3;j>=0;j--)
				{
					string temp=curr;
					for(int k=0;k<10;k++)
					{
							//change temp char and check if it is prime or not;
							temp[j]=moves[k];
							if(f_p.find(temp)!=f_p.end() && vis.find(temp)==vis.end())
							{
									q.push(temp); 
									vis.insert(temp);	
										
							}
						}

					}
				}
				step++;
			}
			return -1;
			
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
	sieve();

	while(t--)
	{
		string start,end;
		cin>>start>>end;
		int ans=bfs(start,end);
		if(ans!=-1)
			cout<<ans<<endl;
		else
			cout<<"Impossible"<<endl;
		
	
	}
	return 0;
}