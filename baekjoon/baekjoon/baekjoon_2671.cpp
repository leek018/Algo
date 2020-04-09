#include <iostream>
#include <string>
using namespace std;
string test_seq;
int check_one_start(int pos)
{
	int start = pos + 1;
	int zero_cnt = 0;
	while (start < test_seq.size() && test_seq[start] != '1')
	{
		zero_cnt++;
		start++;
	}
	if (start == test_seq.size() || zero_cnt < 2)
		return -1;
	while (start < test_seq.size() && test_seq[start] != '0')
		start++;
	return start;
}
int check_zero_start(int pos)
{
	int start = pos + 1;
	char next = '1';
	int delta[2] = { 1,-1 };
	int delta_index = 0;
	while (start < test_seq.size() && test_seq[start] == next)
	{
		(++delta_index) %= 2;
		start++;
		next += delta[delta_index];		
	}
	if (start == test_seq.size())
	{
		if (next == '1')
			return -1;
		return start;
	}
	if (test_seq[start] == '0')
		return -1;
	return start;
}

bool recursive(int pos)
{
	if (pos >= test_seq.size())
		return true;
	if (test_seq[pos] == '1')
	{
		int ret = check_one_start(pos);
		if (ret < 0)
			return false;
		bool is_possible = recursive(ret);
		if (is_possible)
			return true;
		if (test_seq[ret - 2] == '1' && test_seq[ret - 1] == '1')
		{
			is_possible = recursive(ret - 1);
			if (is_possible)
				return true;
		}
	}
	else {
		int ret = check_zero_start(pos);
		if (ret < 0)
			return false;
		bool is_possible = recursive(ret);
		if (is_possible)
			return true;
	}
	return false;
}


int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> test_seq;
	bool ret = recursive(0);
	if (ret)
		cout << "SUBMARINE";
	else
		cout << "NOISE";
	return 0;
}