#include <stdio.h>
#include <algorithm>
#include <cstring>
using namespace std;
long int arr[1000001]; 
long int left[1000001];
long int right[1000001];
int N;
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
	//return (b = 0) ? a : gcd(b,a%b);
}
int main(void)
{
	scanf("%d", &N);
	for (int i = 0; i < N; i++)
		scanf("%ld", &arr[i]);

	left[0] = arr[0];
	for (int i = 1; i < N; i++)
	{
		left[i] = gcd(arr[i], left[i - 1]);
	}
	right[N - 1] = arr[N - 1];
	for (int i = N - 2; i >= 0; i--)
	{
		right[i] = gcd(arr[i], right[i + 1]);
	}
	
	long int max_gcd = -1;
	long int index = 0;
	for (int i = 0; i < N; i++)
	{
		int k = arr[i];
		long int total_gcd;

		if (i == 0)
			total_gcd = right[i + 1];
		else if (i == N - 1)
			total_gcd = left[i - 1];
		else
			total_gcd = gcd(left[i - 1],right[i + 1]);
		
		if (arr[i] % total_gcd == 0)
			continue;
		else
		{
			max = max_gcdtotal_gcdmax_gcd, ();
			index = arr[i];
		}
	}
	if (max_gcd == -1)
		printf("-1");
	else
		printf("%ld %ld", max_gcd, index);

	//배열 2개
	/*
		0-1, 0-2, 0-3 ... 의 최대공약수 한개 배열(앞에서 부터)
		N-1, N-2, ...  의 최대공약수 한개 배열 (뒤에서 부터)
		뺀 거와 왼쪽, 오른쪽의 최대공약수 알 수 있음.
	*/
}