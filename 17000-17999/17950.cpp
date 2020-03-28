#include <iostream>
using namespace std;
int main(void)
{
	long long int mod = 1000000007;
	int h, x;
	cin >> h >> x;
	long long int res=0;
	long long int f = 1;
	while(h--)
	{
		f*=x;
		f%=mod;
		long long int y;
		cin >> y;
		res+=y*f;
		res%=mod;
	}
	cout << res;
}
