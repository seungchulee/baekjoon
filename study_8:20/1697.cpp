#include <stdio.h>
#include <queue>
using namespace std;
queue<int> qq;
int dist[100001]={-1,};
int N,K;
int main(void)
{
	for(int i=0;i<=100001;i++)
	{
		dist[i]=-1;
	}
	scanf("%d %d",&N,&K);
	qq.push(N);
	dist[N]=0;
	while(!qq.empty())
	{
		int now=qq.front();

		qq.pop();
		
		if(now-1>=0)
		{
			if(dist[now-1]==-1)
			{
				qq.push(now-1);
				dist[now-1]=dist[now]+1;
			}
		}
		if(now+1<=100000)
		{
			if(dist[now+1]==-1)
			{
				qq.push(now+1);
				dist[now+1]=dist[now]+1;
			}
		}
		if(now*2<=100000)
		{
			if(dist[now*2]==-1)
			{
				qq.push(now*2);
				dist[now*2]=dist[now]+1;
			}
		}

	}

	printf("%d",dist[K]);
}
