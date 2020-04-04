#include <iostream>
#include <queue>
#include <cstring>
using namespace std;
int arr[301][310];
int visit[301][301];
int n,m;
int main(void)
{
	memset(visit,-1,sizeof(visit));
	cin >> n >> m;
	for(int i=0;i<n;i++)
		for(int j=0;j<m;j++)
			cin >> arr[i][j];
	queue<pair<int,pair<int,int> > > qq;
	visit[0][0]=0;
	qq.push(make_pair(0,make_pair(0,0)));
	while(!qq.empty())
	{
		int cnt = qq.front().first;
		int x = qq.front().second.first;
		int y = qq.front().second.second;
		qq.pop();
		if(x==n-1 && y==m-1)
			cout << cnt;
		for(int i=1;i<=arr[x][y];i++)
		{
			int ddx = x+i;
			int ddy = y;
			if(ddx>=n)
				break;
			if(visit[ddx][ddy]==-1)
			{
				visit[ddx][ddy]=visit[x][y]+1;
				qq.push(make_pair(cnt+1,make_pair(ddx,ddy)));
			}
		}
		for(int i=1;i<=arr[x][y];i++)
		{
			int ddx = x;
			int ddy = y+i;
			if(ddy>=m)
				break;
			if(visit[ddx][ddy]==-1)
			{
				visit[ddx][ddy]=visit[x][y]+1;
				qq.push(make_pair(cnt+1,make_pair(ddx,ddy)));
			}
		}


	}
}

