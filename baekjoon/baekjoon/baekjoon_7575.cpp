#include <iostream>
#include <vector>
using namespace std;
vector<int> map[100];
int N, K;
struct Trie {
	Trie* child[10001];
	bool visit[100];
	int count = 0;
	bool insert(int number, int start, int last,int type)
	{
		if (start == last)
		{
			if (!visit[number]) {
				count++;
				visit[number] = true;
			}				
			if (count == N)
				return true;
			return false;
		}
		if (child[map[number][start]] == NULL)
			child[map[number][start]] = new Trie();
		return child[map[number][start]]->insert(number, start + type, last,type);
	}
};
Trie tree;
bool check()
{
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j <= map[i].size() - K; j++)
		{
			int start = j; int last = j + K - 1;
			if (tree.insert(i, start, last, 1))
				return true;			
		}
		for (int j = map[i].size() - 1; j > K - 1; j--)
		{
			int start = j; int last = j - K + 1;
			if (tree.insert(i, start, last, -1))
				return true;			
		}		
	}
	return false;
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> N >> K;
	for (int i = 0; i < N; i++)
	{
		int M; cin >> M;
		for (int j = 0; j < M; j++)
		{
			int val; cin >> val;
			map[i].push_back(val);
		}			
	}		
	if (check())
		cout << "YES";
	else
		cout << "NO";
	return 0;
}