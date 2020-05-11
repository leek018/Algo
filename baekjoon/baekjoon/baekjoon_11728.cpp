#include <iostream>
using namespace std;
int arr_a[1000000];
int arr_b[1000000];
int answer[2000000];
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int N, M; cin >> N >> M;
	for (int i = 0; i < N; i++)
		cin >> arr_a[i];
	for (int i = 0; i < M; i++)
		cin >> arr_b[i];
	int start_a = 0;
	int start_b = 0;
	int start_c = 0;
	while (start_a < N && start_b < M)
	{
		if (arr_a[start_a] >= arr_b[start_b])
			answer[start_c] = arr_b[start_b++];
		else
			answer[start_c] = arr_a[start_a++];
		start_c++;
	}	
	while (start_a < N) {
		answer[start_c] = arr_a[start_a++];
		start_c++;
	}
	while (start_b < M) {
		answer[start_c] = arr_b[start_b++];
		start_c++;
	}
	for (int i = 0; i < N + M; i++)
		cout << answer[i] << " ";
	return 0;
}
