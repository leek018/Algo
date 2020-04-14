#include <iostream>
#include <string>
using namespace std;
int check = 0;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int M; cin >> M;
	for (int i = 0; i < M; i++)
	{
		string input;
		cin >> input;
		if (input == "add")
		{
			int target; cin >> target;
			check |= (1 << target);
		}
		else if (input == "remove")
		{
			int target; cin >> target;
			if ( (check & (1 << target)) != 0)
				check -= (1 << target);
		}
		else if (input == "check")
		{
			int target; cin >> target;
			int answer = 0;
			if ((check & (1 << target)) != 0)
				answer = 1;
			cout << answer << "\n";			
		}
		else if (input == "toggle")
		{
			int target; cin >> target;
			check ^= (1 << target);
		}
		else if (input == "all")
		{
			check = (1 << 22) - 1;
		}
		else {
			check = 0;
		}
	}
	return 0;
}