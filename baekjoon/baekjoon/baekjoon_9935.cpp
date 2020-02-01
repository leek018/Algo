#include <iostream>
#include <string>
#include <vector>
using namespace std;

vector<int> wating;
string input;
string reference;
vector<int> candidate;
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> input;
	cin >> reference;	
	int referSize = reference.size();
	for (int i = 0; i < input.size(); i++)
	{
		if (input[i] == reference[0])
			candidate.push_back(i);
	}	
	int firstPos = candidate[0];
	int lastPos = input.size();

	for (int i = candidate.size() - 1; i >= 0; i--)
	{
		int targetIdx = candidate[i];
		for (int j = lastPos - 1; j >= targetIdx; j--)
			wating.push_back(j);
		int count = 0;
		int len = wating.size()-1;
		for (int j = 0; j < referSize; j++)
		{
			if (len - j < 0)
				break;
			if (input[wating[len - j]] == reference[j])
				count++;
			else
				break;
		}
		if (count == referSize)
		{
			for (int j = 0; j < referSize; j++)
				wating.pop_back();
		}
		lastPos = targetIdx;
	}		
	for (int i = firstPos-1; i >= 0; i--)
		wating.push_back(i);
	string answer = "";
	
	if (wating.size() == 0)
		answer = "FRULA";
	else {
		for (int j = wating.size() - 1; j >= 0; j--)
			answer += input[wating[j]];
	}
	cout << answer;
	return 0;
}

