#include <iostream>
using namespace std;
int sumation[10001];
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int N, M; cin >> N >> M;
	for (int i = 1; i <= N; i++)
	{
		int value; cin >> value;
		sumation[i] = value + sumation[i - 1];
	}
	int answer = 0;
	for (int i = 1; i <= N; i++)
	{
		for (int j = 0; j < i; j++)
		{
			if (sumation[i] - sumation[j] < M)
				break;
			if (sumation[i] - sumation[j] == M) {
				answer++;
				break;
			}
		}
	}
	cout << answer;
	return 0;
}