#include <iostream>

using namespace std;
int arr[2][1000001];
int H_MAX[1000001];
int H_MIN[1000001];
int S_MAX[1000001];
int S_MIN[1000001];
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int N; cin >> N;
	for (int i = 1; i <= N; i++)
	{
		int u, v; cin >> u >> v;
		arr[0][i] = u; arr[1][i] = v;
		S_MAX[i] = S_MAX[i - 1] < v ? v : S_MAX[i - 1];
		if (u == 0)
			H_MIN[i] = H_MIN[i - 1];
		else {
			if (H_MIN[i - 1] == 0)
				H_MIN[i] = u;
			else 
				H_MIN[i] = H_MIN[i - 1] > u ? u : H_MIN[i - 1];			
		}
	}
	H_MAX[N] = arr[0][N];
	S_MIN[N] = arr[1][N];
	for (int i = N - 1; i > 0; i--)
	{
		H_MAX[i] = H_MAX[i + 1] < arr[0][i] ? arr[0][i] : H_MAX[i + 1];
		if (arr[1][i] == 0)
			S_MIN[i] = S_MIN[i + 1];
		else
			S_MIN[i] = S_MIN[i + 1] < arr[1][i] ? S_MIN[i+1] : arr[1][i];
	}
	int K = -1;
	int H_K = -1;
	int S_K = -1;
	for (int i = 1; i < N; i++)
	{
		if (H_MIN[i] != 0 && H_MAX[i + 1] != 0)
		{
			if (H_MIN[i] > H_MAX[i + 1])
				H_K = i;
		}
		else
			H_K = i;
		if (S_MIN[i + 1] != 0 && S_MAX[i] != 0)
		{
			if (S_MAX[i] < S_MIN[i + 1])
				S_K = i;
		}
		else
			S_K = i;
		if (H_K == S_K)
			K = H_K;
	}	
	cout << K;
	return 0;
}