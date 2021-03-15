#include <stdio.h>
#include <vector>
using namespace std;
vector < vector<pair<int, int> > > vv;
int dist[501];
int main(void)
{
	int N, M;
	scanf("%d %d", &N, &M);
	vv.resize(N + 1);
	for (int i = 0; i < M; i++)
	{
		int a, b, c;
		scanf("%d %d %d", &a, &b, &c);
		vv[a].push_back(make_pair(b, c));
	}
	for (int i = 1; i <= 500; i++)
		dist[i] = 10000000;
	dist[1] = 0;
	bool check = true;
	
	// 벨만 포드 수행
	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= N; j++)
		{
			for (int k = 0; k < vv[j].size(); k++)
			{
				int new_val = dist[j] + vv[j][k].second;
				int before_val = dist[vv[j][k].first];
				if (dist[j] != 10000000 && new_val < before_val)
				{
					dist[vv[j][k].first] = new_val;
				}
			}
		}
	}

	// 음의 사이클 찾기 위함
	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= N; j++)
		{
			for (int k = 0; k < vv[j].size(); k++)
			{
				int new_val = dist[j] + vv[j][k].second;
				int before_val = dist[vv[j][k].first];
				if (dist[j] != 10000000 && new_val < before_val)
				{
					check = false;
				}
			}
		}
	} 
	
	if (check == false)
	{
		printf("-1\n");
		return 0;
	}
	for (int i = 2; i <= N; i++)
	{
		if (dist[i] == 10000000)
			printf("-1\n");
		else
			printf("%d\n", dist[i]);
	}

}
