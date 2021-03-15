#include <stdio.h>
#include <vector>
#include <queue>
#include <cstring>
#include <algorithm>
using namespace std;
int arr[20][40404];
int dis[20][40404];
int depth[40404]; 
int visit[40404];
int N;
vector<vector<pair<int,int> > > vv;
void dfs(int here, int dd)
{
	depth[here]=dd;
	visit[here]=1;

	for(int i=0;i<vv[here].size();i++)
	{
		if(visit[vv[here][i].first]==0)
		{
			arr[0][vv[here][i].first]=here;
			dis[0][vv[here][i].first]=vv[here][i].second;
			dfs(vv[here][i].first,dd+1);
		}
	}
}
void init()
{
	for(int i=1;i<=19;i++)
	{
		for(int j=1;j<=N;j++)
		{
			arr[i][j]=arr[i-1][arr[i-1][j]];
			dis[i][j]=dis[i-1][j]+dis[i-1][arr[i-1][j]];
		}
	}
}
int lca(int a, int b)
{
	if(depth[a]>depth[b])
		swap(a,b);
	int diss = 0;
	for(int i=19;i>=0;i--)
	{
		if(depth[b]-depth[a] >= (1<<i))
		{
			diss+=dis[i][b];
			b=arr[i][b];
		}
	}
	if(a==b)
		return diss;
	//printf("diss %d\n",diss);
	int dis2=0;
	for(int i=19;i>=0;i--)
	{
		if(arr[i][b]!=arr[i][a])
		{
			dis2+=dis[i][b];
			dis2+=dis[i][a];
			a=arr[i][a];
			b=arr[i][b];
		//	printf("!%d %d!\n",dis[i][b],dis[i][a]);
		}
	}
		
	dis2+=dis[0][a];
	dis2+=dis[0][b];
	return diss+dis2;
}
int main(void)
{
	memset(arr,0,sizeof(arr));
	memset(dis,0,sizeof(dis));
	memset(depth,0,sizeof(depth));
	memset(visit,0,sizeof(visit));
	scanf("%d",&N);
	vv.resize(N+1);
	for(int i=0;i<N-1;i++)
	{
		int a,b,c;
		scanf("%d %d %d",&a,&b,&c);
		vv[a].push_back(make_pair(b,c));
		vv[b].push_back(make_pair(a,c));
	}
	dfs(1,0);
	init();
	int M;
	scanf("%d",&M);
	for(int i=0;i<M;i++)
	{
		int a,b;
		scanf("%d %d",&a,&b);
		printf("%d\n",lca(a,b));
	}
}
