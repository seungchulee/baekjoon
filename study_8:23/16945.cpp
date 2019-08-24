#include <stdio.h>
#include <algorithm>
using namespace std;
int main(void)
{
	int m0[9]={8,1,6,3,5,7,4,9,2};	
	int m1[9]={4,9,2,3,5,7,8,1,6};
	int m2[9]={6,1,8,7,5,3,2,9,4};
	int m3[9]={2,9,4,7,5,3,6,1,8};
	int m4[9]={4,3,8,9,5,1,2,7,6};
	int m5[9]={8,3,4,1,5,9,6,7,2};
	int m6[9]={2,7,6,9,5,1,4,3,8};
	int m7[9]={6,7,2,1,5,9,8,3,4};
	int arr[9];
	for(int i=0;i<9;i++)
		scanf("%d",&arr[i]);

	int result=1000000;
	int tmp=0;
	for(int i=0;i<9;i++)
		tmp+=abs(arr[i]-m0[i]);
	result=min(result,tmp);
	tmp=0;
	for(int i=0;i<9;i++)
		tmp+=abs(arr[i]-m1[i]);
	result=min(result,tmp);
	tmp=0;
	for(int i=0;i<9;i++)
		tmp+=abs(arr[i]-m2[i]);
	result=min(result,tmp);
	tmp=0;
	for(int i=0;i<9;i++)
		tmp+=abs(arr[i]-m3[i]);
	result=min(result,tmp);
	tmp=0;
	for(int i=0;i<9;i++)
		tmp+=abs(arr[i]-m4[i]);
	result=min(result,tmp);
	tmp=0;
	for(int i=0;i<9;i++)
		tmp+=abs(arr[i]-m5[i]);
	result=min(result,tmp);
	tmp=0;
	for(int i=0;i<9;i++)
		tmp+=abs(arr[i]-m6[i]);
	result=min(result,tmp);
	tmp=0;
	for(int i=0;i<9;i++)
		tmp+=abs(arr[i]-m7[i]);
	result=min(result,tmp);

	
	printf("%d",result);
}	
