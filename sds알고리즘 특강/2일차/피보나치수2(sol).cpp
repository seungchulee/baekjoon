#include <stdio.h>
long long int arr[91];
int main(void)
{
	arr[0] = 0;
	arr[1] = 1;
	int n;
	scanf("%d", &n);
	for (int i = 2; i <= n; i++)
	{
		arr[i] = arr[i - 1] + arr[i - 2];
	}
	printf("%lld", arr[n]);
}