#include <iostream>
#include <string>
using namespace std;

char library[36];
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	char start = '0';
	for (int i = 0; i < 36; i++)
	{
		if (i == 10)
			start = 'A';
		library[i] = start;
		start++;
	}	
	int target, B; cin >> target >> B;
	int temp = target;
	string answer;
	while (true)
	{
		if (temp == 0)
			break;
		answer.push_back(library[temp%B]);
		temp /= B;
	}
	for (int i = answer.size() - 1; i >= 0; i--)
		cout << answer[i];
	return 0;
}