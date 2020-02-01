#include <iostream>

using namespace std;

struct mal {
	int x, y, direc;		
};
int N, K;
int map[12][12];
int position[12][12][10];
int len_record[12][12];
//bool move_possible[10];
int goal = 4;
int dx[5] = { 0,1,-1,0,0 };
int dy[5] = { 0,0,0,-1,1 };
mal arr[10];
int change_direc(int index)
{
	int direc = arr[index].direc;
	if (direc == 1)
		return 2;
	if (direc == 2)
		return 1;
	if (direc == 3)
		return 4;
	return 3;
}

void print()
{
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (len_record[i][j])
			{
				cout << "*" << " ";
			}
			else
				cout << "-" << " ";
		}
		cout << "\n";
	}
	cout << "==================\n";
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	//0 Èò»ö, 1 »¡°£, 2 ÆÄ¶õ
	cin >> N >> K;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cin >> map[i][j];
		}
	}
	for (int i = 0; i < K; i++)
	{
		int r, c, direc;
		cin >> r >> c >> direc;
		arr[i].y = r-1;
		arr[i].x = c-1;
		arr[i].direc = direc;
		len_record[r - 1][c - 1] = 1;
		position[r - 1][c - 1][0] = i;
	}
	//fill_n(move_possible, 10, true);
	int tern = 0;
	int answer = -1;
	int possible_count = K;
	while (tern < 1000 )
	{
		bool stop_possible = false;
		for (int i = 0; i < K; i++)
		{			
			int direc = arr[i].direc;
			int x = arr[i].x;
			int y = arr[i].y;
			if (position[y][x][0] == i) {
				int nx = x + dx[direc];
				int ny = y + dy[direc];
				int current_len = len_record[y][x];
				if (nx >= 0 && nx < N && ny >= 0 && ny < N)
				{
					if (map[ny][nx] == 0)
					{
						int next_len = len_record[ny][nx];						
						for (int j = 0; j < current_len; j++) {
							int ele = position[y][x][j];
							arr[ele].x = nx;
							arr[ele].y = ny;
							position[ny][nx][next_len++] = ele;
						}

						len_record[y][x] = 0;
						len_record[ny][nx] = next_len;
						
					}
					else if (map[ny][nx] == 1)
					{
						int next_len = len_record[ny][nx];						
						for (int j = current_len - 1; j >= 0; j--) {
							int ele = position[y][x][j];
							arr[ele].x = nx;
							arr[ele].y = ny;
							position[ny][nx][next_len++] = ele;
						}
						len_record[y][x] = 0;
						len_record[ny][nx] = next_len;						
					}
					else {
						arr[i].direc = change_direc(i);
						int n_direc = arr[i].direc;
						int nnx = x + dx[n_direc];
						int nny = y + dy[n_direc];
						if (nnx >= 0 && nnx < N && nny >= 0 && nny < N && map[nny][nnx] != 2) {
							i--;
							continue;
						}
					}
				}
				else {
					arr[i].direc = change_direc(i);
					int n_direc = arr[i].direc;
					int nnx = x + dx[n_direc];
					int nny = y + dy[n_direc];
					if (nnx >= 0 && nnx < N && nny >= 0 && nny < N && map[nny][nnx] != 2) {						
						i--;
						continue;
					}
				}
			}							
			if (len_record[arr[i].y][arr[i].x] >= 4)
			{				
				stop_possible = true;
				answer = tern + 1;
				break;
			}												
		}
		//print();
		if (stop_possible)
			break;		
		tern++;		
	}
	//cout << tern;
	cout << answer;
	return 0;

}