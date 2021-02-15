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
vector<string>ans;
void recurse(string st)
{
  //cout<<s<<endl;
  if(int(st.size())==24)
  {
    ans.push_back(st);
    return;
  }
  st+='0';
  recurse(st);
  st.pop_back();
  st+='1';
  recurse(st);
    
  
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

	string st;
	recurse(st);
	int zz=0;
	//cout<<ans.size();
	for(int i=0;i<ans.size();i++)
		ans[i].append(16,'0');
  string poly="10001000000100001";
  string crc="0000000000000000000000000110000111100001";
  //get all the ones in the ucf strig;
  for(int i=0;i<ans.size();i++)
  {
  	string ucf=ans[i];
  set<int>st;
  for(int i=0;i<24;i++)
    if(ucf[i]=='1')
      st.insert(i);
    //string main_temp=ucf;
    string temp=ucf;
 while(!st.empty())
  {
     //cout<<temp<<endl;
    //pointer for ucf string
    int i=*st.begin();
    //pointer for poly string
    int j=0;
    while(j<int(poly.size()))
    {
      if(temp[i]=='1' && poly[j]=='1')
      {
        //cout<<i<<endl;
        temp[i]='0';
        st.erase(i);
        i++;
        j++;
      }
        
      else if(temp[i]=='0' && poly[j]=='0')
      {
        temp[i]='0';
        i++;
        j++;
      }
        
      else if(temp[i]=='1' && poly[j]=='0')
      {
        temp[i]='1';
        if(i<24)
          st.insert(i);
        i++;
        j++;
      }
      else if(temp[i]=='0' && poly[j]=='1')
      {
        temp[i]='1';
        if(i<24)
          st.insert(i);
        i++;
        j++;
      }
      
    }

  }
  //string cmp=temp.substr(24,40);
    if(temp==crc)
    {
    	cout<<ucf<<endl;
    }
}

}