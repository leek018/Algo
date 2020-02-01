#include <iostream>

using namespace std;
bool prime[10001];

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int N, M;
	cin >> M >> N; 
	for (int i = 2; i * i < 10001; i++)
	{
		if (!prime[i])
		{
			for (int j = 2 * i; j < 10001; j += i)
				prime[j] = true;
		}		
	}
	prime[1] = true;
	int answer = -1;
	int sum = 0;
	for (int i = N; i >= M; i--)
	{
		if (!prime[i])
		{
			answer = i;
			sum += i;
		}
	}
	if (answer != -1)
		cout << sum << "\n";
	cout << answer << "\n";
	return 0;

}