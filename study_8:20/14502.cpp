#include <stdio.h>
#include <utility>
#include <queue>
#include <string.h>
using namespace std;
int arr[9][9];
int tmp[9][9];

int N,M;
int maxs=-1;
int dx[4]={-1,1,0,0};
int dy[4]={0,0,1,-1};
void BFS()
{
	int tmp2[9][9];
	for(int i=0;i<N;i++)
	{
		for(int j=0;j<M;j++)
		{
			tmp2[i][j]=tmp[i][j];
		}
	}

	queue<pair<int, int> > qq;
	

	int p1=0;
	int q1=0;
	for(int i=0;i<N;i++)
	{
		for(int j=0;j<M;j++)
		{
			if(tmp2[i][j]==2)
			{
				pair<int, int> s = make_pair(i,j);
				qq.push(s);
			}
		}
		
	}

	while(!qq.empty())
	{
		pair <int,int> q = qq.front();
		qq.pop();
		int a=q.first;
		int b=q.second;
	


			
		for(int i=0;i<4;i++)
		{
			int ddx=a+dx[i];
			int ddy=b+dy[i];
			if(ddx<0 || ddy<0 || ddx>=N || ddy>=M || tmp2[ddx][ddy]==1)
				continue;
			if(tmp2[ddx][ddy]==0)
			{
				pair <int, int> s=make_pair(ddx,ddy);
				tmp2[ddx][ddy]=2;
				qq.push(s);
			}
		}
	}
	int area=0;
	for(int i=0;i<N;i++)
	{
		for(int j=0;j<M;j++)
		{
			if(tmp2[i][j]==0)
				area++;


		}
	}
	
	//printf("%d\n",area);
	maxs=max(area,maxs);


}
void func(int index)
{
	if(index==3)
	{
		BFS();
		// DO BFS
		return;
	}
	for(int i=0;i<N;i++)
	{
		for(int j=0;j<M;j++)
		{
			if(tmp[i][j]==0)
			{
				tmp[i][j]=1;
				func(index+1);
				tmp[i][j]=0;
			}
		}
	}

}
int main(void)
{

	scanf("%d %d",&N,&M);
	for(int i=0;i<N;i++)
	{
		for(int j=0;j<M;j++)
		{
			scanf("%d",&arr[i][j]);
			tmp[i][j]=arr[i][j];
		}
	}
	func(0);
	printf("%d",maxs);
}
