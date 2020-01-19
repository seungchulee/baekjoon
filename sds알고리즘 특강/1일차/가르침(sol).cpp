#include <stdio.h>
#include <cstring>

int N,K;
char st[51][27];
char data[51][27];
int visit[27];
int maxs=-1;
void DFS(int start,int cnt)
{
	if(cnt==K)
	{

		int res=0;
		for(int i=0;i<N;i++)
		{
			bool flag=true;
			for(int j=0;j<strlen(data[i]);j++)
			{
				if(visit[data[i][j]-'a']==-1)
				{
					flag=false;
					break;
				}
			}
			if(flag==true)
				res++;
		}
		if(res>maxs)
			maxs=res;
		return;
	}

	for(int i=start;i<26;i++)
	{
		if(visit[i]==1)
			continue;
		visit[i]=1;
			
		DFS(i,cnt+1);

		visit[i]=-1;
	}
}
int main(void)
{
	memset(visit,-1,sizeof(visit));
	scanf("%d %d",&N,&K);
	if(K<5)
	{
		printf("0");
		return 0;
	}
	if(K==26)
	{
		printf("%d",N);
		return 0;
	}
	K-=5;
	for(int i=0;i<N;i++)
	{
		scanf("%s",st[i]);
		for(int j=strlen(st[i])-4;j<strlen(st[i]);j++)
			st[i][j]='\0';	
		for(int j=4;j<strlen(st[i]);j++)
		{
			data[i][j-4]=st[i][j];
			if(j==strlen(st[i])-1)
				data[i][j+1]='\0';
		}
		
	}
	visit[0]=1;
	visit['n'-'a']=1;
	visit['t'-'a']=1;
	visit['i'-'a']=1;
	visit['c'-'a']=1;

	DFS(0,0);
	printf("%d",maxs);
}
