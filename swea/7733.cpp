#include <stdio.h>
#include <queue>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
int arr[101][101];
int visit[101][101];
int dx[4]={1,-1,0,0};
int dy[4]={0,0,1,-1};
int maxx=-1;
int n;
int maxs;

void ddfs2(int x, int y, int mm)
{
	for(int i=0;i<4;i++)
	{
		int ddx = x+dx[i];
		int ddy = y+dy[i];
		if(ddx<0 || ddy<0 || ddx>=n || ddy>=n)
			continue;
		if(visit[ddx][ddy]==-1 && arr[ddx][ddy]>mm)
		{
			visit[ddx][ddy]=1;
			ddfs2(ddx,ddy,mm);
		}
	}

}
void dfs()
{
	for(int x=0;x<=maxs;x++)
	{
		memset(visit,-1,sizeof(visit));
		int cnt=0;
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<n;j++)
			{
				if(visit[i][j]==-1 && arr[i][j]>x)
				{

					visit[i][j]=1;
					ddfs2(i,j,x);
					cnt++;
				}

			}
		}

		maxx=max(maxx,cnt);
	}
}
int main(void)
{
	int t;
	cin >> t;
	for(int a=1;a<=t;a++)
	{
		cin >> n ;
		maxs=-1;
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<n;j++)
			{
				scanf("%d",&arr[i][j]);
				maxs=max(maxs,arr[i][j]);
			}
		}
		dfs();
		printf("#%d %d\n",a,maxx);
		maxx=-1;
	}
}
