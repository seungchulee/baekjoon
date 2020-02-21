#include <stdio.h>
#include <queue>
#include <cstring>
using namespace std;
int arr[101];
int visit[101];
int main(void)
{
	int n,m;
	memset(visit,-1,sizeof(visit));
	memset(arr,0,sizeof(arr));
	scanf("%d %d",&n,&m);
	for(int i=0;i<n+m;i++)
	{
		int a,b;
		scanf("%d %d",&a,&b);
		arr[a]=b;
	}
	queue<int> qq;
	qq.push(1);
	visit[1]=0;
	while(!qq.empty())
	{
		int x = qq.front();
		qq.pop();

		for(int i=1;i<=6;i++)
		{
			int nxt = x+i;
			if(nxt>100)
				continue;
			if(arr[nxt]>0)
				nxt=arr[nxt];
			if(visit[nxt]==-1)
			{
				qq.push(nxt);
				visit[nxt]=visit[x]+1;
			}

		}

	}
	printf("%d",visit[100]);
}	

