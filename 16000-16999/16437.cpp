#include <stdio.h>
#include <queue>
#include <iostream>
#include <vector>
#include <cstring>
using namespace std;
int indegree[123480];
long long int sheep[123480];
int N;
int main(void)
{
	int N;
	scanf("%d",&N);
	memset(sheep,0,sizeof(sheep));
	memset(indegree,0,sizeof(indegree));
	vector<vector<int> > vv;
	vv.resize(N+1);

	for(int i=0;i<N-1;i++)
	{
		char ch;
		long long int a;
		int	b;
		cin >> ch >> a >> b;
		indegree[b]++;
		vv[i+2].push_back(b);
		if(ch=='S')
		{
			sheep[i+2]=a;
		}
		else
		{
			sheep[i+2]=-a;
		}
	}
	queue<int> qq;
	for(int i=2;i<=N;i++)
	{
		if(indegree[i]==0)
		{
			qq.push(i);
		}
	}
	while(!qq.empty())
	{	
		int to = qq.front();
		qq.pop();
		for(int i=0;i<vv[to].size();i++)
		{
			if(sheep[to]>=0)
				sheep[vv[to][i]]+=sheep[to];

			indegree[vv[to][i]]--;
			if(indegree[vv[to][i]]==0)
				qq.push(vv[to][i]);
		}
	}
	printf("%lld",sheep[1]);
}
