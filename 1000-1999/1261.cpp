#include <stdio.h>
#include <queue>
#include <cstring>
using namespace std;
int arr[101][101];
int visit[101][101];
int dx[4]={1,-1,0,0};
int dy[4]={0,0,1,-1};
int main(void)
{
	int n,m;
	scanf("%d %d",&n,&m);
	for(int i=0;i<m;i++)
	{
		for(int j=0;j<n;j++)
		{
			scanf("%1d",&arr[i][j]);
		}
	}
	memset(visit,0,sizeof(visit));
	visit[0][0]=1;
	priority_queue<pair<int,pair<int,int> > , vector<pair<int,pair<int,int> > >, greater<pair<int,pair<int,int> > > > qq;
	qq.push(make_pair(0,make_pair(0,0)));
	while(!qq.empty())
	{
		int idx = qq.top().first;
		int x = qq.top().second.first;
		int y = qq.top().second.second;
		//printf("%d ",idx);
		if(x==m-1 && y==n-1)
			printf("%d",idx);

		qq.pop();
		for(int i=0;i<4;i++)
		{
			int ddx = x+dx[i];
			int ddy = y+dy[i];
			if(ddx<0 || ddy<0 || ddx>=m || ddy>=n)
				continue;
			if(visit[ddx][ddy]==0)
			{
				visit[ddx][ddy]=1;
				if(arr[ddx][ddy]==0)
				{
					qq.push(make_pair(idx,make_pair(ddx,ddy)));
				}
				if(arr[ddx][ddy]==1)
				{
					qq.push(make_pair(idx+1,make_pair(ddx,ddy)));
				}
			}
		}
		
	}

}
