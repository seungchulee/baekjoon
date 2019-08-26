#include <stdio.h>
#include <queue>
#include <utility>
using namespace std;
int arr[10];
int tmp[10];
int cnt=0;
void func(int index, int tm[])
{
	if(cnt>=1)
		return;
	if(index==2)
	{
		int sum=0;
		for(int i=0;i<9;i++)
		{
			if(tm[i]==-1)
				continue;
			sum+=tm[i];
		}


		if(sum==100)
		{
			priority_queue <int,vector<int>,greater<int> > qq;
			cnt++;
			for(int i=0;i<9;i++)
			{
				if(tm[i]==-1)
					continue;
				qq.push(tm[i]);	
			}
			while(!qq.empty())
			{
				int s=qq.top();
				printf("%d\n",s);
				qq.pop();
			}
		}
		return;
	}
	for(int i=index;i<9;i++)
	{
		tm[i]=-1;
		func(index+1,tm);
		tm[i]=arr[i];
	}
}
int main(void)
{
	for(int i=0;i<9;i++)
	{
		scanf("%d",&arr[i]);
		tmp[i]=arr[i];
	}
	func(0,tmp);
}
