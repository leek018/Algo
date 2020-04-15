#include <iostream>
#include <vector>
using namespace std;

vector<int> node[1001];
bool visit[1001];
void solve(int target)
{
	if (visit[target])
		return;
	visit[target] = true;
	for (int i = 0; i < node[target].size(); i++)	
		solve(node[target][i]);	
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int N,M; cin >> N >> M;
	for (int i = 0; i < M; i++)
	{
		int u, v; cin >> u >> v;
		node[u].push_back(v);
		node[v].push_back(u);
	}
	int answer = 0;
	for (int i = 1; i <= N; i++)
	{
		if (!visit[i])
		{
			answer++;
			solve(i);
		}			
	}
	cout << answer;
	return 0;
}