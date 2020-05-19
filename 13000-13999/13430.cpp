#include <iostream>
#include <vector>
using namespace std;
long long int MOD = 1000000007;
typedef vector<vector<long long> > matrix;
long long int n,k;
matrix operator * (const matrix &a, const matrix &b)
{
	matrix c(k+3,vector<long long>(k+3));
	
	for(int i=0;i<k+2;i++)
	{
		for(int j=0;j<k+2;j++)
		{
			for(int l=0;l<k+2;l++)
			{
				c[i][j] += a[i][l]*b[l][j];
				c[i][j]%=MOD;
			}
		}

	}
	return c;
}
int main(void)
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	cin >> k >> n;
	if(n==1)
	{
		cout << 1;
		return 0;
	}
	matrix vv;
	vv.resize(k+3);
	for(int i=0;i<k+2;i++)
	{
		for(int j=0;j<k+2;j++)
		{
			if(j<=i)
				vv[i].push_back(1);
			else
				vv[i].push_back(0);
		}
	}
	matrix ans;
	ans.resize(k+3);
	for(int i=0;i<k+2;i++)
	{
		for(int j=0;j<k+2;j++)
		{
			if(i==j)
				ans[i].push_back(1);
			else
				ans[i].push_back(0);
		}
	}
	while(n>0)
	{
		if(n%2==1)
			ans = ans * vv;
		vv = vv*vv;
		n/=2;
	}
	cout << ans[k+1][0];

}
