#include <stdio.h>
#include <cstring>
#include <math.h>
#include <vector>
using namespace std;
int N, M, K;
long long init(vector<long long> &arr, vector<long long> &tree, int node, int start, int end)
{
	if (start == end)
	{
		return tree[node] = arr[start];
	}
	else
	{
		return tree[node] = init(arr, tree, node * 2, start, (start + end) / 2) + init(arr, tree, node * 2 + 1, (start + end) / 2 + 1, end);
	}
}
void update(vector<long long> &tree, int node, int start, int end, int index, long long int diff)
{
	if (index<start || index>end)
		return;
	tree[node] = tree[node] + diff;
	if (start != end)
	{
		update(tree, node*2, start, (start + end) / 2, index, diff);
		update(tree, node*2+1 , (start + end) / 2 + 1, end, index, diff);
	}
}
long long int sum(vector<long long> &tree, int node, int start, int end, int left, int right)
{
	if (left>end || right<start)
	{
		return 0;
	}
	if (left <= start && end<=right)
		return tree[node];
	return sum(tree, node*2, start, (start + end) / 2, left, right) + sum(tree, node*2+1, (start + end) / 2 + 1,end, left, right);
}
int main(void)
{
	scanf("%d %d %d", &N,&M, &K);
	vector<long long> arr(N+1);
	int h = (int)ceil(log2(N));
	int tree_size = (1 << (h + 1));
	vector<long long> tree(tree_size);
	for (int i = 1;i <= N; i++)
	{
		scanf("%lld", &arr[i]);
	}
	init(arr, tree, 1, 1, N);

	for (int i = 0; i < M+K; i++)
	{
		int a;
		scanf("%d", &a);
		if (a == 1)
		{
			int b;
			long long int c;
			scanf("%d %lld", &b, &c);
			// update
			long long int diff = c - arr[b];
			arr[b] = c;
			update(tree, 1, 1, N, b, diff);
		}
		else
		{
			int b, c;
			scanf("%d %d", &b, &c);
			// sum
			long long int result = sum(tree,1,1,N,b,c);
			printf("%lld\n", result);

		}
	}
}