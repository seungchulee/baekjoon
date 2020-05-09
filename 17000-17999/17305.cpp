#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector<int> three;
vector<int> five;
long long five_w[252525];
long long three_w[252525];
int n;
long long int w;
bool sort1(const int &p1, const int &p2)
{
	return p1 > p2;
}
int main(void)
{
	cin >> n >> w;
	for(int i=0;i<n;i++)
	{
		int x,y;
		cin >> x >> y;
		if(x==3)
		{
			three.push_back(y);
		}
		else
		{
			five.push_back(y);
		}
	}
	sort(three.begin(),three.end(),sort1);
	sort(five.begin(),five.end(),sort1);
	five_w[0]=0;
	int start=0;
	int i;
	for(i=0;i<five.size();i++)
	{
		start+=5;
		if(start>w)
			break;
		five_w[i+1]=five_w[i]+five[i];
	}
	int five_len=i+1;

	start=0;
	three_w[0]=0;
	for(i=0;i<three.size();i++)
	{
		start+=3;
		if(start>w)
			break;
		three_w[i+1]=three_w[i]+three[i];
	}
	int three_len=i+1;
	long long int maxs=-1;
	int tt=0;

	for(int i=0;i<five_len;i++)
	{
		long long int base = five_w[i];
		int three_idx = (w-(i*5))/3;
		base += three_w[min(three_idx,three_len-1)];
		maxs = max(maxs,base);
	}
	cout << maxs;
}
