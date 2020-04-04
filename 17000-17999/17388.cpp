#include <iostream>
using namespace std;
int main(void)
{
	int s,k,h;
	cin >> s >> k >> h;
	int total = s+k+h;
	if(total>=100)
	{
		cout << "OK";
		return 0;
	}
	int mins = min(s,min(k,h));
	if(mins== s)
		cout << "Soongsil";
	else if(mins == k)
		cout << "Korea";
	else
		cout << "Hanyang";

}
