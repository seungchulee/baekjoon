#include <stdio.h>
#include <queue>
using namespace std;
int main(void)
{
	int N;
	queue<int> qq;
	scanf("%d",&N);
	for(int i=1;i<=N;i++)
	{
		qq.push(i);
	}

	while(qq.size()>1)
	{
		int numm=qq.front();
		printf("%d ",numm);
		qq.pop();
		int num=qq.front();
		qq.pop();
		qq.push(num);
	}
	printf("%d",qq.front());
}
