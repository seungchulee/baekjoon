#include <stdio.h>
#include <queue>
#include <utility>
#include <cstring>
using namespace std;
int R, C;
char arr[51][51];
int visit[51][51];
int waters[51][51];
int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,1,-1 };
int d_i, d_j;
int s_i, s_j;
int w_i, w_j;
queue<pair<int, int> > waterr;
void water()
{
	
	while (!waterr.empty())
	{
		pair<int, int> pp = waterr.front();
		int first = pp.first;
		int second = pp.second;
		waterr.pop();
		for (int i = 0; i < 4; i++)
		{
			int ddx = first + dx[i];
			int ddy = second + dy[i];
			if (ddx < 0 || ddy < 0 || ddx >= R || ddy >= C)
				continue;
			if (arr[ddx][ddy] == 'X' || arr[ddx][ddy]=='D')
				continue;
			if (waters[ddx][ddy] == -1 && arr[ddx][ddy]=='.')
			{
				waters[ddx][ddy] = waters[first][second] + 1;
				waterr.push(make_pair(ddx, ddy));
			}
		}
	}


}
void gosum()
{
	queue<pair<int, int> > qq;
	qq.push(make_pair(s_i, s_j));
	visit[s_i][s_j] = 0;
	while (!qq.empty())
	{
		pair<int, int> pp = qq.front();
		int first = pp.first;
		int second = pp.second;
		qq.pop();
		for (int i = 0; i < 4; i++)
		{
			int ddx = first + dx[i];
			int ddy = second + dy[i];
			if (ddx < 0 || ddy < 0 || ddx >= R || ddy >= C)
				continue;
			if (arr[ddx][ddy] == 'X')
				continue;
		
			if (visit[ddx][ddy] == -1 && (arr[ddx][ddy]=='.' || arr[ddx][ddy]=='D'))
			{
				if (waters[ddx][ddy] == -1 || waters[ddx][ddy] > visit[first][second] + 1)
				{
					visit[ddx][ddy] = visit[first][second] + 1;
					qq.push(make_pair(ddx, ddy));
				}
			}
		}
	}

}
int main(void)
{
	scanf("%d %d", &R, &C);
	memset(visit, -1,sizeof(visit));
	memset(waters, -1, sizeof(waters));
	for (int i = 0; i < R; i++)
	{
		char st[51];
		scanf("%s", st); 
		for (int j = 0; j < C; j++)
		{
			arr[i][j] = st[j];
			if (arr[i][j] == 'D')
			{
				d_i = i;
				d_j = j;
			}
			if (arr[i][j] == 'S')
			{
				s_i = i;
				s_j = j;
			}
			if (arr[i][j] == '*')
			{
				w_i = i;
				w_j = j;
				waterr.push(make_pair(i, j));
				waters[i][j] = 0;
			}
		}
	}

	water();
	gosum();
	if (visit[d_i][d_j] == -1)
	{
		printf("KAKTUS");
		return 0;
	}
	printf("%d", visit[d_i][d_j]);
}