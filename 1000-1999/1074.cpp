#include <stdio.h>
#include <iostream>
#include <stdlib.h>
using namespace std;
int n;
int r,c;
int cnt=0;
void func(int n, int x, int y)
{
	if(n==2)
	{
		for(int i=x;i<x+n;i++)
		{
			for(int j=y;j<y+n;j++)
			{
				cnt++;
				if(i==r && j==c)
				{
					cout << cnt-1;
					exit(0);
				}

			}
		}
		return;
	}

	func(n/2,x,y);
	func(n/2,x,y+n/2);
	func(n/2,x+n/2,y);
	func(n/2,x+n/2,y+n/2);

}
int main(void)
{
	cin >> n;
	cin >> r >> c;
	func(1<<n,0,0);

}

