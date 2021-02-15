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
int main()
{
        FIO;
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif
    string line;
    int valid=0;
    while(getline(cin,line))
    {
        string temp;
        temp+=line;
        while(getline(cin,line))
        {
            if(line.empty())
                break;
            temp+=" ";
            temp+=line;
        }
        //getline(cin,line);
        bool byr=false,iyr=false,eyr=false,hgt=false, hcl=false,ecl=false,pid=false,cid=false;
         string byr1,iyr1,eyr1,hgt1, hcl1,ecl1,pid1,cid1;
        stringstream ss(temp);
        string word;
        //cout<<temp<<endl;
        while(ss>>word)
        {
            string val=word.substr(0,3);
            //cout<<val<<endl;
            if(val=="byr")
                byr=true,byr1=word.substr(4);
            else if(val=="iyr")
                iyr=true,iyr1=word.substr(4);
            else if(val=="eyr")
                eyr=true,eyr1=word.substr(4);
            else if(val=="hgt")
                hgt=true,hgt1=word.substr(4);
            else if(val=="hcl")
                hcl=true,hcl1=word.substr(4);
            else if(val=="ecl")
                ecl=true,ecl1=word.substr(4);
            else if(val=="pid")
                pid=true,pid1=word.substr(4);
            else if(val=="cid")
                cid=true,cid1=word.substr(4);
        }
        bool ok1=true;
        
            if((byr&&iyr&&eyr&&hgt&&hcl&&ecl&&pid)){
                 cout<<byr1<<" "<<iyr1<<" "<<eyr1<<" "<<hgt1<<" "<<hcl1<<" "<<ecl1<<" "<<pid1<<" "<<cid1<<endl;
                if(byr1.size()>4 || stoi(byr1)<1920 || stoi(byr1)>2002)
                    ok1=false,cout<<"HERE1"<<endl;
                if(iyr1.size()>4 || stoi(iyr1)<2010 || stoi(iyr1)>2020)
                    ok1=false,cout<<"HERE2"<<endl;
                if(eyr1.size()>4 || stoi(eyr1)<2020 || stoi(eyr1)>2030)
                    ok1=false,cout<<"HERE3"<<endl;
                if(hgt1.size()<4)
                {
                    ok1=false;
                    continue;
                }
                if(hgt1.substr(hgt1.size()-2)=="cm")
                {
                    //cout<<stoi(hgt1.substr(0,hgt1.size()-2))<<endl;
                    if(stoi(hgt1.substr(0,hgt1.size()-2))<150 || stoi(hgt1.substr(0,hgt1.size()-2))>193)
                        ok1=false,cout<<"HERE4"<<endl;
                }
                else if(hgt1.substr(hgt1.size()-2)=="in")
                {
                    //cout<<(hgt1.substr(0,hgt1.size()-2))<<endl;
                    if(stoi(hgt1.substr(0,hgt1.size()-2))<59 || stoi(hgt1.substr(0,hgt1.size()-2))>76)
                        ok1=false,cout<<"HERE5"<<endl;
                }
                if(hcl1[0]!='#')
                    ok1=false,cout<<"HERE6"<<endl;
                if(hcl1[0]=='#')
                {
                    string temp1=hcl1.substr(1);
                    if(temp1.size()!=6)
                        ok1=false,cout<<"HERE7"<<endl;
                    for(char c:temp1)
                    {
                        if(!isdigit(c) && c!='a' && c!='b' && c!='c' && c!='d' && c!='e' && c!='f')
                            ok1=false,cout<<"HERE8"<<endl;
                    }
                }
                if(ecl1!="amb"&& ecl1!="blu"&&ecl1!="brn"&& ecl1!="gry"&& ecl1!="grn"&& ecl1!="hzl"&& ecl1!="oth")
                    ok1=false,cout<<"HERE9"<<endl;
                if(pid1.length()!=9)
                    ok1=false,cout<<"HERE10"<<endl;
                if(pid1.length()==9)
                {
                    for(char c:pid1)
                        if(!isdigit(c))
                            ok1=false;
                }
                if(ok1)
            valid++;  
            }
              

    }
    cout<<valid;
return 0;
}