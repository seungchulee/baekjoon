#include <stdio.h>
#include <queue>
#include <utility>
#include <cstring>
int dx[4]={1,-1,0,0};
int dy[4]={0,0,1,-1};
using namespace std;
int N,M;
char arr[250][250];
int visit[250][250];
int wolf,sheep;
void BFS(int x, int y)
{

	sheep=0;
	wolf=0;

	queue<pair<int,int> > qq;
	qq.push(make_pair(x,y));
	while(!qq.empty())
	{
		pair<int,int> ss;
		ss=qq.front();
		qq.pop();
		int a=ss.first;
		int b=ss.second;
		if(arr[a][b]=='o')
		{
			sheep++;
		}
		if(arr[a][b]=='v')
			wolf++;
		visit[a][b]=1;
		for(int i=0;i<4;i++)
		{
			int ddx=a+dx[i];
			int ddy=b+dy[i];

			if(ddx<0 || ddy<0 || ddx>=N || ddy>=M)
				continue;
			if(arr[ddx][ddy]!='#' && visit[ddx][ddy]==0)
			{
				visit[ddx][ddy]=1;
				qq.push(make_pair(ddx,ddy));
			}
		}
		
	}
}
int main(void)
{
	memset(visit,0,sizeof(visit));
	scanf("%d %d",&N,&M);
	int all_wolf=0;
	int all_sheep=0;
	for(int i=0;i<N;i++)
	{
		char st[250];
		scanf("%s",st);
		for(int j=0;j<M;j++)
		{
			arr[i][j]=st[j];
			if(arr[i][j]=='o')
				all_sheep++;
			if(arr[i][j]=='v')
				all_wolf++;
		}
	}
	
	for(int i=0;i<N;i++)
	{
		for(int j=0;j<M;j++)
		{

			if((arr[i][j]=='o' || arr[i][j]=='v') && visit[i][j]==0)
			{

				BFS(i,j);

				if(wolf>=sheep)
				{
					all_sheep-=sheep;
				}
				else
				{
					all_wolf-=wolf;
				}
			}
		}
	}
	printf("%d %d",all_sheep, all_wolf);
}

