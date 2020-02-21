#include <stdio.h>
#include <queue>
#include <cstring>
#include <vector>
using namespace std;
int depth[101010];
int main(void)
{
	int n;
	scanf("%d",&n);
	memset(depth,-1,sizeof(depth));
	vector<vector<int> > vv;
	vv.resize(n+1);
	for(int i=0;i<n-1;i++)
	{
		int a,b;
		scanf("%d %d",&a,&b);
		vv[a].push_back(b);
		vv[b].push_back(a);
	}
	queue<int> qq;
	qq.push(1);
	depth[1]=0;
	while(!qq.empty())
	{
		int x = qq.front();
		qq.pop();
		for(int i=0;i<vv[x].size();i++)
		{
			if(depth[vv[x][i]]==-1)
			{
				qq.push(vv[x][i]);
				depth[vv[x][i]]=depth[x]+1;
			}
		}
	}

	for(int i=2;i<=n;i++)
	{
		for(int j=0;j<vv[i].size();j++)
		{
			if(depth[i]>depth[vv[i][j]])
				printf("%d\n",vv[i][j]);
		}
	}

}
