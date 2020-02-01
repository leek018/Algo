#include <iostream>

using namespace std;
int arr[10000];
int dp[10004];
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int N;
	cin >> N;
	for (int i = 3; i < N + 3; i++)
		cin >> arr[i];

	for (int i = 3; i < N + 3; i++)
	{
		dp[i] = dp[i - 1] < dp[i - 2] + arr[i] ? dp[i - 2] + arr[i] : dp[i - 1];
		dp[i] = dp[i] < dp[i - 3] + arr[i] + arr[i - 1] ? dp[i - 3] + arr[i] + arr[i - 1] : dp[i];
	}
	cout << dp[N + 2];

}