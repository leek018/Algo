#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;
int dist[10][10];
string map[20];
vector<pair<int, int>> dists;
bool visit[20][20];
pair<int, int> start;
int dx[] = { -1,0,1,0 };
int dy[] = { 0,-1,0,1 };
int answer = 9999;
int temp_answer = 9999;
bool visit_dist[10];
int s_d[10];
void shortest(int rem, int total, int start)
{
	if (total > temp_answer)
		return;
	if (rem == 0)
	{
		temp_answer = temp_answer > total ? total : temp_answer;
		return;
	}
	for (int i = 0; i < dists.size(); i++)
	{
		if (!visit_dist[i])
		{
			visit_dist[i] = true;
			shortest(rem - 1, total + dist[start][i], i);
			visit_dist[i] = false;
		}
	}
}

bool is_poss(const int &len)
{
	for (int i = 0; i < len; i++)
		if (s_d[i] == 9999)
			return false;
	return true;
}

int main()
{
	freopen("sample_4911.txt", "r", stdin);
	int w, h;
	cin >> w >> h;
	while (w != 0 && h != 0)
	{
		answer = 9999;
		dists.clear();
		for (int i = 0; i < h; i++)
			cin >> map[i];

		for (int i = 0; i < h; i++)
		{
			for (int j = 0; j < w; j++)
			{
				if (map[i][j] == '*')
					dists.push_back({ j,i });
				else if (map[i][j] == 'o')
					start = { j,i };
			}
		}
		queue<pair<int, int>> q;
		int dists_len = dists.size();
		fill_n(s_d, 10, 9999);
		memset(visit, 0, sizeof(visit));
		q.push(start);
		visit[start.second][start.first] = true;
		int count = 0;
		while (!q.empty())
		{
			int len = q.size();
			for (int i = 0; i < len; i++)
			{
				pair<int, int> ret = q.front();
				q.pop();
				if (map[ret.second][ret.first] == '*')
				{
					for (int i = 0; i < dists_len; i++)
					{
						if (dists[i].first == ret.first && dists[i].second == ret.second)
						{
							s_d[i] = count;
							break;
						}
					}
				}
				for (int i = 0; i < 4; i++)
				{
					int nx = ret.first + dx[i];
					int ny = ret.second + dy[i];
					if (nx >= 0 && nx < w && ny >= 0 && ny < h && !visit[ny][nx] && map[ny][nx] != 'x')
					{
						visit[ny][nx] = true;
						q.push({ nx,ny });
					}
				}
			}
			count++;
		}

		if (!is_poss(dists_len))
		{
			cout << -1 << "\n";
		}
		else {
			for (int i = 0; i < dists.size(); i++)
			{
				memset(visit, 0, sizeof(visit));
				q.push(dists[i]);
				visit[dists[i].second][dists[i].first] = true;
				int count = 0;
				while (!q.empty())
				{
					int len = q.size();
					for (int k = 0; k < len; k++)
					{
						pair<int, int> ret = q.front();
						q.pop();
						if (map[ret.second][ret.first] == '*')
						{
							for (int j = 0; j < dists.size(); j++)
							{
								if (dists[j].first == ret.first && dists[j].second == ret.second)
								{
									dist[i][j] = count;
									dist[j][i] = count;
									break;
								}
							}
						}
						for (int j = 0; j < 4; j++)
						{
							int nx = ret.first + dx[j];
							int ny = ret.second + dy[j];
							if (nx >= 0 && nx < w && ny >= 0 & ny < h && !visit[ny][nx] && map[ny][nx] != 'x')
							{
								q.push({ nx,ny });
								visit[ny][nx] = true;
							}
						}
					}
					count++;
				}				
			}
			for (int i = 0; i < dists_len; i++)
			{
				temp_answer = 9999;
				memset(visit_dist, 0, sizeof(visit_dist));
				visit_dist[i] = true;
				shortest(dists.size() - 1, 0, i);
				int total = s_d[i] + temp_answer;
				answer = total < answer ? total : answer;
			}
			cout << answer << "\n";
		}						
		cin >> w >> h;
	}
	return 0;
}