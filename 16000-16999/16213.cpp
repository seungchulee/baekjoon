#include <stdio.h>
#include <vector>
#include <cstring>
#include <queue>
#include <algorithm>
#include <functional>
using namespace std;
int N,M,Q;
long int lcabase[20][202020];
long int minbase[20][202020];
long int depth[202020];
int visit[202020];
int arr[202020];
priority_queue<pair<long int,pair<long int,long int> > > pq;
vector<vector<pair<long int,long int> > > vv;
void dfs(int idx, long int dd)
{

	depth[idx]=dd;
	visit[idx]=0;
	for(int i=0;i<vv[idx].size();i++)
	{
		long int ww = vv[idx][i].second;
		long int to = vv[idx][i].first;
		if(visit[to]==-1)
		{
			minbase[0][to]=ww;
			lcabase[0][to]=idx;
			dfs(to,dd+1);
		}
	}
}
void init()
{
	for(int i=1;i<=19;i++)
	{
		for(int j=1;j<=N;j++)
		{
			minbase[i][j]=min(minbase[i-1][j],minbase[i-1][lcabase[i-1][j]]);
			lcabase[i][j]=lcabase[i-1][lcabase[i-1][j]];
		}
	}
}

int find(int a)
{
	if(a==arr[a])
		return a;
	else
		return arr[a]=find(arr[a]);
}
void Union(int a, int b)
{
	int aa = find(a);
	int bb = find(b);
	arr[aa]=bb;

}
long int find_lca(int a, int b)
{
	if(depth[a] > depth[b])
		swap(a,b);
	long int mins = 1001010101;
	for(int i=19;i>=0;i--)
	{
		if(depth[b] - depth[a] >= 1 << i)
		{
			mins = min(mins,minbase[i][b]);
			b = lcabase[i][b];	
			//mins = min(mins,minbase[i][b]);
		}
	}
	
	if(a==b)
		return mins;

	long int min1 = 1001010101;

	for(int i=19;i>=0;i--)
	{
		if(lcabase[i][a] != lcabase[i][b])
		{
			min1 = min(min1,minbase[i][a]);
			min1 = min(min1,minbase[i][b]);
			a=lcabase[i][a];
			b=lcabase[i][b];
		}
	}
	min1 = min(min1,minbase[0][a]);
	min1 = min(min1,minbase[0][b]);
	mins = min(mins,min1);
	return mins;
}
int main(void)
{
	for(int i=1;i<=200000;i++)
		arr[i]=i;
	memset(visit,-1,sizeof(visit));
	memset(depth,0,sizeof(depth));
	scanf("%d %d %d",&N,&M,&Q);
	for(int i=0;i<M;i++)
	{
		long int a, b, c;
		scanf("%ld %ld %ld",&a,&b,&c);
		pq.push(make_pair(c,make_pair(a,b)));
	}
	int res = 0;

	vv.resize(N+1);
	while(!pq.empty())
	{
		pair<long int, pair<long int,long int> > pp = pq.top();
		pq.pop();
		long int ww = pp.first;
		long int left = pp.second.first;
		long int right = pp.second.second;
		if(find(left) != find(right))
		{
			Union(left,right);
			//printf("%d %d\n",left,right);
			vv[left].push_back(make_pair(right,ww));
			vv[right].push_back(make_pair(left,ww));
			res+=ww;
		}
	}
	dfs(1,0);
	init();

	for(int i=0;i<Q;i++)
	{
		int a,b;
		scanf("%d %d",&a,&b);
		long int lca = find_lca(a,b);
		printf("%ld\n",lca);
	}
}
