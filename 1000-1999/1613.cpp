#include <stdio.h>
#include <algorithm>
using namespace std;
int arr[411][411];
int n,k;
int main(void)
{
	scanf("%d %d",&n,&k);
	for(int i=0;i<=401;i++)
	{
		for(int j=0;j<=401;j++)
		{
			if(i==j)
				arr[i][j]=0;
			else
				arr[i][j]=10000000;
		}
	}
	for(int i=0;i<k;i++)
	{
		int a,b;
		scanf("%d %d",&a,&b);
		arr[a][b]=1;
	}
	for(int k=1;k<=n;k++)
	{
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=n;j++)
			{
				arr[i][j]=min(arr[i][j],arr[i][k]+arr[k][j]);
			}
		}	
	}
	int x;
	scanf("%d",&x);
	for(int t=0;t<x;t++)
	{
		int a,b;
		scanf("%d %d",&a,&b);
		if(arr[a][b]==10000000)
		{
			if(arr[b][a]==10000000)
				printf("0\n");
			else
				printf("1\n");
		}
		else if(arr[a][b]>=1)
			printf("-1\n");
	}

}
