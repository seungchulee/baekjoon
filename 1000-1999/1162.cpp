#include <stdio.h>
#include <cstring>
#include <queue>
#include <algorithm>
#include <vector>
#include <limits.h>
#include <functional>
using namespace std;
typedef long long ll;
ll  dist[10011][22];
int N,M,K;
ll MAXX = 99999900000;
//priority_queue<pair<ll,pair<ll,ll> > > pq;
priority_queue<pair<ll ,pair<ll ,ll > >, vector<pair<ll ,pair<ll ,ll > > >, greater<pair<ll ,pair<ll , ll> > > > pq;
vector<vector<pair<ll , ll > > > vv;
int main(void)
{
	scanf("%d %d %d",&N,&M,&K);
	vv.resize(N+1);
	for(int i=0;i<M;i++)
	{
		ll a,b,c;
		scanf("%lld %lld %lld",&a,&b,&c);
		vv[a].push_back(make_pair(b,c));
		vv[b].push_back(make_pair(a,c));
	}
	for(int i=0;i<10011;i++)
		for(int j=0;j<=21;j++)
			dist[i][j]=MAXX;
	pq.push(make_pair(0,make_pair(1,0)));
	dist[1][0]=0;
	while(!pq.empty())
	{
		pair<ll,pair<ll ,ll > > pp = pq.top();
		pq.pop();
		ll ww = pp.first;
		ll u = pp.second.first;
		ll cnt = pp.second.second;
		if(ww > dist[u][cnt])
			continue;
		for(int i=0;i<vv[u].size();i++)
		{
			ll nxt = vv[u][i].first;
			ll nstCost = ww + vv[u][i].second;
			if(nstCost < dist[nxt][cnt])
			{
				dist[nxt][cnt]=nstCost;
				pq.push(make_pair(nstCost,make_pair(nxt,cnt)));
			}
			if(cnt < K && ww < dist[nxt][cnt+1])
			{
				dist[nxt][cnt+1]=ww;
				pq.push(make_pair(ww,make_pair(nxt,cnt+1)));
			}
		}
	}
	ll mins = MAXX;
	for(int i=0;i<=K;i++)
	{
		mins = min(mins,dist[N][i]);
	}
	printf("%lld",mins);
}

