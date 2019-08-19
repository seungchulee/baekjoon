#include <stdio.h>
#include <algorithm>
using namespace std;
int H,W,N;
int R[100];
int C[100];

int main(void)
{
	scanf("%d %d",&H,&W);
	scanf("%d",&N);
	for(int i=0;i<N;i++)
	{
		scanf("%d %d",&R[i],&C[i]);
	}
	int area=0;

	for(int i=0;i<N;i++)
	{
		int ar=R[i];
		int ac=C[i];
		for(int j=i+1;j<N;j++)
		{
			int br=R[j];
			int bc=C[j];
			int tmp=ar*ac+br*bc;
			for(int ro1=0;ro1<2;ro1++)
			{
				for(int ro2=0;ro2<2;ro2++)
				{
					if(max(ar,br) <= H && ac+bc<=W)
					{
						int tmp=ar*ac+br*bc;	
						area=max(tmp,area);
					}
					if(ar+br<=H && max(ac,bc)<=W)
					{
						int tmp=ar*ac+br*bc;
						area=max(tmp,area);
					}
					swap(br,bc);
				}
				swap(ar,ac);
			}
		}
	}
	printf("%d",area);
}

