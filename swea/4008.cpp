#include <stdio.h>
#include <iostream>
#include <algorithm>
using namespace std;
int data[13];
int n;
int maxs;
int mins;
void func(int plus,int minus, int mul, int div,int summ,int idx)
{
	if(idx==n)
	{
		mins=min(mins,summ);
		maxs=max(maxs,summ);
		return;
	}

	if(plus>0)
	{
		func(plus-1,minus,mul,div,summ+data[idx],idx+1);
	}
	if(minus>0)
		func(plus,minus-1,mul,div,summ-data[idx],idx+1);
	if(mul>0)
		func(plus,minus,mul-1,div,summ*data[idx],idx+1);
	if(div>0)
		func(plus,minus,mul,div-1,summ/data[idx],idx+1);
}
int main(void)
{
	int tt;
	cin >> tt;
	for(int t=1;t<=tt;t++)
	{
		cin >> n;
		int arr[4];
		maxs=-100000001;
		mins=1000000001;
		for(int i=0;i<4;i++)
			cin >> arr[i];
		for(int i=0;i<n;i++)
			cin >> data[i];
		func(arr[0],arr[1],arr[2],arr[3],data[0],1);
		printf("#%d %d\n",t,maxs-mins);
	}
}
