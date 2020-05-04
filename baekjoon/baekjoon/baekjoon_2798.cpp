#include <iostream>
using namespace std;
int arr[100];
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int N, M; cin >> N >> M;
	for (int i = 0; i < N; i++)	
		cin >> arr[i];
	int answer = 0;
	for (int i = 0; i < N - 2; i++)
	{
		for (int j = i + 1; j < N - 1; j++)
		{
			for (int k = j + 1; k < N; k++)
			{
				int sum = arr[i] + arr[j] + arr[k];
				if (M - sum >= 0 && M - sum < M-answer)
					answer = sum;
			}
		}
	}
	cout << answer;
	return 0;
}