#include <stdio.h>
#include <algorithm>
using namespace std;
int binary_sh(int arr[], int first, int second,int target)
{
	while (first <= second)
	{
		int mid = (first + second) / 2;
		if (arr[mid] == target)
			return 1;
		else if (arr[mid] < target)
		{
			first = mid + 1;
		}
		else
		{
			second = mid - 1;
		}
	}
	return 0;
}
int main(void)
{
	int N, M;
	int arr[100001];

	scanf("%d", &N);
	for (int i = 0; i < N; i++)
	{
		scanf("%d", &arr[i]);
	}
	sort(arr, arr + N);
	scanf("%d", &M);
	for (int i = 0; i < M; i++)
	{
		int ss;
		scanf("%d", &ss);
		printf("%d\n", binary_sh(arr, 0, N,ss));
	}

}