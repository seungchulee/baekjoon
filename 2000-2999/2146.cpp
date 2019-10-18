#include <stdio.h>
#include <cstring>
#include <queue>
#include <utility>
using namespace std;
int N;
int arr[101][101];
int visit[101][101];
int dx[4]={0,0,-1,1};
int dy[4]={-1,1,0,0};
void DFS(int x, int y, int cnt)
{
	visit[x][y]=0;
	arr[x][y]=cnt;
	for(int i=0;i<4;i++)
	{
		int ddx=x+dx[i];
		int ddy=y+dy[i];
		if(ddx<0 || ddy<0 || ddx>=N || ddy>=N)
			continue;
		if(arr[ddx][ddy]==1 && visit[ddx][ddy]==-1)
		{
			arr[ddx][ddy]=cnt;
			DFS(ddx,ddy,cnt);
		}
	}
}
int BFS(int cnt)
{
	memset(visit,-1,sizeof(visit));
	queue<pair<int,int> > qq;
	for(int i=0;i<N;i++)
	{
		for(int j=0;j<N;j++)
		{
			if(arr[i][j]==cnt)
			{
				qq.push(make_pair(i,j));
				visit[i][j]=0;
			}
		}
	}
	int res=0;
	while(!qq.empty())
	{
		pair<int,int> pp=qq.front();
		qq.pop();
		int x=pp.first;
		int y=pp.second;

		for(int i=0;i<4;i++)
		{
			int ddx=x+dx[i];
			int ddy=y+dy[i];
			if(ddx<0 || ddy<0 || ddx>=N || ddy>=N)
				continue;
			if(arr[ddx][ddy]!=0 && arr[ddx][ddy]!=cnt && visit[ddx][ddy]==-1)
			{
				return visit[x][y];
			}
			if(arr[ddx][ddy]==0 && visit[ddx][ddy]==-1)
			{
				qq.push(make_pair(ddx,ddy));
				visit[ddx][ddy]=visit[x][y]+1;
			}
		}

		
	}
	return -1;
}
int main(void)
{
	scanf("%d",&N);
	for(int i=0;i<N;i++)
	{
		for(int j=0;j<N;j++)
		{
			scanf("%d",&arr[i][j]);
		}
	}
	int cnt=2;
	memset(visit,-1,sizeof(visit));
	for(int i=0;i<N;i++)
	{
		for(int j=0;j<N;j++)
		{
			if(visit[i][j]==-1 && arr[i][j]==1)
			{
				DFS(i,j,cnt);
				cnt++;
			}
		}
	}
/*	for(int i=0;i<N;i++)
	{
		for(int j=0;j<N;j++)
		{
			printf("%d ",arr[i][j]);
		}
		printf("\n");

	}*/
	int mins=10000000;
	for(int i=2;i<=cnt;i++)
	{
		int res=BFS(i);
		if(res==-1)
			continue;
		mins=min(res,mins);

	}
	printf("%d",mins);
}
