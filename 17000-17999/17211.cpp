#include <iostream>
using namespace std;
double good[101];
double bad[101];
int main(void)
{
	int n, g;
	cin >> n >> g;
	double gg, gb, bg, bb;
	cin >> gg >> gb >> bg >> bb;
	
	if(g==0)
	{
		good[0]=gg;
		bad[0]=gb;
		for(int i=1;i<n;i++)
		{
			good[i]=bad[i-1]*bg + good[i-1]*gg;
			bad[i]=bad[i-1]*bb + good[i-1]*gb;
		}
	}
	else
	{
		good[0]=bg;
		bad[0]=bb;
		for(int i=1;i<n;i++)
		{
			good[i]=bad[i-1]*bg + good[i-1]*gg;
			bad[i]=bad[i-1]*bb + good[i-1]*gb;
		}
	}
	printf("%.0f\n",good[n-1]*1000);
	printf("%.0f",bad[n-1]*1000);
//	printf("%d",good[n]*1000);
}
