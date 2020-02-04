#include <stdio.h>
#include <algorithm>
#include <vector>
using namespace std;
int main(void)
{
	int n;
	scanf("%d",&n);
	vector<int> vv;
	for(int i=0;i<n;i++)
	{
		int x;
		scanf("%d",&x);
		vv.push_back(x);
	}
	sort(vv.begin(),vv.end());
	for(int i=0;i<vv.size();i++)
		printf("%d\n",vv[i]);
		

}
