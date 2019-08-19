#include <stdio.h>
int N;
bool arr[1001]={false};
int result=0;
int sum=0;
int ar[4]={1,5,10,50};
void func(int index,int start,int sum)
{
	
	if(index==N)
	{
		if(arr[sum]==false)
		{
			arr[sum]=true;
			result++;
		}
		return;
	}

	for(int i=start;i<4;i++)
	{
		func(index+1,i,sum+ar[i]);
	}
	
}
int main(void)
{
	scanf("%d",&N);
	func(0,0,sum);
	
	printf("%d",result);
}
