#include <stdio.h>
#include <vector>
using namespace std;
int n,k;
long int arr[1010101];
int main(void)
{
	int t;
	scanf("%d",&t);
	arr[1]=1;
	arr[2]=2;
	arr[3]=4;
	for(int i=4;i<=1010100;i++)
		arr[i]=(arr[i-1]+arr[i-2]+arr[i-3])%1000000009;
	for(int i=0;i<t;i++)
	{
		int N;
		scanf("%d",&N);
		printf("%ld\n",arr[N]);
	}
}
