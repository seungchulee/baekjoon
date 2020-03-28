#include <iostream>
using namespace std;
int arr[4000];
int main(void)
{
	int n,t;
	cin >> n >> t;
	for(int i=0;i<2*n;i++)
		arr[i]=i+1;
	int m = 2*n-1;
	for(int i=2*n;i<4*n-2;i++)
		arr[i]=m--;

	int x = 4*n-2;
	t = (t-1)%x;

	cout << arr[t];
}
