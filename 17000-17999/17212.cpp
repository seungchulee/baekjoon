#include <iostream>
using namespace std;
int arr[101010];
int main(void)
{
	int n;
	cin >> n;
	arr[1]=1;
	arr[2]=1;
	arr[3]=2;
	arr[4]=2;
	arr[5]=1;
	arr[6]=2;
	arr[7]=1;
	for(int i=8;i<=101000;i++)
		arr[i]=min(arr[i-7],min(arr[i-5],min(arr[i-2],arr[i-1])))+1;
	cout << arr[n];
}
