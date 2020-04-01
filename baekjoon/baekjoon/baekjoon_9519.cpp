#include <iostream>
#include <string>
using namespace std;
string input;
int map[1000][1000];
int leftRight[2];
int delta[2] = { 1,-1 };
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int X; cin >> X;
	cin >> input;		
	for (int i = 0; i < input.size(); i++)
		map[0][i] = i;
	int index = 0;
	while (true)
	{
		leftRight[0] = 0; leftRight[1] = input.size() - 1;
		int wrapper = 0;
		for (int time = 0; time < input.size(); time++)
		{
			map[index+1][time] = map[index][leftRight[wrapper]];
			leftRight[wrapper] += delta[wrapper];
			(++wrapper) %= 2;
		}
		bool find_p = true;
		for (int time = 0; time < input.size(); time++)
		{
			if (map[index + 1][time] != map[0][time])
			{
				find_p = false;
				break;
			}
		}
		if (find_p)
			break;
		index++;
	}
	int Q = index+1;
	int target = Q - (X % Q);
	for (int i = 0; i < input.size(); i++)
		cout << input[map[target][i]];	
	return 0;
}