#include <iostream>

using namespace std;
long long arr[1000000];
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int N;
	cin >> N;
	for (int i = 0; i < N; i++)
		cin >> arr[i];
	long long b, c;
	cin >> b >> c;
	long long answer = N;
	for (int i = 0; i < N; i++)
	{
		long long rem = arr[i] - b;
		if (rem <= 0)
			continue;
		long long q = rem / c;
		long long r = rem % c;
		answer += q;
		if (r > 0)
			answer += 1LL;
	}
	cout << answer;
}