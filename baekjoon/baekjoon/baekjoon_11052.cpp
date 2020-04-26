#include <iostream>
using namespace std;
int memo[1001];
int arr[1001];

int solve(int N)
{
	if (N == 0)
		return 0;
	int val = memo[N];
	if (val > 0)
		return val;
	int localMax = 0;
	for (int i = 1; i <= N; i++)
	{
		if (N - i >= 0)
		{
			int ret = solve(N - i) + arr[i];
			if (localMax < ret)
				localMax = ret;			
		}
		else
			break;
	}
	return memo[N] = localMax;
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int N; cin >> N;
	for (int i = 1; i <= N; i++)
		cin >> arr[i];
	int answer = solve(N);
	cout << answer;
	return 0;
}