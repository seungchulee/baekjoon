#include <iostream>
using namespace std;
int main(void)
{
	long long int n;
	int dir;
	cin >> n >> dir;
	long long int idx=2;
	
	if(n>=6)
		cout << "Love is open door";
	else
	{
		while(1)
		{
			if(idx==n+1)
				break;
			cout << (dir+1)%2 << '\n';
			dir++;
			idx++;
		}
	}
}	
