#include <stdio.h>
#include <cstring>
int visit[301][301];
int arr[301][301];
int N,M;
int dx[4]={1,-1,0,0};
int dy[4]={0,0,1,-1};
void func(int x, int y)
{
	visit[x][y]=0;
	for(int i=0;i<4;i++)
	{
		int ddx=x+dx[i];
		int ddy=y+dy[i];
		if(ddx<0 || ddy<0 || ddx>=N || ddy>=M)
			continue;
		if(arr[ddx][ddy]>0 && visit[ddx][ddy]==-1)
		{
			func(ddx,ddy);
		}
	}
}
int DFS()
{
	int glacier=0;
	memset(visit,-1,sizeof(visit));
	for(int i=0;i<N;i++)
	{
		for(int j=0;j<M;j++)
		{
			if(arr[i][j]>0 && visit[i][j]==-1)
			{
				glacier++;
				func(i,j);
			}
		}
	}
	

	return glacier;
}
void melt()
{
	int melt[301][301];
	memset(melt,0,sizeof(melt));
	for(int i=0;i<N;i++)
	{
		for(int j=0;j<M;j++)
		{
			if(arr[i][j]>0)
			{
				int cnt=0;
				for(int x=0;x<4;x++)
				{
					int ddx=i+dx[x];
					int ddy=j+dy[x];
					if(ddx<0 || ddy<0 || ddx>N || ddy>M)
						continue;
					if(arr[ddx][ddy]==0)
						cnt++;
				}
				melt[i][j]=cnt;
			}
		}
	}
	for(int i=0;i<N;i++)
	{
		for(int j=0;j<M;j++)
		{
			arr[i][j]=arr[i][j]-melt[i][j];
			if(arr[i][j]<0)
				arr[i][j]=0;
		}
	}
}
int main(void)
{
	scanf("%d %d",&N,&M);
	for(int i=0;i<N;i++)
	{
		for(int j=0;j<M;j++)
		{
			scanf("%d",&arr[i][j]);
		}
	}
	int year=0;	
	while(1)
	{
		//녹음
		melt();
		//빙산개수
		int glacier=DFS();
		year++;
		if(glacier==0)
		{
			year=0;
			break;
		}
		if(glacier>=2)
			break;

		//2면 break
	}
	printf("%d",year);
}
