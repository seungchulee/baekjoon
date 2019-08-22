#include <stdio.h>
#include <algorithm>
using namespace std;
int N,S;
int finds[100000];
int GCD(int a, int b)
{
	if(b==0)
		return a;
	else
		return GCD(b,a%b);
}
int main(void)
{
	scanf("%d %d",&N,&S);
	for(int i=0;i<N;i++)
	{
		scanf("%d",&finds[i]);
	}
	for(int i=0;i<N;i++)
	{
		finds[i]=abs(finds[i]-S);

	}
	int a=finds[0];
	int b=finds[1];
	if(a<b)
		swap(a,b);
	int gcd=GCD(a,b);
	int new_gcd=0;
	for(int i=2;i<N;i++)
	{
		if(gcd<finds[i])
			swap(gcd,finds[i]);
		gcd=GCD(gcd,finds[i]);
	}
	printf("%d",gcd);
	
}
