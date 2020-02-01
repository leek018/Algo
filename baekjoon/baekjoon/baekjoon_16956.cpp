#include <iostream>
#include <vector>
using namespace std;

vector<pair<int, int>> sheepSheKki;
vector<pair<int, int>> wolf;

char map[500][500];
int dx[] = { -1,0,1,0 };
int dy[] = { 0,-1,0,1 };
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int r, c;
	cin >> r >> c;
	for (int i = 0; i < r; i++)
	{
		for (int j = 0; j < c; j++)
		{
			char input;
			cin >> input;
			map[i][j] = input;
			if (input == 'S')
				sheepSheKki.push_back({ j,i });
			else if (input == 'W')
				wolf.push_back({ j,i });
		}
	}
	if (wolf.size() == 0)
	{
		cout << 1 << "\n";
		for (int i = 0; i < r; i++)
		{
			for (int j = 0; j < c; j++)
				cout << map[i][j];
			cout << "\n";
		}
	}
	else {
		for (int i = 0; i < sheepSheKki.size(); i++)
		{
			int x = sheepSheKki[i].first;
			int y = sheepSheKki[i].second;
			for (int j = 0; j < 4; j++)
			{
				int nx = x + dx[j];
				int ny = y + dy[j];
				if (nx >= 0 && nx < c && ny >= 0 && ny < r)
				{
					if (map[ny][nx] == '.')
						map[ny][nx] = 'D';
				}
			}
		}
		bool possible = true;
		for (int i = 0; i < wolf.size(); i++)
		{
			int x = wolf[i].first;
			int y = wolf[i].second;
			for (int j = 0; j < 4; j++)
			{
				int nx = x + dx[j];
				int ny = y + dy[j];
				if (nx >= 0 && nx < c && ny >= 0 && ny < r)
				{
					if (map[ny][nx] == 'S')
					{
						possible = false;
						break;
					}
				}
			}
			if (!possible)
				break;
		}
		if (!possible)
			cout << 0;
		else {
			cout << 1 << "\n";
			for (int i = 0; i < r; i++)
			{
				for (int j = 0; j < c; j++)
					cout << map[i][j];
				cout << "\n";
			}
		}
	}

}