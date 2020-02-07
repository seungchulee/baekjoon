#include <stdio.h>
#include <algorithm>
using namespace std;
int arr[11][11];
int mins=10000000;
int gaesu[6]={0,5,5,5,5,5};
bool possible(int r, int c, int len)
{
	if(r+len>10 || c+len>10)
		return false;
	for(int i=r;i<r+len;i++)
	{
		for(int j=c;j<c+len;j++)
		{

			if(arr[i][j]==0)
				return false;
		}
	}
	return true;
}
void fill(int r, int c, int len, int f)
{
	for(int i=r;i<r+len;i++)
	{
		for(int j=c;j<c+len;j++)
		{
			arr[i][j]=f;
		}
	}
}
void func(int idx, int cnt)
{

	if(idx==100)
	{
		mins=min(mins,cnt);
		return;
	}
	if(cnt>=mins)
		return;
	int r = idx/10;
	int c = idx%10;
	if(arr[r][c]==1)
	{
		for(int i=5;i>=1;i--)
		{
			if(gaesu[i]>0)
			{
				if(possible(r,c,i))
				{
					fill(r,c,i,0);
					gaesu[i]--;
					func(idx+1,cnt+1);
					fill(r,c,i,1);
					gaesu[i]++;
				}
			}
		}
	}
	else
	{
		func(idx+1,cnt);
	}

}
int main(void)
{
	for(int i=0;i<10;i++)
		for(int j=0;j<10;j++)
			scanf("%d",&arr[i][j]);
	func(0,0);
	if(mins==10000000)
		printf("-1");
	else
		printf("%d",mins);
}
