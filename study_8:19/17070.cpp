#include <stdio.h>
int N;
int arr[16][16]={-1};
int result=0;
void func(int i,int j,int shape)
{

	if(i==N-1 && j==N-1)
	{
		result++;
		return;
	}

	if(i>=N || j>=N)
	{
		return;
	}

	if(shape==0)
	{
		if(arr[i][j+1]==0)
			func(i,j+1,0);
		if(arr[i][j+1]==0 && arr[i+1][j]==0 && arr[i+1][j+1]==0)
		{
			func(i+1,j+1,1);
		}
	}
	
	if(shape==1)
	{
		if(arr[i][j+1]==0)
			func(i,j+1,0);
		if(arr[i][j+1]==0 && arr[i+1][j]==0 && arr[i+1][j+1]==0)
		{
			func(i+1,j+1,1);
		}
		if(arr[i+1][j]==0)
			func(i+1,j,2);

	}
	if(shape==2)
	{
		if(arr[i+1][j]==0)
			func(i+1,j,2);
		if(arr[i][j+1]==0 && arr[i+1][j]==0 && arr[i+1][j+1]==0)
		{
			func(i+1,j+1,1);
		}

	}

		
}
int main(void)
{
	scanf("%d",&N);
	for(int i=0;i<N;i++)
	{
		for(int j=0;j<N;j++)
		{
			scanf("%d",&arr[i][j]);
		}
	}

	func(0,1,0);
		
	printf("%d",result);
}
