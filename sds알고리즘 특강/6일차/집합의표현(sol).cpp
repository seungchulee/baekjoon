#include <stdio.h>
int arr[1000001];
void init()
{
	for (int i = 0; i < 1000001; i++)
		arr[i] = i;
}
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
	int n, m;
	scanf("%d %d", &n, &m);
	init();
	for (int i = 0; i < m; i++)
	{
		int t, a, b;
		scanf("%d %d %d", &t, &a, &b);
		if (t == 0)
		{
			Union(a, b);
		}
		else
		{
			int aa = find(a);
			int bb = find(b);
			if (aa == bb)
				printf("YES\n");
			else
				printf("NO\n");
		}
	}
}