#include <iostream>
using namespace std;
int arr[3][10101];
int main(void)
{
	int n;
	cin >> n;
	arr[0][0] = 2*n;
	arr[0][n-1] = 2*n-1;
	arr[1][n-1] = 2*n-3;
	arr[1][0] = 2*n-2;
	if(n==1)
	{
		printf("2\n1\n2");
		return 0;
	}
	int idx = 2*n-4;
	for(int i=n-2;i>=1;i--)
	{
		arr[1][i] = idx;
		idx--;
	}
	for(int i=n-2;i>=1;i--)
	{
		arr[0][i] = idx;
		idx--;
	}
	long long int total = 0;
	for(int i=0;i<2;i++)
	{
		for(int j=0;j<n;j++)
		{
			total+=arr[i][j];
		}
	}
	total -= arr[1][n-1];
	long long int res = 0;
	res+=total;
	int t=2;
	for(int i=n-2;i>=0;i--)
	{
		total-=arr[1][i];
		res+=total*t;
		t++;
	}
	for(int i=n-1;i>=0;i--)
	{
		total-=arr[0][i];
		res+=total*t;
		t++;
	}
	cout << res << '\n';

	for(int i=0;i<2;i++)
	{
		for(int j=0;j<n;j++)
		{
			printf("%d ",arr[i][j]);
		}
		printf("\n");
	}
}
