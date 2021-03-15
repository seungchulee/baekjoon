#include <stdio.h>
#include <set>
using namespace std;
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
	for (int i = 1; i <= 1000; i++)
		arr[i] = i;
	int N, M;
	scanf("%d %d", &N, &M);
	for (int i = 0; i < M; i++)
	{
		int a, b;
		scanf("%d %d", &a, &b);
		Union(a, b);
	}
	set<int> ss;
	for (int i = 1; i <= N; i++)
		ss.insert(find(i));
	printf("%d", ss.size());
}