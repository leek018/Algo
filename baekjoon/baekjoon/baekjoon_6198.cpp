#include <iostream>
#include <vector>
using namespace std;
vector<pair<int,int>> stack;
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int N; cin >> N;
	long long answer = 0;
	for (int i = 0; i < N; i++)
	{
		int val; cin >> val;
		if (stack.empty())
			stack.push_back({ i,val });
		else {			
			while (!stack.empty())
			{
				pair<int, int> ret = stack.back();
				if (ret.second > val)
					break;				
				else {
					answer += (long long)(i - ret.first - 1);
					stack.pop_back();
				}
			}
			stack.push_back({ i,val });
		}
	}
	while (!stack.empty())
	{
		answer += (long long)(N - stack.back().first - 1);
		stack.pop_back();
	}
	cout << answer;
	return 0;
}