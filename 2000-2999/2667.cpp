#include <stdio.h>
#include <queue>
using namespace std;
int graph[25][25];
int visit[25][25]={0};
int dx[4]={1,-1,0,0};
int dy[4]={0,0,1,-1};
int cnt=0;
void DFS(int i, int j, int N)
{
	visit[i][j]=1;
	int ddx, ddy;
	
	for(int x=0;x<4;x++)
	{
		ddx=i+dx[x];
		ddy=j+dy[x];

		if(ddx<0 || ddy<0 || ddx>=N || ddy>=N)
			continue;
		if(visit[ddx][ddy]==0 && graph[ddx][ddy]==1)
		{
			DFS(ddx,ddy,N);
			cnt++;
		}

	}
}
int main(void)
{
	int N;
	scanf("%d",&N);
	
	for(int i=0;i<25;i++)
	{
		for(int j=0;j<25;j++)
		{
			visit[i][j]=0;
			graph[i][j]=0;
		}
	}

	
	

	for(int i=0;i<N;i++)
	{
		for(int j=0;j<N;j++)
		{

			scanf("%1d",&graph[i][j]);
			
		}
	}
	int danji = 0;
	queue<int> q;
	priority_queue<int, vector<int>, greater<int> > pq;

	for(int i=0;i<N;i++)
	{
		for(int j=0;j<N;j++)
		{
			if(visit[i][j]==0 && graph[i][j]==1)
			{
				cnt=1;
				DFS(i,j,N);
				pq.push(cnt);

				danji++;
			}
		}
		
	}
	printf("%d\n",danji);
	
	while(!pq.empty())
	{
		printf("%d\n",pq.top());
		pq.pop();
	}
}

