#include <stdio.h>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;
int order[100001];
int cut[100001];
vector< vector<int> > vv;
int ord = 1;
int dfs(int here, bool root)
{
	order[here] = ++ord;
	int ret = order[here];
	int child = 0;
	for (int i = 0; i < vv[here].size(); i++)
	{
		if (order[vv[here][i]] == 0)
		{
			child++;
			int tt = dfs(vv[here][i],false);
			if (tt >= order[here] && root==false)
				cut[here] = 1;
			ret = min(ret, tt);
		}
		else
			ret = min(ret, order[vv[here][i]]);
	}
	if (child >= 2 && root==true)
		cut[here] = 1;
	return ret;
}
int main(void)
{
	int V, E;
	scanf("%d %d", &V, &E);
	vv.resize(V + 1);
	memset(cut, 0, sizeof(cut));
	memset(order, 0, sizeof(order));
	for (int i = 0; i < E; i++)
	{
		int A, B;
		scanf("%d %d", &A, &B);
		vv[A].push_back(B);
		vv[B].push_back(A);
	}
	for (int i = 1; i <= V; i++)
		if (order[i] == 0)
			dfs(i,true);

	int result = 0;
	for (int i = 1; i <= V; i++)
	{
		if (cut[i] == 1)
			result++;
	}
	printf("%d\n", result);

	for (int i = 1; i <= V; i++)
	{
		if(cut[i]==1)
			printf("%d ", i);
	}
}