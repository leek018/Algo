#include <iostream>
#include <string>
#define REF 1000000
using namespace std;
string input;
int memo[5000];
int solve(int pos)
{
	if (pos == input.size())
		return 1;
	int val = memo[pos];
	if (val >= 0)
		return val;
	int sum = 0;
	if (input[pos] != '0')
	{
		int ret_a = solve(pos + 1);
		sum = (sum + ret_a) % REF;
	}
	if (pos + 1 < input.size())
	{
		int num = 10 * (input[pos] - '0') + (input[pos + 1] - '0');
		if (num >= 10 && num <= 26)
		{
			int ret_b = solve(pos + 2);
			sum = (sum + ret_b) % REF;			
		}
	}
	return memo[pos] = sum;
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> input;
	fill_n(memo, 5000, -1);	
	int answer = solve(0);	
	cout << answer;
	return 0;
}