#include <stdio.h>
int graph[51][51];
int visit[51][51];
int max_id = 0;
int dx[8]={-1,-1,0,1,1,1,0,-1};
int dy[8]={0, 1, 1,1,0,-1,-1,-1};
void DFS(int x, int y,int h, int w)
{
	int ddx, ddy;
	 visit[x][y] = 1;
	 for(int i=0;i<8;i++)
	 {
		ddx=x+dx[i];
		ddy=y+dy[i];
		
		if(ddx<1 || ddy<1 || ddx>h || ddy>w)
			continue;

		if(visit[ddx][ddy] == 0 && graph[ddx][ddy] == 1)
			DFS(ddx,ddy,h,w);
	 }
}

int main(void)
{
	int w,h;
	while(1)

	{
		int island=0;

		for(int i=0;i<51;i++)
		{
			for(int j=0;j<51;j++)
			{
				visit[i][j] = 0;
				graph[i][j] = 0;
			}
		}
	
		scanf("%d %d",&w,&h);
		if(w==0 && h==0)
			break;
		for(int i=1;i<=h;i++)
		{
			for(int j=1;j<=w;j++)
			{
				scanf("%d",&graph[i][j]);
			}
		}
		
		for(int i=1;i<=h;i++)
		{
			for(int j=1;j<=w;j++)
			{
				if(visit[i][j] == 0 && graph[i][j] == 1)
				{
					DFS(i,j,h,w);
					island++;
				}
			}
		}	
		printf("%d\n",island);
			
	}
}

