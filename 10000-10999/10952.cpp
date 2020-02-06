#include <stdio.h>
int main(void)
{
	while(1)
	{
		int a,b;
		scanf("%d %d",&a,&b);
		if(a==0 && b==0)
			break;
		printf("%d\n",a+b);
	}	
}
