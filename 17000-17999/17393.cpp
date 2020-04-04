#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int n;
long long int arr[501010];
vector<long long int> vv;
int main(void)
{
	cin >> n;
	for(int i=0;i<n;i++)
		cin >> arr[i];
	for(int i=0;i<n;i++)
	{
		long long int x;
		cin >> x;
		vv.push_back(x);
	}
	for(int i=0;i<n;i++)
	{
		long long int target = arr[i];
		int idx = upper_bound(vv.begin(),vv.end(),target)-vv.begin();
		idx--;
		if(idx<=i)
			cout << 0 << ' ';
		else
			cout << idx - i << ' ';

	}
}
