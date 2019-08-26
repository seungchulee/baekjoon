#include <stdio.h>
#include <queue>
#include <algorithm>

using namespace std;
int N,M;
int arr[101];
int tmp[101];
int maxs=-1;

void func(int index,int sum, int cnt)
{
	if(cnt==3 && sum<=M)
	{
		maxs=max(maxs,sum);
		return;
	}
	if(cnt>3 || sum>M || index>=N)
		return;
	
	func(index+1,sum+arr[index],cnt+1);
	func(index+1,sum,cnt);
}
int main(void)
{
	scanf("%d %d",&N,&M);
	for(int i=0;i<N;i++)
	{
		scanf("%d",&arr[i]);
	}
	int sum=0;
	int cnt=0;
	func(0,sum,cnt);
	printf("%d",maxs);
}

