#include <stdio.h>
#include <iostream>
#include <stdlib.h>
using namespace std;
int n;
int cnt=0;
void func(int f)
{
	if(f==1)
	{
		if(cnt+1==n)
		{
			cout << "m\n";
			exit(0);
		}
		else if(cnt+2==n || cnt+3==n)
		{
			cout << "o\n";
			exit(0);
		}	
		cnt+=3;
		return;
	}
	func(f-1);
	if(cnt+1==n)
	{
		cout << "m\n";
		exit(0);
	}

	cnt++;
	for(int i=0;i<=f;i++)
	{
		if(cnt+1==n)
		{
			cout << "o\n";
			exit(0);
		}
		cnt++;
	}
	func(f-1);
}
int main(void)
{
	cin >> n;
	func(30);
}
