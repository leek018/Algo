#include <iostream>
using namespace std;

int N;
long long memo[91][91];
long long combi(int n, int r)
{	
	if (n == r || r == 0)
		return memo[n][r] = 1LL;	
	long long val = memo[n][r];
	if (val >= 0)
		return val;
	return memo[n][r] = combi(n - 1, r - 1) + combi(n - 1, r);
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> N;
	for (int i = 0; i <= 90; i++)
		fill_n(memo[i], 91, -1);
	long long  sum = 0;
	int limit = N / 2;
	if (N % 2 == 1)
		limit++;
	for (int i = 1; i <= limit; i++)
		sum += combi(N - i, i-1);
	cout << sum;
	return 0;
}