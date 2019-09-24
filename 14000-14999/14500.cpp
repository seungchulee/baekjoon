#include <stdio.h>
#include <algorithm>
using namespace std;
int N,M;
int arr[501][501];
int main(void)
{
	scanf("%d %d",&N,&M);
	for(int i=0;i<N;i++)
	{
		for(int j=0;j<M;j++)
		{
			scanf("%d",&arr[i][j]);
		}
	}

	int maxs=-1;
	for(int i=0;i<N;i++)
	{
		for(int j=0;j<M;j++)
		{
			if(j+3<M)
			{
				int result=arr[i][j]+arr[i][j+1]+arr[i][j+2]+arr[i][j+3];
				maxs=max(result,maxs);
			} // sero
			if(i+3<N)
			{
				int result=arr[i][j]+arr[i+1][j]+arr[i+2][j]+arr[i+3][j];
				maxs=max(result,maxs);
			} // sero
			if(i+1<N && j+1<M)
			{
				int result=arr[i][j]+arr[i+1][j]+arr[i][j+1]+arr[i+1][j+1];
				maxs=max(result,maxs);
			} // nemo
			if(i+2<N && j+1<M)
			{
				int result=arr[i][j]+arr[i+1][j]+arr[i+2][j]+arr[i+2][j+1];
				maxs=max(result,maxs);
			}
			if(i+1<N && j+2<M)
			{
				int result=arr[i][j]+arr[i+1][j]+arr[i][j+1]+arr[i][j+2];
				maxs=max(result,maxs);
			}
			if(i+2<N && j+1<M)
			{
				int result=arr[i][j]+arr[i][j+1]+arr[i+1][j+1]+arr[i+2][j+1];
				maxs=max(result,maxs);
			}
			if(i<N && j+2<M && i>=1)
			{
				int result=arr[i][j]+arr[i][j+1]+arr[i][j+2]+arr[i-1][j+2];
				maxs=max(result,maxs);
			}

			if(i+2<N && j>=1)
			{
				int result=arr[i][j]+arr[i+1][j]+arr[i+2][j]+arr[i+2][j-1];
				maxs=max(result,maxs);
			}
			if(i+1<N && j+2<M)
			{
				int result=arr[i][j]+arr[i+1][j]+arr[i+1][j+1]+arr[i+1][j+2];
				maxs=max(result,maxs);
			}
			if(i+2<N && j+1<M)
			{
				int result=arr[i][j]+arr[i][j+1]+arr[i+1][j]+arr[i+2][j];
				maxs=max(result,maxs);
			}
			if(i+1<N && j+2<M)
			{
				int result=arr[i][j+1]+arr[i][j+2]+arr[i][j]+arr[i+1][j+2];
				maxs=max(result,maxs);
			}




			if(i+2<N && j+1<M)
			{
				int result=arr[i][j]+arr[i+1][j]+arr[i+1][j+1]+arr[i+2][j+1];
				maxs=max(result,maxs);
			}
			if(i<N && j+2<M && i>=1)
			{
				int result=arr[i][j]+arr[i][j+1]+arr[i-1][j+1]+arr[i-1][j+2];
				maxs=max(result,maxs);
			}
			if(j>=1 && i+2<N)
			{
				int result=arr[i][j]+arr[i+1][j]+arr[i+1][j-1]+arr[i+2][j-1];
				maxs=max(result,maxs);
			}
			if(i+1<N && j+2<M)
			{
				int result=arr[i][j]+arr[i][j+1]+arr[i+1][j+1]+arr[i+1][j+2];
				maxs=max(result,maxs);
			}




			if(i+1<N && j+2<M)
			{
				int result=arr[i][j]+arr[i][j+1]+arr[i][j+2]+arr[i+1][j+1];
				maxs=max(result,maxs);
			}
			if(i+2<N && j<M && j>=1)
			{
				int result=arr[i][j]+arr[i+1][j]+arr[i+2][j]+arr[i+1][j-1];
				maxs=max(result,maxs);
			}
			if(i>=1 && j+2<M)
			{
				int result=arr[i][j]+arr[i][j+1]+arr[i-1][j+1]+arr[i][j+2];
				maxs=max(result,maxs);
			}
			if(i+2<N && j+1<M)
			{
				int result=arr[i][j]+arr[i+1][j]+arr[i+2][j]+arr[i+1][j+1];
				maxs=max(result,maxs);
			}


		}
	}
	printf("%d",maxs);

}
