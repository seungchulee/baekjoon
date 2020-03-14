#include <stdio.h>
#include <cstring>
#include <iostream>
using namespace std;
int n;
long long int b;
int arr[6][6];
int base[6][6];
int c[6][6];
void get(int a[6][6],int b[6][6])
{
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			c[i][j]=0;
			for(int k=0;k<n;k++)
			{
				c[i][j]+=a[i][k]*b[k][j];
			}
			c[i][j]%=1000;
		}
	}
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
			a[i][j]=c[i][j];
}
int main(void)
{
	cin >> n >> b;	
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{

			cin >> arr[i][j];
		}
		base[i][i]=1;
	}

	while(b>0)
	{
		if(b%2==1)
		{
			get(base,arr);
		}
		get(arr,arr);
		b/=2;
	}

	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			printf("%d ",base[i][j]);
		}
		printf("\n");
	}

}
