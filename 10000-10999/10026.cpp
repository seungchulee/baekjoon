#include <stdio.h>
char graph[101][101];
int visit[101][101];

int dx[4] = {1,-1,0,0};
int dy[4] = {0,0,1,-1};
int N;
void DFS(int i, int j)
{
	visit[i][j]=1;
	int ddx,ddy;
	for(int x=0;x<4;x++)
	{
		ddx=i+dx[x];
		ddy=j+dy[x];
		if(ddx<0 || ddy<0 || ddx>=N || ddy>=N)
		{
			continue;
		}
		if(visit[ddx][ddy]==0 && graph[ddx][ddy]==1)
			DFS(ddx,ddy);
	}
}
int main(void)
{
	char ch;
	scanf("%d",&N);

	for(int i=0;i<N;i++)
	{
		for(int j=0;j<N;j++)
		{
			visit[i][j]=0;

			scanf("%c",&graph[i][j]);
		}
	}
	printf("\n\n");
	for(int i=0;i<N;i++)
	{
		for(int j=0;j<N;j++)
		{
			printf("%c",graph[i][j]);
		}
		printf("\n");
	}

	int yes=0;
	int no=0;
	for(int i=0;i<N;i++)
	{
		for(int j=0;j<N;j++)
		{
			if(visit[i][j]==0 && graph[i][j]==1)
			{
				DFS(i,j);
				yes++;
			}
//			if(non_visit[i][j]==0 && graph[i][j]>=1)
//			{
//				non_DFS(i,j);
//			}
		}
	}
	printf("%d\n",yes+1);

}
