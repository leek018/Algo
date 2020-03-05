#include <iostream>
using namespace std;
bool visit[400001];
int arr[5000];
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int N; cin >> N;
	for (int i = 0; i < N; i++)
		cin >> arr[i];
	int answer = 0;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < i; j++)
		{
			int D = arr[i];
			int C = arr[j];
			if (visit[D - C + 200000])
			{
				answer++;
				break;
			}
		}
		for (int j = 0; j <= i; j++)
		{
			int A = arr[i]; int B = arr[j];
			visit[A + B + 200000] = true;
		}
	}
	cout << answer;
	return 0;
}