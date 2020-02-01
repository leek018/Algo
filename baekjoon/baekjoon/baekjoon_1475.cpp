#include <iostream>
#include <string>
using namespace std;
int digit[10];
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	string input;
	cin >> input;
	for (int i = 0; i < input.size(); i++)
	{
		int val = input[i] - '0';
		if (val == 9)
			val = 6;
		digit[val]++;
	}
	digit[6] = digit[6] - digit[6] / 2;
	int max = 0;
	for (int i = 0; i < 10; i++)
		max = max < digit[i] ? digit[i] : max;
	cout << max;
	return 0;
}