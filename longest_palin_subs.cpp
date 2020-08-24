#include<bits/stdc++.h>
using namespace std;
int main()
{
	string s;
	cin>>s;
	int n=s.length();
	//Calculate the longest even and odd palindrome from thww string and return the max length

	int global_length=1;//Single alphabet is a palindrome
	for(int i=1;i<n;i++)
	{
		//Calculate the longest odd length palindrome
		int low=i-1;
		int high=i+1;
		int local_length=1;
		while(low>=0 && high<n && s[low]==s[high])
		{
			local_length=high-low+1;
			low--;
			high++;
		}
		global_length=max(global_length,local_length);
	}
	for(int i=1;i<n;i++)
	{
		//Calulate the longest even length palindrome
		int low=i-1;
		int high=i;
		int local_length=1;
		while(low>=0 && high<n && s[low]==s[high])
		{
			local_length=high-low+1;
			low--;
			high++;
		}
	global_length=max(global_length,local_length);
	}
	cout<<global_length;
	return 0;
}
