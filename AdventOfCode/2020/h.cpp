// Created by Tanuj Jain
#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
#define pb push_back
#define mp make_pair
# define M_PI           3.14159265358979323846  /* pi */
#define FIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll>pll;
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
int acc;
bool subroutine(vector<pair<string,int>>&temp)
{
    set<pair<string,int>>seen;
    int i=0;
    while(i<temp.size() && seen.find({temp[i].first+to_string(i),temp[i].second})==seen.end()){
        seen.insert({temp[i].first+to_string(i),temp[i].second});
        if(temp[i].first=="acc")
        {
            acc+=temp[i].second;
        }
        else if(temp[i].first=="jmp")
        {
            i=i+temp[i].second-1;
        }
        i++;
    }
    if(seen.find({"jmp642",1})!=seen.end())
        return true;
    else
    {
        return false;
    }
    
}
int main()
{
        FIO;
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif
    string line;
    vector<pair<string,int>>temp;
    set<pair<string,int>>seen;
    while(getline(cin,line))
    {
        stringstream ss(line);
        string word;
        string fi;
        int se;
        int i=0;
        while(ss>>word)
        {   
            if(i==0)
              fi=word,i++;
            else
            {
                se=stoi(word);
            }
              
        }
        temp.pb({fi,se});
    }
    for(int i=0;i<10;i++)
    cout<<temp[i].first<<" "<<temp[i].second<<endl;
    for(int it=0;it<temp.size();it++)
    {
        //try all possible changes
        //change nop to jmp and vice versa
        if(temp[it].first=="nop")
        {
            string prev=temp[it].first;
            temp[it].first="jmp";
            acc=0;
            if(subroutine(temp))
            {   
                cout<<prev<<" "<<temp[it].second<<endl;
                cout<<acc;
                break;
            }
            else
            {
                temp[it].first=prev;
            }

        }
        if(temp[it].first=="jmp")
        {
            string prev=temp[it].first;
            temp[it].first="nop";
            acc=0;
            if(subroutine(temp))
            {   
                cout<<prev<<" "<<temp[it].second<<endl;
                cout<<acc;
                break;
            }
            else
            {
                temp[it].first=prev;
            }
            
                
        }
    }

return 0;
}