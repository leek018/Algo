#include <iostream>

using namespace std;
long long arr[15];
int N;
pair<long long, long long> solve(int idx)
{
	if (idx == N-1)
	{
		return { 1LL,arr[N-1] };
	}
	pair<long long, long long> ret = solve(idx+1);
	return { ret.second,ret.second * arr[idx] + ret.first };	
}


int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> N;
	for (int i = 0; i < N; i++)
		cin >> arr[i];
	pair<long long, long long> ret = solve(0);
	cout << ret.second - ret.first << " " << ret.second << "\n";
	return 0;
}