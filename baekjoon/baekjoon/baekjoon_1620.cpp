#include <iostream>
#include <map>
#include <string>
using namespace std;
map<string, int> word2idx;
map<int, string> idx2word;
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int N, M; cin >> N >> M;
	int start = 1;
	for (int i = 0; i < N; i++)
	{
		string poketmon; cin >> poketmon;
		pair<map<string, int>::iterator, bool> ret = word2idx.insert({ poketmon,start });
		if (ret.second) {
			idx2word[start] = poketmon;
			start++;
		}
	}	
	for (int i = 0; i < M; i++)
	{
		string input; cin >> input;
		if (input.find_first_not_of("0123456789") == string::npos)
		{
			int target = stoi(input);
			cout << idx2word[target] << "\n";
		}
		else
			cout << word2idx[input] << "\n";
	}
	return 0;
}