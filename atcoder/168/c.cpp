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
const double PI  =3.141592653589793238463;
int main()
{
	ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

	#ifndef ONLINE_JUDGE
	freopen("inputf.in","r",stdin);
	freopen("outputf.in","w",stdout);
	#endif

	int a,b,h,m;
	cin>>a>>b>>h>>m;
	//if (h == 12) h = 0;  
    //if (m == 60) m = 0;  

		double hour_angle = 0.5 * (h * 60 + m);  
    	double minute_angle = 6 * m;  
     	double angle = abs(hour_angle - minute_angle);
        angle = min(360 - angle, angle);
        //cout<<angle<<endl;
        angle=angle*PI/180.0;
		double ans=(a*a+b*b)-((2*(a*b))*cos(angle));
		cout<<fixed<<setprecision(12)<<sqrt(ans);
        



	
}