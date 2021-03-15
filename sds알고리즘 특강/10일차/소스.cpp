#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;
int arr[20][101010];
int len[20][101010];
int depth[101010];
int visit[101010];
int N;
vector < vector<pair<int, int> > > vv;
vector<pair<int, int> > edges;
void dfs(int here, int dd)
{
	visit[here] = 1;
	depth[here] = dd;
	for (int i = 0; i < vv[here].size(); i++)
	{
		if (visit[vv[here][i].first] == 0)
		{
			arr[0][vv[here][i].first] = here;
			len[0][vv[here][i].first] = vv[here][i].second;
			dfs(vv[here][i].first, dd + 1);
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
			len[i][j] = max(len[i - 1][j], len[i - 1][arr[i - 1][j]]);
		}
	}
}
int find(int a, int b)
{
	if (depth[a] > depth[b])
		swap(a, b);
	int maxs = -1;
	for (int i = 19; i >= 0; i--)
	{
		if (depth[b] - depth[a] >= (1 << i))
		{
			maxs = max(maxs, len[i][b]);
			b = arr[i][b];
		}
	}
	if (a == b)
	{
		return maxs;
	}

	int max2 = -1;
	for (int i = 19; i >= 0; i--)
	{
		if (arr[i][a] != arr[i][b])
		{
			max2 = max(max2, len[i][a]);
			max2 = max(max2, len[i][b]);
			a = arr[i][a];
			b = arr[i][b];
		}
	}
	max2 = max(max2, len[0][a]);
	max2 = max(max2, len[0][b]);
	return max2;
}
void change(int a, int b, int c)
{
	//printf("a : %d , b : %d , depth[a] : %d , depth[b] : %d\n", a, b, depth[a], depth[b]);
	if (depth[a] < depth[b])
	{
		len[0][b] = c;
	}
	else
	{
		len[0][a] = c;
	}
	if (depth[a] > depth[b])
		swap(a, b);

	for (int i = 1; i <= 19; i++)
	{
		len[i][b] = max(len[i - 1][b], len[i - 1][arr[i - 1][b]]);
		b = arr[i][b];
	}
}
int main(void)
{
	scanf("%d", &N);
	vv.resize(N + 1);
	for (int i = 0; i < N-1; i++)
	{
		int a, b, c;
		scanf("%d %d %d", &a, &b, &c);
		edges.push_back(make_pair(a, b));
		vv[a].push_back(make_pair(b, c));
		vv[b].push_back(make_pair(a, c));
	}
	dfs(1, 0);
	init();
	int M;
	scanf("%d", &M);
	for (int i = 0; i < M; i++)
	{
		int a, b, c;
		scanf("%d %d %d", &a, &b, &c);
		if (a == 1)
		{
			int from = edges[b - 1].first;
			int to = edges[b - 1].second;
			change(from, to, c);
		}
		else
		{
			printf("%d", find(b, c));
		}
	}
}