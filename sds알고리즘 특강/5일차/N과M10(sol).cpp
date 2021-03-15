#include <stdio.h>
#include <cstring>
#include <algorithm>
#include <vector>
#include <set>
using namespace std;
int N, M;
int arr[10];
int check[10];

void dfs(int idx, int cnt, vector<int> vv)
{
	if (cnt == M)
	{
		for (int i = 0; i < M; i++)
			printf("%d ", vv[i]);
		printf("\n");
		return;
	}
	int ch[10001];
	memset(ch, -1, sizeof(ch));
	for (int i = idx; i < N; i++)
	{
		if (check[i] == 1 || ch[arr[i]] >= 0)
			continue;
		check[i] = 1;
		ch[arr[i]]++;
		vv.push_back(arr[i]);
		dfs(i + 1, cnt + 1, vv);
		check[i] = -1;
		vv.pop_back();
	}
}
int main(void)
{
	memset(check, -1, sizeof(check));
	scanf("%d %d", &N, &M);
	for (int i = 0; i < N; i++)
		scanf("%d", &arr[i]);
	sort(arr, arr + N);
	vector<int> vv;
	dfs(0, 0, vv);
}