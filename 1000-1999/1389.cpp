#include <stdio.h>
#include <algorithm>
#include <queue>
using namespace std;
int arr[101][101];
int main(void)
{
	for(int i=0;i<=100;i++)
		for(int j=0;j<=100;j++)
			arr[i][j]=10000000;
	for(int i=0;i<=100;i++)
		arr[i][i]=0;
	int n,m;
	scanf("%d %d",&n,&m);
	for(int i=0;i<m;i++)
	{
		int a,b;
		scanf("%d %d",&a,&b);
		arr[a][b]=1;
		arr[b][a]=1;

	}
	for(int k=1;k<=n;k++)
	{
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=n;j++)
			{
				arr[i][j]=min(arr[i][j],arr[i][k]+arr[k][j]);
			}
		}
	}
	int mins=10000000;
	priority_queue<int> pq;
	for(int i=1;i<=n;i++)
	{
		int cnt=0;
		for(int j=1;j<=n;j++)
		{
			if(i==j)
				continue;
			cnt+=arr[i][j];
		}
		if(cnt<mins)
		{
			mins=cnt;
			pq.push(i);
		}
	}
	printf("%d",pq.top());

}
