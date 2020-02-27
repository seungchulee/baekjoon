#include <stdio.h>
int arr[3000][3000];
int n;
int minus=0,zero=0,plus=0;
void func(int n, int x, int y, int find)
{
	bool check=true;
	if(n==1)
	{
		if(arr[x][y]==-1 && find==-1)
			minus++;
		else if(arr[x][y]==0 && find==0)
			zero++;
		else if(arr[x][y]==1 && find==1)
			plus++;
		return;
	}
	for(int i=x;i<x+n;i++)
	{
		for(int j=y;j<y+n;j++)
		{
			if(arr[i][j]!=find)
			{
				check=false;
			}
		}
	}

	if(check==true)
	{
		if(arr[x][y]==-1 && find==-1)
			minus++;
		else if(arr[x][y]==0 && find==0)
			zero++;
		else if(arr[x][y]==1 && find==1)
			plus++;
	}
	else
	{
		int div = n/3;
		func(div,x,y,find);
		func(div,x,y+div,find);
		func(div,x,y+div*2,find);

		func(div,x+div,y,find);
		func(div,x+div,y+div,find);
		func(div,x+div,y+div*2,find);

		func(div,x+div*2,y,find);
		func(div,x+div*2,y+div,find);
		func(div,x+div*2,y+div*2,find);
	}
	return;

}
int main(void)
{
	scanf("%d",&n);
	
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			scanf("%d",&arr[i][j]);
		}
	}
	func(n,0,0,-1);
	func(n,0,0,0);
	func(n,0,0,1);
	printf("%d\n%d\n%d",minus,zero,plus);

}
