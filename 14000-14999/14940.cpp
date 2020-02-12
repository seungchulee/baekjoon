#include <stdio.h>
#include <queue>
#include <cstring>
using namespace std;
int arr[1001][1001];
int visit[1001][1001];
int dx[4]={1,-1,0,0};
int dy[4]={0,0,1,-1};
int main(void)
{
	int n,m;
	scanf("%d %d",&n,&m);
	memset(visit,0,sizeof(visit));
	int ii,jj;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			scanf("%d",&arr[i][j]);
			if(arr[i][j]==2)
			{
				ii=i;
				jj=j;
			}
		}
	}

	queue<pair<int,int> > qq;
	qq.push(make_pair(ii,jj));
	visit[ii][jj]=0;
	while(!qq.empty())
	{
		pair<int,int> pp=qq.front();
		qq.pop();
		int x = pp.first;
		int y = pp.second;
		for(int i=0;i<4;i++)
		{
			int ddx = x+dx[i];
			int ddy = y+dy[i];
			if(ddx<0 || ddy<0 || ddx>=n || ddy>=m)
				continue;
			if(arr[ddx][ddy]==1 && visit[ddx][ddy]==0)
			{
				visit[ddx][ddy]=visit[x][y]+1;
				qq.push(make_pair(ddx,ddy));
			}
		}
	}
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			if(arr[i][j]==1 && visit[i][j]==0)
				printf("-1 ");
			else
				printf("%d ",visit[i][j]);
		}
		printf("\n");
	}
}
