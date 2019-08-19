#include <stdio.h>
int arr[10];
int N,M;
void func(int index, int select)
{
	if(select==M)
	{
		for(int i=0;i<M;i++)
			printf("%d ",arr[i]);
		printf("\n");
		return;
	}
	if(index>N)
		return;
	arr[select]=index;
	func(index+1,select+1);
	arr[select]=0;
	func(index+1,select);
}
int main(void)
{
	scanf("%d %d",&N,&M);
	func(1,0);
}
