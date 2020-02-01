#include <iostream>
#include <vector>
#include <string>
using namespace std;

vector<int> graph[26];

int SentenceOri[10000];
int SentenceVary[10000];
int doyouKnowsentence(int N)
{
	int answer = 0;
	for (int i = 0; i < N; i++)
	{
		if (SentenceOri[i] == SentenceVary[i])
			answer++;
	}
	return answer;
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	
	int N, M;
	cin >> N >> M;
	for (int i = 0; i < N; i++)
	{
		string input; cin >> input;
		bool visit[26];
		fill_n(visit, 26, false);
		for (int j = 0; j < input.size(); j++)
		{
			int alphabet = input[j] - 'a';
			visit[alphabet] = true;
		}
		int count = 0;
		for (int j = 0; j < 26; j++)
		{
			if (visit[j]) {
				graph[j].push_back(i);
				count++;
			}
				
		}
		SentenceOri[i] = count;
		SentenceVary[i] = count;
	}	
	for (int i = 0; i < M; i++)
	{
		int queryType; cin >> queryType;
		char target; cin >> target;
		int targetAlphabet = target - 'a';
		int plusVal = 1;
		if (queryType == 1)
			plusVal = -1;		
		for (int j = 0; j < graph[targetAlphabet].size(); j++)
		{
			int targetIdx = graph[targetAlphabet][j];
			SentenceVary[targetIdx] += plusVal;
		}
		int ret = doyouKnowsentence(N);
		cout << ret << "\n";
	}
	return 0;
}