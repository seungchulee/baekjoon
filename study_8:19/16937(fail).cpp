#include <stdio.h>
#include <algorithm>
using namespace std;
int H,W,N;
int R[100];
int C[100];
int c[10]={false};
int arr[2];
int area=0;
void func(int index,int start)
{
	if(index==2)
	{

		int ar=arr[0];
		int br=arr[1];
		bool flag=true;
		int result=C[ar]*R[ar]+C[br]*R[br];

		if(C[ar]+C[br]<=W && R[ar]<=H && R[br]<=H)
			flag=false;
		if(C[ar]+R[br]<=W && R[ar]<=H && C[br]<=H)
			flag=false;
		if(R[ar]+R[br]<=H && C[ar]<=W && C[br]<=W)
			flag=false;
		if(R[ar]+C[br]<=H && C[ar]<=W && R[br]<=W)
			flag=false;
		if(R[ar]+C[br]<=W && C[ar]<=H && R[br]<=H)
			flag=false;
		if(R[ar]+R[br]<=W && C[ar]<=H && C[br]<=H)
			flag=false;
		if(C[ar]+R[br]<=H && R[ar]<=W && C[br]<=W)
			flag=false;
		if(C[ar]+C[br]<=H && R[ar]<=W && R[br]<=W)
			flag=false;
//		printf("%d %d\n",result,flag);	
		if(flag==true)
			return;
		if(result>area)
			area=result;

		return;
	}
	for(int i=0;i<N;i++)
	{
		if(c[i]==true)
			continue;
		arr[index]=i;
		c[i]=true;

		func(index+1,i+1);
		c[i]=false;


	}
}
int main(void)
{
	scanf("%d %d",&H,&W);
	scanf("%d",&N);
	for(int i=0;i<N;i++)
	{
		scanf("%d %d",&R[i],&C[i]);
	}
	func(0,0);
	printf("%d",area);
}
