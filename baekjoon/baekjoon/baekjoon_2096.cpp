#include <iostream>

using namespace std;

int min_dp[3];
int max_dp[3];


int N;
int arr[100000][3];


int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	
	
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < 3; j++)
			cin >> arr[i][j];
	}	
		
	for (int i = N - 1; i >= 0; i--)
	{		
		int ret_a = max_dp[0] + arr[i][0];
		int ret_b = max_dp[1] + arr[i][0];
	
		int max_a = ret_a < ret_b ? ret_b : ret_a;

		int ret_c = max_dp[0] + arr[i][1];
		int ret_d = max_dp[1] + arr[i][1];
		int ret_e = max_dp[2] + arr[i][1];

		int max_b = ret_c < ret_d ? ret_d : ret_c;
		max_b = max_b < ret_e ? ret_e : max_b;

		int ret_f = max_dp[1] + arr[i][2];
		int ret_g = max_dp[2] + arr[i][2];
		
		int max_c = ret_f < ret_g ? ret_g : ret_f;

		max_dp[0] = max_a;
		max_dp[1] = max_b;
		max_dp[2] = max_c;

		ret_a = min_dp[0] + arr[i][0];
		ret_b = min_dp[1] + arr[i][0];

		int min_a = ret_a < ret_b ? ret_a : ret_b;

		ret_c = min_dp[0] + arr[i][1];
		ret_d = min_dp[1] + arr[i][1];
		ret_e = min_dp[2] + arr[i][1];

		int min_b = ret_c < ret_d ? ret_c : ret_d;
		min_b = min_b > ret_e ? ret_e : min_b;

		ret_f = min_dp[1] + arr[i][2];
		ret_g = min_dp[2] + arr[i][2];

		int min_c = ret_f < ret_g ? ret_f : ret_g;

		min_dp[0] = min_a;
		min_dp[1] = min_b;
		min_dp[2] = min_c;
	}
	int max = 0;
	int min = 900001;
	for (int i = 0; i < 3; i++)
	{
		max = max < max_dp[i] ? max_dp[i] : max;
		min = min > min_dp[i] ? min_dp[i] : min;
	}
	cout << max << " " << min << "\n";	
	return 0;
}