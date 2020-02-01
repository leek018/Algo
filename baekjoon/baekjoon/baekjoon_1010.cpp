#include <iostream>

using namespace std;
int memo[30][30];
int combi(int n, int r)
{
	if (n == r || r == 0)
		return 1;
	int ret = memo[n][r];
	if (ret > 0)
		return ret;
	int res = combi(n - 1, r - 1) + combi(n-1, r);
	return memo[n][r] = res;
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int N;
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		int n, r;
		cin >> r >> n;
		cout << combi(n, r) << "\n";
	}
	return 0;

}