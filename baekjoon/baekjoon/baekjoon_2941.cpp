#include <iostream>
#include <string>
using namespace std;
string input;
int e_f(int pos)
{
	char val = input[pos - 1];
	if (val == 'c' || val == 's')
		return 2;
	if (val == 'z')
	{
		if (pos - 2 >= 0 && input[pos - 2] == 'd')
			return 3;		
	}
	return 2;
}
int j_f(int pos)
{
	if (pos - 1 >= 0)
	{
		char val = input[pos - 1];
		if (val == 'l' || val == 'n')
			return 2;
	}
	return 1;
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> input;
	int start = input.size() - 1;
	int answer = 0;
	while (start >= 0)
	{
		if (input[start] == '=')
		{
			int ret = e_f(start);
			start -= ret;
		}
		else if (input[start] == '-')
			start -= 2;
		else if (input[start] == 'j')
		{
			int ret = j_f(start);
			start -= ret;
		}
		else
			start -= 1;
		answer++;
	}
	cout << answer;
	return 0;
}