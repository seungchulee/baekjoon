#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;
int main(void)
{
	int T;
	scanf("%d",&T);

	for(int i=0;i<T;i++)
	{
		char st[501];
		scanf("%s",st);
		int len=strlen(st);
		int minx=0;
		int miny=0;
		int maxx=0;
		int maxy=0;
		int dir=0;
		int x=0;
		int y=0;

		for(int j=0;j<len;j++)
		{
			if(st[j]=='F')
			{
				if(dir==0)
				{
					y++;
				}
				else if(dir==1)
				{
					x++;
				}
				else if(dir==2)
				{
					y--;
				}
				else if(dir==3)
				{
					x--;
				}
			}
			else if(st[j]=='B')
			{
				if(dir==0)
				{
					y--;
				}
				else if(dir==1)
				{
					x--;
				}
				else if(dir==2)
				{
					y++;
				}
				else if(dir==3)
				{
					x++;
				}

			}
			else if(st[j]=='L')
			{
				dir=dir-1;
				if(dir==-1)
					dir=3;
			}
			else if(st[j]=='R')
			{
				dir=(dir+1)%4;
			}
			maxx=max(maxx,x);
			minx=min(minx,x);
			maxy=max(maxy,y);
			miny=min(miny,y);
		}
		printf("%d\n",abs(maxx-minx)*abs(maxy-miny));
	}
}
