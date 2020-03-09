#include <stdio.h>
#include <queue>
#include <cstring>
#include <algorithm>
using namespace std;
int arr[201][201];
int visit[201][201][31];
int dx[8]={-1,-2,-2,-1,1,2,2,1};
int dy[8]={-2,-1,1,2,2,1,-1,-2};
int dx2[4]={1,-1,0,0};
int dy2[4]={0,0,1,-1};
int main(void)
{
	int k;
	int n,m;
	scanf("%d",&k);
	scanf("%d %d",&n,&m);
	for(int i=0;i<m;i++)
	{		
		for(int j=0;j<n;j++)
		{
			scanf("%d",&arr[i][j]);
		}
	}
	memset(visit,-1,sizeof(visit));
	queue<pair<int,pair< int,int> > > qq;
	qq.push(make_pair(0,make_pair(0,0)));
	visit[0][0][0]=0;
	while(!qq.empty())
	{
		int kk = qq.front().first;
		int x = qq.front().second.first;
		int y = qq.front().second.second;
		qq.pop();
		for(int i=0;i<4;i++)
		{
			int ddx = x+dx2[i];
			int ddy = y+dy2[i];
			if(ddx<0 || ddy<0 || ddx>=m || ddy>=n)
				continue;
			if(arr[ddx][ddy]==1)
				continue;
			if(visit[ddx][ddy][kk]==-1)
			{
				visit[ddx][ddy][kk]=visit[x][y][kk]+1;
				qq.push(make_pair(kk,make_pair(ddx,ddy)));
			}
		}
		if(kk<k)
		{
			for(int i=0;i<8;i++)
			{
				int ddx = x+dx[i];
				int ddy = y+dy[i];
				if(ddx<0 || ddy<0 || ddx>=m || ddy>=n)
					continue;
				if(arr[ddx][ddy]==1)
					continue;
				if(visit[ddx][ddy][kk+1]==-1)
				{
					visit[ddx][ddy][kk+1]=visit[x][y][kk]+1;
					qq.push(make_pair(kk+1,make_pair(ddx,ddy)));
				}
			}
		}
	}
	int mins = 10000000;
	for(int i=0;i<=k;i++)
	{
		if(visit[m-1][n-1][i]!=-1)
			mins=min(mins,visit[m-1][n-1][i]);
	}
	if(mins==10000000)
		printf("-1");
	else
		printf("%d",mins);
}
