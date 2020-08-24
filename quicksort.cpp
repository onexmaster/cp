#include<bits/stdc++.h>
using namespace std;
int partition(int *A, int start, int end)
{
	int pivot=A[end];
	int p_index=start;
	for(int i=start;i<=end-1;i++)
	{
		if(A[i]<=pivot)
		{
			swap(A[i],A[p_index]);
			p_index++;
		}
	}
	swap(A[p_index],A[end]);
	return(p_index);
}
void quick(int *A, int start, int end)
{
	if(start<end)
	{
		int p_index=partition(A, start,end);
		quick(A,start,p_index-1);
		quick(A,p_index+1,end);
	}
}
int main()
{
	int A[]={3,2,3,1,2,4,5,5,6};
	quick(A,0,8);
	for(int i=0;i<9;i++)
		cout<<A[i]<<" ";
}
