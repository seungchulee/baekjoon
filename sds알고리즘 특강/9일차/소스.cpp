#include <stdio.h>
#include <vector>
#include <cstring>
using namespace std;
int arr[201];
vector<int> vv;
int main(void)
{
	int n, m;
	scanf("%d %d",&n, &m);
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &arr[i]);
	}
	vv.push_back(arr[0]);
	for (int i = 1; i < n; i++)
	{
		if (arr[i] == vv[vv.size() - 1])
			continue;
		else
			vv.push_back(arr[i]);
	}
	int i = 0;
	int j = vv.size()-1;
	int cnt = 0;
	int tmp=-1;
	while (1)
	{
		if (i == j)
		{
			if (tmp == vv[i])
				cnt--;
			break;
		}
		if (vv[i] != vv[j])
		{
			if (vv[i] == tmp)
				cnt--;
			i++;
			cnt++;
		}
		else if (vv[i] == vv[j])
		{
			tmp = vv[i];
			i++;
			j--;
			cnt++;

		}
	}
	printf("%d", cnt);
	
}