#include <stdio.h>
#include <cmath>
int N;
long int arr[2000000];
int gaesu=500000;
int main(void)
{
	scanf("%d", &N);
	for (int i = 0; i < N; i++)
	{
		scanf("%ld", &arr[i]);
	}
	int H = (int)log2(gaesu-1)+1;
	int base = 1 << H;
	

	for (int i = 1; i < N; i++)
	{

	}
}
