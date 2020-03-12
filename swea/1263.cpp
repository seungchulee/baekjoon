#include <stdio.h>
#include <algorithm>
#include <iostream>
using namespace std;
int arr[1010][1010];
int main(void)
{
	int q;
	cin >> q;
	for(int t=1;t<=q;t++)
	{
		int n;
		cin >> n;
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<n;j++)
			{
				cin >> arr[i][j];
				if(arr[i][j]==0 && i!=j)
					arr[i][j]=100000000;
			//	cout << arr[i][j] << ' ';
			}
			//printf("\n");
		}
		
		for(int k=0;k<n;k++)
		{
			for(int i=0;i<n;i++)
			{

				for(int j=0;j<n;j++)
				{

					if(arr[i][j]>arr[i][k]+arr[k][j])
						arr[i][j]=arr[i][k]+arr[k][j];
				}
			}
		}	
		int mins=100000000;
		for(int i=0;i<n;i++)
		{
			int summ=0;
			for(int j=0;j<n;j++)
			{
				summ+=arr[i][j];
			}
			mins=min(mins,summ);
		}	
		printf("#%d %d\n",t,mins);
	}
}
