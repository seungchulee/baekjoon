#include <stdio.h>
int fact(int n)
{
	if (n == 0)
		return 1;
	else
		return n*fact(n - 1);
}
int main(void)
{
	int N, K;
	scanf("%d %d", &N, &K);
	printf("%d", fact(N) / (fact(N - K)*fact(K)));
	

	
}