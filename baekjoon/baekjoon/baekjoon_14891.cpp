#include <iostream>
#include <cstring>
#include <string>
using namespace std;

string gear[4];

void rotate_cw(int target)
{
	string copy = gear[target];	
	for (int i = 0; i < 7; i++)
		gear[target][i + 1] = copy[i];
	gear[target][0] = copy[7];
}

void rotate_ccw(int target)
{
	string copy = gear[target];	
	for (int i = 0; i < 7; i++)
		gear[target][i] = copy[i + 1];
	gear[target][7] = copy[0];
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int three = 2;
	int nine = 6;
	for (int i = 0; i < 4; i++)
		cin >> gear[i];
	int cw_count = 0;
	int ccw_count = 0;
	int rotate_cw_target[2];
	int rotate_ccw_target[2];	

	int k;
	cin >> k;

	for (int i = 0; i < k; i++)
	{		
		cw_count = 0;
		ccw_count = 0;
		int number, direction;
		cin >> number >> direction;	
		number -= 1;
		if (direction == 1)
			rotate_cw_target[cw_count++] = number;
		else
			rotate_ccw_target[ccw_count++] = number;
		int copy_direction = direction;		
		for (int i = number; i > 0; i--)
		{
			copy_direction *= -1;
			if (gear[i][nine] != gear[i - 1][three])
			{
				if (copy_direction == 1)
					rotate_cw_target[cw_count++] = i - 1;
				else
					rotate_ccw_target[ccw_count++] = i - 1;

			}
			else
				break;
		}
		copy_direction = direction;
		for (int i = number; i < 3; i++)
		{
			copy_direction *= -1;
			if (gear[i][three] != gear[i + 1][nine])
			{
				if (copy_direction == 1)
					rotate_cw_target[cw_count++] = i + 1;
				else
					rotate_ccw_target[ccw_count++] = i + 1;

			}
			else
				break;
		}
		for (int i = 0; i < cw_count; i++)
			rotate_cw(rotate_cw_target[i]);
		for (int i = 0; i < ccw_count; i++)
			rotate_ccw(rotate_ccw_target[i]);
	}
	int answer = 0;
	for (int i = 0; i < 4; i++)
	{
		if (gear[i][0] == '1')
			answer += (1 << i);
	}
	cout << answer;
}