#include <stdio.h>
#include <stack>
#include <string.h>
#include <queue>
#include <iostream>
using namespace std;
long int ll = 1000000000;
int main(void)
{
	queue<string> ss;
	while(1)
	{
		char str[100];
		cin.getline(str,100);
		if(strlen(str)==0)
		{

			continue;
		}
		if(strcmp(str,"QUIT")==0)
			return 0;
		else if(strcmp(str,"END")==0)
		{
			int t;
			scanf("%d",&t);
			
			for(int i=0;i<t;i++)
			{
				int num;
				scanf("%d",&num);
				stack<long int> data;

				data.push(num);
				queue<string> st = ss;
				bool check=true;
				while(!st.empty())
				{

					string ch = st.front();

					if(ch=="DUP")
					{

						if(data.size()==0)
						{
							check=false;
							break;
						}
						int tt = data.top();
						data.push(tt);
					}
					else if(ch=="POP")
					{
						if(data.size()==0)
						{
							check=false;
							break;
						}
						data.pop();
					}
					else if(ch=="INV")
					{
						if(data.size()==0)
						{
							check=false;
							break;
						}
						int tt = data.top();
						tt=-tt;
						data.pop();
						data.push(tt);
					}
					else if(ch=="SWP")
					{
						if(data.size()<=1)
						{
							check=false;
							break;
						}
						int first = data.top();
						data.pop();
						int second=data.top();
						data.pop();
						data.push(first);
						data.push(second);
					}
					else if(ch=="ADD")
					{
						if(data.size()<=1)
						{
							check=false;
							break;
						}
						long int first = data.top();
						data.pop();
						long int second=data.top();
						if(first+second>1000000000)
						{
							check=false;
							break;
						}
						data.pop();
						data.push(first+second);
					}
					else if(ch=="SUB")
					{
						if(data.size()<=1)
						{
							check=false;
							break;
						}
						long int first = data.top();
						data.pop();
						long int second=data.top();
						if(second-first<-1000000000)
						{
							check=false;
							break;
						}
						data.pop();
						data.push(second-first);
					}
					else if(ch=="MUL")
					{
						if(data.size()<=1)
						{
							check=false;
							break;
						}
						long int first = data.top();
						data.pop();
						long int second=data.top();
						if(first*second>ll)
						{
							check=false;
							break;
						}
						data.pop();
						data.push(first*second);

					}
					else if(ch=="DIV")
					{
						if(data.size()<=1)
						{
							check=false;
							break;
						}
						
						long int first = data.top();
						data.pop();
						long int second=data.top();

						if(first==0)
						{
							check=false;
							break;
						}
						data.pop();
						if(first<0 && second>=0)
						{
							first=-first;
							data.push(-(second/first));
						}
						else if(first>0 && second<=0)
						{
							second=-second;
							data.push(-(second/first));
						}
						else if(first<0 && second<=0)
						{
							first=-first;
							second=-second;
							data.push(second/first);
						}
						else
							data.push(second/first);
					}
					else if(ch=="MOD")
					{
						if(data.size()<=1)
						{
							check=false;
							break;
						}
						long int first = data.top();

						data.pop();
						long int second=data.top();
						if(second==0)
						{
							check=false;
							break;
						}
						data.pop();
						if(first<0 && second>=0)
						{
							first=-first;
							data.push(second%first);
						}
						else if(first>0 && second<=0)
						{
							second=-second;
							data.push(-(second%first));
						}
						else if(first<0 && second<=0)
						{
							first=-first;
							second=-second;
							data.push(-(second%first));
						}
						else
							data.push(second%first);
					}
					else
					{

						string pushs = ch.substr(4);

						int numm = atol(pushs.c_str());

						data.push(numm);
					}						
					st.pop();
				}
				if(check==false)
				{
					printf("ERRROR\n");
					while(!data.empty())
						data.pop();
					continue;
				}
				if(data.size()==1 && check==true)
				{
					printf("%ld\n",data.top());
					while(!data.empty())
						data.pop();
				}
				else
				{
					while(!data.empty())
						data.pop();
					printf("ERROR\n");
				}
			}

			while(!ss.empty())
			{
				ss.pop();
			}
			printf("\n");
		}
		else
		{
			ss.push(str);
		}



	}
}
