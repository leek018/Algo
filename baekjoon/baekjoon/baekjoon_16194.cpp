#include <iostream>
using namespace std;
int memo[1001];
int price[1001];
int minCost(int N)
{
	if (N == 0)
		return 0;
	int ret = memo[N];
	if (ret > 0)
		return ret;
	int minVal = 10000000;
	for (int i = 1; i <= N; i++)
	{
		int localMin = minCost(N - i) + price[i];
		minVal = minVal > localMin ? localMin : minVal;
	}
	return memo[N] = minVal;
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int N;	cin >> N;
	for (int i = 1; i <= N; i++)	
		cin >> price[i];	
	cout << minCost(N);
	return 0;
}