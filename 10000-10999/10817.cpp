#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;
int main(void)
{
	vector<int> vv;
	for(int i=0;i<3;i++)
	{
		int x;
		scanf("%d",&x);
		vv.push_back(x);
	}
	sort(vv.begin(),vv.end());
	printf("%d",vv[1]);
}
