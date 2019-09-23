#include <stdio.h>
#include <queue>
#include <cstring>
#include <vector>
using namespace std;
int N,M;
int degree[32001];
vector<vector<int> > vv;
priority_queue<int> pq;
int main(void)
{
	
	memset(degree,0,sizeof(degree));

	scanf("%d %d",&N,&M);
	vv.resize(N+1);
	for(int i=0;i<M;i++)
	{
		int a,b;
		scanf("%d %d",&a,&b);
		vv[a].push_back(b);
		degree[b]++;
	}

	for(int i=1;i<=N;i++)
	{
		if(degree[i]==0)
			pq.push(-i);
	}

	while(!pq.empty())
	{
		int out=-(pq.top());
		pq.pop();
		printf("%d ",out);

		for(int i=0;i<vv[out].size();i++)
		{
			int tmp=vv[out][i];
			degree[tmp]--;
			if(degree[tmp]==0)
				pq.push(-tmp);
		}

	}
}
