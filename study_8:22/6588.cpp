#include <stdio.h>
#include <string.h>
bool isPrime[1000001];
int pn=0;
void make_prime()
{


	for(int i=0;i<=1000000;i++)
	{
		isPrime[i]=false;
	}
	isPrime[0]=true;
	isPrime[1]=true;
	for(int i=2;i<=1000000;i++)
	{
		for(int j=i*2;j<=1000000;j+=i)
			isPrime[j]=true;
				
	}
}
void gold_bach(int n)
{
	
	for(int i=0,j=n;i<=1000;i++,j--)
	{
		if(isPrime[i]==false && isPrime[j]==false && i%2==1 && j%2==1)
		{
			printf("%d = %d + %d\n",n,i,j);
			return;
		}
		
	}
	printf("Goldbach's conjecture is wrong.\n");
}
int main(void)
{

	make_prime();	

	while(1)
	{
		int n;
		scanf("%d",&n);

		if(n==0)
			break;
		gold_bach(n);
	}
}


