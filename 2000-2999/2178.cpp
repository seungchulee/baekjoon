#include <stdio.h>
#include <queue>
#include <string.h>
using namespace std;
int N,M;
int arr[101][101];
int dist[101][101];

void BFS()
{
	queue<pair<int,int> > qq;
	qq.push(make_pair(0,0));
	dist[0][0]=1;

	while(!qq.empty())
	{
		pair<int, int> ss;
		ss=qq.front();
		qq.pop();
		int x=ss.first;
		int y=ss.second;

		if(arr[x+1][y]==1 && dist[x+1][y]==-1 && x+1<N)
		{
			dist[x+1][y]=dist[x][y]+1;
			qq.push(make_pair(x+1,y));
		}
		if(arr[x-1][y]==1 && dist[x-1][y]==-1 && x-1>=0)
		{
			dist[x-1][y]=dist[x][y]+1;
			qq.push(make_pair(x-1,y));
		}
		if(arr[x][y-1]==1 && dist[x][y-1]==-1 && y-1>=0)
		{
			dist[x][y-1]=dist[x][y]+1;
			qq.push(make_pair(x,y-1));
		}
		if(arr[x][y+1]==1 && dist[x][y+1]==-1 && y+1<M)
		{
			dist[x][y+1]=dist[x][y]+1;
			qq.push(make_pair(x,y+1));
		}

		
	}
}
int main(void)
{
	memset(arr,-1,sizeof(arr));
	memset(dist,-1,sizeof(dist));
	scanf("%d %d",&N,&M);
	for(int i=0;i<N;i++)
	{
		for(int j=0;j<M;j++)
		{
			
			scanf("%1d",&arr[i][j]);
		}
	}
	BFS();
	printf("%d",dist[N-1][M-1]);
}
