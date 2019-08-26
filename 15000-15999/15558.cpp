#include <stdio.h>
#include <queue>
#include <utility>
using namespace std;
int N,K;
int arr[2][100000];
int dist[2][100000];

int main(void)
{
	scanf("%d %d",&N,&K);
	for(int i=0;i<2;i++)
	{
		for(int j=0;j<N;j++)
		{
			dist[i][j]=-1;
			scanf("%1d",&arr[i][j]);		
		}
	}
	int dx[3]={0,0,1};
	int dy[3]={1,-1,K};

	queue<pair<int,int> > qq;
	qq.push(make_pair(0,0));
	dist[0][0]=0;
	bool result=false;
	int cnt=0;
	while(!qq.empty())
	{
		pair<int,int> ss;
		ss=qq.front();
		qq.pop();
		int x=ss.first;
		int y=ss.second;
		for(int i=0;i<3;i++)
		{
			int ddx=(x+dx[i])%2;
			int ddy=y+dy[i];

			if(ddy>=N)
			{
				result=true;
				break;
			}
			if(ddy<0)
				continue;

			if(dist[ddx][ddy]!=-1)
				continue;
			if(arr[ddx][ddy]==0)
				continue;
			if(ddy<dist[x][y]+1)
				continue;
			dist[ddx][ddy]=dist[x][y]+1;
			qq.push(make_pair(ddx,ddy));
		}
		if(result==true)
			break;
	}


	printf("%u",result);

			
}
