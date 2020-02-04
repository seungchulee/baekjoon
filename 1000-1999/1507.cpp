#include <stdio.h>
#include <cstring>
int N;
int arr[21][21];
bool possible[21][21];
int main(void)
{
	memset(possible,false,sizeof(possible));
	scanf("%d",&N);
	for(int i=0;i<N;i++)
	{
		for(int j=0;j<N;j++)
		{
			scanf("%d",&arr[i][j]);
		}
	}
	for(int k=0;k<N;k++)
	{
		for(int i=0;i<N;i++)
		{
			for(int j=0;j<N;j++)
			{
				if(k==i || i==j || k==j)
					continue;
				if(arr[i][j]==arr[i][k]+arr[k][j])
				{
					possible[i][j]=true;
				}
				if(arr[i][j]>arr[i][k]+arr[k][j])
				{
					printf("-1");
					return 0;
				}
			}
		}
	}
	int ans=0;
	for(int i=0;i<N;i++)
	{
		for(int j=0;j<N;j++)
		{
			if(possible[i][j]==false)
				ans+=arr[i][j];
		}
	}
	printf("%d",ans/2);
}
