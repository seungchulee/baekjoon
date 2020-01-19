#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;
vector<pair<int, pair<int, int> > > vv;
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
	int N, M;
	for (int i = 0; i < 1001; i++)
		arr[i] = i;
	scanf("%d %d", &N, &M);

	for (int i = 0; i < M + 1; i++) {
		int a, b, c;
		scanf("%d %d %d", &a, &b, &c);
		if (c == 1)
			c = 0;
		else
			c = 1;
		vv.push_back(make_pair(c, make_pair(a, b)));
	}
	Union(0, 1);
	sort(vv.begin(), vv.end());
	int result = 0;
	for (int i = 0; i < vv.size(); i++)
	{
		pair<int, pair<int, int> > pp;
		pp = vv[i];
		int cost = pp.first;
		int from = pp.second.first;
		int to = pp.second.second;
		if (from == 0)
		{
			result += cost;
			continue;
		}
		if (find(from) != find(to))
		{
			result += cost;
			Union(from, to);
		}
	}

	for (int i = 0; i < 1001; i++)
		arr[i] = i;

	Union(0, 1);
	int result2 = 0;
	for (int i = vv.size()-1; i >=0; i--)
	{
		pair<int, pair<int, int> > pp;
		pp = vv[i];
		int cost = pp.first;
		int from = pp.second.first;
		int to = pp.second.second;
		if (from == 0)
		{
			result2 += cost;
			continue;
		}
		if (find(from) != find(to))
		{
			result2 += cost;
			Union(from, to);
		}
	}
	printf("%d", result2*result2 - result*result);
}