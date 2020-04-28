#include <iostream>
#include <vector>
#include <queue>
using namespace std;
queue<int> q;
vector<int> answer;
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int N, K; cin >> N >> K;	
	for (int i = 1; i <= N; i++)
		q.push(i);
	int count = 0;
	while (!q.empty())
	{
		int ret = q.front();
		q.pop();
		count++;
		if (count == K)
		{
			count = 0;
			answer.push_back(ret);
		}
		else
			q.push(ret);
	}
	cout << "<" << answer[0];
	for (int i = 1; i < answer.size(); i++)
		cout << ", " << answer[i];
	cout << ">";
	return 0;
}