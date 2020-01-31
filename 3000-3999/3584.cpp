#include <stdio.h>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;
int arr[15][10101];
int depth[10101];
int visit[10101];
int indegree[10101];
int T;
int N;
vector<vector<int> > vv;
void dfs(int here, int dd)
{
	visit[here]=1;
	depth[here]=dd;
	for(int i=0;i<vv[here].size();i++)
	{
		if(visit[vv[here][i]]==0)
		{
			arr[0][vv[here][i]]=here;
			dfs(vv[here][i],dd+1);
		}
	}
}
void init()
{
	for(int i=1;i<=14;i++)
	{
		for(int j=1;j<=N;j++)
		{
			arr[i][j]=arr[i-1][arr[i-1][j]];
		}
	}
}
int find_lca(int a, int b)
{
	if(depth[a]>depth[b])
		swap(a,b);
	for(int i=14;i>=0;i--)
	{
		if(depth[b]-depth[a] >= 1<<i)
		{
			b=arr[i][b];
		}
	}	
	if(a==b)
		return a;

	for(int i=14;i>=0;i--)
	{
		if(arr[i][a]!=arr[i][b])
		{
			a=arr[i][a];
			b=arr[i][b];
		}
	}
	return arr[0][a];
}
int main(void)
{
	scanf("%d",&T);

	for(int i=0;i<T;i++)
	{
		scanf("%d",&N);
		vv.clear();
		memset(depth,0,sizeof(depth));
		memset(visit,0,sizeof(visit));
		memset(indegree,0,sizeof(indegree));
		vv.resize(N+1);
		for(int j=0;j<N-1;j++)
		{
			int a,b;
			scanf("%d %d",&a,&b);
			vv[a].push_back(b);
			vv[b].push_back(a);
			indegree[b]++;
		}
		int root;
		for(int j=1;j<=N;j++)
		{
			if(indegree[j]==0)
				root=j;
		}
		dfs(root,0);
		init();
		int x,y;
		scanf("%d %d",&x,&y);
		printf("%d\n",find_lca(x,y));
	}
}
