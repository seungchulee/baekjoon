#include <stdio.h>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;
vector<pair<int, pair<int, int> > > vv;
vector<pair<int, int> > vv2;
int arr[2020202];
bool comp(const pair<int, pair<int, int> > &p1, const pair<int, pair<int, int> > &p2)
{
	return p1.second.first < p2.second.first;
}
long long int find(int start, int end, int left, int right, int idx)
{
	if (left == start && right == end)
		return arr[idx];
	
	int nstart = start;
	int nend = (start + end) / 2;
	long long int summ = 0;
	if (left >= nstart && left <= nend)
		summ += find(nstart, nend, left, min(right, nend), idx * 2);

	nstart = (start + end) / 2 + 1;
	nend = end;
	if (right >= nstart && right <= nend)
		summ += find(nstart, nend, max(left, nstart), right, idx * 2 + 1);

	return summ;

}
int main(void)
{
	int N;
	scanf("%d", &N);
	for (int i = 1; i <= N; i++)
	{
		int a;
		scanf("%d", &a);
		vv.push_back(make_pair(a,make_pair(i,0)));
	}
	for (int i = 1; i <= N; i++)
	{
		int a;
		scanf("%d", &a);
		vv2.push_back(make_pair(a, i));
	}
	sort(vv.begin(), vv.end());
	sort(vv2.begin(), vv2.end());

	for (int i = 0; i < vv.size(); i++)
	{
		vv[i].second.second = vv2[i].second;
	}
	sort(vv.begin(), vv.end(), comp);
	/*for (int i = 0; i < vv.size(); i++)
		printf("%d ", vv[i].first);
	printf("\n");
	for (int i = 0; i < vv.size(); i++)
		printf("%d ", vv[i].second.second);*/

	int H = (int)log2(N - 1) + 1;
	int base = 1 << H;
	for (int i = 1; i < 2 * base; i++)
		arr[i] = 0;

	long long int res = 0;
	for (int i = 0; i < vv.size(); i++)
	{
		long long int cnt = find(1, base, vv[i].second.second, N, 1);

		res += cnt;
		int k = base + vv[i].second.second - 1;
		arr[k] = 1;
		while (k > 1)
		{
			k /= 2;
			arr[k] = arr[k * 2] + arr[k * 2 + 1];
		}
	}
	printf("%lld", res);


}