#include <stdio.h>
#include <queue>
#include <iostream>
#include <cstring>
#include <vector>
using namespace std;
vector<pair<int,int> > vv;
char arr[101][101];
int dp[101][101][81];
char st[81];
int dx[4]={1,-1,0,0};
int dy[4]={0,0,1,-1};
int n,m,k;
int dfs(int x, int y, int idx)
{
	if(dp[x][y][idx]!=-1)
		return dp[x][y][idx];
	if(idx>=strlen(st))
		return 1;
	dp[x][y][idx]=0;
	for(int i=0;i<4;i++)
	{
		for(int K=1;K<=k;K++)
		{
			int ddx = x+dx[i]*K;
			int ddy = y+dy[i]*K;
			if(ddx<0 || ddy<0 || ddx>=n || ddy>=m)
				continue;
			if(arr[ddx][ddy]!=st[idx])
				continue;
			dp[x][y][idx]+=dfs(ddx,ddy,idx+1);
		}
	}
	return dp[x][y][idx];
}
int main(void)
{
	int sx,sy;
	memset(dp,-1,sizeof(dp));
	cin >> n >> m >> k;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			cin >> arr[i][j];
		}

	}
	cin >> st;
	int res=0;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			if(arr[i][j]==st[0])
			{
				res+=dfs(i,j,1);
			}
		}
	}
	printf("%d",res);
	
}
