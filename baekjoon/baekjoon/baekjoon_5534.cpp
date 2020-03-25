#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
vector<int> firstCharIndex, secondCharIndex;
string baseString;
bool isRight(string &target,int start, int diff)
{
	int point = 2;
	while (point < baseString.size())
	{
		if (start + diff >= target.size() || target[start + diff] != baseString[point])
			return false;
		point++;
		start += diff;
	}
	return true;
}
bool solve(string& input)
{
	for (int i = 0; i < firstCharIndex.size(); i++)
	{
		int firstIndex = firstCharIndex[i];
		bool possible = false;
		for (int j = 0; j < secondCharIndex.size(); j++)
		{
			int secondIndex = secondCharIndex[j];
			int diff = secondIndex - firstIndex;
			if (diff > 0)
			{
				possible = true;
				if (isRight(input, secondIndex, diff))
					return true;
			}
		}
		if (!possible)
			return false;
	}
	return false;
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int answer = 0;
	int N;
	cin >> N;
	cin >> baseString;	
	for (int i = 0; i < N; i++)
	{
		string input; cin >> input;
		firstCharIndex.clear(); secondCharIndex.clear();
		for (int j = 0; j < input.size(); j++)
		{
			if (input[j] == baseString[0])
				firstCharIndex.push_back(j);
			if (input[j] == baseString[1])
				secondCharIndex.push_back(j);
		}
		sort(firstCharIndex.begin(), firstCharIndex.end());
		sort(secondCharIndex.begin(), secondCharIndex.end());
		if (solve(input))
			answer++;		
	}
	cout << answer;
	return 0;
}