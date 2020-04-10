#include <iostream>
using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int N; cin >> N;
	int q = N / 5;
	int a = -1;
	int b = -1;
	while (q >= 0)
	{
		if ((N - 5 * q) % 3 == 0)
		{
			a = q;
			b = (N - 5 * q) / 3;
			break;
		}
		q--;
	}
	if (a == -1)
		cout << -1;
	else
		cout << a + b;
	return 0;
}