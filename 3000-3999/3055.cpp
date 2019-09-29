#include <stdio.h>
#include <queue>
#include <utility>
#include <cstring>
using namespace std;
char arr[51][51];
int water[51][51];
int bfs[51][51];
int N,M;
int start_i, start_j;
int end_i,end_j;
queue<pair<int,int> > water_queue;
int dx[4]={-1,1,0,0};
int dy[4]={0,0,-1,1};
void water_bfs()
{
	while(!water_queue.empty())
	{
		pair<int,int> qq=water_queue.front();
		water_queue.pop();
		int xx=qq.first;
		int yy=qq.second;

		for(int i=0;i<4;i++)
		{
			int ddx=xx+dx[i];
			int ddy=yy+dy[i];
			if(ddx<0 || ddy<0 || ddx>=N || ddy>=M)
				continue;
			if(water[ddx][ddy]==-1 && arr[ddx][ddy]=='.')
			{
				water[ddx][ddy]=water[xx][yy]+1;
				water_queue.push(make_pair(ddx,ddy));
			}
		}
	}
	
}
void bfss()
{
	bfs[start_i][start_j]=0;
	queue<pair<int,int> > qq;
	qq.push(make_pair(start_i,start_j));
	while(!qq.empty())
	{	
		pair<int,int> ss=qq.front();
		qq.pop();
		int xx=ss.first;
		int yy=ss.second;
		
		for(int i=0;i<4;i++)
		{
			int ddx=xx+dx[i];
			int ddy=yy+dy[i];

			if(ddx<0 || ddy<0 || ddx>=N || ddy>=M)
			{
				continue;
			}
			if(bfs[ddx][ddy]==-1 && (arr[ddx][ddy]=='.' || arr[ddx][ddy]=='D'))
			{
	/*			if(arr[ddx][ddy]=='D')
				{
					qq.push(make_pair(ddx,ddy));
					bfs[ddx][ddy]=bfs[xx][yy]+1;
					continue;
				}*/
				if(water[ddx][ddy]==-1)
				{
					qq.push(make_pair(ddx,ddy));
					bfs[ddx][ddy]=bfs[xx][yy]+1;
				}
				else
				{
					if(water[ddx][ddy]>bfs[xx][yy]+1)
					{
						qq.push(make_pair(ddx,ddy));
						bfs[ddx][ddy]=bfs[xx][yy]+1;
					}
				}
			}
		}	
	}
}
int main(void)
{
	memset(water,-1,sizeof(water));
	memset(bfs,-1,sizeof(bfs));
	scanf("%d %d",&N,&M);
	for(int i=0;i<N;i++)
	{
		char st[51];
		scanf("%s",st);
		for(int j=0;j<M;j++)
		{
			arr[i][j]=st[j];
			if(arr[i][j]=='D')
			{
				end_i=i;
				end_j=j;
			}
			if(arr[i][j]=='S')
			{
				start_i=i;
				start_j=j;
			}
			if(arr[i][j]=='*')
			{
				water_queue.push(make_pair(i,j));
				water[i][j]=0;
			}
		}

	}

	water_bfs();

	bfss();
/*	for(int i=0;i<N;i++)
	{
		for(int j=0;j<M;j++)
		{
			printf("%3d",bfs[i][j]);
		}
		printf("\n");
	}	*/
	if(bfs[end_i][end_j]==-1)
		printf("KAKTUS");
	else
		printf("%d\n",bfs[end_i][end_j]);	
}

