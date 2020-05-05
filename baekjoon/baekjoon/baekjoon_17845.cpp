#include <iostream>
using namespace std;
int dp[10001];
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int N, K; cin >> N >> K;
	for (int i = 0; i < K; i++)
	{
		int val, time; cin >> val >> time;
		for (int j = N; j >= time; j--)
		{
			int compareVal = dp[j - time] + val;
			if (dp[j] < compareVal)			
				dp[j] = compareVal;
			
		}
	}
	cout << dp[N];
	return 0;
}