#include <iostream>
#include <string>
using namespace std;

string map[20];

int dx[] = { -1,0,1,0 };
int dy[] = { 0,-1,0,1 };
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int test_case = 1;
	int w, l;
	cin >> w >> l;
	
	while (w != 0 && l != 0)
	{
		int start_x, start_y;
		for (int i = 0; i < l; i++)
			cin >> map[i];

		for (int i = 0; i < l; i++)
		{
			for (int j = 0; j < l; j++)
			{
				if (map[i][j] == '*')
				{
					start_x = j;
					start_y = i;
					break;
				}
			}
		}
		int dir = 0;
		if (start_x == w - 1)
			dir = 0;
		else if (start_x == 0)
			dir = 2;
		else if (start_y == l - 1)
			dir = 1;
		else
			dir = 3;
		while (true)
		{
			start_x += dx[dir];
			start_y += dy[dir];
			if (map[start_y][start_x] == 'x')
			{
				map[start_y][start_x] = '&';
				break;
			}
			else if (map[start_y][start_x] == '/')
			{
				if (dir == 2)
					dir = 1;
				else if (dir == 3)
					dir = 0;
				else if (dir == 1)
					dir = 2;
				else
					dir = 3;
			}
			else if (map[start_y][start_x] == '\\')
			{
				if (dir == 2)
					dir = 3;
				else if (dir == 3)
					dir = 2;
				else if (dir == 1)
					dir = 0;
				else
					dir = 1;
			}
		}
		cout << "HOUSE " << test_case++ << "\n";
		for (int i = 0; i < l; i++)
			cout << map[i] << "\n";
		cin >> w >> l;
	}
	return 0;

}