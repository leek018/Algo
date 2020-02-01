#include <iostream>

using namespace std;

int sel[8];
bool visit[9];
int N, M;
void solve(int r)
{
	if (r == M)
	{
		for (int i = 0; i < M; i++)
			cout << sel[i] << " ";
		cout << "\n";
	}
	for (int i = 1; i <= N; i++)
	{
		if (!visit[i])
		{
			visit[i] = true;
			sel[r] = i;
			solve(r + 1);
			visit[i] = false;
		}			
	}
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> N >> M;
	solve(0);
}