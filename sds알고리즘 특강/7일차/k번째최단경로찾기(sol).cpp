#include <stdio.h>
#include <queue>
#include <vector>
#include <functional>
using namespace std;
int dist[1001];
int dist2[1001];
priority_queue<pair<int, int>, vector<pair<int, int >>, greater<pair<int, int> > > pq;
priority_queue<int> to_dist[1001];
vector<vector<pair<int, int> > > vv;

int main(void)
{
	int n, m, k;
	for (int i = 1; i <= 1000; i++)
	{
		dist[i] = 10000000;
		dist2[i] = 10000000;
	}

	scanf("%d %d %d", &n, &m, &k);
	vv.resize(n + 1);
	for (int i = 0; i < m; i++)
	{
		int a, b, c;
		scanf("%d %d %d", &a, &b, &c);
		vv[a].push_back(make_pair(b, c));
	}
	pq.push(make_pair(0, 1));
	to_dist[1].push(0);
	dist[1] = 0;
	dist2[1] = 0;
	while (!pq.empty())
	{
		pair<int, int> pp = pq.top();
		pq.pop();
		int w = pp.first;
		int v = pp.second;
		for (int i = 0; i < vv[v].size(); i++)
		{
			int u = vv[v][i].first;
			int ww = vv[v][i].second;
			//printf("!%d : %d!\n", u, w + ww);
			if (to_dist[u].size() < k)
			{
				to_dist[u].push(w + ww);
				pq.push(make_pair(w+ww, u));
			}
			else if(to_dist[u].top()>ww+w)
			{
				to_dist[u].pop();
				to_dist[u].push(w + ww);
				pq.push(make_pair(w+ww, u));
			}
		}
	}

	for (int i = 1; i <= n; i++) {
		if (to_dist[i].size() < k)
			printf("-1\n");
		else
			printf("%d\n", to_dist[i].top());

	}

}