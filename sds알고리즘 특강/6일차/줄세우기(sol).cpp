#include <stdio.h>
#include <cstring>
#include <vector>
#include <queue>
using namespace std;
vector<vector<int> > vv;
int degree[32001];
int main(void)
{
	memset(degree, 0, sizeof(degree));
	int N, M;
	scanf("%d %d", &N, &M);
	vv.resize(N + 1);
	for (int i = 0; i < M; i++)
	{
		int a, b;
		scanf("%d %d", &a, &b);
		degree[b]++;
		vv[a].push_back(b);
	}
	priority_queue<int> pq;
	for (int i = 1; i <= N; i++)
	{
		if (degree[i] == 0)
			pq.push(-i);
	}
	while (!pq.empty())
	{
		int out = -pq.top();
		pq.pop();
		printf("%d ", out);
		for (int i = 0; i < vv[out].size(); i++)
		{
			degree[vv[out][i]]--;
			if(degree[vv[out][i]]==0)
				pq.push(-vv[out][i]);	
		}
	}

}