#include <stdio.h>
#include <vector>
using namespace std;
vector < vector<pair<long long int, long long int> > > vv;
long long int dist[501];
int main(void)
{
	int N, M;
	scanf("%d %d", &N, &M);
	vv.resize(N + 1);
	for (int i = 0; i < M; i++)
	{
		long long int a, b, c;
		scanf("%lld %lld %lld", &a, &b, &c);
		vv[a].push_back(make_pair(b, c));
	}
	for (int i = 1; i <= 500; i++)
		dist[i] = 1000000000;
	dist[1] = 0;
	bool check = true;
	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= N; j++)
		{
			for (int k = 0; k < vv[j].size(); k++)
			{
				long long int new_val = dist[j] + vv[j][k].second;
				long long int before_val = dist[vv[j][k].first];
				if (dist[j] != 1000000000 && new_val < before_val)
				{
					dist[vv[j][k].first] = new_val;
				}
			}
		}
	}

	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= N; j++)
		{
			for (int k = 0; k < vv[j].size(); k++)
			{
				long long int new_val = dist[j] + vv[j][k].second;
				long long int before_val = dist[vv[j][k].first];
				if (dist[j] != 1000000000 && new_val < before_val)
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
		if (dist[i] == 1000000000)
        {
            printf("-1\n");
        }
		else
			printf("%lld\n", dist[i]);
	}

}
