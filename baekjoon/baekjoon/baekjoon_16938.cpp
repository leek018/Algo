#include <iostream>
#include <algorithm>
using namespace std;

int N, L, R, X;
int arr[15];
int solve(int startIdx, int lastIdx, int sum)
{
	if (sum > R)return 0;
	int count = 0;
	if (sum >= L)
		count++;
	for (int i = startIdx + 1; i < lastIdx; i++)	
		count += solve(startIdx, i, sum + arr[i]);
	return count;
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> N >> L >> R >> X;
	for (int i = 0; i < N; i++)
		cin >> arr[i];
	sort(arr, arr + N);
	int answer = 0;
	for (int i = 0; i < N; i++)
	{
		for (int j = i + 1; j < N; j++)
		{
			if (arr[j] - arr[i] >= X)
				answer += solve(i, j, arr[i] + arr[j]);
		}
	}
	cout << answer;
	return 0;
}