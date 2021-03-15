#include <stdio.h>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;
int visit[100001];
int depth[100001];
int arr[22][100001];
int wmin[22][100001];
int wmax[22][100001];
int N;
vector<vector<pair<int,int> > > vv;
void dfs(int here, int dd)
{
	visit[here] = 1;
	depth[here] = dd;
	for (int i = 0; i < vv[here].size(); i++)
	{
		if (visit[vv[here][i].first] == 0)
		{
			arr[0][vv[here][i].first] = here;
			wmin[0][vv[here][i].first] = vv[here][i].second;
			wmax[0][vv[here][i].first] = vv[here][i].second;
			dfs(vv[here][i].first, dd + 1);
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
			wmin[i][j] = min(wmin[i - 1][arr[i - 1][j]], wmin[i - 1][j]);
			wmax[i][j] = max(wmax[i - 1][arr[i - 1][j]], wmax[i - 1][j]);
		}
	}
}
void lca(int a, int b)
{
	if (depth[a] > depth[b])
		swap(a, b);
	int maxs = -1;
	int mins = 1000001;
	for (int i = 20; i >= 0; i--)
	{
		if (depth[b] - depth[a] >= (1 << i))
		{
			maxs = max(maxs, wmax[i][b]);
			mins = min(mins, wmin[i][b]);
			b = arr[i][b];
		}
	}
	if (a == b)
	{
		printf("%d %d\n", mins, maxs);
		return;
	}
	for (int i = 20; i >= 0; i--)
	{
		if (arr[i][a] != arr[i][b])
		{
			maxs = max(maxs, wmax[i][a]);
			maxs = max(maxs, wmax[i][b]);
			mins = min(mins, wmin[i][a]);
			mins = min(mins, wmin[i][b]);
			a = arr[i][a];
			b = arr[i][b];
		}
	}
	maxs = max(maxs, wmax[0][a]);
	maxs = max(maxs, wmax[0][b]);
	mins = min(mins, wmin[0][a]);
	mins = min(mins, wmin[0][b]);
	printf("%d %d\n", mins, maxs);
	return;

}
int main(void)
{

	scanf("%d", &N);
	vv.resize(N+1);
	memset(visit, 0, sizeof(visit));
	memset(arr, 0, sizeof(arr));
	memset(wmax, -1, sizeof(wmax));
	memset(wmin, -1, sizeof(wmin));
	for (int i = 0; i < N-1; i++)
	{
		int a, b, c;
		scanf("%d %d %d", &a, &b, &c);
		vv[a].push_back(make_pair(b, c));
		vv[b].push_back(make_pair(a, c));
	}
	dfs(1, 0);
	init();
	int K;
	scanf("%d", &K);
	for (int i = 0; i < K; i++)
	{
		int a, b;
		scanf("%d %d", &a, &b);
		lca(a, b);
	}
}