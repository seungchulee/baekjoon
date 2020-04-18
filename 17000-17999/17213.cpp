#include <iostream>
using namespace std;
long long int arr[31][31];
int main(void)
{
	int n,m;
	cin >> n >> m;
	m-=n;
    // nHm = n+m-1Cm
	arr[1][1]=1;
	arr[1][2]=1;

	for(int i=2;i<=30;i++)
	{
		for(int j=1;j<=30;j++)
		{
			if(j==1)
			{
				arr[i][j]=1;
				continue;
			}
			if(j==i+1)
			{
				arr[i][j]=1;
				break;
			}

			arr[i][j]=arr[i-1][j-1]+arr[i-1][j];
		}
	}

	cout << arr[n+m-1][m+1];	
}
