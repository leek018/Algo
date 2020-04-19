#include <iostream>
#include <string>
#include <vector>
using namespace std;

string map[5];
int bit[10];
vector<int> info[10];
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	info[0] = { 0,1,2,3,5,6,8,9,11,12,13,14 };
	info[1] = { 2,5,8,11,14 };
	info[2] = { 0,1,2,5,6,7,8,9,12,13,14 };
	info[3] = { 0,1,2,5,6,7,8,11,12,13,14 };
	info[4] = { 0,2,3,5,6,7,8,11,14 };
	info[5] = { 0,1,2,3,6,7,8,11,12,13,14 };
	info[6] = { 0,1,2,3,6,7,8,9,11,12,13,14 };
	info[7] = { 0,1,2,5,8,11,14 };
	info[8] = { 0,1,2,3,5,6,7,8,9,11,12,13,14 };
	info[9] = { 0,1,2,3,5,6,7,8,11,12,13,14 };
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < info[i].size(); j++)		
			bit[i] |= (1 << info[i][j]);		
	}	
	for (int i = 0; i < 5; i++)
		getline(cin, map[i]);
	int str_len = map[0].size();
	string answer = "BOOM!!";
	if (str_len % 4 == 3) {
		int digit = 0;
		int start = 0;
		bool isFind = false;
		while (start < str_len)
		{
			int count = 0;
			int temp = 0;
			for (int i = 0; i < 5; i++)
			{
				for (int j = start; j < start + 3; j++)
				{
					if (map[i][j] == '*')
						temp |= (1 << count);
					count++;
				}
			}
			isFind = false;
			for (int i = 0; i < 10; i++)
			{
				if (bit[i] == temp)
				{
					digit = digit * 10 + i;
					isFind = true;
					break;
				}
			}
			if (!isFind) {
				answer = "BOOM!!";
				break;
			}
			start += 4;
		}		
		if (isFind && digit % 6 == 0)
			answer = "BEER!!";
	}
	cout << answer << "\n";
	return 0;	
}