#include <stdio.h>
#include <algorithm>
#include <queue>
#include <vector>
#include <cstring>
using namespace std;
int arr[21][101010];
int dis[21][101010];
int depth[101010];
int visit[101010];
int n,q;
vector<vector<pair<int,int> > > vv;
void dfs(int here, int dd)
{
	visit[here]=1;
	depth[here]=dd;
	for(int i=0;i<vv[here].size();i++)
	{
		if(visit[vv[here][i].first]==-1)
		{
			arr[0][vv[here][i].first]=here;
			dis[0][vv[here][i].first]=vv[here][i].second;
			dfs(vv[here][i].first,dd+1);
		}
	}
}
void init()
{
	for(int i=1;i<=20;i++)
	{
		for(int j=1;j<=n;j++)
		{
			arr[i][j]=arr[i-1][arr[i-1][j]];
			dis[i][j]=dis[i-1][j]+dis[i-1][arr[i-1][j]];
		}
	}
}
int find_lca(int a, int b)
{
	if(depth[a]>depth[b])
		swap(a,b);
	int summ=0;
	for(int i=20;i>=0;i--)
	{
		if(depth[b]-depth[a]>= (1<<i))
		{

			summ+=dis[i][b];
			b=arr[i][b];
		}
	}
	if(a==b)
	{
		return summ;
	}

	for(int i=20;i>=0;i--)
	{
		if(arr[i][a]!=arr[i][b])
		{

			summ+=dis[i][a];
			summ+=dis[i][b];
			a=arr[i][a];
			b=arr[i][b];
		}
	}
	summ+=dis[0][a];
	summ+=dis[0][b];
	return summ;
}
int main(void)
{
	memset(visit,-1,sizeof(visit));
	memset(depth,0,sizeof(depth));
	scanf("%d %d",&n,&q);
	vv.resize(n+1);
	for(int i=0;i<n-1;i++)
	{
		int a,b,w;
		scanf("%d %d %d",&a,&b,&w);
		vv[a].push_back(make_pair(b,w));
		vv[b].push_back(make_pair(a,w));
	}
	dfs(1,0);
	init();
	for(int i=0;i<q;i++)
	{
		int a,b;
		scanf("%d %d",&a,&b);
		printf("%d\n",find_lca(a,b));
	}
}
