#include <stdio.h>
#include <cstring>
#include <stack>
#include <algorithm>
using namespace std;
int dp[1001][1001];
int vis[1001][1001];
char arr[1001];
char brr[1001];
int main(void)
{
	scanf("%s", arr);
	scanf("%s", brr);
	int lena = strlen(arr);
	int lenb = strlen(brr);
	int maxs = -1;
	memset(dp, 0, sizeof(dp));
	
	for (int i = 0; i < lena; i++)
	{
		for (int j = 0; j < lenb; j++)
		{
			if (arr[i] == brr[j])
			{
				if (i == 0 || j == 0)
					dp[i][j] = 1;
				else
					dp[i][j] = dp[i - 1][j - 1] + 1;

				maxs = max(dp[i][j], maxs);
				vis[i][j] = 3;
			}
			else
			{
				dp[i][j] = max(dp[i][j - 1], dp[i - 1][j]);
				if (dp[i][j] == dp[i][j - 1])
					vis[i][j] = 1;
				else
					vis[i][j] = 2;
			}
		}
	}
	if (maxs == -1)
	{
		printf("0");
		return 0;
	}
	int i = lena - 1;
	int j = lenb - 1;
	int cnt = 0;
	stack<char> ans;
	while (1)
	{
		if (cnt == maxs)
			break;
		if (vis[i][j] == 3)
		{
			ans.push(arr[i]);
			i--;
			j--;
			cnt++;
		}
		else if (vis[i][j] == 2)
		{
			i--;
		}
		else
		{
			j--;
		}
	}
	printf("");
	printf("%d\n", maxs);
	while (!ans.empty())
	{
		printf("%c", ans.top());
		ans.pop();
	}

}