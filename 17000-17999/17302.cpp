#include <iostream>
using namespace std;
char arr[2020][2020];
int main(void)
{
	int n,m;
	cin >> n >> m;
	for(int i=0;i<n;i++)
		for(int j=0;j<m;j++)
			cin >> arr[i][j];
	printf("1\n");
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			int cnt = 0;
			if(i-1>=0)
				cnt++;
			if(i+1<n)
				cnt++;
			if(j+1<m)
				cnt++;
			if(j-1>=0)
				cnt++;
			if(arr[i][j]=='W')
			{
				if(cnt%2==0)
					printf("2");
				else
					printf("3");
			}
			else
			{
				if(cnt%2==0)
					printf("3");
				else
					printf("2");
			}

		}
		printf("\n");
	}
}

