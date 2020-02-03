#include <iostream>
#include <cstring>
using namespace std;

int map[10][10];
int dolpos[10][10];
bool isdolDead[100];
pair<int, int> dol[100];
int dx[] = { -1,-1,0,1,1,1,0,-1 };
int dy[] = { 0,-1,-1,-1,0,1,1,1 };
int totalDolNum = 0;
int checkJumping(int dol_index, int dir)
{
	int start_x = dol[dol_index].first; int start_y = dol[dol_index].second;
	int nx = start_x + dx[dir]; int ny = start_y + dy[dir];
	if (map[ny][nx] == 2)
	{
		int nnx = nx + dx[dir]; int nny = ny + dy[dir];
		if (map[nny][nnx] == 0)
			return dolpos[ny][nx];
	}
	return -1;
}
void statechange(int dead_index, int moved_index, int target_x, int target_y,bool isrollback)
{
	pair<int, int> dead_dol_pos = dol[dead_index];
	if (isrollback)
	{
		//죽은돌은 살리고		
		map[dead_dol_pos.second][dead_dol_pos.first] = 2;
		isdolDead[dead_index] = false;
	}
	//죽일돌은 죽이고
	else {
		map[dead_dol_pos.second][dead_dol_pos.first] = 0;
		isdolDead[dead_index] = true;
	}
	//넘은 돌은 다시 자리로 돌아가고 혹은 넘어갈 자리로 넘어가고
	pair<int, int> current_dol_pos = dol[moved_index];
	map[current_dol_pos.second][current_dol_pos.first] = 0;
	dolpos[current_dol_pos.second][current_dol_pos.first] = -1;
	map[target_y][target_x] = 2;
	dol[moved_index] = { target_x,target_y };
	dolpos[target_y][target_x] = moved_index;
}

bool play(int aliveDol)
{
	if (aliveDol == 1)
		return true;
	for (int i = 0; i < totalDolNum; i++)
	{
		if (!isdolDead[i])
		{
			for (int j = 0; j < 8; j++)
			{
				int deadDolIndex = checkJumping(i, j);
				if (deadDolIndex>=0)
				{
					pair<int, int> current_pos = dol[i];
					pair<int, int> next_pos = { current_pos.first + dx[j] * 2,current_pos.second + dy[j] * 2 };
					statechange(deadDolIndex, i, next_pos.first, next_pos.second, false);
					if (play(aliveDol - 1))
						return true;
					statechange(deadDolIndex, i, current_pos.first, current_pos.second, true);
				}
			}
		}
	}
	return false;
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int N; cin >> N;
	for (int i = 0; i < N; i++)
	{
		fill_n(dolpos[i], 10, -1);
		for (int j = 0; j < N; j++)
		{
			cin >> map[i][j];
			if (map[i][j] == 2) {
				dolpos[i][j] = totalDolNum;
				dol[totalDolNum++] = { j,i };
			}				
		}			
	}
	if (play(totalDolNum))
		cout << "Possible";
	else
		cout << "Impossible";
	return 0;
}