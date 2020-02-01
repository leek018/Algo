#include <iostream>

using namespace std;

int arr[30000];
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int N;
	cin >> N;
	for (int i = 0; i < N; i++)
		cin >> arr[i];

	int answer = 0;
	for (int i = 0; i < N - 1; i++)
	{
		int val = arr[i];
		int sum = 0;
		for (int j = i + 1; j < N;j++)
		{
			if (val > arr[j])
				sum++;
			else
				break;
		}
		answer = answer < sum ? sum : answer;
	}
	cout << answer;


}