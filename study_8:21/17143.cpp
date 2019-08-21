#include <stdio.h>
int R,C,M;
struct shark{
	int r;
	int c;
	int s;
	int d;
	int z;
	bool get;
};
bool down=true;
bool up=true;
bool right=true;
bool left=true;
int total=0;
struct shark sh[10000];
void catch_shark(int x)
{
	bool one=false;
	for(int i=1;i<=R;i++)
	{
		for(int j=0;j<M;j++)
		{
			if(sh[j].r==i && sh[j].c==x && sh[j].get==false)
			{
				sh[j].get=true;
				total+=sh[j].z;
				one=true;
				break;
			}
		}
		if(one==true)
			break;
	}
/*	for(int i=0;i<M;i++)
	{
		printf("%u\n",sh[i].get);
	}*/
}
void move_shark()
{
	for(int i=0;i<M;i++)
	{
		if(sh[i].get==false)
		{
			if(sh[i].d==1)
			{
				for(int j=0;j<sh[i].s;j++)
				{
					if(up==true)
					{
						if(sh[i].r==1)
						{
							sh[i].r=sh[i].r+1;
							up=false;
						}
						else
						{
							sh[i].r=sh[i].r-1;
							if(sh[i].r<=1)
							{
								up=false;
							}
						}
					}
					else
					{
						sh[i].r=sh[i].r+1;
						if(sh[i].r>=R)
							up=true;
					}
				}
				// 위로 이동
			}
			else if(sh[i].d==2)
			{
				
				for(int j=0;j<sh[i].s;j++)
				{
					if(down==true)
					{
						if(sh[i].r==R)
						{
							sh[i].r=sh[i].r-1;
							down=false;
						}
						else
						{
							sh[i].r=sh[i].r+1;
							if(sh[i].r>=R)
								down=false;
						}
						
					}
					else
					{
						sh[i].r=sh[i].r-1;
						if(sh[i].r<=1)
							down=true;
					}
				}
				// 아래로 이동
			}
			else if(sh[i].d==3)
			{
				for(int j=0;j<sh[i].s;j++)
				{
					if(right==true)
					{
						if(sh[i].c==C)
						{
							sh[i].c=sh[i].c-1;
							right=false;
						}
						else
						{
							sh[i].c=sh[i].c+1;
							if(sh[i].c>=C)
								right=false;
						}
					}
					else
					{
						sh[i].c=sh[i].c-1;
						if(sh[i].c<=1)
							right=true;
					}
				}

				// 오른쪽으로 이동
			}
			else if(sh[i].d==4)
			{
				for(int j=0;j<sh[i].s;j++)
				{
					if(left==true)
					{
						if(sh[i].c==1)
						{
							sh[i].c=sh[i].c+1;
							left=false;
						}
						else
						{
							sh[i].c=sh[i].c-1;
							if(sh[i].c<=1)
								left=false;
						}
					}
					else
					{
						sh[i].c=sh[i].c+1;
						if(sh[i].c>=C)
							left=true;
					}
				}
				//왼쪽으로 이동
			}
		}
	}	
}
void eat_shark()
{
	for(int i=0;i<M-1;i++)
	{
		for(int j=i+1;j<M;j++)
		{
			if(sh[i].r==sh[j].r && sh[i].c==sh[j].c)
			{
				if(sh[i].z>sh[j].z)
				{
					sh[j].get=true;
				}
				else
				{
					sh[i].get=true;
				}
			}
		}
	}
}
void print_shark()
{
	int arr[100][100];
	for(int i=1;i<=R;i++)
	{
		for(int j=1;j<=C;j++)
		{
			arr[i][j]=0;
			for(int k=0;k<M;k++)
			{
				if(i==sh[k].r && j==sh[k].c && sh[k].get==false)
				{
					arr[i][j]=1;
					

				}
				else if(i==sh[k].r && j==sh[k].c && sh[k].get==true)
					arr[i][j]=-1;
				
			}
			printf("%2d",arr[i][j]);
		}
		printf("\n");
	}

}
int main(void)
{
	scanf("%d %d %d",&R,&C,&M);
	for(int i=0;i<M;i++)
	{
		scanf("%d %d %d %d %d",&sh[i].r,&sh[i].c,&sh[i].s,&sh[i].d,&sh[i].z);
		sh[i].get=false;	
	}
	
	for(int i=1;i<=C;i++)
	{
		catch_shark(i);

		move_shark();
		//print_shark();

		eat_shark();
	}
	printf("%d",total);
}
