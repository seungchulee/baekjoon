#include <stdio.h>
int n;
int arr[65][65];
void func(int n, int x, int y)
{
	if(n==1)
	{
		if(arr[x][y]==1)
			printf("1");
		else
			printf("0");
		return;
	}
	bool one=true;
	bool zero=true;
	for(int i=x;i<x+n;i++)
	{
		for(int j=y;j<y+n;j++)
		{
			if(arr[i][j]==0)
				one=false;
			else
				zero=false;
		}
	}
	if(one==true  && arr[x][y]==1)
	{
		printf("1");
	}
	else if(zero==true  && arr[x][y]==0)
	{
		printf("0");
	}
	else
	{
		printf("(");
		int div=n/2;
		func(div,x,y);
		func(div,x,y+div);
		func(div,x+div,y);
		func(div,x+div,y+div);
		printf(")");
	}
}
int main(void)
{
	scanf("%d",&n);

	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			scanf("%1d",&arr[i][j]);
		}

	}
	func(n,0,0);

}
