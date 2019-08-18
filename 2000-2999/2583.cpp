#include <stdio.h>
#include <queue>
using namespace std;
int graph[101][101];
int visit[101][101];
int dx[4]={1,-1,0,0};
int dy[4]={0,0,1,-1};
int M,N,K;
int cnt=0;

void DFS(int i,int j)
{
	visit[i][j]=1;
	int ddx,ddy;

	for(int x=0;x<4;x++)
	{
		ddx=j+dx[x];
		ddy=i+dy[x];
		if(ddx<0 || ddy<0 || ddx>=N || ddy>=M)
			continue;
		if(visit[ddy][ddx]==0 && graph[ddy][ddx]==1)
		{
			DFS(ddy,ddx);
			cnt++;
		}
	}
}
int main(void)
{
	scanf("%d %d %d",&M,&N,&K);
	for(int i=0;i<M;i++)
	{
		for(int j=0;j<N;j++)
		{
			visit[i][j]=0;
			graph[i][j]=1;
		}
	}


	for(int i=0;i<K;i++)
	{
		int x1,y1,x2,y2;
		scanf("%d %d %d %d",&x1,&y1,&x2,&y2);
		for(int x=x1;x<x2;x++)
		{
			for(int y=y1;y<y2;y++)
			{
				graph[y][x]=0;

			}

		}	
	}
	priority_queue<int, vector<int>, greater<int> > pq;
	int island=0;
	for(int i=0;i<M;i++)
	{
		for(int j=0;j<N;j++)
		{
			if(visit[i][j]==0 && graph[i][j]==1)
			{
				cnt=1;
				DFS(i,j);
				island++;
				pq.push(cnt);
	
			}
		}
	}
	printf("%d\n",island);
	while(!pq.empty())
	{
		printf("%d ",pq.top());
		pq.pop();
	}

}
