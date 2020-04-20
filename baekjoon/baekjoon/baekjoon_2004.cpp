#include <iostream>
using namespace std;

int get(long long N, long long target)
{
	int count = 0;
	for (long long i = target; i <= N; i *= target)
		count += N / i;
	return count;
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int N, M; cin >> N >> M;
	int two = 0;
	int five = 0;
	two += get(N, 2);
	five += get(N, 5);
	two -= get(N - M, 2);
	five -= get(N - M, 5);
	two -= get(M, 2);
	five -= get(M, 5);
	int answer = two > five ? five : two;
	cout << answer;
	return 0;
}