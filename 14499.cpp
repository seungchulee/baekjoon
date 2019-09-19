#include <stdio.h>
#include <cstring>
int dice[7];
int arr[21][21];
int N,M;
int x,y;
void move(int index)
{
	if(index==1)
	{
		if(y+1>=M)
			return;
		y+=1;
		if(arr[x][y]==0)
		{
			arr[x][y]=dice[3];
		}
		else
		{
			dice[3]=arr[x][y];
			arr[x][y]=0;
		}
		int temp=dice[1];
		dice[1]=dice[5];
		dice[5]=dice[3];
		dice[3]=dice[2];
		dice[2]=temp;
		
		printf("%d\n",dice[2]);
	}
	if(index==2)
	{
		if(y-1<0)
			return;
		y-=1;
		if(arr[x][y]==0)
		{
			arr[x][y]=dice[1];
		}
		else
		{
			dice[1]=arr[x][y];
			arr[x][y]=0;
		}

		int temp=dice[1];
		dice[1]=dice[2];
		dice[2]=dice[3];
		dice[3]=dice[5];
		dice[5]=temp;

		printf("%d\n",dice[2]);


	}
	if(index==3)
	{
		if(x-1<0)
			return;
		x-=1;
		if(arr[x][y]==0)
			arr[x][y]=dice[0];
		else
		{
			dice[0]=arr[x][y];
			arr[x][y]=0;
		}

		int temp=dice[0];
		dice[0]=dice[2];
		dice[2]=dice[4];
		dice[4]=dice[5];
		dice[5]=temp;
		printf("%d\n",dice[2]);
	}
	if(index==4)
	{
		if(x+1>=N)
			return;
		x+=1;
		if(arr[x][y]==0)
			arr[x][y]=dice[4];
		else
		{
			dice[4]=arr[x][y];
			arr[x][y]=0;
		}

		int temp=dice[0];
		dice[0]=dice[5];
		dice[5]=dice[4];
		dice[4]=dice[2];
		dice[2]=temp;

		printf("%d\n",dice[2]);
	}
}
int main(void)
{
	int K;
	memset(dice,0,sizeof(dice));
	
	scanf("%d %d %d %d %d",&N,&M,&x,&y,&K);
	for(int i=0;i<N;i++)
	{
		for(int j=0;j<M;j++)
		{
			scanf("%d",&arr[i][j]);
		}
	}

	int index;
	for(int i=0;i<K;i++)
	{
		scanf("%d",&index);
		move(index);


	}
}
