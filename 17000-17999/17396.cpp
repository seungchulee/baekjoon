#include <stdio.h>
#include <cstring>
#include <vector>
#include <queue>
#include <functional>
using namespace std;
int N,M;
long long int dist[101010];
int seeya[101010];
vector<vector<pair<long long int,int> > > vv;
priority_queue<pair<long long int,int> ,vector<pair<long long int,int> > , greater<pair<long long int,int> > > pq;
int main(void)
{
	scanf("%d %d",&N,&M);
	for(int i=0;i<N;i++)
		scanf("%d",&seeya[i]);
	vv.resize(N+1);
	for(int i=0;i<M;i++)
	{
		int a,b;
		long long int w;
		scanf("%d %d %lld",&a,&b,&w);
		vv[a].push_back(make_pair(w,b));
		vv[b].push_back(make_pair(w,a));
	}
	for(int i=0;i<=N;i++)
		dist[i]=10000000001;
	dist[0]=0;
	pq.push(make_pair(0,0));
	while(!pq.empty())
	{
		long long int w = pq.top().first;
		int from = pq.top().second;
		pq.pop();
		if(w > dist[from])
			continue;
		for(int i=0;i<vv[from].size();i++)
		{
			if(dist[vv[from][i].second] > dist[from]+vv[from][i].first)
			{
				if(seeya[vv[from][i].second]==1 && vv[from][i].second!=N-1)
					continue;
				dist[vv[from][i].second]=dist[from]+vv[from][i].first;
				pq.push(make_pair(dist[vv[from][i].second],vv[from][i].second));
			}
		}
	}
	if(dist[N-1]==10000000001)
		printf("-1");
	else
		printf("%lld",dist[N-1]);

}
