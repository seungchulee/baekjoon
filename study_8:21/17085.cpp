#include <stdio.h>
#include <cstring>
#include <utility>
#include <algorithm>
#include <queue>
using namespace std;
int N,M;
char arr[15][15];
int dx[2]={1,0};
int dy[2]={0,1};
char tmp[15][15];
int another[2]={0,0};
char check[15][15];
int maxs=-1;

int get_area(int x, int y)
{

	int cnt=0;

	for(int k=1;;k++)
	{
		int ddx1=x+dx[0]*k;
		int ddy1=y+dy[0]*k;
		int ddx2=x-dx[0]*k;
		int ddy2=y-dy[0]*k;

		int ddx3=x+dx[1]*k;
		int ddy3=y+dy[1]*k;
		int ddx4=x-dx[1]*k;
		int ddy4=y-dy[1]*k;
		if(ddx1<0 || ddx2<0 || ddx3<0 || ddx4<0)
			break;
		if(ddy1<0 || ddy2<0 || ddy3<0 || ddy4<0)
			break;
		if(ddx1>=N || ddx2>=N || ddx3>=N || ddx4>=N)
			break;
		if(ddy1>=M || ddy2>=M || ddy3>=M || ddy4>=M)
			break;
		if(check[ddx1][ddy1]=='@' || check[ddx2][ddy2]=='@')
			break;
		if(check[ddx3][ddy3]=='@' || check[ddx4][ddy4]=='@')
			break;
		if(check[ddx1][ddy1]=='.' || check[ddx2][ddy2]=='.')
			break;
		if(check[ddx3][ddy3]=='.' || check[ddx4][ddy4]=='.')
			break;
		if(check[ddx1][ddy1]=='#' && check[ddx2][ddy2]=='#' && check[ddx3][ddy3]=='#' && check[ddx4][ddy4]=='#')
		{
				check[ddx1][ddy1]='$';
				check[ddx2][ddy2]='$';
				check[ddx3][ddy3]='$';
				check[ddx4][ddy4]='$';
				cnt++;
		}
		else
			break;

		//printf("%d %d %d %d\n",ddx1,ddy1,ddx2,ddy2);	
		//cnt++;
	}

	/*for(int i=0;i<N;i++)
	{
		for(int j=0;j<M;j++)
		{
			printf("%c",check[i][j]);
		}
		printf("\n");
	}
	printf("%d\n\n",4*cnt+1);*/

	return 4*cnt+1;

}
int get_max()
{

	memcpy(check,tmp,sizeof(tmp));
//	printf("=========\n");	
	int size=1;
	for(int i=0;i<N;i++)
	{
		for(int j=0;j<M;j++)
		{
			if(check[i][j]=='@')
			{
				size*=get_area(i,j);
			}
		}
	}
	return size;
	
}
void func(int index)
{
	if(index==2)
	{
		maxs=max(get_max(),maxs);
		return;
	}

	for(int i=0;i<N;i++)
	{
		for(int j=0;j<M;j++)
		{
			if(tmp[i][j]=='#')
			{
				tmp[i][j]='@';
				func(index+1);
				tmp[i][j]='#';
			}
		}
	}
}

int main(void)
{
	scanf("%d %d",&N,&M);
	for(int i=0;i<N;i++)
	{
		char st[16];
		scanf("%s",st);
		for(int j=0;j<M;j++)
		{
			arr[i][j]=st[j];
			tmp[i][j]=arr[i][j];
		}
	}
	func(0);
	printf("%d",maxs);
}
