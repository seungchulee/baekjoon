#include <stdio.h>
#include <iostream>
#include <vector>
#include <cstring>
#include <string>
#include <set>
using namespace std;
int arr[11];
int check[11];
int n, k;
set<int> ss;
void dfs(int idx, int cnt, vector<int> vv)
{
	if (cnt == k)
	{
		string num;
		for (int i = 0; i < vv.size(); i++)
		{
			num += to_string(vv[i]);
		}
		ss.insert(atoi(num.c_str()));
		return;
	}
	for (int i = 0; i < n; i++)
	{
		if (check[i] == 1)
			continue;
		check[i] = 1;
		vv.push_back(arr[i]);
		dfs(i + 1, cnt + 1,vv);
		check[i] = -1;
		vv.pop_back();
	}

}
int main(void)
{
	scanf("%d", &n);
	scanf("%d", &k);
	memset(check, -1, sizeof(check));
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &arr[i]);
	}
	vector<int> vv;
	dfs(0, 0, vv);

	printf("%d", ss.size());

}