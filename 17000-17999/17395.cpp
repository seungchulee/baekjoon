#include <iostream>
#include <vector>
using namespace std;

int main(void)
{
	long long int m,n;
	cin >> m >> n;
	vector<long long int> vv;
	n--;
	for(int i=60;i>=0;i--)
	{
		if(m&(1ll<<i))
		{
			m^=(1ll<<i);
			vv.push_back(m);
			n--;
		}
		if(n==0)
			break;
	}
	if(n>0)
		cout << -1;
	else
	{
		for(int i=0;i<vv.size();i++)
			cout << vv[i] << " " ;
		cout << 0;
	}

}
