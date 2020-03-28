#include <iostream>
#include <cmath>
using namespace std;
int main(void)
{
	int a,b;
	cin >> a >> b;
	int x = -a+(int)sqrt(a*a-b);
	int y = -a-(int)sqrt(a*a-b);

	if(x==y)
		cout << x;
	else
		cout << min(x,y) << " " << max(x,y);
}
