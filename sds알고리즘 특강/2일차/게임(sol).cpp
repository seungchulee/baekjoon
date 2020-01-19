#include <stdio.h>
int main(void)
{
	long long int X, Y;
	scanf("%lld %lld", &X, &Y);
	int Z = (Y * 100) / X;
	if (Z >= 99)
	{
		printf("-1");
		return 0;
	}
	long long int last = 1000000000;
	long long int first = 1;
	while (first <= last)
	{
		long long int mid = (first + last) / 2;
		int new_Z = ((Y + mid) * 100) / (X + mid);

		if (new_Z > Z)
		{
			last = mid - 1;
		}
		else
		{
			first = mid + 1;
		}

	}
	printf("%ld", first);
}