#include <iostream>
#include <cstring>
#include <string>

using namespace std;
string map[5];
int R = 5,C = 9;
pair<int, int> candidate[9];
int candidateSize = 0;
int IndexMapping[5][9];
int dx[] = { -1,0,1,0 };
int dy[] = { 0,-1,0,1 };
int calcul(int srcPosX, int srcPosY,int dir,int (*mapping)[9])
{
	int nx = srcPosX + dx[dir];
	int ny = srcPosY + dy[dir];
	int nnx = nx + dx[dir];
	int nny = ny + dy[dir];
	if (nx < 0 || nx >= C || ny < 0 || ny >= R || map[ny][nx] == '#' || mapping[ny][nx] == 0)
		return -1;
	if (nnx < 0 || nnx >= C || nny < 0 || nny >= R || map[nny][nnx] == '#' || mapping[nny][nnx] >0)
		return -1;
	return mapping[ny][nx];	
}
bool isDead[9];
int minMove = 0;
int minaliive = 8;
void solve(int (*originalMapping)[9],int alive,int move)
{	
	int copyMapping[5][9];
	for (int i = 1; i < candidateSize; i++)
	{
		if (!isDead[i]) {			
			for (int j = 0; j < 4; j++)
			{				
				memcpy(copyMapping, originalMapping, sizeof(int) * 5 * 9);
				pair<int, int> ele = candidate[i];
				int possible = calcul(ele.first, ele.second, j, copyMapping);
				if (possible >0)
				{					
					pair<int, int> target = candidate[possible];
					copyMapping[target.second][target.first] = 0;
					copyMapping[ele.second][ele.first] = 0;
					pair<int, int> changedPos = { target.first + dx[j],target.second + dy[j] };
					candidate[i] = changedPos;
					copyMapping[changedPos.second][changedPos.first] = i;
					isDead[possible] = true;		

					solve(copyMapping,alive-1,move+1);					

					
					copyMapping[target.second][target.first] = possible;
					copyMapping[ele.second][ele.first] = i;					
					candidate[i] = ele;
					copyMapping[changedPos.second][changedPos.first] = 0;
					isDead[possible] = false;
				}
			}
		}						
	}
	if (minaliive > alive)
	{
		minaliive = alive;
		minMove = move;
	}
	return;
}




int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int T;
	cin >> T;
	for (int test_case = 1; test_case <= T; test_case++)
	{
		candidateSize = 1;				
		fill_n(isDead, 9, false);
		for (int i = 0; i < 5; i++)
			fill_n(IndexMapping[i], 9, 0);
		for (int i = 0; i < 5; i++)
		{
			cin >> map[i];
			for (int j = 0; j < 9; j++)
			{
				if (map[i][j] == 'o') {
					candidate[candidateSize] = { j,i };
					IndexMapping[i][j] = candidateSize++;
				}
			}
		}								
		minaliive = 8;
		minMove = 0;
		solve(IndexMapping, candidateSize-1, 0);
		cout << minaliive << " " << minMove << "\n";			
	}
	
}