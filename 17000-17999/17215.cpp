#include <iostream>
#include <cstring>
using namespace std;
int jumsoo[11];
int strike[11];
int spare[11];
int main(void)
{
	char str[30];
	scanf("%s",str);
	int len = strlen(str);
	int idx=0;
	for(int i=1;i<=10;i++)
	{
		char ch = str[idx];
		idx++;
		int score;
		int before;
		
		if(ch>='0' && ch<='9')
			score = ch-'0';
		else if(ch=='-')
			score = 0;
		else if(ch=='S')
		{
			score = 10;
			strike[i]=2;
		}
		jumsoo[i]=score;
		if(i-2>=1 && strike[i-2]>0)
		{
			strike[i-2]--;
			jumsoo[i-2]+=score;
		}
		if(i-1>=1 && strike[i-1]>0)
		{
			strike[i-1]--;
			jumsoo[i-1]+=score;
		}
		if(i-1>=1 && spare[i-1]>0)
		{
			spare[i-1]--;
			jumsoo[i-1]+=score;
		}
		before = score;

		if(ch=='S')
			continue;
		ch = str[idx];

		idx++;
		if(ch>='0' && ch<='9')
			score = ch-'0';
		else if(ch=='-')
			score = 0;
		else if(ch=='P')
		{
			score = 10-before;
			spare[i]=1;
		}
		
		jumsoo[i]+=score;
		if(i-1>=1 && strike[i-1]>0)
		{
			strike[i-1]--;
			jumsoo[i-1]+=score;
		}

		if(score == 10)
			spare[i]+=1;
		
	}
	if(strike[10]>0)
	{
		bool check=false;
		char st = str[idx];
		idx++;
		int score;
		if(st>='0' && st<='9')
			score = st-'0';
		else if(st=='-')
			score =0 ;
		else if(st=='S')
		{
			score=10;
			check=true;
		}
		jumsoo[10]+=score;
		if(strike[9]>0)
		{
			jumsoo[9]+=score;
			strike[9]--;
		}

		st=str[idx];
		int before = score;
		if(st>='0' && st<='9')
			score=st-'0';
		else if(st=='-')
			score=0;
		else if(st=='S')
			score=10;
		else if(st=='P')
			score = 10-before;
		jumsoo[10]+=score;
	}
	else if(spare[10]>0)
	{
		char st=str[idx];
		int score;
		if(st>='0' && st<='9')
			score=st-'0';
		else if(st=='-')
			score=0;
		else if(st=='S')
			score=10;
		jumsoo[10]+=score;
	}
	int ans=0;
	for(int i=1;i<=10;i++)
		ans+=jumsoo[i];
	cout << ans;
}
