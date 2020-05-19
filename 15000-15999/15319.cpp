#include <iostream>
#include <vector>
using namespace std;
int n;
long long int MOD = 1000000007;
int main(void)
{
	cin >> n;
	long long int ans = 0;
	while(n--)
	{
		int x;
		long long int k;
		cin >> x >> k;
		vector<int> vv;
		while(k>0)
		{
			if(k%2==1)
				vv.push_back(1);
			else
				vv.push_back(0);
			k/=2;
		}
		long long int result = 0;
		long long int base = 1;
		for(int i=0;i<vv.size();i++)
		{
			result += (base*vv[i])%MOD;
			result%=MOD;
			base*=x;
			base%=MOD;
		}
		ans += result;
		ans %= MOD;
	}
	cout << ans;
	
}
