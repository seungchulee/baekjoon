#include <stdio.h>
#include <algorithm>
using namespace std;
int main(void)
{
	long long int N,M;
	scanf("%lld %lld",&N,&M);
	long long int arr[1000001];
	long long int maxs=-1;
	for(int i=0;i<N;i++)
	{
		scanf("%lld",&arr[i]);
		maxs=max(maxs,arr[i]);
	}
	long long int left=0;
	long long int right=maxs;
	long long int mid;
	long long result;
	
	while(left<=right)
	{
		mid=(left+right)/2;
		long long int total=0;
		for(int i=0;i<N;i++)
		{
			if(mid<arr[i])
				total+=arr[i]-mid;
		}
		
		if(total>=M)
		{
			if(result<mid)
				result=mid;
			left=mid+1;
		}
		else
		{
			right=mid-1;
		}
	}
	printf("%lld\n",result);


}
