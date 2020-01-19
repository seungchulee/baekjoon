#include <stdio.h>
#include <vector>
#include <queue>
#include <cstring>
#include <algorithm>
using namespace std;
int degree[501];
int time[501];
int min_t[501];
vector<vector<int> > vv;
int main(void)
{
	int N;
	scanf("%d", &N);
	vv.resize(N + 1);
	memset(min_t, 0, sizeof(min_t));
	for (int i = 1; i <= N; i++)
	{
		int times;
		scanf("%d", &times);
		time[i] = times;
		while (1)
		{
			int a;
			scanf("%d", &a);
			if (a == -1)
				break;
			degree[i]++;
			vv[a].push_back(i);
		}
	}
	queue<int> pq;
	for (int i = 1; i <= N; i++)
	{
		if (degree[i] == 0)
			pq.push(i);
	}
	while (!pq.empty())
	{
		int out = pq.front();
		pq.pop();

		for (int i = 0; i < vv[out].size(); i++)
		{
			int tmp = vv[out][i];
			int tt = time[out] + min_t[out];
			if (tt > min_t[tmp])
				min_t[tmp] = tt;
			degree[tmp]--;
			if (degree[tmp] == 0)
				pq.push(tmp);
		}
	}
	for (int i = 1; i <= N; i++)
		printf("%d ", time[i] + min_t[i]);

}