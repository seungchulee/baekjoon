#include <stdio.h>
#include <queue>
#include <cstring>
#include <vector>
using namespace std;
int dis[101010];
vector<vector<pair<int,int> > > vv;
int main(void)
{
	memset(dis,-1,sizeof(dis));
	int n;
	scanf("%d",&n);
	vv.resize(n+1);
	for(int i=1;i<=n;i++)
	{
		int a;
		scanf("%d",&a);
		while(1)
		{
			int b;
			scanf("%d",&b);
			if(b==-1)
				break;
			int w;
			scanf("%d",&w);
			vv[a].push_back(make_pair(b,w));
			vv[b].push_back(make_pair(a,w));
		}
	}
	dis[1]=0;
	queue<int> qq;
	qq.push(1);
	int max_dis = -1;
	int max_pos = -1;
	while(!qq.empty())
	{
		int from = qq.front();
		qq.pop();
		for(int i=0;i<vv[from].size();i++)
		{
			int to = vv[from][i].first;
			int ww = vv[from][i].second;
			if(dis[to]==-1)
			{
				dis[to]=dis[from]+ww;
				if(max_dis < dis[to])
				{
					max_dis = dis[to];
					max_pos = to;
				}
				qq.push(to);
			}
		}
	}
	memset(dis,-1,sizeof(dis));
	qq.push(max_pos);
	dis[max_pos]=0;
	max_dis=-1;
	while(!qq.empty())
	{
		int from = qq.front();
		qq.pop();
		for(int i=0;i<vv[from].size();i++)
		{
			int to = vv[from][i].first;
			int ww = vv[from][i].second;
			if(dis[to]==-1)
			{
				dis[to]=dis[from]+ww;
				if(max_dis < dis[to])
				{
					max_dis = dis[to];
					max_pos = to;
				}
				qq.push(to);
			}
		}

	}
	printf("%d",max_dis);
}
