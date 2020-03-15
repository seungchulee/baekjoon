#include <stdio.h>
#include <queue>
#include <vector>
#include <iostream>
#include <cstring>
using namespace std;
int indegree[10100];
int times[10100];
int min_t[10100];
int main(void)
{
	int n;
	cin >> n;
	memset(indegree,0,sizeof(indegree));
	vector<vector<int> > vv;
	vv.resize(n+1);
	for(int i=1;i<=n;i++)
	{
		cin >> times[i];
		min_t[i]=times[i];
		int gaesu;
		cin >> gaesu;
		for(int j=0;j<gaesu;j++)
		{
			int x;
			cin >> x;
			vv[x].push_back(i);
			indegree[i]++;
		}
	}
	queue<int> qq;
	for(int i=1;i<=n;i++)
	{
		if(indegree[i]==0)
			qq.push(i);
	}

	while(!qq.empty())
	{
		int from = qq.front();
		qq.pop();
		for(int i=0;i<vv[from].size();i++)
		{
			int to = vv[from][i];
			indegree[to]--;

			if(times[to] < min_t[to]+times[from])
				times[to]=min_t[to]+times[from];
			if(indegree[to]==0)
				qq.push(to);
		}
	}
	int ans=0;
	for(int i=1;i<=n;i++)
	{
		if(ans<times[i])
			ans=times[i];
	}
	cout << ans;
}
