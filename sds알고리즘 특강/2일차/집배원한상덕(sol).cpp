#include <stdio.h>
#include <cstring>
#include <queue>
#include <set>
using namespace std;
int dx[8] = { 1,-1,0,0,1,1,-1,-1 };
int dy[8] = { 0,0,1,-1,1,-1,1,-1 };
int visit[51][51];
char arr[51][51];
int godo[51][51];
int main(void)
{
	int N;
	scanf("%d", &N);
	int p_i, p_j;
	int house = 0;
	for (int i = 0; i<N; i++)
	{
		char st[51];
		scanf("%s", st);
		for (int j = 0; j<N; j++)
		{
			arr[i][j] = st[j];
			if (arr[i][j] == 'P')
			{
				p_i = i;
				p_j = j;
			}
			if (arr[i][j] == 'K')
			{
				house++;
			}
		}
	}
	int max_godo = -1;
	int max_real_godo = -1;
	int min_godo = 1000000;
	int min_real_godo = 1000000;
	set<int> ss;
	for (int i = 0; i<N; i++)
	{
		for (int j = 0; j<N; j++)
		{
			scanf("%d", &godo[i][j]);
			ss.insert(godo[i][j]);
			if (godo[i][j]>max_real_godo)
			{
				max_real_godo = godo[i][j];
			}
			if (godo[i][j]>max_godo && (arr[i][j] == 'K' || arr[i][j] == 'P'))
			{
				max_godo = godo[i][j];
			}
			if (godo[i][j]<min_godo && (arr[i][j] == 'K' || arr[i][j] == 'P'))
			{
				min_godo = godo[i][j];
			}
			if (godo[i][j]<min_real_godo)
			{
				min_real_godo = godo[i][j];
			}
		}
	}
	int i = min_real_godo, j = max_godo;
	int ans = 10000000;
	int t = 100;
	
	set<int>::iterator l = ss.begin(), r = ss.begin();
	while (r != ss.end())
	{
		while (l != ss.end())
		{
			int cnt = 0;
			memset(visit, -1, sizeof(visit));
			int lo = *l;
			int hi = *r;
			queue<pair<int, int> > qq;
			qq.push(make_pair(p_i, p_j));
			visit[p_i][p_j] = 1;
			while (!qq.empty())
			{
				pair<int, int> pp = qq.front();
				int x = pp.first;
				int y = pp.second;
				qq.pop();
				if (arr[x][y] == 'K')
					cnt++;
				for (int k = 0; k < 8; k++)
				{
					int ddx = x + dx[k];
					int ddy = y + dy[k];
					if (ddx < 0 || ddy < 0 || ddx >= N || ddy >= N)
						continue;
					if (visit[ddx][ddy] == -1 && godo[ddx][ddy] >= lo && godo[ddx][ddy] <= hi)
					{
						visit[ddx][ddy] = 1;
						qq.push(make_pair(ddx, ddy));
					}
				}
			}
			if (cnt == house)
			{
				if (godo[p_i][p_j] > hi)
					ans = min(ans, godo[p_i][p_j] - lo);
				else if(godo[p_i][p_j]<lo)
					ans = min(ans, hi - godo[p_i][p_j]);
				else
					ans = min(ans, *r - *l);
			}
			else
				break;
			++l;
		}
		++r;
	}
	printf("%d", ans);
}

