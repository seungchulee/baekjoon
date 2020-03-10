#include <stdio.h>
#include <queue>
#include <cstring>
#include <iostream>
using namespace std;
int dx[4]={0,0,1,-1};
int dy[4]={1,-1,0,0};
int n,m;
int h,w,sr,sc,fr,fc;
int arr[1001][1001];
int visit[1001][1001];
bool check(int x, int y ,int i)
{
	if(i==0)
	{
		if(y+w-1>=m)
			return false;
		for(int i=x;i<x+h;i++)
			if(arr[i][y+w-1]==1)
				return false;
	}
	else if(i==1)
	{
		for(int i=x;i<x+h;i++)
			if(arr[i][y]==1)
				return false;
	}
	else if(i==2)
	{
		if(x+h-1>=n)
			return false;
		for(int i=y;i<y+w;i++)
			if(arr[x+h-1][i]==1)
				return false;
	}
	else if(i==3)
	{
		for(int i=y;i<y+w;i++)
			if(arr[x][i]==1)
				return false;
	}
	return true;
}
int main(void)
{
	cin >> n >> m;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			cin >> arr[i][j];
		}
	}
	memset(visit,-1,sizeof(visit));
	cin >> h >> w >> sr >> sc >> fr >> fc;
	sr--;sc--;fr--;fc--;
	queue<pair<int,int> > qq;
	qq.push(make_pair(sr,sc));
	visit[sr][sc]=0;
	while(!qq.empty())
	{
		int x = qq.front().first;
		int y = qq.front().second;
		qq.pop();
		for(int i=0;i<4;i++)
		{
			int ddx = x+dx[i];
			int ddy = y+dy[i];
			if(ddx<0 || ddy<0 || ddx>=n || ddy>=m)
				continue;
			
			bool chk = check(ddx,ddy,i);
			if(chk==false)
				continue;
			if(visit[ddx][ddy]==-1) 
			{
				visit[ddx][ddy]=visit[x][y]+1;
				qq.push(make_pair(ddx,ddy));
			}
		}
	}
	printf("%d",visit[fr][fc]);
}
