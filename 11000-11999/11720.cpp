#include <stdio.h>
#include <stdlib.h>
int main(void)
{
	char *num;
	int len;

	scanf("%d",&len);
	getchar();
	num=(char*)malloc(sizeof(char)*(len));
	for(int i=0;i<len;i++)
	{
		scanf("%c",&num[i]);
	}
	num[len+1]='\0';
	int result=0;
	for(int i=0;i<len;i++)
	{

		result+=num[i]-'0';
	}
	printf("%d",result);


}


