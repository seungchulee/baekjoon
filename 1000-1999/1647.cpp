#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;
int arr[101010];
int find(int a)
{
	if(arr[a]==a)
		return a;
	else
		return arr[a]=find(arr[a]);
}
void Union(int a,int b)
{
	int aa = find(a);
	int bb = find(b);
	arr[aa]=bb;
}
int main(void)
{
	int n,m;
	scanf("%d %d",&n,&m);
	vector<pair<long int,pair<int,int> > > vv;
	for(int i=0;i<=101000;i++)
		arr[i]=i;
	for(int i=0;i<m;i++)
	{
		int a,b;
		long int c;
		scanf("%d %d %ld",&a,&b,&c);
		vv.push_back(make_pair(c,make_pair(a,b)));
	}
	sort(vv.begin(),vv.end());
	long int res=0;
	long int maxs=-1;
	for(int i=0;i<vv.size();i++)
	{
		long int cost = vv[i].first;
		int a = vv[i].second.first;
		int b = vv[i].second.second;
		if(find(a)!=find(b))
		{
			maxs=max(maxs,cost);
			Union(a,b);
			res+=cost;
		}
	}
	res-=maxs;
	printf("%ld",res);
}
