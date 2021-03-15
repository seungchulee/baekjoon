#include <stdio.h>
int arr[1001];
int find(int a)
{
	if (arr[a] == a)
		return a;
	else
		return arr[a] = find(arr[a]);
}
void Union(int a, int b)
{
	int aa = find(a);
	int bb = find(b);
	arr[aa] = bb;
}
int main(void)
{
	int T;
	scanf("%d", &T);
	for (int t = 0; t < T; t++)
	{
		int N, M;
		scanf("%d %d", &N, &M);
		for (int i = 1; i <= N; i++)
			arr[i] = i;
		int result = 0;
		for (int i = 0; i < M; i++)
		{
			int a, b;
			scanf("%d %d", &a, &b);
			if (find(a) != find(b))
			{
				result++;
				Union(a, b);
			}
		}
		printf("%d\n", result);
	}
}