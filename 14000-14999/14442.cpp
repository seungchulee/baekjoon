#include <stdio.h>
#include <cstring>
#include <queue>
using namespace std;
int arr[1010][1010];
int visit[11][1010][1010];
int dx[4]={0,0,1,-1};
int dy[4]={1,-1,0,0};
int N,M,K;
int main(void)
{
	memset(visit,-1,sizeof(visit));
	memset(arr,0,sizeof(arr));
	scanf("%d %d %d",&N,&M,&K);
	for(int i=0;i<N;i++)
	{
		for(int j=0;j<M;j++)
		{
			scanf("%1d",&arr[i][j]);
		}
	}
	queue<pair<int,pair<int,int> > > qq;
	qq.push(make_pair(0,make_pair(0,0)));
	visit[0][0][0]=0;
	while(!qq.empty())
	{
		pair<int,pair<int,int > > pp = qq.front();
		qq.pop();
		int cnt = pp.first;
		int x = pp.second.first;
		int y = pp.second.second;
		for(int i=0;i<4;i++)
		{
			int ddx = x+dx[i];
			int ddy = y+dy[i];
			if(ddx<0 || ddy<0 || ddx>=N || ddy>=M)
				continue;
			if(visit[cnt][ddx][ddy]==-1 && arr[ddx][ddy]==0)
			{
				visit[cnt][ddx][ddy]=visit[cnt][x][y]+1;
				qq.push(make_pair(cnt,make_pair(ddx,ddy)));
			}
			if(visit[cnt+1][ddx][ddy]==-1 && arr[ddx][ddy]==1 && cnt+1<=K)
			{
				visit[cnt+1][ddx][ddy]=visit[cnt][x][y]+1;
				qq.push(make_pair(cnt+1,make_pair(ddx,ddy)));

			}
		}
	}
	int mins=100000000;
	for(int i=0;i<=K;i++)
	{
		if(visit[i][N-1][M-1]!=-1)
			mins=min(mins,visit[i][N-1][M-1]+1);

	}
	if(mins==100000000)
		printf("-1");
	else
		printf("%d",mins);
	
}
