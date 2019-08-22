#include <stdio.h>
#include <queue>
#include <utility>
using namespace std;
void BFS(int n)
{

}
int main(void)
{
	int T;
	scanf("%d",&T);

	for(int i=0;i<T;i++)
	{
		int N;
		scanf("%d",&N);
		if(N==1)
			printf("1\n");
		else
			BFS(N);
	}
}
