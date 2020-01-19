#include <stdio.h>
#include <algorithm>
#include <cstring>
#include <queue>
#include <vector>
#include <utility>
#include <stack>
using namespace std;
int arr[1000001];
int D[1000001];
int P[1000001];
vector<pair<int, int> > qq;
// qq : data / idx
bool comp(const pair<int, int> &p1, const pair<int, int> &p2)
{
	return p1.first < p2.first;
}
int main(void)
{
	int N;
	scanf("%d", &N);
	memset(D, 0, sizeof(D));
	memset(P, 0, sizeof(P));

	for (int i = 1; i <= N; i++)
	{
		scanf("%d", &arr[i]);
	}
	D[1] = 1;
	P[1] = -1;
	qq.push_back(make_pair(arr[1], D[1]));
	for (int i = 2; i <= N; i++)
	{
		qq.push_back(make_pair(arr[i], i));
		sort(qq.begin(), qq.end());
		auto idx = upper_bound(qq.begin(), qq.end(), make_pair(arr[i],i),comp)-qq.begin();
		if (idx == 0)
		{
			D[i] = 1;
			P[i] = -1;
		}
		else
		{
			pair<int, int> p1 = qq[idx - 1];
			P[i] = p1.second;
			D[i] = D[p1.second] + 1;
			/*int ii = idx;
			while (1)
			{
				pair<int, int> p1 = qq[idx - 1];
				if (P[p1.second] == -1)
				{
					idx--;
					if (idx == 0)
					{
						P[i] = p1.second;
						break;
					}

				}
				else
				{
					P[i] = p1.second;
					break;
				}
			}
			if (P[i] == -1)
				D[i] = -1;
			else
			{
				while (1)
				{
					pair<int, int> p1 = qq[ii - 1];
					if (P[p1.second] == -1)
					{
						D[i] = D[p1.second] + 1;
						ii--;
						if (ii == 0)
							break;
					}
					else
					{
						D[i] = D[p1.second] + 1;
						break;
					}
				}
			}*/
		}
	}
	for (int i = 1; i <= N; i++)
	{
		printf("%2d ", D[i]);
	}
	printf("\n");
	for (int i = 1; i <= N; i++)
	{
		printf("%2d ", P[i]);
	}
	printf("\n");
	printf("%d\n", D[N]);
	int n = N;
	int p = arr[n];
	stack<int> qq;
	while (1)
	{
		if (n == -1)
			break;
		qq.push(p);
		n = P[n]; 
		p = arr[n];

	}
	while (!qq.empty())
	{
		printf("%d ", qq.top());
		qq.pop();
	}
}