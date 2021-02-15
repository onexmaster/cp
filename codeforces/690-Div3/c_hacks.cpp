#include<bits/stdc++.h>
#define pb push_back
#define ll long long
using namespace std;
string ans;
string cmp;
void init()
{
    ans = "zzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzz";
    cmp = ans;
}
int cnt[11];
void rec(ll sum,string s,int target)
{
    // cout<<sum<<' '<<s<<' '<<target<<endl;
    if(sum > target) return;
    if(sum == target) {
        if((int)ans.size() > (int)s.size()){
            ans = s;
        }
        else {
            ans = min(ans,s);
        }
        return;
    }
    for(int i=1;i<10;i++){
        if(cnt[i] == 0){
            cnt[i] = 1;
            s += (char)('0'+i);
            rec((ll)i + sum,s,target);
            s.pop_back();
            cnt[i] = 0;
        }
    }
}
void solve()
{
    ll n;
    cin>>n;
    for(int i=0;i<=10;i++) cnt[i]=0;
    init();
    for(int i=1;i<10;i++){
        cnt[i] = 1;
        string s;
        s += (char)('0'+i);
        rec((ll)i,s,n);
        cnt[i] = 0;
    }
    if(ans == cmp){
        cout<<"-1"<<endl;
    }
    else{
        cout<<ans<<endl;
    }
}
int main()
{
     #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif
    int t = 1;
    cin>>t;
    while(t--){
        solve();
    }
}