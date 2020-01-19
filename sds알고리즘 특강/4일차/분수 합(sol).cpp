#include <stdio.h>
#include <math.h>
#include <algorithm>
using namespace std;
/*
	gcd(a,b)
		return b=0 ? a : gcd(b,a%b);
*/
int main(void)
{
	int a, b;
	int c, d;
	scanf("%d %d", &a, &b);
	scanf("%d %d", &c, &d);
	int ja = a*d + b*c;
	int mo = b*d;
	int gcd = 0;
	
	int left = max(ja, mo);
	int right = min(ja, mo);
	while (right != 0)
	{
		int re = left%right;
		left = right;
		right = re;
	}
	printf("%d %d", ja / left, mo / left);
}