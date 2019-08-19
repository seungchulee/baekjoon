#include <stdio.h>
int N,M,K;
int arr[51][51];
int R[51];
int C[51];
int S[51];
bool check[51]={false};

void rotate(int r, int c, int s)
{
	int cnt=1;
	for(int i=0;i<s;i++)
	{
		int new_r=r-cnt;
		int new_c=c-cnt;
		
		int tmp[201];
		int k=1;
		
		for(int x=new_r;x<=new_r+2*cnt;x++)
		{

		}

	
		cnt++;
	}
}
void func(int index)
{

	if(index==K)
	{
		// get min
		return;
	}
	
	for(int i=1;i<=K;i++)
	{
		if(check[i]==true)
			continue;
		check[i]=true;
		rotate(R[i],C[i],S[i]);
		func(index+1);
		check[i]=false;
	}
}
int main(void)
{
	scanf("%d %d %d",&N,&M,&K);
	for(int i=1;i<=N;i++)
	{
		for(int j=1;j<=M;j++)
		{
			scanf("%d",&arr[i][j]);
		}
	}
	for(int i=1;i<=K;i++)
	{
		scanf("%d %d %d",&R[i],&C[i],&S[i]);	
	}
	func(0);
}
