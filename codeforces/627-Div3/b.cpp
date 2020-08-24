#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
int main()
{
  int t;
  cin>>t;
  while(t--)
   { int n;
     cin>>n;
     int s[n];
     for(int i=0;i<n;i++)
        cin>>s[i];
        if(n==0)
            return 0;
        int dp[n][n];
        //fill the diagnols with 1 since single elements are palindromes
        for(int i=0;i<n;i++)
            dp[i][i]=1;

        for(int l = 2; l <= n; l++){
            for(int i = 0; i < n-l + 1; i++){
                int j = i + l - 1;
                if(l == 2 && s[i] == s[j]){
                    dp[i][j] = 2;
                }else if(s[i] == s[j]){
                    dp[i][j] = dp[i + 1][j-1] + 2;
                }else{
                    dp[i][j] = max(dp[i + 1][j], dp[i][j - 1]);
                }
            }
        }
        if(dp[0][n-1]>=3)
          cout<<"YES"<<endl;
        else
          cout<<"NO"<<endl;
}
}
