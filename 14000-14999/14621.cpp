#include <stdio.h>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;
int arr[1010];
int	ss[1010];
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
int main(void)
{
	int n,m;
	cin >> n >> m;
	for(int i=1;i<=n;i++)
	{
		arr[i]=i;
		char ch;
		cin >> ch;
		if(ch=='M')
			ss[i]=0;
		else
			ss[i]=1;
	}
	priority_queue<pair<int,pair<int,int> >, vector<pair<int,pair<int,int> > >, greater<pair<int,pair<int,int> > > > pq;
	for(int i=0;i<m;i++)
	{
		int x,y,d;
		cin >> x >> y >> d;
		pq.push(make_pair(d,make_pair(x,y)));
	}
	int res=0;
	int cnt=0;
	while(!pq.empty())
	{
		int u = pq.top().second.first;
		int v = pq.top().second.second;
		int d = pq.top().first;
		pq.pop();
		if(ss[u]==ss[v])
			continue;
		if(find(u)!=find(v))
		{
			cnt++;
			Union(u,v);
			res+=d;
		}
	}
	if(cnt == n-1)
		cout << res;
	else
		cout << "-1";

}
