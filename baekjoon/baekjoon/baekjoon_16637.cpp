#include <iostream>
#include <string>
using namespace std;

string equation;

int cal(int left, int right, char& oper)
{
	if (oper == '*')
		return left * right;
	else if (oper == '+')
		return left + right;
	else
		return left - right;
}
int answer = -1000000;

void solve(int left, int idx,int len)
{			
	
	if (idx == len - 2)
	{
		int ret = cal(left, equation[idx + 1] - '0', equation[idx]);
		answer = answer < ret ? ret : answer;
		return;
	}
	if (idx + 2 < len) {
		int temp = cal(equation[idx + 1] - '0', equation[idx + 3] - '0', equation[idx + 2]);
		temp = cal(left, temp, equation[idx]);
		solve(temp, idx + 4, len);
	}
		
	
		

}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int N;
	cin >> N;
	cin >> equation;
	solve(0, 1, N);
	cout << answer;
	return 0;

}