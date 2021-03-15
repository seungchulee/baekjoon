#include <stdio.h>
#include <queue>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;
int N, K;
int flag=0;
int arr[13];
int make(int arr[],int fl)
{
	int tmp=0;
	for(int i=0;i<fl;i++)
	{
		tmp*=10;
		tmp+=arr[i];
	}
	return tmp;
	
}
int digit(int n, int i)
{
	for(int k=0;k<i;k++)
		n/=10;
	return n%10;
}
int swapdigit(int num, int k, int l)
{
	int tt[13];
	int fl=0;
	while(num>=1)
	{
		tt[fl]=num%10;
		fl++;
		num/=10;
	}
	reverse(tt,tt+fl);
	int tmp = tt[k];
	tt[k]=tt[l];
	tt[l]=tmp;
	return make(tt,fl);
}
int main(void)
{
	scanf("%d %d", &N, &K);

	int data = N;
	flag = 0;
	while (data >= 1)
	{
		flag++;
		data /= 10;
	}
	queue<int> qq;
	qq.push(N);
	for(int i=0;i<K;i++)
	{
		int qs = qq.size();
		int visit[1000001]={0,};
		for(int j=0;j<qs;j++)
		{
			int num = qq.front();
			qq.pop();
			for(int k=0;k<flag-1;k++)
			{
				for(int l=k+1;l<flag;l++)
				{
					if(l<flag-1 || digit(num,k))
					{
						int next = swapdigit(num,k,l);
						if(!visit[next])
						{
							visit[next]=1;
							qq.push(next);
						}
					}
				}
			}
		}
	}
	int maxs=-1;
	while(!qq.empty())
	{
		maxs=max(maxs,qq.front());
		qq.pop();
	}
	printf("%d",maxs);
}
