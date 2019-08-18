#include <stdio.h>
#include <cstring>
int graph[300][300];
int sub_graph[300][300];
int visit[300][300];
int dx[4]={1,-1,0,0};
int dy[4]={0,0,1,-1};
int N,M;

void DFS(int i,int j)
{
	visit[i][j]=1;
	int ddx,ddy;
	for(int x=0;x<4;x++)
	{
		ddx=i+dx[x];
		ddy=j+dy[x];
		if(ddx<0 || ddy<0 || ddx>=M || ddy>=N)
			continue;
		if(visit[ddx][ddy]==0 && graph[ddx][ddy]>=1)
		{	
			DFS(ddx,ddy);
		}
	}
}
void reset()
{
	for(int x=0;x<N;x++)
	{
		for(int y=0;y<M;y++)
		{
			int cnt=0;
			if(sub_graph[x][y]>=1)
			{
				for(int t=0;t<4;t++)
				{
					int ddx=x+dx[t];
					int ddy=y+dy[t];
					if(ddx<0 || ddy<0 || ddx>=M || ddy>=N)
						continue;
					if(sub_graph[ddx][ddy]==0)
					{
						cnt++;
					}
				}
				graph[x][y]=sub_graph[x][y]-cnt;
				if(graph[x][y]<0)
					graph[x][y]=0;
			}
		}
	}
	
}
int main(void)
{
	scanf("%d %d",&N,&M);
	

	memset(graph,0,sizeof(graph));
	memset(sub_graph,0,sizeof(sub_graph));

	for(int i=0;i<N;i++)
	{
		for(int j=0;j<M;j++)
		{
			scanf("%d",&graph[i][j]);
			sub_graph[i][j]=graph[i][j];
		}
	}
	int year=0;
	while(1)
	{

		int glacier=0;
		bool result=false;
		memset(visit,0,sizeof(visit));

		for(int i=1;i<N-1;i++)
		{
			for(int j=1;j<M-1;j++)
			{
				if(visit[i][j]==0 && graph[i][j]>=1)
				{
					glacier++;
					if(glacier>=2)
					{
						result=true;
						break;
					}
					DFS(i,j);

				}
			}
		}
		if(result)
			break;
		printf("==%d %d==\n",glacier,year);
		if(glacier==0)
		{
			printf("!");
			year=0;
			break;
		}
		reset();
		year++;	
	}
	printf("%d",year);
}

