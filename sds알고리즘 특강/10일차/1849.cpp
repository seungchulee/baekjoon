#include <stdio.h>
#include <cmath>
#include <algorithm>
#include <cstring>
using namespace std;
int arr[404040];
int brr[404040];
int crr[101010];
int find(int start, int end, int idx, int gaesu)
{
	if (start == end)
		return start;
	else
	{
		if (gaesu < arr[idx * 2])
			return find(start, (start + end) / 2, idx * 2, gaesu);
		else
			return find((start + end) / 2 + 1, end, idx * 2 + 1, gaesu - arr[idx * 2]);
	}


}
int main(void)
{
	int N;
	scanf("%d", &N);
	int H = (int)log2(N - 1) + 1;
	int base = 1 << H;
	for (int i = 1; i < 2 * base; i++)
		arr[i] = 0;
	for (int i = 0; i < N; i++)
	{
		scanf("%d", &brr[i]);
		arr[i + base] = 1;
	}

	for (int i = base - 1; i >= 1; i--)
	{
		arr[i] = arr[i * 2] + arr[i * 2 + 1];
	}

	memset(crr,0,sizeof(crr));
	for (int i = 0; i < N; i++)
	{
		int gaesu = brr[i];
		int wheres = find(1, base,1, gaesu);

		arr[base + wheres-1] = 0;
		
		int k = base + wheres - 1;
		while (k>1)
		{
			k /= 2;
			arr[k] = arr[k * 2] + arr[k * 2 + 1];
		}
		crr[wheres] = i + 1;

	}
	for (int i = 1; i <= N; i++)
		printf("%d\n", crr[i]);

	

}