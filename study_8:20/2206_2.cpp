#include <stdio.h>
#include <string.h>
#include <queue>
#include <utility>
using namespace std;
int arr[1001][1001];
int dist[1001][1001][2];

int N,M;
int dx[4]={-1,1,0,0};
int dy[4]={0,0,-1,1};
int BFS()
{
	
	queue<pair<pair<int,int>, int> > qq;
	
	pair<pair<int,int> ,int> s = make_pair(make_pair(1,1),0);

	qq.push(s);

	dist[1][1][0]=1;
	while(!qq.empty())
	{
		pair<pair<int,int>,int> r = qq.front();

		int a=qq.front().first.first;
		int b=qq.front().first.second;
		int crash = qq.front().second;	
		if(a==N && b==M)
			return dist[a][b][crash];
		qq.pop();



		for(int i=0;i<4;i++)
		{
			int ddx=a+dx[i];
			int ddy=b+dy[i];

			if(ddx<1 || ddy<1 || ddx>N || ddy>M)
				continue;

			// 0이 있고 방문 안함 
			if(arr[ddx][ddy]==0 && dist[ddx][ddy][crash]==-1)
			{
				dist[ddx][ddy][crash]=dist[a][b][crash]+1;
				pair<pair<int,int>,int> r = make_pair(make_pair(ddx,ddy),crash);
				qq.push(r);
			}
			// 벽이 있어서 허물어야함(한번도 허문적 없음)
			if(arr[ddx][ddy]==1 && crash==0)
			{
				dist[ddx][ddy][crash+1]=dist[a][b][crash]+1;
				pair<pair<int,int>,int> r = make_pair(make_pair(ddx,ddy),crash+1);
				qq.push(r);
			}
		}
	}

	return -1;
}
int main(void)
{
	scanf("%d %d",&N,&M);
	for(int i=1;i<=N;i++)
	{
		for(int j=1;j<=M;j++)
		{
			scanf("%1d",&arr[i][j]);

		}
	}
	memset(dist,-1,sizeof(dist));

	printf("%d",BFS());
	

}
