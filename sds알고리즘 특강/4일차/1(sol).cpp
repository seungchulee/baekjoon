#include <stdio.h>
#include <iostream>
using namespace std;
int main(void)
{
	while (1)
	{
		char c[6];
		cin.getline(c, 6);
		if (cin.eof() == true)
			break;
		int num = atoi(c);
		int res = 1;
		int cnt = 1;
		if (num == 1)
		{
			printf("1\n");
			continue;
		}
		while (1)
		{
			res = (1 + res * 10) % num;
			cnt++;
			if (res == 0)
				break;
		}
		printf("%d\n", cnt);
	}
}