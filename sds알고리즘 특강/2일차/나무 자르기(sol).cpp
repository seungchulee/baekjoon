#include <stdio.h>
#include <algorithm>
using namespace std;
long long int N;
long long int M;
long long int arr[1000001];
int main(void)
{
	scanf("%lld %lld", &N, &M);
	for (int i = 0; i < N; i++)
	{
		scanf("%lld", &arr[i]);
	}
	sort(arr, arr + N);
	long long int first = 0;
	long long int last = arr[N - 1];
	long long int mid;
	long long int maxs = -1;
	while (first <= last)
	{
		mid = (first + last) / 2;
		long long int nas = 0;
		for (int i = 0; i < N; i++)
		{
			if (arr[i] - mid <= 0)
				continue;
			nas += arr[i] - mid;
		}
		if (nas < M)
		{
			last = mid - 1;
		}
		else
		{
			if (mid > maxs)
				maxs = mid;
			first = mid + 1;
		}
	}
	printf("%lld", maxs);
}