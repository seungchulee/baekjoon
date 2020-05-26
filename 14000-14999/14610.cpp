#include <iostream>
using namespace std;
int n,m;
int correct_list[101];
int score_list[11];
int board[101][11];
int main(void)
{
	cin >> n >> m;
	for(int i=0;i<n;i++)
	{
		cin >> correct_list[i];
		if(correct_list[i]==0 || correct_list[i]==m)
		{
			cout << "NO";
			return 0;
		}
		int one = 0;
		for(int j=0;j<m;j++)
		{
			cin >> board[i][j];
			if(board[i][j]==1)
			{
				one++;
			}
			if(one==correct_list[i] && board[i][j]==-1)
				board[i][j]=0;
		}
		correct_list[i]-=one;
	}
	for(int j=0;j<m;j++)
	{
		int cnt=0;
		for(int i=0;i<n;i++)
		{
			if(board[i][j]==1)
				cnt++;
		}
		score_list[j]=cnt;
	}
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			if(board[i][j]==-1 && correct_list[i]>0)
			{
				if(score_list[j]==0)
				{
					board[i][j]=1;
					score_list[j]++;
					correct_list[i]--;
				}
			}
		}
	}

	for(int i=0;i<m;i++)
	{
		if(score_list[i]==0)
		{
			cout << "NO";
			return 0;
		}
	}
	cout << "YES";
				
}
