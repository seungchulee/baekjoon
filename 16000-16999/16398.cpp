#include <stdio.h>
#include <cstring>
#include <vector>
#include <queue>
using namespace std;
priority_queue<pair<int,pair<int,int> > , vector<pair<int,pair<int,int> > >, greater<pair<int,pair<int,int> > > > pq;
int arr[1010101];
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
	int n;
	for(int i=0;i<1010101;i++)
		arr[i]=i;
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			int x;
			scanf("%d",&x);
			if(i==j)
				continue;
			else
				pq.push(make_pair(x,make_pair(i,j)));

		}
	}
	long long int res=0;
	while(!pq.empty())
	{
		pair<int,pair<int,int> > pp=pq.top();
		pq.pop();
		int w = pp.first;
		int x = pp.second.first;
		int y = pp.second.second;
		if(find(x)!=find(y))
		{
			Union(x,y);
			res+=w;
		}


	}
	printf("%lld",res);	
}
