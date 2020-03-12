#include <stdio.h>
#include <queue>
#include <algorithm>
#include <vector>
#include <iostream>
#include <cstring>
using namespace std;
int indegree[1010];
int main(void)
{
	for(int a=1;a<=10;a++)
	{
		memset(indegree,0,sizeof(indegree));
		int v,e;
		cin >> v >> e;
		vector<vector<int> > vv;
		vv.resize(v+1);
		for(int i=0;i<e;i++)
		{
			int x,y;
			cin >> x >> y;
			vv[x].push_back(y);
			indegree[y]++;
		}
		queue<int> qq;
		for(int i=1;i<=v;i++)
			if(indegree[i]==0)
				qq.push(i);
		printf("#%d ",a);
		while(!qq.empty())
		{
			int from = qq.front();
			qq.pop();
			printf("%d ",from);
			for(int i=0;i<vv[from].size();i++)
			{
				indegree[vv[from][i]]--;
				if(indegree[vv[from][i]]==0)
					qq.push(vv[from][i]);
			}
		}
		printf("\n");
	}

}
