#include <stdio.h>
#include <algorithm>
#include <cmath>
#include <iostream>
using namespace std;
int n;
double x[10101];
double y[10101];
int main(void)
{
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		cin >> x[i] >> y[i];
	}
	x[n]=x[0];
	y[n]=y[0];
	long double res=0;
	for(int i=0;i<n;i++)
	{
		res+=((x[i]*y[i+1])/2-(x[i+1]*y[i])/2);


	}
	printf("%.1Lf",fabs(res));

}
