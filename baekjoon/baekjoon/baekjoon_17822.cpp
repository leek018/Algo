#include <iostream>
#include <cstring>
using namespace std;


int N, M, T;
int map[51][50];
bool visit[51][50];

int dx[] = { -1,0,1,0 };
int dy[] = { 0,1,0,-1 };
void clockRotate(int target, int how)
{
	int temp[50];
	memcpy(temp, map[target], sizeof(int) * M);	
	int stride = how;
	for (int start = 0; start < M; start++)	
		map[target][(stride + start) % M] = temp[start];	
}

void rotate(int target, int direc, int how)
{
	if (how % M == 0)
		return;
	int copy_how = how;
	if (direc == 1)	
		copy_how = M - how;
	clockRotate(target, copy_how);		
}
int dfs(int target_y, int target_x,int target_val)
{
	if (visit[target_y][target_x])
		return 0;
	int count = 1;
	visit[target_y][target_x] = true;
	map[target_y][target_x] = -1;
	for (int i = 0; i < 4; i++)
	{
		int nx = target_x + dx[i];		
		int ny = target_y + dy[i];
		nx = (nx + M) % M;
		if (ny >= 1 && ny <= N && map[ny][nx] == target_val )
		{
			count += dfs(ny, nx, target_val);
		}
	}
	return count;
}

bool find_same()
{
	for (int i = 1; i <= N; i++)
		fill_n(visit[i], 50, false);
	bool total = false;
	for (int i = 1; i <= N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			int save = map[i][j];
			if (!visit[i][j] && save > 0) {				
				int ret = dfs(i, j, save);
				if (ret == 1)
					map[i][j] = save;
				else
					total = true;
			}				
		}
	}
	return total;
}
void print()
{
	cout << "====================\n";
	for (int i = 1; i <= N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			cout << map[i][j] << " ";
		}
		cout << "\n";
	}
	cout << "====================\n";
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N >> M >> T;
	for (int i = 1; i <= N; i++)
	{
		for (int j = 0; j < M; j++)
			cin >> map[i][j];
	}

	bool possible = true;
	for (int i = 0; i < T; i++)
	{
		int x, d, k;
		cin >> x >> d >> k;
		if (possible) {
			for (int j = 1; j <= N; j++)
			{
				if (j % x == 0) {
					rotate(j, d, k);
				}
			}
			bool ret = find_same();

			if (!ret)
			{
				int sum = 0;
				int count = 0;
				for (int i = 1; i <= N; i++)
				{
					for (int j = 0; j < M; j++)
					{
						if (map[i][j] > 0) {
							sum += map[i][j];
							count++;
						}
					}
				}
				if (sum == 0) {
					possible = false;
					continue;
				}									
				int avg = sum / count;
				int rem = sum % count;
				for (int i = 1; i <= N; i++)
				{
					for (int j = 0; j < M; j++)
					{
						int val = map[i][j];
						if (val > 0)
						{
							if (val > avg) {
								map[i][j]--;
							}
							else if (val < avg)
								map[i][j]++;
							else {
								if (rem > 0)
									map[i][j]++;
							}
						}
					}
				}
			}
		}
		
	}
	int answer = 0;
	for (int i = 1; i <= N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			if (map[i][j] > 0)
				answer += map[i][j];
		}
	}
	cout << answer;

}