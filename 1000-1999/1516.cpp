#include <stdio.h>
#include <queue>
#include <cstring>
using namespace std;
int N;
vector<vector<int> > vv;
int times[501];
int degree[501];
int addTime[501];
int main(void)
{
	scanf("%d",&N);
	vv.resize(N+1);
	memset(addTime,0,sizeof(addTime));
	memset(degree,0,sizeof(degree));
	memset(times,0,sizeof(times));

	for(int i=1;i<=N;i++)
	{
		scanf("%d",&times[i]);
		while(1)
		{
			int b;
			scanf("%d",&b);
			if(b==-1)
				break;
			vv[b].push_back(i);
			degree[i]++;
		}
	}
	priority_queue <int> pq;
	for(int i=1;i<N;i++)
	{
		if(degree[i]==0)
			pq.push(-i);
	}
	
	while(!pq.empty())
	{
		int out=-pq.top();

		pq.pop();
		for(int i=0;i<vv[out].size();i++)
		{
			int tmp=vv[out][i];
			degree[tmp]--;
			if(degree[tmp]==0)
				pq.push(-tmp);
			int prevConstructTime = times[out]+addTime[out];
			if(prevConstructTime > addTime[tmp])
				addTime[tmp]=prevConstructTime;
		}
	}
	for(int i=1;i<=N;i++)
	{
		//printf("==%d %d==\n",times[i],addTime[i]);
		printf("%d\n",times[i]+addTime[i]);
	}
}
