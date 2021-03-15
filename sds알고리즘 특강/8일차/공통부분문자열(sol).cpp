#include <stdio.h>
#include <cstring>
#include <algorithm>
using namespace std;
int dp[4001][4001];
int main(void)
{
	char st[4001];
	char at[4001];
	memset(dp, 0, sizeof(dp));
	scanf("%s", st);
	scanf("%s", at);
	int lena = strlen(st);
	int lenb = strlen(at);

	int maxs = -1;
	for (int i = 0; i < lena; i++)
	{
		for (int j = 0; j < lenb; j++)
		{
			if (st[i] == at[j])
			{
				if (i == 0 || j == 0)
					dp[i][j] = 1;
				else
					dp[i][j] = dp[i - 1][j - 1] + 1;
			
				maxs = max(maxs, dp[i][j]);
			}
		}
	}
	if (maxs == -1)
		printf("0");
	else
		printf("%d", maxs);
}