// Created by Tanuj Jain
#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
using namespace std::chrono; 
#define pb push_back
#define mp make_pair
typedef long long ll;
typedef pair<int,int> pii;
template<class T> using oset=tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

bool z(string text, string pattern)
{
    bool found=false;
	int p_size=pattern.size();
	string st=pattern+"$"+text;
	int z[st.size()+1];
	z[0]=0;
	int l=0;
	int r=0;
	for(int i=0;i<st.size();i++)
	{
		if(i>r)
		{
			l=r=i;
			while(r<st.size() && st[r-l]==st[r])
				r++;
			z[i]=r-l;
			r--;
		}
		else
		{
			int k=i-l;
			if(z[k]<r-i+1)
			{
				z[i]=z[k];
			}
			else
			{
				l=r;
				while(r<st.size() && st[r-l]==st[r])
					r++;
				z[i]=r-l;
				r--;
			}

		}
	}
	for(int i=0;i<st.size();i++)
	{
		if(z[i]==p_size)
		{
			found=true;
            break;
		}
	}
    return found;
}
int main()
{
	ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

	#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif

    auto start = high_resolution_clock::now(); 
    string text;
    cin>>text;
    int q;
    cin>>q;
    while(q--)
    {
        string pattern;
        cin>>pattern;
        if(!z(text,pattern))
            cout<<"Pattern Not Found"<<endl;
        else
        {
            cout<<"Pattern Found"<<endl;
        }
        
    }
    auto stop = high_resolution_clock::now(); 
  
    // Get duration. Substart timepoints to  
    // get durarion. To cast it to proper unit 
    // use duration cast method 
    auto duration = duration_cast<microseconds>(stop - start); 
  
    cout << "Time taken by function: "
         << duration.count() << " microseconds" << endl; 
	
}