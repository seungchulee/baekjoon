#include <stdio.h>
#include <queue>
#include <functional>
#include <vector>
#include <cstring>
using namespace std;
priority_queue<pair<int,int> , vector<pair<int,int >>, greater<pair<int, int> > > pq;
vector<vector<pair<int, int> > > vv;
int dist[20001];
int main(void)
{
	for (int i = 1; i <= 20000; i++)
		dist[i] = 1000000;
	int V, E;
	scanf("%d %d", &V, &E);
	int R;
	scanf("%d", &R);
	vv.resize(V + 1);
	for (int i = 0; i < E; i++)
	{
		int u, v, w;
		scanf("%d %d %d", &u, &v, &w);
		vv[u].push_back(make_pair(v, w));
	}
	pq.push(make_pair(0,R));
	dist[R] = 0;
	// pq : (무게, idx)
	// vv : (idx, 무게)
	while (!pq.empty())
	{
		pair<int, int> pp = pq.top();
		pq.pop();
		int ww = pp.first;
		int vs = pp.second;
		if (ww > dist[vs])
			continue;
		//printf("%d\n", vs);
		for (int i = 0; i < vv[vs].size(); i++)
		{
			//printf("-%d %d-\n", vv[vs][i].first,vv[vs][i].second);
			if (dist[vv[vs][i].first] > dist[vs] + vv[vs][i].second)
			{
				dist[vv[vs][i].first] = dist[vs] + vv[vs][i].second;
				pq.push(make_pair(dist[vv[vs][i].first], vv[vs][i].first));
			}
		
		}
	}
	for (int i = 1; i <= V; i++)
	{
		if (dist[i] == 1000000)
			printf("INF\n");
		else
			printf("%d\n", dist[i]);
	}
}