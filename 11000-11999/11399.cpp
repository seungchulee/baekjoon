#include <stdio.h>
#include <algorithm>
using namespace std;
int main(void)
{
	int N;
	scanf("%d",&N);
	int arr[1000];
	for(int i=0;i<N;i++)
		scanf("%d",&arr[i]);
	sort(arr,arr+N);
	int result=arr[0];
	for(int i=1;i<N;i++)
	{
		arr[i]+=arr[i-1];	
		result+=arr[i];	
	}
	printf("%d",result);
		
}
