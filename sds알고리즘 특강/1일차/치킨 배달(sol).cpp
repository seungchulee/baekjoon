#include <stdio.h>
#include <vector>
#include <utility>
#include <algorithm>
using namespace std;
vector<pair<int, int> > vv;
vector<pair<int, int> > one;
int N, M;
int arr[51][51];

int main(void)
{
	scanf("%d %d", &N, &M);
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			scanf("%d", &arr[i][j]);
			if (arr[i][j] == 2)
			{
				vv.push_back(make_pair(i,j));
			}
			if (arr[i][j] == 1)
			{
				one.push_back(make_pair(i, j));
			}
		}
	}
	vector<int> ch;
	for (int i = 0; i < M; i++)
		ch.push_back(0);
	for (int i = 0; i < vv.size() - M; i++)
	{
		ch.push_back(1);
	}
	int ans = 10000000;
	do {
		int ans_2 = 0;
		for (int i = 0; i < one.size(); i++)
		{
			int mins = 10000000;
			int one_i = one[i].first;
			int one_j = one[i].second;
			for (int j = 0; j < ch.size(); j++)
			{
				if (ch[j] == 0)
				{
					int ch_i = vv[j].first;
					int ch_j = vv[j].second;
					int dist = abs(one_i - ch_i) + abs(one_j - ch_j);
					if (dist < mins)
						mins = dist;
				}
			}
			ans_2 += mins;
		}
		if (ans > ans_2)
			ans = ans_2;
		/*for (int i = 0; i < ch.size(); i++)
		{
			printf("%d ", ch[i]);
		}
		printf("\n");*/
	} while (next_permutation(ch.begin(), ch.end()));
	printf("%d", ans);
}