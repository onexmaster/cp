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
double dist(pair<ll,ll>& a, pair<ll,ll>& b)
{
	//function to cal distance between 2 points
	return sqrt((a.first-b.first)*(a.first-b.first)+(a.second-b.second)*(a.second-b.second));
}
void closest_pair_problem(vector<pair<ll,ll>>&points)
{

	int n=points.size();
	//map the points to their index
	map<pair<ll,ll>,int>point_to_index;
	for(int i=0;i<n;i++)
		point_to_index[{points[i].first,points[i].second}]=i;
	//sort the points according to x-cordinates
	sort(points.begin(),points.end());
	//set holds all the previous points
	//this set is sorted according to y-axis 
	//so insert the points in reverse fashion;
	set<pair<ll,ll>>box;
	//points holding the two closest points
	pair<ll,ll>p1;
	pair<ll,ll>p2;
	double best=DBL_MAX;
	box.insert({points[0].second,points[0].first});
	int left=0;
	for(int i=1;i<n;i++)
	{
		//remove all the points which have x co-ordinate > currxx-min
		while(left<i && points[i].first-points[left].first>best)
			box.erase({points[left].second,points[left].first}),left++;
		//iterate over all the points that are in range
		//i.e have x cor-dinate greater than [curr_x-best,x] and y between [curr_y-h,curr_y+h] 
		for(auto it=box.lower_bound({points[i].second-best,points[i].first-best});it!=box.end() && 
			points[i].second+best>=it->first;it++)
		{
			pair<ll,ll>temp={it->second,it->first};
			double distance=dist(points[i],temp);
			if(abs(distance)<best)
			{
				p1=temp;
				p2=points[i];
				best=abs(distance);
			}
		}
		box.insert({points[i].second,points[i].first});

	}
	//best pair are p1 and p2 and the min distance is stores in best
	cout<<min(point_to_index[p1],point_to_index[p2])<<" ";
	cout<<max(point_to_index[p1],point_to_index[p2])<<" ";
	cout<<fixed<<setprecision(6)<<best;

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
	vector<pair<ll,ll>>points(t);
	for(int i=0;i<t;i++)
		cin>>points[i].first>>points[i].second;
	closest_pair_problem(points);


}