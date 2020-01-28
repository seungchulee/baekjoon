#include <stdio.h>
#include <queue>
#include <algorithm>
#include <vector>
#include <functional>
using namespace std;

int main(void)
{
	int T;
	scanf("%d",&T);
	for(int t=0;t<T;t++)
	{
		int n,m;
		scanf("%d %d",&n,&m);
		queue<pair<int,int> > qq;
		priority_queue<int> pq;
		for(int i=0;i<n;i++)
		{
			int x;
			scanf("%d",&x);
			qq.push(make_pair(x,i));
			pq.push(x);
		}
		int cnt=0;
		while(!qq.empty())
		{
			pair<int,int> pp = qq.front();
			int idx = pp.second;
			int val = pp.first;
			qq.pop();
			if(val == pq.top())
			{
				pq.pop();
				cnt++;
				if(idx==m)
					printf("%d\n",cnt);
			}
			else
			{
				qq.push(make_pair(val,idx));
			}
		}
	}
}
