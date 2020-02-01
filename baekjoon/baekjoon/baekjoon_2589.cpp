#include <iostream>
#include <string>
#include <vector>
#include <queue>
using namespace std;


string map[50];
bool visit[50][50];
vector<pair<int, int>> islands[1250];
int dx[] = { -1,0,1,0 };
int dy[] = { 0,-1,0,1 };
int N, M;
bool find_candidate(int start_y, int start_x)
{
	int cnt = 0;
	for (int i = 0; i < 4; i++)
	{
		int nx = start_x + dx[i];
		int ny = start_y + dy[i];
		if (nx >= 0 && nx < M && ny >= 0 && ny < N && map[ny][nx] == 'L')
			cnt++;
	}
	if (cnt <= 2)
		return true;
	return false;
}
void bfs(int start_x, int start_y, const int& island_cnt)
{
	queue<pair<int, int>> q;
	visit[start_y][start_x] = true;
	q.push({ start_x,start_y });
	while (!q.empty())
	{
		pair<int, int> ret = q.front();
		q.pop();
		if (find_candidate(ret.second, ret.first)) {
			islands[island_cnt].push_back(ret);
		}
		for (int i = 0; i < 4; i++)
		{
			int nx = start_x + dx[i];
			int ny = start_y + dy[i];
			if (nx >= 0 && nx < M && ny >= 0 && ny < N && map[ny][nx] == 'L' && !visit[ny][nx])
			{
				visit[ny][nx] = true;
				q.push({ nx,ny });
			}
		}
	}
}
int find_dist(int island_idx)
{
	int candidate_len = islands[island_idx].size();

	int max_dist = 0;
	for (int i = 0; i < candidate_len; i++) {

		for (int j = 0; j < N; j++)
			fill_n(visit[j], M, false);
		queue<pair<int, int>> q;
		pair<int, int>& start = islands[island_idx][i];
		visit[start.second][start.first] = true;
		q.push(start);
		int dist = 0;
		while (!q.empty())
		{
			int len = q.size();
			for (int j = 0; j < len; j++)
			{
				pair<int, int> ret = q.front();
				q.pop();
				for (int j = 0; j < 4; j++)
				{
					int nx = ret.first + dx[j];
					int ny = ret.second + dy[j];
					if (nx >= 0 && nx < M && ny >= 0 && ny < N && map[ny][nx] == 'L' && !visit[ny][nx])
					{
						visit[ny][nx] = true;
						q.push({ nx,ny });
					}
				}
			}
			dist++;
		}
		max_dist = max_dist < dist ? dist : max_dist;
	}
	return max_dist - 1;

}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		cin >> map[i];
	}

	int island_count = 0;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			if (map[i][j] == 'L' && !visit[i][j])
			{
				bfs(j, i, island_count);
				island_count++;
			}
		}
	}
	int answer = 0;
	for (int i = 0; i < island_count; i++)
	{
		int ret = find_dist(i);
		answer = answer < ret ? ret : answer;
	}
	cout << answer << "\n";
	return 0;

}