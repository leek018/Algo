#include <iostream>
#include <string>
using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	string input; cin >> input;
	char initval = input[0];
	int cnt = 0;
	for (int i = 1; i < input.size(); i++)
	{
		if (initval != input[i])
		{
			initval = input[i];
			cnt++;
		}
	}
	cout << cnt - cnt / 2;
	return 0;
}