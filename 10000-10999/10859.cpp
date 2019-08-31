#include <stdio.h>
#include <math.h>
bool check(long long int N)
{
	if(N<2)
		return false;
	for(int i=2;i*i<=N;i++)
	{
		if(N%i==0)
			return false;
	}		
	return true;
}
long long int make(long long int N)
{

	int base=1;
	int arr[17];
	int i=0;
	while(N>0)
	{
		int a=N%10;
		if(a==3 || a==4 || a==7)
			return -1;
		if(a==6)
			a=9;
		else if(a==9)
			a=6;
		arr[i]=a;
		N/=10;
		i++;
	}
	long long int result=0;
	for(int j=0;j<i;j++)
	{
	//	printf("%d",arr[j]);
		
		result+=pow(10,i-j-1)*arr[j];
	}


	return result;
}
int main(void)
{
	long long int N;

	scanf("%lld",&N);
	long long int A=N;	
	bool result=true;


	bool result2=true;
	result2=check(A);

	
	long long int new_N=make(A);
	bool result3=true;
	if(new_N==-1)
		result3=false;
	else
		result3=check(new_N);


	if(result2==true && result3==true)
		printf("yes");
	else
		printf("no");
}
