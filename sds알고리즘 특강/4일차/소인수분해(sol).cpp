#include <stdio.h>
#include <algorithm>
using namespace std;
int main(void)
{
	int N;
	scanf("%d", &N);
	int cnt = 2;
	while (N != 1)
	{
		if (N%cnt == 0)
		{
			N /= cnt;
			printf("%d\n", cnt);
		}
		else
			cnt++;
	}
}