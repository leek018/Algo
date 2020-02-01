#include <iostream>
#include <cstring>
#include <string>
using namespace std;

struct Trie {
	bool isDone = false;
	Trie* number[10];
	Trie() {
		memset(number, 0, sizeof(number));
	}
	~Trie()
	{
		for (int i = 0; i < 10; i++)
		{
			if (number[i])
				delete number[i];
		}
	}
	
};

bool check(Trie* origin,string &tel)
{
	Trie* temp = origin;
	for (int k = 0; k < tel.size(); k++)
	{
		int idx = tel[k] - '0';
		if (temp->number[idx] == NULL)		
			temp->number[idx] = new Trie();
		else {
			if (k == tel.size() - 1)
				return false;
		}
		temp = temp->number[idx];
		if (temp->isDone)
			return false;
	}
	
	temp->isDone = true;
	return true;
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int T;
	cin >> T;
	for (int test_case = 1; test_case <= T; test_case++)
	{
		int N;
		cin >> N;
		Trie* trie = new Trie();
		bool possible = true;
		for (int j = 0; j < N; j++)
		{
			string tel;
			cin >> tel;						
			if (!check(trie, tel))
				possible = false;			
		}
		if (possible)
			cout << "YES\n";
		else
			cout << "NO\n";
		delete trie;
	}
}