#include <stdio.h>
#include <cstring>
#include <queue>
#include <functional>
using namespace std;
priority_queue<int,vector<int>, greater<int> > pq;
int indegree[10101];
int main(void)
{
	int N,M;
	scanf("%d %d",&N,&M);
	memset(indegree,0,sizeof(indegree));
	for(int i=0;i<M;i++)
	{
		int a,b;
		scanf("%d %d",&a,&b);
		indegree[a]++;
	}
	for(int i=1;i<=N;i++)
		if(indegree[i]==0)
			pq.push(i);
	while(!pq.empty())
	{
		printf("%d ",pq.top());
		pq.pop();
	}
}
