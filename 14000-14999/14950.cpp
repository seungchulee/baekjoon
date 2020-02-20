#include <stdio.h>
#include <vector>
#include <queue>
#include <functional>
using namespace std;
int arr[10101];
vector<vector<pair<int,int> > > vv;
priority_queue<pair<int,pair<int,int> >,vector<pair<int,pair<int,int> > >, greater<pair<int,pair<int,int> > > > pq;
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
	int n,m,t;
	for(int i=0;i<10101;i++)
		arr[i]=i;
	scanf("%d %d %d",&n,&m,&t);
	vv.resize(n+1);
	for(int i=0;i<m;i++)
	{
		int a,b,c;
		scanf("%d %d %d",&a,&b,&c);
		vv[a].push_back(make_pair(b,c));
		vv[b].push_back(make_pair(a,c));
	}
	
	for(int i=0;i<vv[1].size();i++)
	{

		pq.push(make_pair(vv[1][i].second,make_pair(1,vv[1][i].first)));
	}
	int res=0;
	while(!pq.empty())
	{
		pair<int,pair<int,int> > pp = pq.top();
		pq.pop();
		int w = pp.first;
		int x = pp.second.first;
		int y = pp.second.second;

		if(find(x)!=find(y))
		{
			for(int i=0;i<vv[y].size();i++)
			{
				pair<int,int> pp=vv[y][i];
				pq.push(make_pair(pp.second,make_pair(y,pp.first)));

			}
			Union(x,y);
			res+=w;

		}
	}
	res+=((n-1)*(n-2)/2)*t;
	printf("%d",res);
}
