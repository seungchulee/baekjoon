#include <stdio.h>
int graph[50][50];
int visit[50][50];
int dx[4]={1,-1,0,0};
int dy[4]={0,0,1,-1};
void DFS(int i, int j, int m, int n)
{
	visit[i][j]=1;
	int ddx,ddy;
	for(int x=0;x<4;x++)
	{
		ddx=j+dx[x];
		ddy=i+dy[x];

		if(ddx<0 || ddy<0 || ddx>=m || ddy>=n)
			continue;
		if(visit[ddy][ddx]==0 && graph[ddy][ddx]==1)
			DFS(ddy,ddx,m,n);
	}

}
int main(void)

{
	int N;
	scanf("%d",&N);
	
	for(int i=0;i<N;i++)
	{
		int m,n,k;
		scanf("%d %d %d",&m,&n,&k);
		
		for(int x=0;x<50;x++)
		{
			for(int y=0;y<50;y++)
			{
				visit[x][y]=0;
				graph[x][y]=0;
			}
		}

		for(int j=0;j<k;j++)
		{
			int x; int y;
			scanf("%d %d",&x,&y);
			graph[y][x]=1;
		}
		
		int jirung=0;
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<m;j++)
			{
				if(visit[i][j]==0 && graph[i][j]==1)
				{
					DFS(i,j,m,n);
					jirung++;
				}
			}
		}
		printf("%d\n",jirung);

	}
}
