#include <stdio.h>
#include <cstring>
int check[1000001];
int main(void)
{
	memset(check, -1, sizeof(check));
	for (int i = 2; i <= 1000000; i++)
	{
		int cnt = 0;
		for (int j = i; j <= 1000000; j += i)
		{
			if (check[j] == -1 && cnt == 0)
			{
				cnt++;
			}
			else if (check[j] == -1 && cnt == 1)
			{
				check[j] = 1;
			}
		}
	}
	char st[101];
	scanf("%s", st);
	int N;
	scanf("%d", &N);

	for (int i = 2; i <= 1000000; i++)
	{
		if (check[i] == -1)
		{
			if (i >= N)
				break;
			int rs = (st[0]-'0') % i;
			for (int j = 1; j < strlen(st); j++)
			{
				int ss = st[j] - '0';
				rs = (ss + (rs * 10)) % i;
			}
			if (rs == 0)
			{
				printf("BAD %d", i);
				return 0;
			}
		}
	}
	printf("GOOD");
	
	
}