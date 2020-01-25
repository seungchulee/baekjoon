#include <stdio.h>
#include <vector>
using namespace std;
int arr[101010];
int main(void)
{
	int N;
	scanf("%d",&N);
	for(int i=0;i<N;i++)
		scanf("%d",&arr[i]);
	vector<int> vv;
	for(int i=0;i<N;i++)
	{
		if(arr[i]==0)
		{
			vv.push_back(i+1);
		}
		else
		{
			auto pos = vv.end();
			pos-=arr[i];
			vv.insert(pos,i+1);
		}
	}
	for(int i=0;i<vv.size();i++)
		printf("%d ",vv[i]);
}
