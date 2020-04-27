#include <iostream>
using namespace std;
int answer[10];
int main()
{
	int a, b, c; cin >> a >> b >> c;
	int all = a * b * c;
	if (all == 0)
		answer[0]++;
	else {
		while (all != 0)
		{
			answer[all % 10]++;
			all /= 10;
		}
	}
	for (int i = 0; i < 10; i++)
		cout << answer[i] << "\n";
	return 0;
}