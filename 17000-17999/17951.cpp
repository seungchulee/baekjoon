#include <iostream>
using namespace std;
int n,k;
int arr[101010];
int main(void)
{
	cin >> n >> k;
	for(int i=0;i<n;i++)
		cin >> arr[i];
	int left = 0;
	int right = 10000000;
	int ans=-1;
	while(left<=right)
	{
		int mid = (left+right)/2;
		int res=0;
		int cnt=1;
		bool flag=false;
		int mins=10000000;
		for(int i=0;i<n;i++)
		{
			res+=arr[i];
			if(res>=mid)
			{
				mins=min(mins,res);
				res=0;
				cnt++;
				if(cnt>k)
				{
					ans=max(mins,ans);
					flag=true;
					break;
				}
			}
		}
		if(flag==true)
		{
			left=mid+1;
			ans=max(mins,ans);
		}
		else
		{
			right=mid-1;
		}	
	}
	cout << ans;
}
