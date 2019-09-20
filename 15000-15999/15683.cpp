#include <stdio.h>
#include <vector>
#include <utility>
using namespace std;
int N,M;
int arr[10][10];
int check[10][10];
int mins=1000000;
vector<pair<int,int> > qq;
void func(int index,int start)
{

	if(index==qq.size())
	{
		int temp[10][10];
		for(int i=0;i<N;i++)
		{
			for(int j=0;j<M;j++)
			{
				temp[i][j]=arr[i][j];
			}
		}
		for(int i=0;i<qq.size();i++)
		{
			int x = qq[i].first;
			int y = qq[i].second;

			if(arr[x][y]==1)
			{
				if(check[x][y]==1)
				{
					while(temp[x][y+1]!=6)
					{
						if(y+1>=M)
							break;
						if(temp[x][y+1]>=1 && temp[x][y+1]<=5)
						{
							y++;
							continue;
						}
						temp[x][y+1]=7;
						y++;
					}
				}
				if(check[x][y]==2)
				{
					while(temp[x+1][y]!=6)
					{
						if(x+1>=N)
							break;
						if(temp[x+1][y]>=1 && temp[x+1][y]<=5)
						{
							x++;
							continue;
						}
						temp[x+1][y]=7;
						x++;
					}
				}
				if(check[x][y]==3)
				{
					while(temp[x][y-1]!=6)
					{
						if(y-1<0)
							break;
						if(temp[x][y-1]>=1 && temp[x][y-1]<=5)
						{
							y--;
							continue;
						}
						temp[x][y-1]=7;
						y--;
					}

				}
				if(check[x][y]==4)
				{
					while(temp[x-1][y]!=6)
					{
						if(x-1<0)
							break;
						if(temp[x-1][y]>=1 && temp[x-1][y]<=5)
						{
							x--;
							continue;
						}
						temp[x-1][y]=7;
						x--;
					}
				}
			}
			else if(arr[x][y]==2)
			{
				int tmp_x=x;
				int tmp_y=y;
				if(check[x][y]==1 || check[x][y]==3)
				{
					while(temp[x][y+1]!=6)
					{
						if(y+1>=M)
							break;
						if(temp[x][y+1]>=1 && temp[x][y+1]<=5)
						{
							y++;
							continue;
						}

						temp[x][y+1]=7;
						y++;
					}
					while(temp[tmp_x][tmp_y-1]!=6)
					{
						if(tmp_y-1<0)
							break;
						if(temp[x][tmp_y-1]>=1 && temp[x][tmp_y-1]<=5)
						{
							tmp_y--;
							continue;
						}
						temp[tmp_x][tmp_y-1]=7;
						tmp_y--;
					}
				}
				else
				{
					while(temp[x+1][y]!=6)
					{
						if(x+1>=N)
							break;
						if(temp[x+1][y]>=1 && temp[x+1][y]<=5)
						{
							x++;
							continue;
						}
						temp[x+1][y]=7;
						x++;
					}
					while(temp[tmp_x-1][tmp_y]!=6)
					{
						if(tmp_x-1<0)
							break;
						if(temp[tmp_x-1][y]>=1 && temp[tmp_x-1][y]<=5)
						{
							tmp_x--;
							continue;
						}
						temp[tmp_x-1][tmp_y]=7;
						tmp_x--;
					}
				}

			}
			else if(arr[x][y]==3)
			{
				int tmp_x=x;
				int tmp_y=y;
				if(check[x][y]==1)
				{
					while(temp[x-1][y]!=6)
					{
						if(x-1<0)
							break;
						if(temp[x-1][y]>=1 && temp[x-1][y]<=5)
						{
							x--;
							continue;
						}
						temp[x-1][y]=7;
						x--;
					}
					while(temp[tmp_x][tmp_y+1]!=6)
					{
						if(tmp_y+1>=M)
							break;
						if(temp[x][tmp_y+1]>=1 && temp[x][tmp_y+1]<=5)
						{
							tmp_y++;
							continue;
						}					
						temp[tmp_x][tmp_y+1]=7;
						tmp_y++;
					}

				}
				else if(check[x][y]==2)
				{
					while(temp[tmp_x][tmp_y+1]!=6)
					{
						if(tmp_y+1>=M)
							break;
						if(temp[tmp_x][tmp_y+1]>=1 && temp[tmp_x][tmp_y+1]<=5)
						{
							tmp_y++;
							continue;
						}
						temp[tmp_x][tmp_y+1]=7;
						tmp_y++;
					}
					while(temp[x+1][y]!=6)
					{
						if(x+1>=N)
							break;
						if(temp[x+1][y]>=1 && temp[x+1][y]<=5)
						{
							x++;
							continue;
						}
						temp[x+1][y]=7;
						x++;
					}

				}
				else if(check[x][y]==3)
				{
					while(temp[x+1][y]!=6)
					{
						if(x+1>=N)
							break;
						if(temp[x+1][y]>=1 && temp[x+1][y]<=5)
						{
							x++;
							continue;
						}
						temp[x+1][y]=7;
						x++;
					}
					while(temp[tmp_x][tmp_y-1]!=6)
					{
						if(tmp_y-1<0)
							break;
						if(temp[x][tmp_y-1]>=1 && temp[x][tmp_y-1]<=5)
						{
							tmp_y--;
							continue;
						}
						temp[tmp_x][tmp_y-1]=7;
						tmp_y--;
					}

				}
				else if(check[x][y]==4)
				{
					while(temp[tmp_x][tmp_y-1]!=6)
					{
						if(tmp_y-1<0)
							break;
						if(temp[x][tmp_y-1]>=1 && temp[x][tmp_y-1]<=5)
						{
							tmp_y--;
							continue;
						}
						temp[tmp_x][tmp_y-1]=7;
						tmp_y--;
					}
					while(temp[x-1][y]!=6)
					{
						if(x-1<0)
							break;
						if(temp[x-1][y]>=1 && temp[x-1][y]<=5)
						{
							x--;
							continue;
						}
						temp[x-1][y]=7;
						x--;
					}

				}

			}
			else if(arr[x][y]==4)
			{
				
				int tmp_x=x;
				int tmp_y=y;
				if(check[x][y]==1)
				{
					while(temp[x-1][y]!=6)
					{
						if(x-1<0)
							break;
						if(temp[x-1][y]>=1 && temp[x-1][y]<=5)
						{
							x--;
							continue;
						}
						temp[x-1][y]=7;
						x--;
					}
					x=tmp_x;
					y=tmp_y;
					while(temp[x][y+1]!=6)
					{
						if(y+1>=M)
							break;
						if(temp[x][y+1]>=1 && temp[x][y+1]<=5)
						{
							y++;
							continue;
						}
						temp[x][y+1]=7;
						y++;
					}		
					x=tmp_x;
					y=tmp_y;
					while(temp[x][y-1]!=6)
					{
						if(y-1<0)
							break;
						if(temp[x][y-1]>=1 && temp[x][y-1]<=5)
						{
							y--;
							continue;
						}
						temp[x][y-1]=7;
						y--;
					}
				}

				if(check[x][y]==2)
				{
					while(temp[x-1][y]!=6)
					{
						if(x-1<0)
							break;
						if(temp[x-1][y]>=1 && temp[x-1][y]<=5)
						{
							x--;
							continue;
						}
						temp[x-1][y]=7;
						x--;
					}
					x=tmp_x;
					y=tmp_y;
					while(temp[x][y+1]!=6)
					{
						if(y+1>=M)
							break;
						if(temp[x][y+1]>=1 && temp[x][y+1]<=5)
						{
							y++;
							continue;
						}
						temp[x][y+1]=7;
						y++;
					}	
					x=tmp_x;
					y=tmp_y;
					while(temp[x+1][y]!=6)
					{
						if(x+1>=N)
							break;
						if(temp[x+1][y]>=1 && temp[x+1][y]<=5)
						{
							x++;
							continue;
						}
						temp[x+1][y]=7;
						x++;
					}
				}
				if(check[x][y]==3)
				{
					while(temp[x][y+1]!=6)
					{
						if(y+1>=M)
							break;
						if(temp[x][y+1]>=1 && temp[x][y+1]<=5)
						{
							y++;
							continue;
						}
						temp[x][y+1]=7;
						y++;
					}	
					x=tmp_x;
					y=tmp_y;
					while(temp[x+1][y]!=6)
					{
						if(x+1>=N)
							break;
						if(temp[x+1][y]>=1 && temp[x+1][y]<=5)
						{
							x++;
							continue;
						}
						temp[x+1][y]=7;
						x++;
					}
					x=tmp_x;
					y=tmp_y;
					while(temp[x][y-1]!=6)
					{
						if(y-1<0)
							break;
						if(temp[x][y-1]>=1 && temp[x][y-1]<=5)
						{
							y--;
							continue;
						}
						temp[x][y-1]=7;
						y--;
					}

				}
				if(check[x][y]==4)
				{
					while(temp[x+1][y]!=6)
					{
						if(x+1>=N)
							break;
						if(temp[x+1][y]>=1 && temp[x+1][y]<=5)
						{
							x++;
							continue;
						}
						temp[x+1][y]=7;
						x++;
					}
					x=tmp_x;
					y=tmp_y;
					while(temp[x][y-1]!=6)
					{
						if(y-1<0)
							break;
						if(temp[x][y-1]>=1 && temp[x][y-1]<=5)
						{
							y--;
							continue;
						}
						temp[x][y-1]=7;
						y--;
					}
					x=tmp_x;
					y=tmp_y;
					while(temp[x-1][y]!=6)
					{
						if(x-1<0)
							break;
						if(temp[x-1][y]>=1 && temp[x-1][y]<=5)
						{
							x--;
							continue;
						}
						temp[x-1][y]=7;
						x--;
					}
				}
			}
			else if(arr[x][y]==5)
			{
				int tmp_x=x;
				int tmp_y=y;
				while(temp[x+1][y]!=6)
				{
					if(x+1>=N)
						break;
					if(temp[x+1][y]>=1 && temp[x+1][y]<=5)
					{
						x++;
						continue;
					}
					temp[x+1][y]=7;
					x++;
				}
				x=tmp_x;
				y=tmp_y;
				while(temp[x][y-1]!=6)
				{
					if(y-1<0)
						break;
					if(temp[x][y-1]>=1 && temp[x][y-1]<=5)
					{
						y--;
						continue;
					}
					temp[x][y-1]=7;
					y--;
				}
				x=tmp_x;
				y=tmp_y;
				while(temp[x-1][y]!=6)
				{
					if(x-1<0)
						break;
					if(temp[x-1][y]>=1 && temp[x-1][y]<=5)
					{
						x--;
						continue;
					}
					temp[x-1][y]=7;
					x--;
				}
				x=tmp_x;
				y=tmp_y;
				while(temp[x][y+1]!=6)
				{
					if(y+1>=M)
						break;
					if(temp[x][y+1]>=1 && temp[x][y+1]<=5)
					{
						y++;
						continue;
					}
					temp[x][y+1]=7;
					y++;
				}	

			}
		}
		int result=0;
		for(int i=0;i<N;i++)
		{
			for(int j=0;j<M;j++)
			{
		//		printf("%d ",temp[i][j]);
				if(temp[i][j]==0)
					result++;
			}
		//	printf("\n");
		}
		//printf("\n\n");
		mins=min(mins,result);
		return;
	}

	
	for(int i=1;i<=4;i++)
	{
		for(int j=start;j<qq.size();j++)
		{
			int x=qq[j].first;
			int y=qq[j].second;
			check[x][y]=i;
			func(index+1,j+1);
			check[x][y]=i-1;
		}
	}
}
int main(void)
{
	scanf("%d %d",&N,&M);
	for(int i=0;i<N;i++)
	{
		for(int j=0;j<M;j++)
		{
			scanf("%d",&arr[i][j]);
			if(arr[i][j]>=1 && arr[i][j]<=5)
				qq.push_back(make_pair(i,j));
		}
	}

	func(0,0);
	printf("%d",mins);	

}
