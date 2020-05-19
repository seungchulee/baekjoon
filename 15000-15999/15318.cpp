#include <iostream>
using namespace std;
long long int arr[303030];
long long int brr[303030];
int main(void)
{
	int n;
	cin >> n;
	for(int i=0;i<n;i++)
		cin >> arr[i];
	
	long long int b_zero=0;
	long long int start = 1;
	for(int i=0;i<n;i++)
	{
		if(i%2==0)
			b_zero += start*arr[i];
		else
			b_zero -= start*arr[i];
		start++;
	}
	long long int T = 0;
	for(int i=0;i<n;i++)
	{
		if(i%2==0)
			T+=arr[i];
		else
			T-=arr[i];
	}
	brr[0]=b_zero;
	if(n%2==0)
	{
		for(int i=1;i<n;i++)
		{
			if(i%2==1)
				brr[i]=T-brr[i-1];
			else
				brr[i]=-T-brr[i-1];
			brr[i]-=n*arr[(i-1)%n];
		}
	}
	else
	{
		brr[1]=T+n*arr[0]-brr[0];
		for(int i=2;i<n;i++)
		{
			T=-T+2*arr[(i-2)%n];
			brr[i]=T-brr[i-1];
			brr[i]+=n*arr[(i-1)%n];
		}
	}	
	for(int i=0;i<n;i++)
		printf("%lld ",brr[i]);

	
}
