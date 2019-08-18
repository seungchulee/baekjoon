#include <stdio.h>
int main(void)
{
	char ch[101];

	while(scanf("%[^\n]\n",ch)==1)
	{
		printf("%s\n",ch);
	}
}
