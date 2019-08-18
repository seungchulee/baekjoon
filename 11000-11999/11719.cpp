#include <stdio.h>
int main(void)
{
	char ch[101];
	while(fgets(ch,101,stdin))
	{
		printf("%s",ch);
	}
}
