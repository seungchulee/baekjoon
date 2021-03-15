#include <stdio.h>
#include <cstring>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;
int arr[11][11];
int visit[11][11];
int dx[4] = { 0,0,1,-1 };
int dy[4] = { 1,-1,0,0 };
int cnt = 0;
int N, M;
vector<pair<int,pair<int, int> > > vv;
int island[7];
int find(int a)
{
	if (island[a] == a)
		return a;
	else
		return island[a] = find(island[a]);
}
void Union(int a, int b)
{
	int aa = find(a);
	int bb = find(b);
	island[aa] = bb;
}
void dfs(int x, int y)
{
	visit[x][y] = 1;
	arr[x][y] = cnt;
	for (int k = 0; k < 4; k++)
	{
		int ddx = x + dx[k];
		int ddy = y + dy[k];
		if (ddx < 0 || ddy < 0 || ddx >= N || ddy >= M)
			continue;
		if (arr[ddx][ddy] == -1)
			dfs(ddx, ddy);
	}
}
void path(int x, int y)
{
	for (int i = 0; i <4; i++)
	{
		int res = 0;
		for (int j = 1; j <= 10; j++)
		{
			int ddx = x + dx[i] * j;
			int ddy = y + dy[i] * j;
			if (ddx < 0 || ddy < 0 || ddx >= N || ddy >= M)
				break;
			if (arr[ddx][ddy] == arr[x][y])
				break;
			if (arr[ddx][ddy] != arr[x][y] && arr[ddx][ddy]!=0)
			{
				if(res>=2)
					vv.push_back(make_pair(res, make_pair(arr[x][y], arr[ddx][ddy])));
				break;
			}
			if (arr[ddx][ddy] == 0)
			{
				res++;
				continue;
			}
		}
	}
}
int main(void)
{

	memset(visit, -1, sizeof(visit));
	scanf("%d %d", &N, &M);
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			scanf("%d", &arr[i][j]);
			if (arr[i][j] == 1)
				arr[i][j] = -1;
		}
	}
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			if (arr[i][j] != 0 && visit[i][j] == -1)
			{
				cnt++;
				dfs(i, j);
			}
		}
	}
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			if (arr[i][j] != 0)
				path(i, j);
		}
	}

	for (int i = 1; i <= cnt; i++)
		island[i] = i;

	int ans = 0;
	sort(vv.begin(), vv.end());
	for (int i = 0; i < vv.size(); i++)
	{
		int cost = vv[i].first;
		int from = vv[i].second.first;
		int to = vv[i].second.second;
		if (find(from) != find(to))
		{
			ans += cost;
			Union(from, to);
		}
	}
	set<int> ss;
	for (int i = 1; i <= cnt; i++)
		ss.insert(find(i));

	if (ss.size() != 1)
	{
		printf("-1");
		return 0;
	}
	printf("%d", ans);

}