#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <cmath>
using namespace std;
int n,m,k;
int arr[4040400];
vector<int> vv;
bool cmp1(const int &v1, const int &v2)
{
	return v1>v2;
}
int main(void)
{
	for(int i=0;i<=400001;i++)
		arr[i]=1;

	cin >> n >> m >> k;
	for(int i=0;i<m;i++)
	{
		int x,y;
		cin >> x >> y;
		arr[x]=0;
		arr[y]=0;
	}
	
	int kx, ky;
	cin >> kx >> ky;
	arr[kx]=0;
	arr[ky]=0;

	for(int i=1;i<=4*n;i++)
	{
		if(arr[i]==1)
			vv.push_back(i%k);
	}
	sort(vv.begin(),vv.end(),cmp1);

	int cmp = abs(kx%k - ky%k);
	int left=0,right=0;
	int cnt=0, pep=0;
	while(1)
	{
		if(right==vv.size() || vv[left]<cmp || pep==m-1)
			break;
		if(abs(vv[left]-vv[right])<=cmp)
		{
			right++;
		}
		else
		{
			pep++;
			right++;
			left++;
			cnt++;
		}
	}
	cout << cnt;
}
