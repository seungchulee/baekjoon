#include <stdio.h>
#include <algorithm>
#include <string.h>
using namespace std;
long long int gcd(long long int a, long long int b)
{
	long long int maxs = max(a, b);
	long long int mins = min(a, b);
	while (mins != 0)
	{
		long long int re = maxs%mins;
		maxs = mins;
		mins = re;
	}
	return maxs;
}
int main(void)
{
	int N;
	scanf("%d", &N);
	for (int t = 0; t < N; t++)
	{
		char st[10000];
		scanf("%s", st);
		long long int whole = 0;
		int i;
		long long int true_left = 0;
		long long int true_right = 0;
		int cnt_left = 0;
		int cnt_right = 0;
		for (i = 2; i < strlen(st); i++) {

			if (st[i] == '(')
			{
				for (int j = i + 1; j < strlen(st); j++)
				{
					if (st[j] == ')')
						break;
					whole *= 10;
					true_right *= 10;
					whole += st[j] - '0';
					true_right += st[j] - '0';
					cnt_right++;
				}
				break;
			}
			whole *= 10;
			whole += st[i] - '0';
			true_left = whole;
			// printf("!%lld\n", true_left);
			cnt_left++;
		}
		// printf("%d %lld %d %lld %lld\n", cnt_left, true_left, cnt_right, true_right, whole);
		if (cnt_right == 0)
		{
			long long int mo = 1;
			for (int i = 0; i < cnt_left; i++)
				mo *= 10;
			long long int ja = true_left;
			long long int gcds = gcd(mo, ja);
			printf("%lld/%lld\n", ja / gcds, mo / gcds);
		}
		else
		{
			long long int mo = 9;
			for (int i = 1; i < cnt_right; i++)
			{
				mo *= 10;
				mo += 9;
			}
			for (int i = 0; i < cnt_left; i++)
				mo *= 10;
			long long int ja = whole-true_left;
			long long int gds = gcd(mo, ja);
			printf("%lld/%lld\n", ja / gds, mo / gds);
		}

	}
}