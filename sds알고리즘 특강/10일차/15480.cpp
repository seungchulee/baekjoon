#include <stdio.h>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;
vector<vector<int> > vv;
int arr[20][101010];
int depth[101010];
int visit[101010];
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
	for (int i = 1; i <= 19; i++)
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
	for (int i = 19; i >= 0; i--)
	{
		if (depth[b] - depth[a] >= (1 << i))
		{
			b = arr[i][b];
		}
	}
	if (a == b)
		return a;

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
	memset(visit, 0, sizeof(visit));
	memset(depth, 0, sizeof(depth));
	memset(arr, 0, sizeof(arr));
	scanf("%d", &N);
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
		int r, u, v;
		scanf("%d %d %d", &r, &u, &v);

		if (r == 1)
			printf("%d\n", lca(u, v));
		else
		{
			int ru = lca(r, u);
			int uv = lca(u, v);
			int rv = lca(r, v);
			int dr = depth[ru];
			int du = depth[uv];
			int dv = depth[rv];
			if (ru == 1 && uv == 1 && rv == 1)
				printf("1\n");
			else
			{
				int maxs = -1;
				maxs = max(dr, max(du, dv));
				if (maxs == dr)
					printf("%d\n", ru);
				else if (maxs == du)
					printf("%d\n", uv);
				else if(maxs==dv)
					printf("%d\n", rv);
			}

		}
	}
}