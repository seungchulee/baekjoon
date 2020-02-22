#include <stdio.h>
#include <queue>
#include <cstring>

using namespace std;
int arr[51][51];
int dx[4]={1,-1,0,0};
int dy[4]={0,0,1,-1};
int visit[51][51];
int main(void)
{
	int n;
	scanf("%d",&n);
	
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			scanf("%1d",&arr[i][j]);
			visit[i][j]=10000000;
		}
	}
	visit[0][0]=0;
	queue<pair<int,int> > qq;
	qq.push(make_pair(0,0));
	while(!qq.empty())
	{
		pair<int,int> pp = qq.front();
		qq.pop();
		int x = pp.first;
		int y = pp.second;
		for(int i=0;i<4;i++)
		{
			int ddx = x+dx[i];
			int ddy = y+dy[i];
			if(ddx<0 || ddy<0 || ddx>n || ddy>n)
				continue;
			if(visit[ddx][ddy]<=visit[x][y])
				continue;
			if(arr[ddx][ddy]==1)
			{
				qq.push(make_pair(ddx,ddy));
				visit[ddx][ddy]=visit[x][y];
			}
			if(arr[ddx][ddy]==0)
			{
				qq.push(make_pair(ddx,ddy));
				visit[ddx][ddy]=visit[x][y]+1;
			}
		}
				

	}
	printf("%d",visit[n-1][n-1]);

}

