#include <iostream>
using namespace std;
long long int arr[1010];
int main(void)
{
	long long int n,m;
	cin >> n >> m;
	long long int summ=0;
	for(int i=0;i<n;i++)
	{
		cin >> arr[i];
		summ+=arr[i];
		summ+=1;
	}

	if(m-summ <= 0)
	{
		cout << "0";
		return 0;
	}
	int rest = m-summ;
	long long int r = rest/(n+1);
	long long int data = (n+1)*(r*(r+1)*(2*r+1)/6);
	data += (r+1)*(r+1)*(rest%(n+1));
	cout << data;

}
