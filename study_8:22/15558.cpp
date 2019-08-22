#include <stdio.h>
#include <queue>
#include <utility>
using namespace std;
int arr[2][100000];
int visit[2][100000];
int dist[2][100000];
int N,k;
bool BFS()
{
	queue<pair<int, int> > qq;
	qq.push(make_pair(0,0));
	
	visit[0][0]=1;
	dist[0][0]=0;
	int cnt=0;
	while(!qq.empty())
	{
		pair<int, int> ss;
		ss=qq.front();
		qq.pop();
		int x=ss.first;
		int y=ss.second;
		
		if(arr[x][y+1]==1 && y+1<=N)
		{
			if(y+1<dist[x][y]+1)
				continue;
			if(y+1==N)
			{
				return true;
			}
			qq.push(make_pair(x,y+1));
			dist[x][y+1]=dist[x][y]+1;

		}
		if(arr[x][y-1]==1 && y-1>=0)
		{
			if(y-1<dist[x][y]+1)
				continue;		
			qq.push(make_pair(x,y-1));	
			dist[x][y-1]=dist[x][y]+1;
		}
		if(arr[(x+1)%2][y+k]==1)
		{
			if(y+k<dist[x][y]+1)
				continue;
			if(y+k>=N)
				return true;
			qq.push(make_pair((x+1)%2,y+k));
			dist[(x+1)%2][y+k]=dist[x][y]+1;
		}
			

	}	

	return false;
}
int main(void)
{
	scanf("%d %d",&N,&k);

	memset(dist,0,sizeof(dist));
	for(int i=0;i<N;i++)
	{
		scanf("%1d",&arr[0][i]);
	}
	for(int i=0;i<N;i++)
	{
		scanf("%1d",&arr[1][i]);
	}
	bool result=BFS();
	printf("%u",result);

}
