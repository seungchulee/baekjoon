#include <stdio.h>
#include <cstring>
int arr[201][201];
int main(void)
{
	int N,M;
	scanf("%d %d",&N,&M);
	memset(arr,0,sizeof(arr));
	for(int i=0;i<M;i++)
	{
		int a,b;
		scanf("%d %d",&a,&b);
		arr[a][b]=1;
		arr[b][a]=1;
	}
	int result=0;
	for(int i=1;i<=N;i++)
	{
		for(int j=i+1;j<=N;j++)
		{
			if(arr[i][j]==1)
				continue;
			for(int k=j+1;k<=N;k++)
			{
				if(arr[j][k]==1 || arr[i][k]==1)
					continue;
				result++;
			}
		}
	}
	printf("%d",result);	
}
