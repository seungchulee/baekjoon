#include <stdio.h>
#include <queue>
#include <vector>
#include <cstring>
using namespace std;
int arr[1010];
int min_t[1010];
int indegree[1010];
int main(void)
{
	int ttt;
	scanf("%d",&ttt);
	for(int tt=0;tt<ttt;tt++)
	{
		int N,K;
		memset(indegree,0,sizeof(indegree));
		memset(arr,0,sizeof(arr));
		memset(min_t,0,sizeof(min_t));
		vector<vector<int> > vv;

		scanf("%d %d",&N,&K);
		vv.resize(N+1);
		for(int i=1;i<=N;i++)
			scanf("%d",&arr[i]);
		for(int i=0;i<K;i++)
		{
			int a,b;
			scanf("%d %d",&a,&b);
			vv[a].push_back(b);
			indegree[b]++;
		}
		queue<int> qq;
		for(int i=1;i<=N;i++)
		{
			if(indegree[i]==0)
				qq.push(i);
		}
		while(!qq.empty())
		{
			int t = qq.front();
			qq.pop();
			for(int i=0;i<vv[t].size();i++)
			{
				indegree[vv[t][i]]--;
				if(arr[t]+min_t[t]>min_t[vv[t][i]])
					min_t[vv[t][i]]=arr[t]+min_t[t];
				if(indegree[vv[t][i]]==0)
					qq.push(vv[t][i]);
			}
		}
		int W;
		scanf("%d",&W);
		printf("%d\n",arr[W]+min_t[W]);
	}

}
