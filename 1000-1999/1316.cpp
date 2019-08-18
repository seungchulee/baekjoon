#include <stdio.h>
#include <string.h>
bool check[26]={false};
int main(void)
{
	int N;
	scanf("%d",&N);
	int checks=0;

	for(int i=0;i<N;i++)
	{
		char str[101];
		scanf("%s",str);
		bool ch=false;	
		for(int i=0;i<26;i++)
			check[i]=false;
		for(int j=0;j<strlen(str);)
		{
			if(check[str[j]-'a'] == false)
			{
				while(1)
				{
					if(str[j]==str[j+1])
					{
						j++;
					}
					else
					{

						break;
					}
				}
				check[str[j]-'a']=true;
				j++;
			}
			else
			{
				ch=true;
				break;
			}
		}
		
		if(ch==false)
		{

			checks++;
		}
		
	}
	printf("%d",checks);
}



