#include <stdio.h>
#include <cstring>
int N,M,K;
int arr[17][17];
int main(void)
{
	scanf("%d %d %d",&N,&M,&K);
	
	memset(arr,0,sizeof(arr));
	//arr[1][1]=1;
	for(int i=1;i<=N;i++)
	{
		for(int j=1;j<=M;j++)
		{
			arr[i][j]+=arr[i-1][j]+arr[i][j-1];
			arr[1][1]=1;

		}

	}

	if(K==0)
	{
		printf("%d",arr[N][M]);
	}
	else
	{
		int x=(K-1)/M+1;
		int y=(K-1)%M+1;
		int res1=arr[x][y];

		memset(arr,0,sizeof(arr));

		for(int i=x;i<=N;i++)
		{
			for(int j=y;j<=M;j++)
			{
				arr[i][j]=arr[i-1][j]+arr[i][j-1];
				arr[x][y]=1;
			}
		}
		printf("%d",res1*arr[N][M]);

	}

}
