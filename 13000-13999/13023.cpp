#include <stdio.h>
#include <vector>
#include <cstring>

using namespace std;
vector<vector<int> > vv;
int visit[2020];
bool answer=false;
void DFS(int idx, int dd)
{
	if(dd==5)
	{
		answer=true;
		return;
	}
	visit[idx]=dd;
	for(int i=0;i<vv[idx].size();i++)
	{
		if(visit[vv[idx][i]]==-1)
		{
			visit[vv[idx][i]]=dd;
			DFS(vv[idx][i],dd+1);
			visit[vv[idx][i]]=-1;
		}
	}
	visit[idx]=-1;
}
int main(void)
{
	int n,m;
	scanf("%d %d",&n,&m);
	memset(visit,-1,sizeof(visit));
	vv.resize(n+1);
	for(int i=0;i<m;i++)
	{
		int x,y;
		scanf("%d %d",&x,&y);
		vv[x].push_back(y);
		vv[y].push_back(x);
	}

	for(int i=0;i<n;i++)
	{
		if(visit[i]==-1)
		{
			DFS(i,1);
			if(answer==true)
			{
				printf("1");
				return 0;
			}
		}
	}
	
	printf("0");
	return 0;

}
