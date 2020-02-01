#include <stdio.h>
#include <queue>
#include <cstring>
using namespace std;
int arr[1000010];
int main(void)
{
	int F,S,G,U,D;
	scanf("%d %d %d %d %d",&F,&S,&G,&U,&D);
	memset(arr,-1,sizeof(arr));
	arr[S]=0;
	queue<int> qq;
	qq.push(S);
	while(!qq.empty())
	{
		int s = qq.front();
		qq.pop();
		if(s+U<=F && arr[s+U]==-1)
		{
			arr[s+U]=arr[s]+1;
			qq.push(s+U);
		}
		if(s-D>=1 && arr[s-D]==-1)
		{
			arr[s-D]=arr[s]+1;
			qq.push(s-D);
		}
	}

	if(arr[G]==-1)
		printf("use the stairs");
	else
		printf("%d",arr[G]);
}
