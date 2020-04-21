#include <iostream>
using namespace std;

int N;
int arr[10];
bool visit[10];
int answer = 0;

int findLeft(int start)
{
	for (int i = start - 1; i >= 0; i--)
	{
		if (!visit[i])
			return i;
	}
	return -1;
}
int findRight(int start)
{
	for (int i = start + 1; i <= N-1; i++)
	{
		if (!visit[i])
			return i;
	}
	return -1;
}
void solve(int count, int sum)
{
	if (count == 2)
	{
		if (answer < sum)
			answer = sum;
		return;
	}
	for (int i = 1; i < N - 1; i++)
	{
		if (!visit[i])
		{
			int ret_a = findLeft(i);
			int ret_b = findRight(i);
			if (ret_a != -1 && ret_b != -1)
			{
				visit[i] = true;
				solve(count - 1, sum + arr[ret_a] * arr[ret_b]);
				visit[i] = false;
			}
		}
	}
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> N;
	for (int i = 0; i < N; i++)
		cin >> arr[i];	
	solve(N, 0);
	cout << answer;
	return 0;
}