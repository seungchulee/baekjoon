#include <stdio.h>
#include <queue>
#include <cstring>
using namespace std;
int arr[250][250];
int visit[250][250];
int dx[8]={1,-1,0,0,-1,-1,1,1};
int dy[8]={0,0,1,-1,-1,1,-1,1};
int main(void)
{
	int N,M;
	scanf("%d %d",&N,&M);
	memset(arr,0,sizeof(arr));
	memset(visit,0,sizeof(visit));
	for(int i=0;i<N;i++)
		for(int j=0;j<M;j++)
			scanf("%d",&arr[i][j]);

	int cnt=0;
	for(int i=0;i<N;i++)
	{
		for(int j=0;j<M;j++)
		{
			if(arr[i][j]==1 && visit[i][j]==0)
			{
				cnt++;

				queue<pair<int,int> > qq;
				qq.push(make_pair(i,j));
				visit[i][j]=1;
				while(!qq.empty())
				{
					int x = qq.front().first;
					int y = qq.front().second;
					qq.pop();
					for(int k=0;k<8;k++)
					{
						int ddx=x+dx[k];
						int ddy=y+dy[k];
						if(ddx<0 || ddy<0 || ddx>=N || ddy>=M)
							continue;
						if(arr[ddx][ddy]==1 && visit[ddx][ddy]==0)
						{
							visit[ddx][ddy]=1;
							qq.push(make_pair(ddx,ddy));
						}
					}
				}
			}
		}
	}
	printf("%d",cnt);
	
}	
