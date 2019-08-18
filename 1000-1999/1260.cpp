#include <stdio.h>
#include <queue>
using namespace std;

int graph[1001][1001];
int visit[1001];

void dfs(int V,int N)
{
	visit[V] = 1;
	printf("%d ",V);
	for(int i=1;i<=N;i++)		
	{
		if(visit[i]==1 || graph[V][i]==0)
			continue;
		dfs(i,N);
	}
}
void bfs(int V, int N)
{
	queue<int> q;
	q.push(V);
	visit[V] = 0;
	while(!q.empty())
	{
		V=q.front();
		printf("%d ",V);
		q.pop();
		for(int i=1;i<=N;i++)
		{
			if(visit[i] == 0 || graph[V][i]==0)
				continue;
			q.push(i);
			visit[i]=0;
		}
	}
}
int main(void)
{
	int N,M,V;
	scanf("%d %d %d",&N,&M,&V);

	int from;
	int to;

	for(int i=0;i<M;i++)
	{
		scanf("%d %d",&from,&to);
		graph[from][to] = 1;
		graph[to][from] = 1;
	}

	dfs(V,N);
	printf("\n");
	bfs(V,N);

}
