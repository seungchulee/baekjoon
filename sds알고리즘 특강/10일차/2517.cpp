#include <stdio.h>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <vector>
using namespace std;
int arr[1 << 21];
int datas[505050];
int N;
int ans[500001];
vector<pair<int, int> > vv;
int sum(int start, int end, int left, int right, int idx)
{
	if (start == left && end == right)
		return arr[idx];
	int res = 0;
	
	int nstart = start;
	int nend = (start + end) / 2;
	if (left >= nstart && left <= nend)
	{
		res += sum(nstart, nend, left, min(right, nend), idx * 2);
	}

	nstart = (start + end) / 2 + 1;
	nend = end;
	if (right >= nstart && right <= nend)
	{
		res += sum(nstart, nend, max(left, nstart), right, idx * 2 + 1);
	}

	return res;
}
int main(void)
{
	memset(arr, 0, sizeof(arr));
	scanf("%d", &N);
	for (int i = 0; i < N; i++)
	{
		scanf("%d", &datas[i]);
		vv.push_back(make_pair(datas[i], i + 1));
	}
	int H = (int)log2(N - 1) + 1;
	int base = 1 << H;
	sort(vv.begin(), vv.end());
	for (int i = 0; i < vv.size(); i++)
	{
		int idx = vv[i].second;
		// first : find를 통해 구간합 구하기
		// idx 위치에 1로 change 후 update
		int summ = sum(1, base, 1, idx, 1);
		//printf("%d", summ);
		arr[base + idx - 1] = 1;
		int k = base + idx - 1;
		while (k > 1)
		{
			k /= 2;
			arr[k] = arr[k * 2] + arr[k * 2 + 1];
		}
		ans[idx] = idx - summ;
	}
	for (int i = 1; i <= N; i++)
		printf("%d\n", ans[i]);
}