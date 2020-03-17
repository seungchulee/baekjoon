#include <stdio.h>
#include <queue>
#include <iostream>
#include <vector>
#include <cstring>
using namespace std;
int visit[505050];
int main(void)
{
	int n;
	double w;
	cout.precision(11);
	cin >> n >> w;
	vector<vector<int> > vv;
	vv.resize(n+1);
		
	for(int i=0;i<n-1;i++)
	{
		int u,v;
		cin >> u >> v;
		vv[u].push_back(v);
		vv[v].push_back(u);
	}
	memset(visit,-1,sizeof(visit));
	queue<int> qq;
	qq.push(1);
	visit[1]=1;
	int cnt=0;
	while(!qq.empty())
	{
		int x = qq.front();
		qq.pop();
		int check=false;
		for(int i=0;i<vv[x].size();i++)
		{
			if(visit[vv[x][i]]==-1)
			{
				check=true;
				visit[vv[x][i]]=1;
				qq.push(vv[x][i]);
			}
		}
		if(check==false)
			cnt++;
	}
	cout << w / cnt;
}
