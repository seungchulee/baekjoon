#include <iostream>
#include <cstring>
using namespace std;
int arr[10];
int check[10];
int main(void)
{
	int n;
	cin >> n;
	memset(check,0,sizeof(check));
	for(int i=0;i<n;i++)
		cin >> arr[i];
	int i;
	for(i=0;i<n-1;i++)
	{
		int before = arr[i];
		int after = arr[i+1];
		check[before]=1;
		if(check[after]==1)
		{
			cout << "NO";
			break;
		}
		if(before==1)
		{
			if(after==2 || after==5 || after==4 || after==6 || after==8)
			{
				if(check[after]==1)
				{
					cout << "NO";
					return 0;
				}
				check[after]=1;
			}
			if(after==3)
			{
				if(check[2]==0)
				{
					cout << "NO";
					break;
				}
				check[3]=1;
			}
			if(after==7)
			{
				if(check[4]==0)
				{
					cout << "NO";
					break;
				}
				check[7]=1;
			}
			if(after==9)
			{
				if(check[5]==0)
				{
					cout << "NO";
					break;
				}
				check[9]=1;
			}
		}
		else if(before==2)
		{
			if(after==1 || after==3 || after==4 || after==5 || after==6 || after==7 || after==9)
			{
				if(check[after]==1)
				{
					cout << "NO";
					break;
				}
				check[after]=1;
			}
			if(after==8)
			{
				if(check[5]==0)
				{
					cout << "NO";
					break;
				}
				check[8]=1;
			}
		}
		else if(before==3)
		{
			if(after==1 || after==2 || after==4 || after==5 || after==6 || after==8)
			{
				if(check[after]==1)
				{
					cout << "NO";
					break;
				}
				check[after]=1;
			}
			if(after==7)
			{
				if(check[5]==0)
				{
					cout << "NO";
					break;
				}
				check[7]=1;
			}
			if(after==9)
			{
				if(check[6]==0)
				{
					cout << "NO";
					break;
				}
				check[9]=1;
			}
		}
		else if(before==4)
		{
			if(after==1 || after==2 || after==3 || after==5 || after==9 || after==8 || after==7)
			{
				if(check[after]==1)
				{
					cout << "NO";
					break;
				}
				check[after]=1;
			}
			if(after==6)
			{
				if(check[5]==0)
				{
					cout << "NO";
					break;
				}
				check[6]=1;
			}

		}
		else if(before==5)
		{
			if(check[after]==1)
			{
				cout << "NO";
				break;
			}
			check[after]=1;
		}
		else if(before==6)
		{
			if(after==1 || after==2 || after==3 || after==5 || after==7 || after==8  || after==9)
			{
				if(check[after]==1)
				{
					cout << "NO";
					break;
				}
				check[after]=1;
			}
			if(after==4)
			{
				if(check[5]==0)
				{
					cout << "NO";
					break;
				}
				check[4]=1;
			}

		}
		else if(before==7)
		{
			if(after==2 || after==4 || after==5 || after==6 || after==8)
			{
				if(check[after]==1)
				{
					cout << "NO";
					break;
				}
				check[after]=1;
			}
			if(after==1)
			{
				if(check[4]==0)
				{
					cout << "NO";
					break;
				}
				check[1]=1;
			}
			if(after==3)
			{
				if(check[5]==0)
				{
					cout << "NO";
					break;
				}
				check[3]=1;
			}
			if(after==9)
			{
				if(check[8]==0)
				{
					cout << "NO";
					break;
				}
				check[9]=1;
			}

		}
		else if(before==8)
		{
			if(after==1 || after==3 || after==4 || after==5 || after==6 || after==7 || after==9)
			{
				if(check[after]==1)
				{
					cout << "NO";
					break;
				}
				check[after]=1;
			}
			if(after==2)
			{
				if(check[5]==0)
				{
					cout << "NO";
					break;
				}
				check[2]=1;
			}
					
		}
		else if(before==9)
		{
			if(after==2 || after==4 || after==5 || after==6 || after==8)
			{
				if(check[after]==1)
				{
					cout << "NO";
					break;
				}
				check[after]=1;
			}
			if(after==1)
			{
				if(check[5]==0)
				{
					cout<< "NO";
					break;
				}
				check[1]=1;
			}
			if(after==3)
			{
				if(check[6]==0)
				{
					cout << "NO";
					break;
				}
				check[3]=1;
			}
			if(after==7)
			{
				if(check[8]==0)
				{
					cout << "NO";
					break;
				}
				check[7]=1;
			}
						
		}
	}
	if(i==n-1)
		cout << "YES";
}
