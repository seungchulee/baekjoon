#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;
int arr[11111];
vector<pair<int, pair<int, int> > > vv;
int find(int a)
{
	if (arr[a] == a)
		return arr[a];
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
	for (int i = 0; i <= 10000; i++)
		arr[i] = i;
	int V, E;
	scanf("%d %d", &V, &E);
	for (int i = 0; i < E; i++)
	{
		int a, b, c;
		scanf("%d %d %d", &a, &b, &c);
		pair<int, pair<int, int> > pp;
		pp.first = c;
		pp.second.first = a;
		pp.second.second = b;
		vv.push_back(pp);
	}
	sort(vv.begin(), vv.end());
	long int result = 0;
	for (int i = 0; i < E; i++)
	{
		int a, b, c;
		a = vv[i].first;
		b = vv[i].second.first;
		c = vv[i].second.second;
		if (find(b) != find(c))
		{
			result += a;
			Union(b, c);
		}
	}
	printf("%ld", result);
}