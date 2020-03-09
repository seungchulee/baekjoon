#include <stdio.h>
#include <vector>
using namespace std;
int cmp[5];
int arr[101];
int n;
int maxx=-1000000001;
int mins=1000000001;
void func(int plus,int minus, int mul, int div, int sum, int idx)
{
	if(idx==n)
	{
		maxx=max(maxx,sum);
		mins=min(mins,sum);
		return;
	}
	if(plus<cmp[0])
		func(plus+1,minus,mul,div,sum+arr[idx],idx+1);
	if(minus<cmp[1])
		func(plus,minus+1,mul,div,sum-arr[idx],idx+1);
	if(mul<cmp[2])
		func(plus,minus,mul+1,div,sum*arr[idx],idx+1);
	if(div<cmp[3])
		func(plus,minus,mul,div+1,sum/arr[idx],idx+1);
}
int main(void)
{
	vector<int> vv;
	scanf("%d",&n);
	for(int i=0;i<n;i++)
		scanf("%d",&arr[i]);
	for(int i=0;i<4;i++)
		scanf("%d",&cmp[i]);
	func(0,0,0,0,arr[0],1);
	printf("%d\n%d",maxx,mins);
}

