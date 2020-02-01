#include <iostream>
#include <string>
#include <vector>

using namespace std;
vector<int> origin;
vector<int> buffer;
string input;
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int T;
	cin >> T;
	for (int test_case = 1; test_case <= T; test_case++)
	{
		cin >> input;
		origin.clear();
		buffer.clear();
		for (int i = 0; i < input.size(); i++)
		{
			if (input[i] == '<')
			{
				if (!origin.empty()) {
					int targetIdx = origin.back();
					origin.pop_back();
					buffer.push_back(targetIdx);
				}				
			}
			else if (input[i] == '>')
			{
				if (!buffer.empty())
				{
					int savedIdx = buffer.back();
					buffer.pop_back();
					origin.push_back(savedIdx);
				}
			}
			else if (input[i] == '-')
			{				
				if (!origin.empty())				
					origin.pop_back();				
			}
			else {
				origin.push_back(i);
			}
		}
		while (!buffer.empty())
		{
			int savedIdx = buffer.back();
			buffer.pop_back();
			origin.push_back(savedIdx);
		}
		string answer = "";
		for (int i = 0; i < origin.size(); i++)
		{
			int targetIdx = origin[i];
			answer += input[targetIdx];
		}
		cout << answer << "\n";
	}

	
}