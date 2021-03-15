#include <stdio.h>
#include <algorithm>
#include <cstring>
#include <limits.h>
using namespace std;
int arr[5];
int brr[5];
int crr[5];
int drr[5];
int min3(int a, int b, int c)
{
	int mins = min(a, b);
	mins = min(mins, c);
	return mins;
}
int max3(int a, int b, int c)
{
	int maxs = max(a, b);
	maxs = max(maxs, c);
	return maxs;
}
int main(void)
{
	int N;
	scanf("%d", &N);
	memset(brr, 0, sizeof(brr));
	memset(crr, 0, sizeof(crr));
	memset(drr, 100, sizeof(drr));
	for (int i = 1; i <= 3; i++)
	{
		scanf("%d", &arr[i]);
		drr[i] = arr[i];
	}
	for (int i = 1; i <= 3; i++)
	{
		brr[i] = max3(arr[i - 1], arr[i], arr[i + 1]);
		crr[i] = min3(drr[i - 1], drr[i], drr[i + 1]);
	}
	for (int i = 1; i < N; i++)
	{
		for (int j = 1; j <= 3; j++)
		{
			scanf("%d", &arr[j]);
			drr[j] = arr[j];
		}
		for (int j = 1; j <= 3; j++)
		{
			arr[j] += brr[j];
			drr[j] += crr[j];
		}
		for (int j = 1; j <= 3; j++)
		{
			brr[j] = max3(arr[j - 1], arr[j], arr[j + 1]);
			crr[j] = min3(drr[j - 1], drr[j], drr[j + 1]);
		}
	}
	int maxx = -1;
	int minn = INT_MAX;
	for (int i = 1; i <= 3; i++)
	{
		if (arr[i] > maxx)
			maxx = arr[i];
		if (drr[i] < minn)
			minn = drr[i];
	}
	printf("%d %d", maxx, minn);
}

