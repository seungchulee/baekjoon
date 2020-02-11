#include <stdio.h>
#include <queue>
using namespace std;
int a,b;
int main(void)
{
	scanf("%d %d",&a,&b);
	int cn=0;
	while(1)
	{
		if(b==a)
		{
			printf("%d",cn+1);
			break;
		}
		if(b<a)
		{
			printf("-1");
			break;
		}

		if(b%10==1)
		{
			cn++;
			b/=10;
		}
		else if(b%2==0)
		{
			cn++;
			b/=2;
		}
		else
		{
			printf("-1");
			break;
		}
		
	}
}
