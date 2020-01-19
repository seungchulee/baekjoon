#include <stdio.h>
#include <cstring>
int check[1000001];
int maxs = 1000000;
void gold_bach(int x)
{
	int i, j;
	for (i = 3, j = x-3;i<=x-3; i++, j--)
	{
		if (check[i] == -1 && check[j] == -1)
		{
			printf("%d = %d + %d\n", x, i, j);
			return;
		}
	}
	printf("Goldbach's conjecture is wrong.");
}
int main(void)
{
	int start = 2;
	memset(check, -1, sizeof(check));
	while (1)
	{
		int cnt = 0;
		for (int i = start; i <= maxs; i += start)
		{
			if (check[i] == -1 && cnt==0)
			{
				cnt++;
			}
			else if (check[i] == -1 && cnt == 1)
			{
				check[i] = 1;
			}
		}
		start++;
		if (start > maxs)
			break;
	}
	while (1)
	{
		int x;
		scanf("%d", &x);
		if (x == 0)
			break;
		gold_bach(x);
	}
}