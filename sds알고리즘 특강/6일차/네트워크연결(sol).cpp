#include <stdio.h>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;
int arr[1001];
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
	int N, M;
	for (int i = 1; i <= 1000; i++)
		arr[i] = i;
	scanf("%d", &N);
	scanf("%d", &M);
	for (int i = 0; i < M; i++)
	{
		int a, b, c;
		scanf("%d %d %d", &a, &b, &c);
		pair<int, pair<int, int> > pp;
		pp.first = c;
		pp.second.first = a;
		pp.second.second = b;	
		vv.push_back(pp);
	}
	set<int> ss;
	sort(vv.begin(), vv.end());
	int result = 0;
	for (int i = 0; i < M; i++)
	{
		if (find(vv[i].second.first) != find(vv[i].second.second))
		{
			ss.insert(vv[i].second.first);
			ss.insert(vv[i].second.second);
			Union(vv[i].second.first, vv[i].second.second);
			result += vv[i].first;
		}
	}
	printf("%d", result);
	
}