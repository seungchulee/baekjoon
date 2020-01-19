#include <stdio.h>
#include <cmath>
#include <algorithm>
using namespace std;
long int arr[1 << 21];
int find(int start, int end, int left, int right, int idx)
{
	if (start == left && end == right)
		return arr[idx];
	int ns = start;
	int ne = (start + end) / 2;
	int res = 1000000001;
	if (left >= ns && left <= ne)
		res = min(res,find(ns, ne, left,min(right,ne), 2 * idx));
	ns = (start + end) / 2 + 1;
	ne = end;
	if (right >= ns && right <= ne)
		res = min(res, find(ns, ne, max(left,ns),right, 2 * idx + 1));

	return res;
}
int main(void)
{
	int N, M;
	scanf("%d %d", &N, &M);
	int H = (int)log2(N - 1) + 1;
	int base = 1 << H;
	for (int i = 1; i < 2 * base; i++)
		arr[i] = 1000000001;
	for (int i = base; i < base + N; i++)
		scanf("%d", &arr[i]);
	for (int i = base - 1; i >= 1; i--)
	{
		arr[i] = min(arr[i * 2], arr[i * 2 + 1]);
	}
	for (int i = 0; i < M; i++)
	{
		int a, b;
		scanf("%d %d", &a, &b);
		printf("%d\n", find(1, base, a, b, 1));
	}
}