#include <stdio.h>
#include <algorithm>
using namespace std;
long int CMP = 1000000000;
long int gcd(long int a, long int b)
{
	long int maxs = max(a, b);
	long int mins = min(a, b);
	while (mins != 0)
	{
		long int re = maxs%mins;
		maxs = mins;
		mins = re;
	}
	return maxs;
}
int main(void)
{
	int N;
	long int nArr[1001];
	int M;
	long int mArr[1001];
	scanf("%d",&N);
	for (int i = 0; i < N; i++)
		scanf("%ld", &nArr[i]);
	scanf("%d", &M);
	for (int i = 0; i < M; i++)
		scanf("%ld", &mArr[i]);
	bool check = true;
	long long int result = 1;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			if (nArr[i] == 1 || mArr[j] == 1)
				continue;
			long int gcd_ab = gcd(nArr[i], mArr[j]);
			if (gcd_ab == 1)
				continue;
			nArr[i] = nArr[i] / gcd_ab;
			mArr[j] = mArr[j] / gcd_ab;
			result *= gcd_ab;
			if (result >= CMP)
			{
				result %= CMP;
				check = false;
			}
		}
	}
	if (check==false)
	{
		long long int res_tmp = result;
		int cnt = 1;
		while (1)
		{
			if (res_tmp / 10 == 0)
				break;
			res_tmp /= 10;
			cnt++;			
		}
		for (int i = 0; i < 9 - cnt; i++)
			printf("0");
		printf("%lld", result);
	}
	else
		printf("%lld", result);
}