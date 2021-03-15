#include <stdio.h>
#include <queue>
#include <functional>
using namespace std;
priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int > > > pq;
vector<vector<pair<int, int> > > vv;
int dist[1001];
int main(void)
{
	int N, M;
	scanf("%d %d", &N, &M);
	vv.resize(N + 1);
	for (int i = 0; i < M; i++)
	{
		int a, b, c;
		scanf("%d %d %d", &a, &b, &c);
		vv[a].push_back(make_pair(b, c));
	}
	int s, t;
	scanf("%d %d", &s, &t);
	for (int i = 0; i <= N; i++)
		dist[i] = 100000000;
	pq.push(make_pair(0, s));
	dist[s] = 0;
	while (!pq.empty())
	{
		pair<int, int> pp = pq.top();
		pq.pop();
		int cost = pp.first;
		int from = pp.second;
		if (cost > dist[from])
			continue;
		for (int i = 0; i < vv[from].size(); i++)
		{
			int to = vv[from][i].first;
			int ww = vv[from][i].second;
			if (dist[to] >= dist[from] + ww)
			{
				dist[to] = dist[from] + ww;
				pq.push(make_pair(dist[to], to));
			}

		}
	}
	printf("%d", dist[t]);
}