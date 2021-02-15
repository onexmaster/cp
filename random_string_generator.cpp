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
int main()
{
        FIO;
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif
    int r;
    char c;
    int r1;
     srand (time(NULL));
    for(int i=1;i<=1;i++)
    {
        string s;
        //r1=rand()%2999;
        //if(r1==0)
         //   r1=1;
        for(int j=1;j<=10000;j++)
        {
             r = rand() % 26;   // generate a random number
          s+=('a' + r);            // Convert to a character from a-z
        }
        cout<<s<<endl;
    }

return 0;
}