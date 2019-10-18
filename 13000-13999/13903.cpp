#include <stdio.h>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;
int N,M;
int arr[1001][1001];
int visit[1001][1001];
int T;
vector<pair<int,int> > vv;
queue<pair<int,int> > qq;
int mins=10000000;
void bfs()
{
	int len=vv.size();
	while(!qq.empty())
	{
		pair<int,int> ss=qq.front();
		qq.pop();
		int i=ss.first;
		int j=ss.second;

		for(int t=0;t<len;t++)
		{
			int ddx=i+vv[t].first;
			int ddy=j+vv[t].second;

			if(ddx<0 || ddy<0 || ddx>=N || ddy>=M)
				continue;
			if(arr[ddx][ddy]==1 && visit[ddx][ddy]==-1)
			{
				visit[ddx][ddy]=visit[i][j]+1;
				qq.push(make_pair(ddx,ddy));
			}
		}	
	}		
	for(int i=0;i<M;i++)
	{
		int res=visit[N-1][i];
		if(res==-1)
			continue;
		else
			mins=min(res,mins);
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
		}
	}
	scanf("%d",&T);	
	//vv.resize(T);
	for(int i=0;i<T;i++)
	{
		int a,b;
		scanf("%d %d",&a,&b);
		vv.push_back(make_pair(a,b));
	}
	memset(visit,-1,sizeof(visit));
	for(int i=0;i<M;i++)
	{
		if(arr[0][i]==1)
		{
			qq.push(make_pair(0,i));
			visit[0][i]=0;
		}
	}
	bfs();

/*	for(int i=0;i<N;i++)
	{
		for(int j=0;j<M;j++)
		{
			printf("%d ",visit[i][j]);
		}
		printf("\n");
	}*/
	if(mins==10000000)
		printf("-1");
	else
		printf("%d",mins);
}

