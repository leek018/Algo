#include <iostream>
#include <algorithm>
#define ABS(X) ((X) <0 ? (-(X)) : (X))
using namespace std;
int A[1000000];
int B[1000000];
int bns(int target,int M)
{
	int localMin = 1e9 + 1;
	int answer = 0;
	int left = 0; int right = M - 1;
	while (left <= right)
	{
		int mid = (left + right) / 2;
		if (B[mid] < target)
			left = mid + 1;
		else
			right = mid - 1;
		if (localMin > ABS(B[mid] - target))
		{
			localMin = ABS(B[mid] - target);
			answer = B[mid];
		}
		else if (localMin == ABS(B[mid] - target))
		{
			if (answer > B[mid])
				answer = B[mid];
		}
	}
	return answer;
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int T; cin >> T;
	for (int test_case = 0; test_case < T; test_case++)
	{
		long long sum = 0;
		int N, M; cin >> N >> M;
		for (int i = 0; i < N; i++)
			cin >> A[i];
		for (int i = 0; i < M; i++)
			cin >> B[i];
		sort(B, B + M);
		for (int i = 0; i < N; i++)		
			sum = sum + (long long)bns(A[i], M);
		cout << sum << "\n";
	}
	return 0;
}