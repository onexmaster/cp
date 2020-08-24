#include<bits/stdc++.h>
using namespace std;
int main()
{

	long long int s, i, j, k, t, n;

	vector <bool> f(1000005);
	f[0] = f[1] = 1;
	f[2] = 0;
	for (i = 2; i * i <= 1000005; i++) {
		if (f[i] == 0) {
			//cout << i << ".." << endl;
			for (j = i * i; j < 1000005; j += i) {
				if (f[j] == 0) {
					f[j] = 1;
				}
			}

		}
	}
	cin >> t;
	while (t--) {
		cin >> n;
		long long low=0;
    long long high=n;
    bool flag=false;
    long double mid;
    while(low<=high)
    {
       mid=low+(high-low)/2;
       //cout<<mid<<" "<<mid*mid<<endl;
      if(mid*mid==n)
      {
        if(f[mid]==0)
          {
            cout<<"YES"<<endl;
            //cout<<mid;
            flag=true;
            break;
          }
          else
          {
            cout<<"NO"<<endl;
            flag=true;
            //cout<<mid;
            break;
          }
        }
          else if(mid*mid>n)
            high=mid-1;
          else if(mid*mid<n)
            low=mid+1;
      }
      if(!flag)
      //cout<<mid;
        cout<<"NO"<<endl;
    }

}
