#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;
long long int arr[1<<21];
long long int brr[1<<21];
int n,q;
long long int find1(int start, int end, int left ,int right, int idx)
{
	if(left>end || right<start)
		return 0;
	if(left<=start && end<=right)
		return arr[idx];
	return find1(start,(start+end)/2, left, right, idx*2)+find1((start+end)/2+1, end, left, right, idx*2+1);

}
long long int find2(int start, int end, int left ,int right, int idx)
{
	if(left>end || right<start)
		return 0;
	if(left<=start && end<=right)
		return brr[idx];
	return find2(start,(start+end)/2, left, right, idx*2)+find2((start+end)/2+1, end, left, right, idx*2+1);

}

int main(void)
{
	cin.tie(NULL);
	std::ios::sync_with_stdio(false);
	cin >> n >> q;
	int H = log2(n-1)+1;
	int base = 1 << H;
	for(int i=1;i<=n;i++)
	{
		if(i%2==1)
		{
			cin >> arr[base+i-1];	
		}
		else if(i%2==0)
		{
			cin >> brr[base+i-1];
		}
	}
	for(int i=base-1;i>=1;i--)
	{
		arr[i]=arr[i*2]+arr[i*2+1];
		brr[i]=brr[i*2]+brr[i*2+1];
	}

	while(q--)
	{
		int a,x,y;
		cin >> a >> x >> y;
		if(a==2)
		{
			if(x%2==0)
			{
				brr[base+x-1]+=y;
				int k = base+x-1;
				while(k>1)
				{
					k/=2;
					brr[k]=brr[k*2]+brr[k*2+1];
				}
			}
			else
			{
				arr[base+x-1]+=y;
				int k =base+x-1;
				while(k>1)
				{
					k/=2;
					arr[k]=arr[k*2]+arr[k*2+1];
				}
			}
		}
		else
		{
			long long int a = find1(1,base,x,y,1);
			long long int b = find2(1,base,x,y,1);
			cout << abs(a-b) << '\n';
		}
	}
}
