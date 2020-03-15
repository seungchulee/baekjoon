#include <stdio.h>
#include <cmath>
#include <iostream>
using namespace std;
int arr[20202];
int len[20202];
int find(int a)
{
	if(a==arr[a])
		return a;
	int tmp = find(arr[a]);
	len[a]+=len[arr[a]];
	return arr[a]=tmp;
}
int main(void)
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int t;
	cin >> t;
	while(t--)
	{
		int n;
		cin >> n;
		for(int i=0;i<=n;i++)
		{
			arr[i]=i;
			len[i]=0;
		}

		while(1)
		{
			char ch;
			cin >> ch;
			if(ch=='E')
			{
				int i;
				cin >> i;
				find(i);
				cout << len[i] << '\n';
			}
			else if(ch=='I')
			{
				int i,j;
				cin >> i >> j;
				len[i]=abs(i-j)%1000;
				arr[i]=j;
			}
			else if(ch=='O')
			{
				break;
			}
		}
	}
}	
