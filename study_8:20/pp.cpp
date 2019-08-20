#include <stdio.h>
#include <queue>
#include <algorithm>
#include <utility>
using namespace std;
int arr[51][51];
int tmp[51][51];
int dx[4]={-1,1,0,0};
int dy[4]={0,0,-1,1};
int N,M;
int min_val=100000;
bool ch=true;
void BFS()
{
	queue<pair<int,int> > qq;
	int check[51][51];
	int visit[51][51];
	for(int i=0;i<N;i++)
	{
		for(int j=0;j<N;j++)
		{
			visit[i][j]=0;
			check[i][j]=tmp[i][j];
			if(check[i][j]==-1)
			{
				pair<int,int> r = make_pair(i,j);
				//printf("%d %d\n",i,j);	
				qq.push(r);
			}
			if(check[i][j]==1)
				check[i][j]=-2;

			
		}


	}
	int dist[51][51];
	memset(dist,0,sizeof(dist));
	//memset(visit,0,sizeof(visit));
	while(!qq.empty())
	{
		pair<int,int> r = qq.front();
		int a = r.first;
		int b = r.second;
		qq.pop();

		visit[a][b]=1;
		
		int maxs=0;
		for(int i=0;i<N;i++)
		{
			for(int j=0;j<N;j++)
			{
				if(maxs<dist[i][j])
					maxs=dist[i][j];
			}
		}

		for(int i=0;i<4;i++)
		{
			int ddx=a+dx[i];
			int ddy=b+dy[i];

			if(ddx<0 || ddy<0 || ddx>=N || ddy>=N || check[ddx][ddy]==-2 || visit[ddx][ddy]==1)
				continue;

			if(check[ddx][ddy]==0 && visit[ddx][ddy]==0)
			{
				pair<int,int> s = make_pair(ddx,ddy);
				qq.push(s);
				dist[ddx][ddy]=dist[a][b]+1;
				//maxs=max(dist[ddx][ddy],maxs);

			}
			if(check[ddx][ddy]==2)
			{

				dist[ddx][ddy]=maxs; // check에서 가장 높은 수
				pair<int,int> s = make_pair(ddx,ddy);
				qq.push(s);
			}	

		}
	}
	int cnt=0;	
	for(int i=0;i<N;i++)
	{
		for(int j=0;j<N;j++)
		{
			printf("%d ",dist[i][j]);
			if(check[i][j]!=-2 && visit[i][j]==0)
			{

			}


			if(dist[i][j]>cnt)
				cnt=dist[i][j];
		}
		printf("\n");
	}
	

	if(cnt<min_val)
		min_val=cnt;

}
void func(int index)
{
	if(index==M)
	{
		BFS();
		//DO BFS
		return;
	}

	for(int i=0;i<N;i++)
	{
		for(int j=0;j<N;j++)
		{
			
			if(tmp[i][j]==2)
			{
				tmp[i][j]=-1;
				func(index+1);
				tmp[i][j]=2;
			}

		}
	}

}
int main(void)
{
	scanf("%d %d",&N,&M);

	for(int i=0;i<N;i++)
	{
		for(int j=0;j<N;j++)
		{
			scanf("%d",&arr[i][j]);
			tmp[i][j]=arr[i][j];
		}
	}

	func(0);

	printf("%d",min_val);

}
