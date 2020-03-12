#include <stdio.h>
#include <iostream>
#include <vector>
#include <queue>
#include <cmath>
#include <algorithm>
using namespace std;
int arr[1010];
int find(int a)
{
	if(arr[a]==a)
		return a;
	else
		return arr[a]=find(arr[a]);
}
void Union(int a, int b)
{
	int aa = find(a);
	int bb = find(b);
	arr[aa]=bb;
}
long long int dis(long long int a, long long int b, long long int c, long long int d)
{
	long long int ac = abs(a-c)*abs(a-c);
	long long int bd = abs(b-d)*abs(b-d);
	return ac+bd;
}
int main(void)
{
	int t;
	cin >> t;
	for(int q=1;q<=t;q++)
	{
		int n;
		cin >> n;
		for(int i=0;i<1010;i++)
			arr[i]=i;
		vector<pair<long long int,long long int> > vv;
		long long int xx[1010];
		long long int yy[1010];
		for(int i=0;i<n;i++)
			scanf("%lld",&xx[i]);
		for(int i=0;i<n;i++)
			scanf("%lld",&yy[i]);
		for(int i=0;i<n;i++)
		{
			vv.push_back(make_pair(xx[i],yy[i]));
		}
		double e;
		cin >> e;
		priority_queue<pair<double,pair<int,int> > , vector<pair<double,pair<int,int> > >, greater<pair<double,pair<int,int> > > > pq;
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<n;j++)
			{
				if(i==j)
					continue;
				long long int ix=vv[i].first;
				long long int iy=vv[i].second;
				long long int jx=vv[j].first;
				long long int jy=vv[j].second;
				long long int res = dis(ix,iy,jx,jy);
				//printf("%lld ",res);
				double ress = res*e;
				pq.push(make_pair(ress,make_pair(i,j)));
			}
		}
		double ans=0;
		while(!pq.empty())
		{
			double re = pq.top().first;
			int x = pq.top().second.first;
			int y = pq.top().second.second;
			pq.pop();
			if(find(x)!=find(y))
			{
				ans+=re;
				Union(x,y);
			}
		}
		printf("#%d %.lf\n",q,ans);
	}
}

