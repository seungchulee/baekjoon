#include <stdio.h>
#include <vector>
#include <stdlib.h>
using namespace std;
vector<pair<int,int> > vv;
int arr[10][10];
int vertical(int r, int c, int num)
{
	for(int i=0;i<9;i++)
	{
		if(arr[i][c]==num)
			return -1;
	}
	return 1;
}
int horizontal(int r, int c, int num)
{
	for(int i=0;i<9;i++)
	{
		if(arr[r][i]==num)
		{
			return -1;
		}
	}
	return 1;
}
int square(int r, int c, int num)
{
	r/=3;
	c/=3;
	for(int i=r*3;i<(r*3)+3;i++)
	{
		for(int j=c*3;j<(c*3)+3;j++)
		{
			if(arr[i][j]==num)
				return -1;
		}
	}
	return 1; 

}
void func(int idx)
{
	if(idx==vv.size())
	{
		for(int i=0;i<9;i++)
		{
			for(int j=0;j<9;j++)
			{
				printf("%d ",arr[i][j]);
			}
			printf("\n");
		}
		exit(0);
		return;
	}

	for(int i=1;i<=9;i++)
	{
		int r=vv[idx].first;
		int c=vv[idx].second;
		if(vertical(r,c,i)==1 && horizontal(r,c,i)==1 && square(r,c,i)==1)
		{
			arr[r][c]=i;
			func(idx+1);
			arr[r][c]=0;
		}
	}
}
int main(void)
{
	for(int i=0;i<9;i++)
	{
		for(int j=0;j<9;j++)
		{
			scanf("%1d",&arr[i][j]);
			if(arr[i][j]==0)
				vv.push_back(make_pair(i,j));
		}
	}
	for(int i=1;i<=9;i++)
	{
		int r,c;
		r=vv[0].first;
		c=vv[0].second;
		if(vertical(r,c,i)==1 && horizontal(r,c,i)==1 && square(r,c,i)==1)
		{
			arr[r][c]=i;
			func(1);
			arr[r][c]=0;
		}
	}

}
