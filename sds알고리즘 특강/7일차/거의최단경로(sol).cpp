#include <stdio.h>
#include <queue>
#include <vector>
#include <algorithm>
#include <cstring>
#include <functional>
using namespace std;
int dist[501];
int visit[501];
int err[501][501];
int S, D;
int erases;
vector<vector<pair<int, int> > > vv;
vector<pair<int,int> > vvs;
void dfs(int idx, vector<int> pp,int sum)
{
	if (sum > erases)
		return;
	if (idx == D)
	{
		if (sum == erases)
		{
			pp.push_back(D);
			for (int i = 0; i < pp.size()-1; i++)
			{
				int start = pp[i];
				int end = pp[i + 1];
				for (int i = 0; i < vv[start].size(); i++) {
					if (vv[start][i].first == end)
					{
						err[start][vv[start][i].first] = 1;
					}
				}
			}
		}
		else
		{
			return;
		}
	}

	for (int i = 0; i < vv[idx].size(); i++)
	{
		int ii = vv[idx][i].first;
		int ww = vv[idx][i].second;
		if (visit[ii] == 0)
		{
			visit[idx] = 1;
			pp.push_back(idx);
			dfs(ii, pp, sum + ww);
			visit[idx] = 0;
			pp.pop_back();
		}
	}
	
	
}
int main(void)
{

	while (1)
	{
		priority_queue<pair<int, int>, vector<pair<int, int >>, greater<pair<int, int> > > pq;
		vv.clear();
		// vv : idx, 가중치
		// pq : 가중치, idx
		int N, M;
		scanf("%d %d", &N, &M);
		if (N == 0 && M == 0)
			break;
		memset(visit, 0, sizeof(visit));
		memset(err, 0, sizeof(err));
		scanf("%d %d", &S, &D);
		for (int i = 0; i < 501; i++)
			dist[i] = 10000000;
		vv.resize(N);
		for (int i = 0; i < M; i++)
		{
			int a, b, c;
			scanf("%d %d %d", &a, &b, &c);
			vv[a].push_back(make_pair(b, c));
		}
		pq.push(make_pair(0, S));
		dist[S] = 0;
		while (!pq.empty())
		{
			pair<int, int> pp = pq.top();
			pq.pop();
			int v = pp.second;
			int w = pp.first;
			if (w > dist[v])
				continue;
			for (int i = 0; i < vv[v].size(); i++)
			{
				int u = vv[v][i].first;
				int ww = vv[v][i].second;
				if (dist[u] > dist[v] + ww)
				{
					dist[u] = dist[v] + ww;
					pq.push(make_pair(dist[u], u));
				}
			}
		}
		erases = dist[D];
		int start = S;
		vector<int> ss;
		// ss : idx, 가중치 합
		dfs(S, ss,0);

		for (int i = 0; i < 501; i++)
			dist[i] = 10000000;
		priority_queue<pair<int, int>, vector<pair<int, int >>, greater<pair<int, int> > > pqq;

		pqq.push(make_pair(0, S));
		dist[S] = 0;
		while (!pqq.empty())
		{
			pair<int, int> pp = pqq.top();
			pqq.pop();
			int v = pp.second;
			int w = pp.first;
			if (w > dist[v])
				continue;
			for (int i = 0; i < vv[v].size(); i++)
			{
				int u = vv[v][i].first;
				int ww = vv[v][i].second;
				if (err[v][u] == 1)
				{
					continue;
				}
				if (dist[u] > dist[v] + ww)
				{
					dist[u] = dist[v] + ww;
					pqq.push(make_pair(dist[u], u));
				}
			}
		}
		if (dist[D] == 10000000)
			printf("-1\n");
		else
			printf("%d\n", dist[D]);
	}
}