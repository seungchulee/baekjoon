#include <stdio.h>
#include <cstring>
int main(void)
{
	int t;
	scanf("%d",&t);
	for(int q=1;q<=t;q++)
	{
		char arr[31];
		scanf("%s",arr);
		int res;
		for(int i=1;i<=30;i++)
		{
			bool repeat=true;
			for(int j=0;;j+=i)
			{
				if(j+i>=strlen(arr))
					break;
				if(arr[j]!=arr[j+i])
					repeat=false;
			}
			if(repeat==false)
				continue;
			else
			{
				res=i;
				break;
			}
		}
		printf("#%d %d\n",q,res);
	}
}
