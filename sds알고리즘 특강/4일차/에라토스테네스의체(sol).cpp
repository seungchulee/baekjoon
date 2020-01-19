#include <stdio.h>
#include <algorithm>
#include <cstring>
using namespace std;
int arr[1001];
int check[1001];
int main(void)
{
	int N, K;
	memset(check, -1, sizeof(check));
	scanf("%d %d", &N, &K);
	int cnt = 0;
	int start = 2;
	while (1)
	{
		for (int i = start; i <= N; i += start)
		{
			if (check[i] == -1)
			{
				cnt++;
				check[i] = 1;
				if (cnt == K)
				{
					printf("%d", i);
					return 0;
				}
			}
		}
		start++;
	}
}