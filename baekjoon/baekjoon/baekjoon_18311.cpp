#include <iostream>

using namespace std;
int arr[100001];
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int N;	long long K;
	cin >> N >> K;
	long long sum = 0;
	long long limit = 0;
	for (int i = 1; i <= N; i++) {
		cin >> arr[i];
		limit += (long long)arr[i];
	}
	int answer = 0;
	if (K < limit)
	{
		for (int i = 1; i <= N; i++)
		{
			sum += (long long)arr[i];
			if (K == sum)
				answer = i + 1;
			else if (K < sum)
				answer = i;
			if (answer != 0)
				break;		
		}
	}
	else {
		for (int i = N; i >= 1; i--)
		{
			limit += (long long)arr[i];
			if (limit == K)
				answer = i - 1;
			else if (limit > K)
				answer = i;
			if (answer != 0)
				break;
		}
	}
	cout << answer;
	return 0;
}