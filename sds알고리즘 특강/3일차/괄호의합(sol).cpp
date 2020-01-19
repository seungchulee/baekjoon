#include <stdio.h>
#include <string.h>
#include <stack>
using namespace std;
int main(void)
{
	char st[32];
	scanf("%s", st);
	stack<char> ss;
	long int result = 0;
	int tmp = 1;
	bool check = true;
	for (int i = 0; i < strlen(st); i++)
	{
		//printf("%d", ss.size());
		if (st[i] == '(')
		{
			ss.push('(');
			tmp *= 2;
		}
		else if (st[i] == '[')
		{  
			ss.push('[');
			tmp *= 3;
		}
		else if (st[i] == ')' && (ss.empty() || ss.top() != '(' ))
		{
			check = false;
			break;
		}
		else if (st[i] == ']' && (ss.empty() || ss.top() != '['))
		{
			check = false; 
			break;
		}
		else if (st[i] == ')')
		{
			if (st[i - 1] == '(')
				result += tmp;
			tmp /= 2;
			ss.pop();
		}
		else if (st[i] == ']')
		{
			if (st[i - 1] == '[')
				result += tmp;
			tmp /= 3;
			ss.pop();
		}
		
		//printf("rs : %d %d\n", tmp,result);
	}
	if (check == false || !ss.empty())
		printf("0");
	else
		printf("%ld", result);
}