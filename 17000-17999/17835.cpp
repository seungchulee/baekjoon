#include <stdio.h>
#include <queue>
#include <cstring>
#include <algorithm>
using namespace std;
long long int dist[101010];

vector<vector<pair<int,long long int> > > vv;
int main(void)
{

	for(int i=0;i<101010;i++)
		dist[i]=10000000000;
	int n,m,k;
	scanf("%d %d %d",&n,&m,&k);
	vv.resize(n+1);
	for(int i=0;i<m;i++)
	{
		int u,v;
		long long int c;
		scanf("%d %d %lld",&u,&v,&c);
		vv[v].push_back(make_pair(u,c));
	}
	for(int i=0;i<k;i++)
	{
		int x;
		scanf("%d",&x);
		vv[0].push_back(make_pair(x,0));
	}
	dist[0]=0;
	priority_queue < pair<long long, int>, vector < pair<long long,int> >, greater<pair<long long, int> > > pq;
	pq.push(make_pair(0,0));
	while(!pq.empty())
	{
		pair<int,int> pp = pq.top();
		pq.pop();
		int from = pp.second;
		long long int ww = pp.first;
		if(ww>dist[from])
			continue;
		for(int i=0;i<vv[from].size();i++)
		{
			if(dist[vv[from][i].first] > dist[from]+vv[from][i].second)
			{
				dist[vv[from][i].first]=dist[from]+vv[from][i].second;
				pq.push(make_pair(dist[vv[from][i].first],vv[from][i].first));
			}
		}

	}
	int max_i;
	long long int max_dis=-1;
	for(int i=n;i>=1;i--)
	{
		if(dist[i]>=max_dis)
		{
			max_dis=dist[i];
			max_i=i;
		}
	}	
	printf("%d\n%lld",max_i,max_dis);
}
