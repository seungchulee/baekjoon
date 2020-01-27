#include <stdio.h>
#include <vector>
#include <algorithm>
#include <cstring>
#include <queue>
using namespace std;
int depth[30303];
int visit[30303];
int arr[19][30303];
vector<vector<int> > vv;
int N;
void dfs(int here, int dd)
{
	depth[here]=dd;
	visit[here]=1;
	for(int i=0;i<vv[here].size();i++)
	{
		if(visit[vv[here][i]] == -1)
		{
			arr[0][vv[here][i]]=here;
			dfs(vv[here][i],dd+1);
		}
	}
}
void init()
{
	for(int i=1;i<=18;i++)
	{
		for(int j=1;j<=N;j++)
		{
			arr[i][j] = arr[i-1][arr[i-1][j]];
		}		
	}
}
int find_lca(int a, int b)
{
	if(depth[a]>depth[b])
		swap(a,b);
	for(int i=18;i>=0;i--)
	{
		if(depth[b]-depth[a] >= 1 << i)
		{
			b=arr[i][b];
		}
	}
	if(a==b)
		return a;
	for(int i=18;i>=0;i--)
	{
		if(arr[i][a] != arr[i][b])
		{
			a = arr[i][a];
			b = arr[i][b];
		}
	}
	return arr[0][a];
}
int main(void)
{
	scanf("%d",&N);
	memset(visit,-1,sizeof(visit));
	memset(depth,0,sizeof(depth));
	vv.resize(N+1);
	for(int i=0;i<N-1;i++)
	{
		int a,b;
		scanf("%d %d",&a,&b);
		vv[a].push_back(b);
		vv[b].push_back(a);
	}

	dfs(1,0);
	init();

	int m;
	scanf("%d",&m);
	queue<int> qq;
	qq.push(1);
	int res = 0;
	for(int i=0;i<m;i++)
	{
		int a;
		scanf("%d",&a);
		int tt = qq.front();
		qq.pop();
		qq.push(a);
		int lca = find_lca(a,tt);
		res += depth[tt]+depth[a]-2*depth[lca];
		//printf("%d",depth[tt]+depth[a]-depth[lca]);
	}
	printf("%d",res);

}
