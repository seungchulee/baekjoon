#include <stdio.h>
#include <set>
using namespace std;
int main(void)
{
	for (int i = 1;; i++)
	{
		bool end = false;
		int line = 0;
		set<int> node;
		bool possible = true;
		for (int j = 0;; j++)
		{
			int a, b;
			scanf("%d %d", &a, &b);
			if (a == 0 && b == 0)
			{
				if (line == 0 || node.size() == line + 1)
					possible = true;
				else
					possible = false;
				break;
			}
			if (a == -1 && b == -1)
			{
				end = true;
				break;
			}
			node.insert(a);
			node.insert(b);
			line++;
		}
		if (end == true)
			break;
		if (possible == false)
			printf("Case %d is not a tree.\n", i);
		else
			printf("Case %d is a tree.\n", i);

	}
}