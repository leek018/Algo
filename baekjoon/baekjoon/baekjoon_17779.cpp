#include <iostream>
using namespace std;
int N;
int map[20][20];
int sum[6];
int check[20][20];
int dx[] = { -1,1,1,-1 };
int dy[] = { 1,1,-1,-1 };
void getFirst(pair<int, int> &first, pair<int, int> &third)
{	
	int maxH = third.second;
	for (int j = first.first; j >= 0; j--)
	{
		int height = first.second + first.first-j;
		if (height > maxH) height = maxH;
		for (int i = 0; i < height; i++)
			check[i][j] = 1;
	}
	
}
void getSecond(pair<int, int>& second, pair<int, int>& one)
{	
	int maxH = one.first;
	for (int i = second.second; i >= 0; i--)
	{
		int height = second.first - (second.second - i);
		if (height < maxH) height = maxH;
		for (int j = N-1; j > height; j--)
			check[i][j] = 2;
	}	
}
void getThird(pair<int, int>& third, pair<int, int>& fourth)
{	
	int maxH = fourth.first;
	for (int i = third.second; i < N; i++)
	{
		int height = third.first + i-third.second;
		if (height > maxH) height = maxH;
		for (int j = 0; j < height; j++)
			check[i][j] = 3;
	}
	
}
void getFourth(pair<int, int>& fourth, pair<int, int>& second)
{	
	int maxH = second.second;
	for (int j = fourth.first; j < N; j++)
	{
		int height = fourth.second - (j-fourth.first);
		if (height < maxH) height = maxH;
		for (int i = N - 1; i > height; i--)
			check[i][j] = 4;
	}	
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);	
	cin >> N; 

	for (int i = 0; i < N; i++)
	{
		
		for (int j = 0; j < N; j++)
			cin >> map[i][j];
	}
	int Answer = 1e9;	
	for (int i = 0; i < N - 2; i++)
	{
		for (int j = 1; j < N - 1; j++)
		{
			for (int d1 = 1; d1 <= j; d1++)
			{
				for (int d2 = 1; d2 < N - j; d2++)
				{
					pair<int, int> first,second,third,fourth;
					first = { j,i };
					second = { j + d2,i + d2 };
					third = { j - d1,i + d1 };
					fourth = { j - d1 + d2,i + d1 + d2 };
					if (fourth.second >= N)
						break;
					fill_n(sum, 6, 0);
					for (int m = 0; m < N; m++)
						fill_n(check[m], N, 5);
					getFirst(first, third);
					getSecond(second, first);
					getThird(third, fourth);
					getFourth(fourth, second);
					int maxSum = 0;
					int minSum = 1e9;					
					for (int m = 0; m < N; m++)
					{
						for (int n = 0; n < N; n++)
						{
							int target = check[m][n];
							int val = map[m][n];
							sum[target] += val;
						}
					}
					for (int m = 1; m <= 5; m++)
					{						
						maxSum = maxSum < sum[m] ? sum[m] : maxSum;
						minSum = minSum > sum[m] ? sum[m] : minSum;
					}					
					Answer = Answer > maxSum - minSum ? maxSum - minSum : Answer;
				}
			}
		}
	}
	cout << Answer;
	return 0;
}