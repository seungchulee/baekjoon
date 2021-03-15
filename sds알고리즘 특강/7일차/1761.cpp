#include <stdio.h>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;
vector< vector<pair<int, int> > > vv;
int N;
int arr[21][50000];
long int dist[50000];
int depth[50000];
int visit[50000];
void dfs(int here, int dd,long int dists)
{
	visit[here] = 1;
	depth[here] = dd;
	dist[here] = dists;
	
	for (int i = 0; i < vv[here].size(); i++)
	{
		if (visit[vv[here][i].first] == 0)
		{
			arr[0][vv[here][i].first] = here;
			dfs(vv[here][i].first, dd + 1, dist[here]+vv[here][i].second);
		}
	}
}
void init()
{
	for (int i = 1; i <= 19; i++)
	{
		for (int j = 1; j <= N; j++)
		{
			arr[i][j] = arr[i - 1][arr[i - 1][j]];
		}
	}
}
int find_lca(int a, int b)
{
	if (depth[a] > depth[b])
		swap(a, b);

	for (int i = 19; i >= 0; i--)
	{
		if (depth[b] - depth[a] >= (1 << i))
		{
			b = arr[i][b];
		}
	}
	if (a == b)
	{
		return a;
	}
	for (int i = 19; i >= 0; i--)
	{
		if (arr[i][b] != arr[i][a])
		{
			a = arr[i][a];
			b = arr[i][b];
		}
	}
	
	return arr[0][a];
}
int main(void)
{
	int N;
	scanf("%d", &N);
	memset(visit, 0, sizeof(visit));
	memset(depth, 0, sizeof(depth));
	memset(dist, 0, sizeof(dist));
	vv.resize(N + 1);
	for (int i = 0; i < N-1; i++)
	{
		long int a, b, c;
		scanf("%d %d %d", &a, &b, &c);
		vv[a].push_back(make_pair(b, c));
		vv[b].push_back(make_pair(a, c));
	}
	dfs(1,0,0);
	init();
	int M;
	scanf("%d", &M);
	for (int i = 0; i < M; i++)
	{
		int a, b;
		scanf("%d %d", &a, &b);
		int tt = find_lca(a, b);
		//printf("%ld ", dist[a]);
		printf("%ld\n", dist[a] + dist[b] - 2 * dist[tt]);
	}
}