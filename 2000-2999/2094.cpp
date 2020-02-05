#include <stdio.h>
#include <cmath>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;
int arr[1<<17];
int n;
int m;
int base;
int y,x;
vector<pair<int,int> > vv;
int find(int start, int end, int left ,int right, int idx)
{
	if(left>right)
		return -1;
	if(right<start || end<left)
		return -1;
	if(left<=start && end<=right)
		return arr[idx];
	int mid = (start+end)/2;
	return max(find(start,mid,left,right,idx*2),find(mid+1,end,left,right,idx*2+1));


}

int func()
{
	int ypos = lower_bound(vv.begin(),vv.end(),make_pair(y,-1))-vv.begin();
	int xpos = lower_bound(vv.begin(),vv.end(),make_pair(x,-1))-vv.begin();
	bool x_range = xpos<n && vv[xpos].first==x;
	bool y_range = ypos<n && vv[ypos].first==y;
	int low = lower_bound(vv.begin(),vv.end(),make_pair(y+1,-1))-vv.begin();
	int maxs = find(1,base,low+1,xpos,1);
	if(x_range==true && maxs>=vv[xpos].second)
	{
		return 0;
	}
	if(y_range==true && maxs>=vv[ypos].second)
	{
		return 0;
	}

	if(y_range==true && x_range==true && vv[ypos].second<vv[xpos].second)
	{
		return 0;
	}
	if(x_range==true && y_range==true && xpos-ypos==x-y)
		return 1;	
	else
		return -1;
}
int main(void)
{
	scanf("%d",&n);

	for(int i=0;i<n;i++)
	{
		int a,b;
		scanf("%d %d",&a,&b);
		vv.push_back(make_pair(a,b));
	}
	memset(arr,-1,sizeof(arr));
	int h = (int)log2(n-1)+1;
	base = 1 << h;

	for(int i=base;i<base+n;i++)
	{
		int a = vv[i-base].second;
		arr[i]=a;
	}
	for(int i=base-1;i>=1;i--)
		arr[i]=max(arr[i*2],arr[i*2+1]);

	scanf("%d",&m);
	for(int i=0;i<m;i++)
	{
		scanf("%d %d",&y,&x);
		int res = func();
		if(res==0)
			printf("false\n");
		else if(res==1)
			printf("true\n");
		else
			printf("maybe\n");
	}
}	

