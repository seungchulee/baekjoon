#include <iostream>
#include <algorithm>
#include <limits.h>
using namespace std;
int rr = INT_MAX;
long long int arr[10101];
int main(void)
{
	int n,k;
	cin >> n >> k;
	long long int maxs=-1;
	for(int i=0;i<n;i++)
		cin >> arr[i];
	long long int left = 0;
	long long int res = -1;
	long long int right=rr;
	while(left<=right)
	{
		long long int mid = (left+right)/2;
		int cnt=0;
		for(int i=0;i<n;i++)
			cnt+=arr[i]/mid;
		if(cnt>=k)
		{
			left=mid+1;
			if(mid>res)
				res=mid;
		}
		else
			right=mid-1;
	}
	printf("%lld",res);
	
}
