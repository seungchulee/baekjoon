#include <stdio.h>
#include <cstring>
#include <algorithm>
#include <cstdio>
using namespace std;
char arr[51][51];
int dp[51][51];
int visit[51][51];
int dx[4]={-1,1,0,0};
int dy[4]={0,0,-1,1};
int N,H;
int dfs(int x, int y)
{
	if(x<0 || x>=N || y<0 || y>=H)
		return 0;
	if(arr[x][y]=='H')
		return 0;
	if(visit[x][y]==1)
	{
		printf("-1");
		exit(0);
	}
	int &ret = dp[x][y];
	if(ret!=-1)
		return ret;
	visit[x][y]=1;
	for(int i=0;i<4;i++)
	{
		int ddx=x+(arr[x][y]-'0')*dx[i];
		int ddy=y+(arr[x][y]-'0')*dy[i];
		ret = max(ret,dfs(ddx,ddy)+1);
		//int val = dfs(ddx,ddy)+1;
		//ret = max(ret,val);
	}
	visit[x][y]=-1;
	return ret;
	
}
int main(void)
{
	memset(visit,-1,sizeof(visit));
	memset(dp,-1,sizeof(dp));
	scanf("%d %d",&N,&H);
	for(int i=0;i<N;i++)
	{
		char st[51];
		scanf("%s",st);
		for(int j=0;j<H;j++)
		{

			arr[i][j]=st[j];
		}
	}


	printf("%d",dfs(0,0));
	
}
