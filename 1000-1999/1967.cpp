#include <stdio.h>
#include <queue>
#include <vector>
#include <cstring>
using namespace std;
int dis[10101];
vector<vector<pair<int,int> > > vv;
int main(void)
{
	int n;
	scanf("%d",&n);
	vv.resize(n+1);
	for(int i=0;i<n-1;i++)
	{
		int a,b,w;
		scanf("%d %d %d",&a,&b,&w);
		vv[a].push_back(make_pair(b,w));
		vv[b].push_back(make_pair(a,w));
	}
	memset(dis,-1,sizeof(dis));
	dis[1]=0;
	queue<int > qq;
	qq.push(1);
	int max_dis=-1;
	int max_pos=-1;
	while(!qq.empty())
	{
		int from = qq.front();
		qq.pop();
		for(int i=0;i<vv[from].size();i++)
		{
			if(dis[vv[from][i].first]==-1)
			{
				dis[vv[from][i].first] = dis[from]+vv[from][i].second;
				if(dis[vv[from][i].first]>max_dis)
				{
					max_dis=dis[vv[from][i].first];
					max_pos=vv[from][i].first;
				}
				qq.push(vv[from][i].first);
			}
		}
	}
	memset(dis,-1,sizeof(dis));
	dis[max_pos]=0;
	qq.push(max_pos);
	while(!qq.empty())
	{
		int from = qq.front();
		qq.pop();
		for(int i=0;i<vv[from].size();i++)
		{
			if(dis[vv[from][i].first]==-1)
			{
				dis[vv[from][i].first] = dis[from]+vv[from][i].second;
				if(dis[vv[from][i].first]>max_dis)
				{
					max_dis=dis[vv[from][i].first];
					max_pos=vv[from][i].first;
				}
				qq.push(vv[from][i].first);
			}
		}

	}
	printf("%d",max_dis);
}

