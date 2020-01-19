#include <stdio.h>
#include <stack>
#include <string.h>
#include <iostream>
using namespace std;
int N;
stack<int> ss;
void TOKEN(char st[])
{
	char del[] = " ";
	char* token = strtok(st, del);
	int cnt = 0;
	while (token != NULL)
	{

		if (strcmp(token, "size") == 0)
		{
			printf("%d\n", ss.size());
		}
		else if (strcmp(token, "top") == 0)
		{
			if (ss.size() == 0)
				printf("-1\n");
			else
				printf("%d\n", ss.top());
		}
		else if (strcmp(token, "empty") == 0)
		{
			if (ss.size() == 0)
				printf("1\n");
			else
				printf("0\n");
		}
		else if (strcmp(token, "pop") == 0)
		{
			if (ss.size() == 0)
				printf("-1\n");
			else
			{
				int sss = ss.top();
				ss.pop();
				printf("%d\n", sss);
			}
		}
		else
		{

			if (cnt == 1)
			{
				int num = 0;
				num = atoi(token);
				ss.push(num);
			}
			cnt++;
		}
		token = strtok(NULL, " ");
	}
}
int main(void)
{
	scanf("%d", &N);
	getchar();
	for (int i = 0; i < N; i++)
	{
		char str[1000];
		cin.getline(str, 1000);
		TOKEN(str);
		
	}
}