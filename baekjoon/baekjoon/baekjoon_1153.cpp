#include <iostream>
#include <vector>
using namespace std;
bool prime[1000001];
vector<int> arr;

bool solve(int N)
{
	for (int i = 2; i <= N; i++)
	{
		if (!prime[i]) {
			for (int j = i; j <= N-i; j++)
			{
				if (!prime[j]) {
					for (int k = j; k <= N-j-i; k++)
					{
						if (!prime[k] && !prime[N-i-j-k]) {
							arr.push_back(i);
							arr.push_back(j);
							arr.push_back(k);
							arr.push_back(N-i-j-k);
							return true;							
						}
					}
				}
			}
		}
	}
	return false;
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int N;
	cin >> N;
	for (int i = 2; i * i < 1000001; i++)
	{
		if (!prime[i])
		{
			for (int j = 2 * i; j < 1000001; j += i)
				prime[j] = true;
		}
	}
	prime[0] = prime[1] = true;
	if (solve(N))
	{
		for (int i = 0; i < 4; i++)
			cout << arr[i] << " ";
	}
	else {
		cout << -1;
	}

	return 0;



}