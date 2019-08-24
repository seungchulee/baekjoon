#include <stdio.h>
#include <queue>
#include <string>
#include <utility>
#include <iostream>
using namespace std;

int main(void)
{
	string S;
	string T;
	cin >> S;
	cin >> T;
	
	bool result=false;
	while(1)
	{
		if(S.length()==T.length())
		{
			if(S==T)
			{
				result=true;
				break;
			}
			else
			{
				result=false;
				break;
			}
		}
		char st=T.back();
		if(st=='A')
		{
			T.pop_back();
		}
		else
		{
			T.pop_back();
			reverse(T.begin(),T.end());	
		}
	}
	printf("%d",result);
	
}
