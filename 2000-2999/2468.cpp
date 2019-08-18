#include <stdio.h>
#include <algorithm>
using namespace std;
int arr[101][101]={0};
int visit[101][101]={0};
int dx[4]={-1,1,0,0};
int dy[4]={0,0,-1,1};
int N;
void reset()
{
	for(int i=1;i<=N;i++)
	{
		for(int j=1;j<=N;j++)
		{
			visit[i][j]=0;
		}
	}

}
void DFS(int i, int j, int k)
{
	int ddx;

	int ddy;
	
	visit[i][j]=1;
	for(int x=0;x<4;x++)
	{
		ddx=j+dx[x];
		ddy=i+dy[x];

		if(ddx<1 || ddy<1 || ddx>N || ddy>N)
		{
			continue;
		}
		if(arr[ddy][ddx]>k && visit[ddy][ddx]==0)
			DFS(ddy,ddx,k);
	}
}
int main(void)
{
	scanf("%d",&N);
	int min_=2147483647;
	int max_=0;
	for(int i=1;i<=N;i++)
	{
		for(int j=1;j<=N;j++)
		{
			scanf("%d",&arr[i][j]);
			if(arr[i][j]>max_)
				max_=arr[i][j];
			if(arr[i][j]<min_)
				min_=arr[i][j];
		}
	}
	
	int max_val=1;
	for(int k=min_;k<=max_;k++)
	{
		int check=0;
		for(int i=1;i<=N;i++)
		{
			for(int j=1;j<=N;j++)
			{
				if(arr[i][j]>k && visit[i][j]==0)
				{
					DFS(i,j,k);
					check++;
				}
			}
		}
		//printf("%d ",check);
		reset();
		max_val=max(check,max_val);
	}
	printf("%d",max_val);
}
