#include <iostream>

using namespace std;

int N;
int arr[300];
int memo[300][2];

int solve(int idx,int type)
{
	if (idx < 0)
		return 0;
	int ret = memo[idx][type];
	if (ret > 0)
		return ret;
	int max = 0;
	if (!type) {
		int ret_a = solve(idx - 2,0) + arr[idx];
		int ret_b = solve(idx - 1,1) + arr[idx];
		max = ret_a < ret_b ? ret_b : ret_a;
	}
	else {
		int ret_c = solve(idx - 2,0) + arr[idx];
		max = max < ret_c ? ret_c : max;
	}
	
	return memo[idx][type] = max;
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> N;
	for (int i = 0; i < N; i++)
		cin >> arr[i];
	memo[0][1] = arr[0];	
	int ret = solve(N - 1,0);
	cout << ret << "\n";
	return 0;
}