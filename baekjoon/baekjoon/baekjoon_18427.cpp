#include <iostream>
#include <string>
#include <fstream>
#include <algorithm>
#include <vector>
using namespace std;
vector<int> StudentBlock[50];
vector<int> NMH;
int dp[50][1001];
void parsingInput(string& input, vector<int>& target)
{
	int tempSum = 0;
	int digit = 1;
	for (int i = input.size() - 1; i >= 0; i--)
	{				
		char inputElementVal = input[i];
		if (inputElementVal == ' ') {
			target.push_back(tempSum);
			digit = 1;
			tempSum = 0;
		}			
		else {			
			tempSum += digit * (inputElementVal - '0');
			digit *= 10;
		}
			
	}
	target.push_back(tempSum);
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	string input;
	getline(cin, input);	
	parsingInput(input, NMH);			
		
	int N = NMH[2]; int M = NMH[1]; int H = NMH[0];
	for (int i = 0; i < N; i++)
	{
		getline(cin, input);		
		StudentBlock[i].push_back(0);
		parsingInput(input, StudentBlock[i]);		
		sort(StudentBlock[i].begin(), StudentBlock[i].end());
	}

	dp[0][0] = 1;
	for (int i = 0; i < StudentBlock[0].size(); i++)
	{
		int blockH = StudentBlock[0][i];
		if(blockH <= H)
			dp[0][blockH] = 1;
	}
	for (int i = 1; i < N; i++)
	{
		for (int j = 0; j < StudentBlock[i].size(); j++)
		{
			int blockH = StudentBlock[i][j];
			for (int k = 0; k <= H; k++)
			{
				int beforeDpVal = dp[i - 1][k];
				if (beforeDpVal > 0 && blockH <= H && blockH+k <=H)				
					dp[i][blockH + k] = (dp[i][blockH+k]+beforeDpVal)%10007;				
			}
		}
	}
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j <= H; j++)
			cout << dp[i][j] << " ";
		cout << "\n";
	}
	cout << dp[N - 1][H];	
	return 0;
}