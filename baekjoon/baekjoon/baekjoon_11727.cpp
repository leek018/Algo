#include <iostream>
#define Q 10007
using namespace std;
int memo[1000];
int N;
int solve(int start)
{
	if (start == N)
		return 1;
	int val = memo[start];
	if (val >= 0)
		return val;
	int sum = 0;
	sum = (sum + solve(start + 1)) % Q;
	if (start + 2 <= N)
		sum = (sum + 2*solve(start + 2)) % Q;	
	return memo[start] = sum;
}
int main()
{
	cin >> N;
	fill_n(memo, 1000, -1);
	cout << solve(0);
	return 0;
}