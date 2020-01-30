#include <stdio.h>
#include <cstring>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;
int arr[202020];
int find(int a)
{
	if(a==arr[a])
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
	while(1)
	{
		int a,b;
		scanf("%d %d",&a,&b);
		if(a==0 && b==0)
			break;
		int ww = 0;
		for(int i=0;i<a;i++)
			arr[i]=i;
		vector<pair<int,pair<int,int> > > vv;
		for(int i=0;i<b;i++)
		{
			int x,y,z;
			scanf("%d %d %d",&x,&y,&z);
			ww+=z;
			vv.push_back(make_pair(z,make_pair(x,y)));
		}
		sort(vv.begin(),vv.end());
		int data = 0;
		for(int i=0;i<vv.size();i++)
		{
			pair<int,pair<int,int> > pp;
			pp = vv[i];
			int weight = pp.first;
			int from = pp.second.first;
			int to = pp.second.second;
			if(find(from)!=find(to))
			{
				Union(from,to);
				data+=weight;
			}
		}
		printf("%d\n",ww - data);
	}

}
