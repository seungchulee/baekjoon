#include <stdio.h>
#include <cmath>
#include <cstring>
#include <algorithm>
using namespace std;
long int arr[404040];
long int origin[101010];
int N;
int main(void)
{
	memset(origin,0,sizeof(origin));
	scanf("%d",&N);
	for(int i=1;i<=N;i++)
	{
		scanf("%ld",&origin[i]);
	}
	int h = (int)log2(N-1)+1;
	int base=1<<h;

	origin[0]=1000000111;
	for(int i=base;i<base+N;i++)
	{
		arr[i]=i-base+1;	
	}
	for(int i=base-1;i>=1;i--)
	{
		if(origin[arr[i*2]] < origin[arr[i*2+1]])
			arr[i]=arr[i*2];
		else
		{

			if(origin[arr[i*2]]==origin[arr[i*2+1]])
				arr[i]=min(arr[i*2],arr[i*2+1]);
			else
				arr[i]=arr[i*2+1];
		}



	}

	int M;
	scanf("%d",&M);
	for(int i=0;i<M;i++)
	{
		int a;
		scanf("%d",&a);
		if(a==1)
		{
			int b;
			long int c;
			scanf("%d %ld",&b,&c);
			int k = base+b-1;
			origin[b]=c;
			while(k>1)
			{
				k/=2;
				if(origin[arr[k*2]]<origin[arr[k*2+1]])
					arr[k]=arr[k*2];
				else
				{

					if(origin[arr[k*2]]==origin[arr[k*2+1]])
						arr[k]=min(arr[k*2],arr[k*2+1]);
					else
						arr[k]=arr[k*2+1];
				}
			}
		}
		else
		{
			printf("%ld\n",arr[1]);	
		}
	}
}
