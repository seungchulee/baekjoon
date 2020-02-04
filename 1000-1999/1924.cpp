#include <string>
#include <vector>
#include <iostream>

using namespace std;
int day(int a)
{
    if(a==1)
        return 0;
    else if(a==2)
        return 31;
    else if(a==3)
        return 28+day(2);
    else if(a==4)
        return 31+day(3);
    else if(a==5)
        return 30+day(4);
    else if(a==6)
        return 31+day(5);
    else if(a==7)
        return 30+day(6);
    else if(a==8)
        return 31+day(7);
    else if(a==9)
        return 31+day(8);
    else if(a==10)
        return 30+day(9);
    else if(a==11)
        return 31+day(10);
    else if(a==12)
        return 30+day(11);
}
int main(void) {
	string answer;
	int a,b;
	scanf("%d %d",&a,&b);
	int date = day(a)+b;
    date--;
    if(date%7==0)
        answer="MON";
    else if(date%7==1)
        answer="TUE";
    else if(date%7==2)
        answer="WED";
    else if(date%7==3)
        answer="THU";
    else if(date%7==4)
        answer="FRI";
    else if(date%7==5)
        answer="SAT";
    else
        answer="SUN";
    
	cout << answer;
	
}
