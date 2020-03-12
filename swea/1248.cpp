#include <stdio.h>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <queue>
#include <vector>
using namespace std;
int arr[15][10101];
int dis[15][10101];
int visit[10101];
int depth[10101];
int v,e,x,y;
vector<vector<int> > vv;
void dfs(int here,int dd)
{
	depth[here]=dd;
	visit[here]=1;
	for(int i=0;i<vv[here].size();i++)
	{
		if(visit[vv[here][i]]==-1)
		{
			arr[0][vv[here][i]]=here;
			dis[0][vv[here][i]]=1;
			dfs(vv[here][i],dd+1);
		}
	}
}
void init()
{
	for(int i=1;i<15;i++)
	{
		for(int j=1;j<=v;j++)
		{
			arr[i][j]=arr[i-1][arr[i-1][j]];
			dis[i][j]=dis[i-1][j]+dis[i-1][arr[i-1][j]];
		}
	}
}
int find_lca(int a, int b)
{
	if(depth[a]>depth[b])
		swap(a,b);

	for(int i=14;i>=0;i--)
	{
		if(depth[b]-depth[a] >= 1<<i)
		{

			b=arr[i][b];
		}
	}

	if(a==b)
	{

		return a;
	}

	for(int i=14;i>=0;i--)
	{
		if(arr[i][a]!=arr[i][b])
		{
			a=arr[i][a];
			b=arr[i][b];
		}
	}
	return arr[0][a];
}
int main(void)
{
	int t;
	cin >> t;
	for(int tt=1;tt<=t;tt++)
	{
		memset(visit,-1,sizeof(visit));
		memset(dis,-1,sizeof(dis));
		cin >> v >> e >> x >> y;
		vv.clear();
		vv.resize(v+1);
		for(int i=0;i<e;i++)
		{
			int a,b;
			cin >> a >> b;
			vv[a].push_back(b);
		}
		dfs(1,0);
		init();
		int r1 = find_lca(x,y);
		queue<int> qq;
		qq.push(r1);
		memset(visit,-1,sizeof(visit));
		int r2=0;
		visit[r1]=1;
		while(!qq.empty())
		{
			int cur = qq.front();
			qq.pop();
			r2++;
			for(int i=0;i<vv[cur].size();i++)
			{
				if(visit[vv[cur][i]]==-1)
				{
					visit[vv[cur][i]]=1;
					qq.push(vv[cur][i]);
				}
			}
		}
		printf("#%d %d %d\n",tt,r1,r2);
	}
}
