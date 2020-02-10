#include <stdio.h>
#include <algorithm>
using namespace std;
int main(void)
{
	int N,K;
	scanf("%d %d",&N,&K);

	int ans;
	int left = 1, right=K;
	while(left<=right)
	{
		long long int cnt=0;
		int mid = (left+right)/2;
		for(int i=1;i<=N;i++)
			cnt+=min(mid/i,N);
		if(cnt<K)
			left=mid+1;
		else
		{
			ans=mid;
			right=mid-1;
		}
	}
	printf("%d",ans);
}
