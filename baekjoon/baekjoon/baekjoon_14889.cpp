#include <iostream>
#include <vector>

using namespace std;

bool team[20];
int min_val = 1000000;
int N;
int arr[20][20];
void combi(int idx, int r, int limit)
{
	if (r == limit)
	{
		int sum_a = 0;
		int sum_b = 0;
		vector<int> a;
		vector<int> b;
		for (int i = 0; i < N; i++)
		{
			if (!team[i])
				a.push_back(i);
			else
				b.push_back(i);
		}
		for (int i = 0; i < N / 2; i++)
		{
			for (int j = i + 1; j < N / 2; j++)
			{
				sum_a += arr[a[i]][a[j]] + arr[a[j]][a[i]];
				sum_b += arr[b[i]][b[j]] + arr[b[j]][b[i]];
			}
		}
		int diff = sum_a - sum_b;
		if (diff < 0)
			diff *= -1;
		min_val = min_val > diff ? diff : min_val;
		return;
	}
	for (int i = idx; i < N; i++)
	{
		team[i] = true;
		combi(i + 1, r + 1, limit);
		team[i] = false;
	}
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
			cin >> arr[i][j];
	}
	combi(0, 0, N / 2);
	cout << min_val;
}