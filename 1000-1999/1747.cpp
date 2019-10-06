#include <stdio.h>
#include <cstring>
#include <vector>
using namespace std;
int arr[2000000];
int main(void)
{
	int N;
	memset(arr,0,sizeof(arr));
	scanf("%d",&N);
	arr[1]=0;
	for(int i=2;i<2000000;i++)
	{
		if(arr[i]==0)
		{
			for(int j=i+i;j<2000000;j+=i)
				arr[j]=1;
		}
	}
	bool flag=true;
	int result=0;
	for(int i=N;i<2000000;i++)
	{
		flag=true;
		if(arr[i]==0)
		{
			vector <int> qq;
			int nn=i;
			while(nn/10!=0)
			{
				qq.push_back(nn%10);
				nn/=10;
			}
			qq.push_back(nn);
			
			int len=qq.size();
				
			for(int j=0;j<len;j++)
			{
				if(j==len-j-1)
				{
					flag=false;
					break;
				}
				if(qq[j]==qq[len-j-1])
				{
					flag=false;
					continue;
				}
				else
				{
					flag=true;
					break;
				}
			}
			qq.clear();

		}

		
		if(flag==false)
		{
			if(i==1)
				continue;
			result=i;
			break;
		}
	}
	printf("%d",result);
	
}
