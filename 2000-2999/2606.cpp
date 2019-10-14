#include <stdio.h>
#include <vector>
#include <cstring>
#include <queue>
using namespace std;
int N;
int M;
int visit[101];
int main(void)
{
	scanf("%d",&N);
	scanf("%d",&M);
	memset(visit,0,sizeof(visit));

	vector<vector<int> > comp;
	comp.resize(N+1);

	for(int i=0;i<M;i++)
	{
		int x,y;
		scanf("%d %d",&x,&y);
		comp[x].push_back(y);
		comp[y].push_back(x);
	}
	queue<int> qq;
	qq.push(1);
	visit[1]=1;
	while(!qq.empty())
	{
		int x = qq.front();
		qq.pop();
		int len = comp[x].size();
		//printf("%d=",x);
		for(int i=0;i<len;i++)
		{
			int num=comp[x][i];
		//	printf("%d ",num);
			if(visit[num]==0)
			{
				visit[num]=1;
				qq.push(num);
			}
		}
		//printf("\n");
	}
	int result=0;
	for(int i=2;i<=N;i++)
	{
		if(visit[i]==1)
			result++;
	}
	printf("%d",result);
}
