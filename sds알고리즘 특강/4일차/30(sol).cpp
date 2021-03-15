#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;
int main(void)
{
	int N;
	char arr[10001];
	scanf("%s", arr);
	int sum = 0;
	bool count = true;
	for (int i = 0; i < strlen(arr); i++)
	{
		if (arr[i] == '0')
			count = false;
		sum += arr[i] - '0';
	}

	if (sum % 3 != 0 || count==true)
	{
		printf("-1");
		return 0;
	}
	sort(arr, arr + strlen(arr));
	for (int i = strlen(arr)-1; i >=0; i--)
	{
		printf("%c", arr[i]);
	}
}