#include <stdio.h>
#include <queue>
#include <algorithm>
#include <iostream>
#include <cstring>
#include <vector>
using namespace std;
int n,m;
int indegree[1010];
int main(void)
{
	cin >> n >> m;
	memset(indegree,0,sizeof(indegree));
	vector<vector<int> > singer;
	singer.resize(n+1);
	for(int i=0;i<m;i++)
	{
		int x;
		cin >> x;
		vector<int> vv;
		for(int j=0;j<x;j++)
		{
			int v;
			cin >> v;
			vv.push_back(v);
		}
		for(int j=0;j<vv.size()-1;j++)
		{
			int f = vv[j];
			int t = vv[j+1];
			singer[f].push_back(t);
			indegree[t]++;
		}
	}
	queue<int> qq;
	for(int i=1;i<=n;i++)
		if(indegree[i]==0)
			qq.push(i);
	vector<int> res;
	while(!qq.empty())
	{
		int from = qq.front();
		qq.pop();
		res.push_back(from);
		for(int i=0;i<singer[from].size();i++)
		{
			int to = singer[from][i];
			indegree[to]--;
			if(indegree[to]==0)
				qq.push(to);
		}
	}
	if(res.size()==n)
	{
		for(int i=0;i<res.size();i++)
			printf("%d\n",res[i]);
	}	
	else
		printf("0");
		
}

