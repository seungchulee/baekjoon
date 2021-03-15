#include <stdio.h>
#include <cstring>
#include <cmath>
#include <algorithm>
using namespace std;
int N, M;
long long int arr[4040404];
long long int find(int start, int end, int left, int right, int idx)
{
	if (left == start && right == end)
		return arr[idx];
	int nstart = start;
	int nend = (start + end) / 2;
	long long int res = 0;
	if (left >= nstart && left <= nend)
		res += find(nstart, nend, left, min(right, nend), idx * 2);
	nstart = (start + end) / 2 + 1;
	nend = end;
	if (right >= nstart && right <= nend)
		res += find(nstart, nend, max(left, nstart), right, idx * 2 + 1);

	return res;
}
int main(void)
{
	scanf("%d %d", &N, &M);
	memset(arr, 0, sizeof(arr));
	int H = (int)log2(N - 1) + 1;
	int base = 1 << H;
	for (int i = 0; i < M; i++)
	{
		int a, b, c;
		scanf("%d %d %d", &a, &b, &c);
		if (a == 0)
		{
			// sum
			if (b > c)
				swap(b, c);
			long long int summ = find(1, base, b, c, 1);
			printf("%lld\n", summ);
		}
		else
		{
			arr[base + b - 1] = c;
			int k = base + b - 1;
			while (k > 1)
			{
				k /= 2;
				arr[k] = arr[k * 2] + arr[k * 2 + 1];
			}
		}
	}
}