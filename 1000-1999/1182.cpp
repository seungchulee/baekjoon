#include <stdio.h>
#include <cstring>

int N,S;
int arr[21];
int check[21];
int cnt=0;
void func(int index,int sum)
{
	sum+=arr[index];
	if(index>=N)
		return;
	if(sum==S)
		cnt++;
	
	func(index+1,sum-arr[index]);
	func(index+1,sum);

/*	for(int i=0;i<N;i++)
	{
		sum+=arr[i];
		func(index+1,sum);
		sum-=arr[i];
	}
*/
}
int main(void)
{
	memset(check,0,sizeof(arr));
	scanf("%d %d",&N,&S);
	for(int i=0;i<N;i++)
	{
		scanf("%d",&arr[i]);
	}
	func(0,0);
	printf("%d",cnt);
}
