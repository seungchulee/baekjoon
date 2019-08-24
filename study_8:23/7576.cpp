#include <stdio.h>
#include <queue>
#include <utility>
using namespace std;
int dx[4]={1,-1,0,0};
int dy[4]={0,0,1,-1};
int arr[1000][1000];
int dist[1000][1000];
int N,M;
int maxs=-2;
void BFS()
{
	queue<pair<int,int> > qq;

	for(int i=0;i<N;i++)
	{
		for(int j=0;j<M;j++)
		{
			if(arr[i][j]==1)
			{
				
				dist[i][j]=0;
				qq.push(make_pair(i,j));
			}

		}

	}
	
	while(!qq.empty())
	{
		pair<int,int> ss;
		ss=qq.front();
		qq.pop();

		int x=ss.first;
		int y=ss.second;
		
		for(int i=0;i<4;i++)
		{
			int ddx=x+dx[i];
			int ddy=y+dy[i];

			if(ddx<0 || ddy<0 || ddx>=N || ddy>=M)
				continue;

			if(arr[ddx][ddy]==0 && dist[ddx][ddy]==0)
			{
				dist[ddx][ddy]=dist[x][y]+1;
				arr[ddx][ddy]=1;
				if(dist[ddx][ddy]>maxs)
					maxs=max(dist[ddx][ddy],maxs);
				qq.push(make_pair(ddx,ddy));
			}
		}
	}

}
int main(void)
{
	scanf("%d %d",&M,&N);
	for(int i=0;i<N;i++)
	{
		for(int j=0;j<M;j++)
		{
			dist[i][j]=0;
			scanf("%d",&arr[i][j]);
		}
	}
	BFS();
	
	for(int i=0;i<N;i++)
	{
		for(int j=0;j<M;j++)
		{
			if(arr[i][j]==0)
			{
				maxs=-1;
				break;
			}
		}
	}

	if(maxs==-2)
		maxs=0;

	printf("%d",maxs);
}
