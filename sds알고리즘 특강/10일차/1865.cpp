#include <stdio.h>
#include <vector>
#include <cstring>
using namespace std;
vector<vector<pair<int, int> > > vv;
int dist[501];
int main(void)
{
	int T;
	scanf("%d", &T);
	for (int i = 0; i < T; i++)
	{
		memset(dist, 0, sizeof(dist));
		vv.clear();
		int N, M, W;
		scanf("%d %d %d", &N, &M, &W);
		vv.resize(N + 1);

		for (int j = 0; j < M; j++)
		{
			int s, e, t;
			scanf("%d %d %d", &s, &e, &t);
			vv[e].push_back(make_pair(s, t));
			vv[s].push_back(make_pair(e, t));
		}
		for (int j = 0; j < W; j++)
		{
			int s, e, t;
			scanf("%d %d %d", &s, &e, &t);
			vv[s].push_back(make_pair(e, -t));
		}

		for (int i = 1; i <= 500; i++)
			dist[i] = 10000000;
		dist[1] = 0;

		bool check = true;
		for (int j = 0; j < N; j++)
		{
			for (int k = 1; k <= N; k++)
			{
				for (int m = 0; m < vv[k].size(); m++)
				{
					int new_val = dist[k] + vv[k][m].second;
					int before_val = dist[vv[k][m].first];
					if ( new_val < before_val)
					{
						dist[vv[k][m].first] = new_val;
					}
				}
			}
		}

		for (int j = 0; j < N; j++)
		{
			for (int k = 1; k <= N; k++)
			{
				for (int m = 0; m < vv[k].size(); m++)
				{
					int new_val = dist[k] + vv[k][m].second;
					int before_val = dist[vv[k][m].first];
					if (new_val < before_val)
					{
						check = false;
						break;
					}
				}
			}
		}

		if (check == false)
			printf("YES\n");
		else
			printf("NO\n");
	}
}