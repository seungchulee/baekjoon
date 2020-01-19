#include <stdio.h>
#include <algorithm>
#include <vector>
using namespace std;
int T;
long int arr[1001];
long int brr[1001];
int n, m;
long int sample = 1000000001;
int main(void)
{
	scanf("%d", &T);
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		scanf("%d", &arr[i]);
	scanf("%d", &m);
	for (int i = 0; i < m; i++)
		scanf("%d", &brr[i]);

	long int sum = 0;
	vector<int> vv;
	for (int a = 0; a < n; a++)
	{
		sum = 0;
		for (int b = a; b < n; b++)
		{
			sum += arr[b];
			vv.push_back(sum);
		}
	}
	vector<int> vvv;
	for (int a = 0; a < m; a++)
	{
		sum = 0;
		for (int b = a; b < m; b++)
		{
			sum += brr[b];
			vvv.push_back(sum);
		}
	}
	long int result = 0;
	sort(vv.begin(), vv.end());
	sort(vvv.begin(), vvv.end());
	int vs = vv.size();
	int vvs = vvv.size();
	for (int i = 0; i < vs; i++)
	{
		int target = T - vv[i];
		auto first = lower_bound(vvv.begin(), vvv.end(), target);
		auto last = upper_bound(vvv.begin(), vvv.end(), target);
		result += last - first;
	
	}
	printf("%ld", result);


}