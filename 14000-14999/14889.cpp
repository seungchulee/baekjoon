#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;
int arr[21][21];
int selects[21];
int N;
int mins=100000000;
void func(int index,int cnt)
{
	if(cnt==N/2 || index>=N)
	{
		if(cnt==N/2)
		{
			vector<int> start(N/2);
			int start_index=0;
			int link_index=0;
			vector<int> link(N/2);
			for(int i=0;i<N;i++)
			{
				if(selects[i]==1)
				{
					start[start_index]=i+1;
					start_index++;

				}
				else
				{
					link[link_index]=i+1;
					link_index++;
				}
			}
		//	printf("start : ");
		//	for(int i=0;i<N/2;i++)
		//		printf("%d ",start[i]);
			vector<int> choice(N/2);
			for(int i=0;i<N/2-2;i++)
				choice[i]=0;	
			for(int i=N/2-2;i<N/2;i++)
				choice[i]=1;
			int start_point=0;
			int link_point=0;
			do{
				int cncn=0;
				int x,y;
				int xx,yy;
				for(int i=0;i<N/2;i++)
				{
					if(choice[i]==1 && cncn==0)
					{
						x=start[i];
						xx=link[i];
						cncn++;
						continue;
					}
					else if(choice[i]==1 && cncn==1)
					{
						y=start[i];
						yy=link[i];
					}
				}
				start_point+=arr[x][y];
				start_point+=arr[y][x];
				link_point+=arr[xx][yy];
				link_point+=arr[yy][xx];
				//printf("%d\n",start_point-link_point);
			}while(next_permutation(choice.begin(),choice.end()));
			mins=min(mins,abs(start_point-link_point));
		}
		return;
	}

	selects[index]=1;
	func(index+1,cnt+1);
	selects[index]=0;
	func(index+1,cnt);


}
int main(void)
{
	scanf("%d",&N);
	for(int i=1;i<=N;i++)
	{
		for(int j=1;j<=N;j++)
		{
			scanf("%d",&arr[i][j]);
		}
	}

	func(0,0);
	printf("%d",mins);
}	

