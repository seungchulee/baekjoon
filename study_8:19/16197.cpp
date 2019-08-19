#include <stdio.h>
#include <string.h>
int step=0;
int N,M;
char arr[20][20];
int dx[4]={0,0,1,-1};
int dy[4]={1,-1,0,0};
int min=100000000;
int move(int x1, int y1, int x2, int y2, int step)
{

	int min=-1;
	bool flag1=true;
	bool flag2=true;
	if(step==11)
		return -1;

	if(x1<0 || y1<0 || x1>=N || y1>=M)
		flag1=false;
	if(x2<0 || y2<0 || x2>=N || y2>=M)
		flag2=false;
	if(flag1==false && flag2==false)
		return -1;
	if(flag1==false || flag2==false)
		return step;

	for(int i=0;i<4;i++)
	{
		int ddx1=x1+dx[i];
		int ddy1=y1+dy[i];
		int ddx2=x2+dx[i];
		int ddy2=y2+dy[i];

		if(arr[ddx1][ddy1]=='#' && ddx1>=0 && ddy1>=0 && ddx1<N && ddy1<M)
		{
			ddx1=x1;
			ddy1=y1;
		}
		if(arr[ddx2][ddy2]=='#' && ddx2>=0 && ddy2>=0 && ddx2<N && ddy2<M)
		{
			ddx2=x2;
			ddy2=y2;
		}
		
		int result=move(ddx1,ddy1,ddx2,ddy2,step+1);
		if(result==-1)
			continue;
		if(min>result || min==-1)
			min=result;



	}

	return min;
}
int main(void)
{
	int result=0;
	scanf("%d %d",&N,&M);
	getchar();
	for(int i=0;i<N;i++)
	{
		for(int j=0;j<M;j++)
		{
			scanf("%c",&arr[i][j]);

		}
		getchar();
	}
	int cnt=0;
	int x1,y1,x2,y2;
	for(int i=0;i<N;i++)
	{
		for(int j=0;j<M;j++)
		{
			if(arr[i][j]=='o')
			{
				if(cnt==0)
				{
					x1=i;
					y1=j;
					cnt++;
				}
				if(cnt==1)
				{
					x2=i;
					y2=j;
				}
			}
		}
	}
	result=move(x1,y1,x2,y2,0);	
	printf("%d",result);

	return 0;	
	
	
}
