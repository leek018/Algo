#include <iostream>
#include <vector>
#define abs(X) ( (X) < 0 ? (-(X)) : (X))
using namespace std;
vector<pair<int,int>> guild[2000];
int map[50][50];
bool visit[50][50];
int N;
int L, R;
int dx[] = { -1,0,1,0 };
int dy[] = { 0,-1,0,1 };
void dfs(int start_x,int start_y,int guild_number)
{
	if (visit[start_y][start_x])
		return;
	visit[start_y][start_x] = true;
	guild[guild_number].push_back({ start_x,start_y });
	for (int i = 0; i < 4; i++)
	{
		int nx = start_x + dx[i];
		int ny = start_y + dy[i];
		if (nx < 0 || nx >= N || ny < 0 || ny >= N)
			continue;
		int diff = map[start_y][start_x] - map[ny][nx];
		if (!visit[ny][nx] && abs(diff) >=L && abs(diff) <= R)
		{
			dfs(nx, ny, guild_number);
		}
	}
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> N >> L >> R;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
			cin >> map[i][j];
	}

	bool possible = true;
	int count = 0;
	while (possible)
	{
		possible = false;
		int guild_num = 0;
		for (int i = 0; i < N; i++)
			fill_n(visit[i], N, false);
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < N; j++)
			{
				if (!visit[i][j])
				{
					dfs(j, i, guild_num);
					if (guild[guild_num].size() > 1) {
						guild_num++;
						possible = true;
					}						
					else
						guild[guild_num].clear();
				}
			}
		}
		for (int i = 0; i < guild_num; i++)
		{
			int sum = 0;
			for (int j = 0; j < guild[i].size(); j++)
			{
				pair<int, int>& ret = guild[i][j];
				sum += map[ret.second][ret.first];
			}
			int avg = sum / guild[i].size();
			for (int j = 0; j < guild[i].size(); j++)
			{
				pair<int, int>& ret = guild[i][j];
				map[ret.second][ret.first] = avg;
			}
			guild[i].clear();
		}
		if (possible)
			count++;
	}
	cout << count << "\n";
	return 0;

}