#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
bool comp(const pair<int, int>& a, const pair<int, int>& b)
{
	return a.first < b.first;
}
int arr[26];
vector<pair<int, int>> buffer;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	string input; cin >> input;
	for (int i = 0; i < input.size(); i++)	
		arr[input[i] - 'A']++;
	int odd_cnt = 0;
	for (int i = 0; i < 26; i++)
	{
		if (arr[i] > 0) {
			buffer.push_back({ i,arr[i] });
			if (arr[i] % 2 == 1)
				odd_cnt++;
		}			
	}	
	string answer = "I'm Sorry Hansoo";
	if (odd_cnt == 0 || odd_cnt == 1)
	{
		answer = "";
		sort(buffer.begin(), buffer.end());
		int odd_index = -1;
		for (int i = 0; i < buffer.size(); i++)
		{
			pair<int, int>& ele = buffer[i];
			if (ele.second % 2 == 1)
				odd_index = i;
			for (int j = 0; j < ele.second / 2; j++)
				answer += (char)('A' + ele.first);
		}
		if (odd_index >= 0)
			answer += (char)('A' + buffer[odd_index].first);
		for (int i = buffer.size() - 1; i >= 0; i--)
		{
			pair<int, int>& ele = buffer[i];			
			for (int j = 0; j < ele.second / 2; j++)
				answer += (char)('A' + ele.first);
		}
	}
	cout << answer;
	return 0;
}