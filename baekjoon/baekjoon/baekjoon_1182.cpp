#include <iostream>
#include <vector>
using namespace std;
int arr[20];
int answer = 0;
int N, S;
void solve(int cnt, int idx, int sum)
{
	if (idx == N)
	{
		if (cnt != 0 && sum == S)
			answer++;
		return;
	}
	solve(cnt, idx + 1, sum);
	solve(cnt + 1, idx + 1, sum + arr[idx]);
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);


	
	cin >> N >> S;
	for (int i = 0; i < N; i++)
		cin >> arr[i];
	solve(0, 0, 0);	
	
	cout << answer;
	
}