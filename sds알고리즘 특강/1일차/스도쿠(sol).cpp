#include <stdio.h>
#include <stdlib.h>
#include <vector>
using namespace std;
vector<pair<int,int> > vv;
int arr[9][9];
int square_check(int num, int r, int c)
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
int vertical_check(int num, int c)
{
	for(int i=0;i<9;i++)
	{
		if(arr[i][c]==num)
			return -1;
	}

	return 1;
}
int horizontal_check(int num, int r)
{
	for(int i=0;i<9;i++)
	{
		if(arr[r][i]==num)
			return -1;
	}
	return 1;

}
void dfs(int idx)
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
	}

	for(int i=1;i<=9;i++)
	{
		int r = vv[idx].first;
		int c = vv[idx].second;
		//printf("i : %d | r: %d | c: %d | ver : %d | hor : %d | squ : %d\n",i,r,c,vertical_check(i,c),horizontal_check(i,r),square_check(i,r,c));
		if(vertical_check(i,c)==1 && horizontal_check(i,r)==1 && square_check(i,r,c)==1)
		{
			arr[r][c]=i;
			dfs(idx+1);
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
			scanf("%d",&arr[i][j]);
			if(arr[i][j]==0)
				vv.push_back(make_pair(i,j));
		}
	}
	for(int i=1;i<=9;i++)
	{

		int r = vv[0].first;
		int c = vv[0].second;
		//printf("%d %d %d\n",i,vertical_check(i,c),horizontal_check(i,r));
		if(vertical_check(i,c)==1 && horizontal_check(i,r)==1 && square_check(i,r,c)==1)
		{
			arr[r][c]=i;
			dfs(1);
			arr[r][c]=0;
		}
	}
}

