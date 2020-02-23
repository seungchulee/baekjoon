#include <iostream>
using namespace std;
int main(void)
{
	int x1,y1,x2,y2,x3,y3;
	cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;
	int tmp = x1*y2 + x2*y3 + x3*y1;
	tmp=tmp-y1*x2-y2*x3-y3*x1;
	if(tmp>0)
		printf("1");
	else if(tmp<0)
		printf("-1");
	else
		printf("0");
}
