#include <iostream>

using namespace std;

const short MAX = 50 * 20;
const short value[4] = { 1 , 5, 10, 50 };

int n;
bool check[MAX + 1];
int result;

void func(int pos, int bound, int val)
{
	if (pos == n)
	{
		if (!check[val])
		{
			check[val] = true;
			++result;
		}
	}
	else
	{
		for (int i = bound; i < 4; i++)
		{
			func(pos + 1, i, val + value[i]);
		}
	}
}

int main()
{
	cin >> n;

	func(0, 0, 0);

	cout << result;

	return 0;
}
