#include <stdio.h>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;
int visit[101];
vector<vector<int> > vv;
int main(void)
{
	int N;
	memset(visit,-1,sizeof(visit));
	scanf("%d",&N);
	int n,m;
	scanf("%d %d",&n,&m);
	int mm;
	scanf("%d",&mm);
	vv.resize(N+1);
	for(int i=0;i<mm;i++)
	{
		int x,y;
		scanf("%d %d",&x,&y);
		vv[x].push_back(y);
		vv[y].push_back(x);
	}
	visit[n]=0;
	queue<int> qq;
	qq.push(n);

	while(!qq.empty())
	{
		int id = qq.front();
		qq.pop();
	
		for(int i=0;i<vv[id].size();i++)
		{
			if(visit[vv[id][i]]==-1)
			{
				visit[vv[id][i]]=visit[id]+1;
				qq.push(vv[id][i]);
			}
		}	
	}
	printf("%d",visit[m]);
}
