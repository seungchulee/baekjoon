#include <stdio.h>
#include <vector>
#include <cstring>
using namespace std;
vector<vector<int> > vv;
int visit[100001];
int depth[100001];
int arr[22][100001];
int N;
void dfs(int here, int dd)
{
	visit[here] = 1;
	depth[here] = dd;
	for (int i = 0; i < vv[here].size(); i++)
	{
		if (visit[vv[here][i]] == 0)
		{
			arr[0][vv[here][i]] = here;
			dfs(vv[here][i], dd + 1);
		}
	}
}
void init()
{
	for (int i = 1; i <= 20; i++)
	{
		for (int j = 1; j <= N; j++)
		{
			arr[i][j] = arr[i - 1][arr[i - 1][j]];
		}
	}		
}
int lca(int a, int b)
{
	if (depth[a] > depth[b])
		swap(a, b);
	for (int i = 20; i >= 0; i--)
	{
		if (depth[b] - depth[a] >= 1 << i)
		{
			b = arr[i][b];
		}
	}
	if (a == b)
		return a;
	for (int i = 20; i >= 0; i--)
	{
		if (arr[i][a] != arr[i][b])
		{
			a = arr[i][a];
			b = arr[i][b];
		}
	}
	return arr[0][a];
}
int main(void)
{
	scanf("%d", &N);
	memset(visit, 0, sizeof(visit));
	memset(depth, 0, sizeof(depth));
	vv.resize(N + 1);
	for (int i = 0; i < N-1; i++)
	{
		int a, b;
		scanf("%d %d", &a, &b);
		vv[a].push_back(b);
		vv[b].push_back(a);
	}
	dfs(1, 0);
	init();
	int M;
 
	scanf("%d", &M);
	for (int i = 0; i < M; i++)
	{
		int a, b;
		scanf("%d %d", &a, &b);
		printf("%d\n", lca(a, b));
	}
}