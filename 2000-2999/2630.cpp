#include <stdio.h>
#include <algorithm>
#include <iostream>
using namespace std;
int arr[129][129];
int n;
int cnt=0;
int cnt2=0;
void func(int n, int x, int y)
{
	if(n==1)
	{
		if(arr[x][y]==1)
			cnt++;
		return ;
	}
	bool check=true;
	for(int i=x;i<x+n;i++)
	{
		for(int j=y;j<y+n;j++)
		{
			if(arr[i][j]==0)
			{
				check=false;
				break;
			}
		}
	}
	if(check==true)
	{
		cnt++;
		return;
	}
	else
	{
		func(n/2,x,y);
		func(n/2,x,y+n/2);
		func(n/2,x+n/2,y);
		func(n/2,x+n/2,y+n/2);
	}
}
void func2(int n, int x, int y)
{
	if(n==1)
	{
		if(arr[x][y]==0)
			cnt2++;
		return ;
	}
	bool check=true;
	for(int i=x;i<x+n;i++)
	{
		for(int j=y;j<y+n;j++)
		{
			if(arr[i][j]==1)
			{
				check=false;
				break;
			}
		}
	}
	if(check==true)
	{
		cnt2++;
		return;
	}
	else
	{
		func2(n/2,x,y);
		func2(n/2,x,y+n/2);
		func2(n/2,x+n/2,y);
		func2(n/2,x+n/2,y+n/2);
	}
}

int main(void)
{
	cin >> n;
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
			cin >> arr[i][j];
	func(n,0,0);
	func2(n,0,0);
	cout << cnt2 << '\n' << cnt;
}
