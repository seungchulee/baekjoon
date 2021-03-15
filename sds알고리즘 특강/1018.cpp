#include <stdio.h>
#include <algorithm>
using namespace std;
char arr[51][51];
char white[8][8]={
	{'W','B','W','B','W','B','W','B'},
	{'B','W','B','W','B','W','B','W'},
	{'W','B','W','B','W','B','W','B'},
	{'B','W','B','W','B','W','B','W'},
	{'W','B','W','B','W','B','W','B'},
	{'B','W','B','W','B','W','B','W'},
	{'W','B','W','B','W','B','W','B'},
	{'B','W','B','W','B','W','B','W'}
};
char black[8][8]={
	{'B','W','B','W','B','W','B','W'},
	{'W','B','W','B','W','B','W','B'},
	{'B','W','B','W','B','W','B','W'},
	{'W','B','W','B','W','B','W','B'},
	{'B','W','B','W','B','W','B','W'},
	{'W','B','W','B','W','B','W','B'},
	{'B','W','B','W','B','W','B','W'},
	{'W','B','W','B','W','B','W','B'}
};
int mins_cnt(int i, int j)
{
	int cnt=0;
	for(int x=i;x<i+8;x++)
	{
		for(int y=j;y<j+8;y++)
		{
			if(arr[x][y]!=black[x-i][y-j])
				cnt++;
		}
	}
	return cnt;
}

int mins_cnt2(int i, int j)
{
	int cnt=0;
	for(int x=i;x<i+8;x++)
	{
		for(int y=j;y<j+8;y++)
		{
			if(arr[x][y]!=white[x-i][y-j])
				cnt++;
		}
	}
	return cnt;
}

int main(void)
{
	int N,M;
	scanf("%d %d",&N,&M);

	for(int i=0;i<N;i++)
	{
		char st[51];
		scanf("%s",st);
		for(int j=0;j<M;j++)
		{
			arr[i][j]=st[j];
		}
	}
	int minss = 100000000;
	for(int i=0;i+7<N;i++)
	{
		for(int j=0;j+7<M;j++)
		{
			int mins = mins_cnt(i,j);
			int mins2 = mins_cnt2(i,j);
			int real_min = min(mins,mins2);
			minss=min(real_min,minss);
		}
	}
	printf("%d",minss);	
}
