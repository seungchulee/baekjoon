#include <iostream>
#include <algorithm>
using namespace std;
int arr[303030];
int res[303030];
int main(void)
{
	cin.tie(NULL);
	std::ios::sync_with_stdio(false);
	int n,q;
	cin >> n >> q;
	for(int i=1;i<=n;i++)
		cin >> arr[i];

	sort(arr+1,arr+n+1);
	arr[0]=0;	
	for(int i=1;i<=n;i++)
		res[i]=res[i-1]+arr[i];
	
	while(q--)
	{
		int x,y;
		cin >> x >> y;
		cout << res[y] - res[x-1] << '\n';
	}
}
