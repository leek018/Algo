#include <iostream>
using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int N; cin >> N;
	int count = 0;
	int total_sum = 0;
	int temp = N;
	while (temp != 0)
	{
		count++;
		total_sum += temp % 10;
		temp /= 10;
	}
	int half_sum = 0;
	temp = N;
	for (int i = 0; i < count / 2; i++)
	{
		half_sum += temp % 10;
		temp /= 10;
	}
	if (total_sum - half_sum == half_sum)
		cout << "LUCKY";
	else
		cout << "READY";
	return 0;
}