#include <stdio.h>
#include <queue>
#include <cstring>
#include <algorithm>
using namespace std;
int n,m;
int dx[4]={1,-1,0,0};
int dy[4]={0,0,1,-1};
int arr[101][101];
int visit[101][101][4];
// 0 동, 1 서, 2 남, 3 북 
int main(void)
{
	scanf("%d %d",&n,&m);
	memset(visit,-1,sizeof(visit));
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			scanf("%d",&arr[i][j]);
		}
	}
	int sx,sy,sd;
	int ex,ey,ed;
	scanf("%d %d %d",&sx,&sy,&sd);
	sd--;sx--;sy--;
	scanf("%d %d %d",&ex,&ey,&ed);
	ed--;
	ex--;ey--;
	visit[sx][sy][sd]=0;
	queue<pair<int,pair<int,int> > > qq;
	qq.push(make_pair(sx,make_pair(sy,sd)));
	while(!qq.empty())
	{
		int x = qq.front().first;
		int y = qq.front().second.first;
		int d = qq.front().second.second;
		qq.pop();
		if(x==ex && y==ey && d==ed)
			break;
		if(d==0)
		{
			for(int i=1;i<=3;i++)
			{
				if(y+i<m)
				{
					if(arr[x][y+i]==1)
						break;
					if(visit[x][y+i][d]==-1 && arr[x][y+i]==0)
					{
						visit[x][y+i][d]=visit[x][y][d]+1;
						qq.push(make_pair(x,make_pair(y+i,d)));
					}
				}
			}
		}
		else if(d==1)
		{
			for(int i=1;i<=3;i++)
			{
				if(y-i>=0)
				{
					if(arr[x][y-i]==1)
						break;
					if(visit[x][y-i][d]==-1 && arr[x][y-i]==0)
					{
						visit[x][y-i][d]=visit[x][y][d]+1;
						qq.push(make_pair(x,make_pair(y-i,d)));
					}
				}
			}
		}
		else if(d==2)
		{
			for(int i=1;i<=3;i++)
			{
				if(x+i<n)
				{
					if(arr[x+i][y]==1)
						break;
					if(visit[x+i][y][d]==-1 && arr[x+i][y]==0)
					{
						visit[x+i][y][d]=visit[x][y][d]+1;
						qq.push(make_pair(x+i,make_pair(y,d)));
					}
				}
			}
		}
		else if(d==3)
		{
			for(int i=1;i<=3;i++)
			{
				if(x-i>=0)
				{
					if(arr[x-i][y]==1)
						break;
					if(visit[x-i][y][d]==-1 && arr[x-i][y]==0)
					{
						visit[x-i][y][d]=visit[x][y][d]+1;
						qq.push(make_pair(x-i,make_pair(y,d)));
					}
				}
			}
		}
		if(d==0)
		{
			if(visit[x][y][3]==-1)
			{
				visit[x][y][3]=visit[x][y][d]+1;
				qq.push(make_pair(x,make_pair(y,3)));
			}
			if(visit[x][y][2]==-1)
			{
				visit[x][y][2]=visit[x][y][d]+1;
				qq.push(make_pair(x,make_pair(y,2)));
			}
			if(visit[x][y][1]==-1)
			{
				visit[x][y][1]=visit[x][y][d]+2;
				qq.push(make_pair(x,make_pair(y,1)));
			}
		}
		if(d==1)
		{
			if(visit[x][y][3]==-1)
			{
				visit[x][y][3]=visit[x][y][d]+1;
				qq.push(make_pair(x,make_pair(y,3)));
			}
			if(visit[x][y][2]==-1)
			{
				visit[x][y][2]=visit[x][y][d]+1;
				qq.push(make_pair(x,make_pair(y,2)));
			}
			if(visit[x][y][0]==-1)
			{
				visit[x][y][0]=visit[x][y][d]+2;
				qq.push(make_pair(x,make_pair(y,0)));
			}
		}

		if(d==2)
		{
			if(visit[x][y][0]==-1)
			{
				visit[x][y][0]=visit[x][y][d]+1;
				qq.push(make_pair(x,make_pair(y,0)));
			}
			if(visit[x][y][1]==-1)
			{
				visit[x][y][1]=visit[x][y][d]+1;
				qq.push(make_pair(x,make_pair(y,1)));
			}
			if(visit[x][y][3]==-1)
			{
				visit[x][y][3]=visit[x][y][d]+2;
				qq.push(make_pair(x,make_pair(y,3)));
			}
		}
		if(d==3)
		{
			if(visit[x][y][0]==-1)
			{
				visit[x][y][0]=visit[x][y][d]+1;
				qq.push(make_pair(x,make_pair(y,0)));
			}
			if(visit[x][y][1]==-1)
			{
				visit[x][y][1]=visit[x][y][d]+1;
				qq.push(make_pair(x,make_pair(y,1)));
			}
			if(visit[x][y][2]==-1)
			{
				visit[x][y][2]=visit[x][y][d]+2;
				qq.push(make_pair(x,make_pair(y,2)));
			}
		}

	}
	printf("%d",visit[ex][ey][ed]);
}

