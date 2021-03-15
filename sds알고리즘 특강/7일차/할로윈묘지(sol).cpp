#include <stdio.h>
#include <cstring>
#include <vector>
#include <limits.h>
#include <queue>
using namespace std;
vector<vector<pair<int, int> > > vv;
int W, H;
int G;
int E;
int dist[901];
int field[31][31];
int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };
int main(void)
{
	while (1)
	{
		memset(field, 0, sizeof(field));
		vv.clear();
		scanf("%d %d", &W, &H);
		vv.resize(W*H + 1);

		for (int i = 0; i <= 900; i++)
			dist[i] = INT_MAX;

		dist[1] = 0;
		bool check = true;

		if (W == 0 && H == 0)
			break;

		scanf("%d", &G);
		for (int i = 0; i<G; i++)
		{
			int x, y;
			scanf("%d %d", &x, &y);
			field[y][x] = 1;
		} // grave

		int edges = 0;
		scanf("%d", &E);
		for (int i = 0; i<E; i++)
		{
			int x1, y1, x2, y2, T;
			scanf("%d %d %d %d %d", &x1, &y1, &x2, &y2, &T);
			field[y1][x1] = 2;
			int start = y1*W + x1 + 1;
			int end = y2*W + x2 + 1;
			vv[start].push_back(make_pair(end, T));
			edges++;
		} // ghost

		for (int i = 0; i<H; i++)
		{
			for (int j = 0; j<W; j++)
			{
				if (i == H - 1 && j == W - 1)
					continue;
				if (field[i][j] == 2 || field[i][j] == 1)
					continue;
				for (int k = 0; k<4; k++)
				{
					int ddx = i + dx[k];
					int ddy = j + dy[k];
					if (ddx<0 || ddy<0 || ddx >= H || ddy >= W)
						continue;
					if (field[ddx][ddy] == 0 || field[ddx][ddy] == 2)
					{
						int start = i*W + j + 1;
						int end = ddx*W + ddy + 1;
						vv[start].push_back(make_pair(end, 1));
						edges++;
					}
				}
			}
		}
		for (int i = 1; i <= W*H-G; i++) // V
		{
			for (int j = 1; j <= W*H; j++)
			{
				for (int k = 0; k<vv[j].size(); k++)
				{
					int new_val = dist[j] + vv[j][k].second;
					int before_val = dist[vv[j][k].first];
					if (dist[j] != INT_MAX && new_val<before_val)
						dist[vv[j][k].first] = new_val;
				}
			}
		}


		for (int j = 1; j <= W*H; j++)
		{
			for (int k = 0; k<vv[j].size(); k++)
			{
				int new_val = dist[j] + vv[j][k].second;
				int before_val = dist[vv[j][k].first];
				if (dist[j] != INT_MAX && new_val<before_val)
				{
					check = false;
					break;
				}
			}
		}

		if (check == false)
			printf("Never\n");
		else if (dist[W*H] == INT_MAX)
			printf("Impossible\n");
		else
			printf("%d\n", dist[W*H]);

	}
}