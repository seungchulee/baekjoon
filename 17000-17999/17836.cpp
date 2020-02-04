#include <stdio.h>
#include <algorithm>
#include <cstring>
#include <queue>
using namespace std;
int N,M,K;
int dx[4]={1,-1,0,0};
int dy[4]={0,0,1,-1};
int arr[101][101];
int visit[101][101][2];
int main(void)
{
	scanf("%d %d %d",&N,&M,&K);
	for(int i=0;i<N;i++)
		for(int j=0;j<M;j++)
			scanf("%d",&arr[i][j]);
	memset(visit,-1,sizeof(visit));
	visit[0][0][0]=0;
	queue<pair<int,pair<int,int> > > qq;
	qq.push(make_pair(0,make_pair(0,0)));
	while(!qq.empty())
	{
		pair<int,pair<int,int> > pp = qq.front();
		qq.pop();
		int sword = pp.first;
		int x = pp.second.first;
		int y = pp.second.second;

		for(int i=0;i<4;i++)
		{
			int ddx = x+dx[i];
			int ddy = y+dy[i];
			if(ddx<0 || ddy<0 || ddx>=N || ddy>=M)
				continue;
			if(arr[ddx][ddy]==0 && visit[ddx][ddy][sword]==-1 && sword==0)
			{
				visit[ddx][ddy][sword]=visit[x][y][sword]+1;
				qq.push(make_pair(sword,make_pair(ddx,ddy)));
			}
			if(sword==1 && visit[ddx][ddy][sword]==-1)
			{
				visit[ddx][ddy][sword]=visit[x][y][sword]+1;
				qq.push(make_pair(sword,make_pair(ddx,ddy)));
			}
			if(arr[ddx][ddy]==2 && visit[ddx][ddy][sword]==-1 && sword==0)
			{
				visit[ddx][ddy][1]=visit[x][y][sword]+1;
				qq.push(make_pair(1,make_pair(ddx,ddy)));
			}
		}

	}
	int mins = 100000000;
	int res;
	if(visit[N-1][M-1][0]==-1 && visit[N-1][M-1][1]!=-1)
		res=visit[N-1][M-1][1];
	else if(visit[N-1][M-1][0]!=-1 && visit[N-1][M-1][1]==-1)
		res=visit[N-1][M-1][0];
	else if(visit[N-1][M-1][0]==-1 && visit[N-1][M-1][1]==-1)
	{
		printf("Fail");
		return 0;
	}
	else
		res=min(visit[N-1][M-1][0],visit[N-1][M-1][1]);
	mins=min(res,mins);
	if(mins<=K)
		printf("%d",mins);
	else
		printf("Fail");
}
