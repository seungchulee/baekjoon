#include <stdio.h>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;
int arr[1001][1001];
int main(void)
{
	int N,M,X;
	for(int i=0;i<1001;i++)
	{
		for(int j=0;j<1001;j++)
		{
			if(i==j)
				arr[i][j]=0;
			else
				arr[i][j]=10000000;
		}
	}
	scanf("%d %d %d",&N,&M,&X);
	for(int i=0;i<M;i++)
	{
		int from,to,time;
		scanf("%d %d %d",&from,&to,&time);
		arr[from][to]=time;
	}
	for(int k=1;k<=N;k++)
	{
		for(int a=1;a<=N;a++)
		{
			for(int b=1;b<=N;b++)
			{
				arr[a][b]=min(arr[a][b],arr[a][k]+arr[k][b]);
			}
		}
	}
	int maxs=-1;
	for(int i=1;i<=N;i++)
	{
		maxs=max(maxs,arr[i][X]+arr[X][i]);
	}
	printf("%d",maxs);
}
