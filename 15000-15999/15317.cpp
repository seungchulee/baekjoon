#include <iostream>
#include <algorithm>
using namespace std;
int	C[101010];
int S[101010];
int n,m;
long long int x;
bool check(int ch)
{
	long long int summ=0;

	for(int i=0;i<ch;i++)
	{
		if(C[i]>S[m-ch+i])
		{
			summ+=C[i]-S[m-ch+i];
		}
	}
	if(summ>x)
		return false;
	else
		return true;
}
int main(void)
{
	cin >> n >> m >> x;
	for(int i=0;i<n;i++)
		cin >> C[i];
	for(int i=0;i<m;i++)
		cin >> S[i];
	
	sort(C,C+n);
	sort(S,S+m);

	int start = 0;
	int end = min(n,m);
	int maxx = -1;
	int mid;
	while(start<=end)
	{
		mid = (start+end)/2;
		if(check(mid))
		{
			maxx = max(maxx, mid);
			start = mid+1;
		}
		else
		{
			end = mid-1;
		}
	}
	cout << maxx;	

}
