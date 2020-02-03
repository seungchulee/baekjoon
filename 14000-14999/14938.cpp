#include <stdio.h>
#include <cstring>
#include <queue>
#include <algorithm>
using namespace std;
int arr[101];
int visit[101];
int dist[101];
int main(void)
{
	int n,m,r;
	scanf("%d %d %d",&n,&m,&r);
	for(int i=0;i<=100;i++)
		dist[i]=10000000;
	for(int i=1;i<=n;i++)
		scanf("%d",&arr[i]);
	vector<vector<pair<int,int> > > vv;
	vv.resize(n+1);
	for(int i=0;i<r;i++)
	{
		int a,b,l;
		scanf("%d %d %d",&a,&b,&l);
		vv[a].push_back(make_pair(b,l));
		vv[b].push_back(make_pair(a,l));
	}
	int maxs=-1;
	for(int i=1;i<=n;i++)
	{
		for(int i=1;i<=n;i++)
			dist[i]=10000000;
		dist[i]=0;
		priority_queue<pair<int,int> > pq;
		pq.push(make_pair(0,i));
		while(!pq.empty())
		{
			int cost = pq.top().first;
			int now = pq.top().second;
			pq.pop();
			if(cost > dist[now])
				continue;
			for(int j=0;j<vv[now].size();j++)
			{
				int to = vv[now][j].first;
				int new_cost = vv[now][j].second;
				if(cost + new_cost < dist[to])
				{
					dist[to]=cost+new_cost;
					pq.push(make_pair(dist[to],to));
				}
			}
		}
		int res=0;
		for(int i=1;i<=n;i++)
		{
			if(dist[i]<=m)
			{
				res+=arr[i];
			}
		}
		maxs=max(maxs,res);
	}
	printf("%d",maxs);
}
