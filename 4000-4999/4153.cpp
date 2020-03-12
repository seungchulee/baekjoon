#include <stdio.h>
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
int main(void)
{
	while(1)
	{	
		int a,b,c;
		cin >> a >> b >> c;
		vector<int> vv;
		vv.push_back(a);vv.push_back(b);vv.push_back(c);
		sort(vv.begin(),vv.end());
		c = vv[2];
		a = vv[0];
		b = vv[1];
		if(a==0 && b==0 && c==0)
			break;
		if(a*a+b*b==c*c)
			printf("right\n");
		else
			printf("wrong\n");
	}


}
