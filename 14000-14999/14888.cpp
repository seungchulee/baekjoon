#include <stdio.h>
#include <limits.h>
#include <algorithm>
using namespace std;
int N;
int arr[12];
int operand[4];
int maxs=INT_MIN;
int mins=INT_MAX;
void func(int sum,int plus,int minus, int multiply, int divide,int index)
{
	if(index==N)
	{
		maxs=max(maxs,sum);
		mins=min(mins,sum);
	}

	if(plus>0)
	{
		func(sum+arr[index],plus-1,minus,multiply,divide,index+1);
	}
	if(minus>0)
	{
		func(sum-arr[index],plus,minus-1,multiply,divide,index+1);
	}
	if(multiply>0)
	{
		func(sum*arr[index],plus,minus,multiply-1,divide,index+1);
	}
	if(divide>0)
	{
		func(sum/arr[index],plus,minus,multiply,divide-1,index+1);
	}
}
int main(void)
{
	scanf("%d",&N);
	for(int i=0;i<N;i++)
		scanf("%d",&arr[i]);

	for(int i=0;i<4;i++)
		scanf("%d",&operand[i]);

	int sum=0;
	func(arr[0],operand[0],operand[1],operand[2],operand[3],1);
	printf("%d\n%d",maxs,mins);	
}
