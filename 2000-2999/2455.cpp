#include <stdio.h>
#include <algorithm>
using namespace std;
int main(void)
{
	int result=0;
	int x,y;
	int tmp=0;
	for(int i=0;i<4;i++)
	{
		scanf("%d %d",&x,&y);
		result+=y-x;
		result=max(result,tmp);
		tmp=result;
	}
	printf("%d",result);
}
