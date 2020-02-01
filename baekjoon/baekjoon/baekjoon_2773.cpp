#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int map[300][300];
int record[300][300];
pair<int,int> allive[90000];
bool isDead[90000];
bool visit[90000];
int dx[] = { -1,0,1,0 };
int dy[] = { 0,-1,0,1 };
int N, M; //За ї­
void bfs(int target)
{
	queue<int> q;
	q.push(target);
	visit[target] = true;
	while (!q.empty())
	{
		int ret = q.front();
		q.pop();
		pair<int, int> &target_pos = allive[ret];
		int x = target_pos.first;
		int y = target_pos.second;
		for (int i = 0; i < 4; i++)
		{
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (nx >= 0 && nx < M && ny >= 0 && ny < N && map[ny][nx] >0 && !visit[record[ny][nx]] && !isDead[record[ny][nx]])
			{
				visit[record[ny][nx]] = true;
				q.push(record[ny][nx]);
			}
		}
	}
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> N >> M;
	int allive_len = 0;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{			
			cin >> map[i][j];
			if (map[i][j] > 0) {
				record[i][j] = allive_len;
				allive[allive_len++] = { j,i };				
			}				
		}
	}	
	int temp = allive_len;
	int day = 0;
	bool possible = false;
	while (temp != 0)
	{
		fill_n(visit, allive_len, false);
		int count = 0;
		for (int i = 0; i < allive_len; i++)
		{
			if (!isDead[i] && !visit[i]  )
			{
				bfs(i);
				if (++count >= 2) {
					possible = true;
					break;
				}

			}
		}
		if (possible)
			break;
		vector<int> melt;
		for (int i = 0; i < allive_len; i++)
		{
			int melt_count = 0;
			if (!isDead[i])
			{
				int x = allive[i].first;
				int y = allive[i].second;
				for (int j = 0; j < 4; j++)
				{
					int nx = x + dx[j];
					int ny = y + dy[j];
					if(nx >=0 && nx < M && ny >=0 && ny <N && !map[ny][nx])					
						melt_count++;					
				}
				if (melt_count >= map[y][x])
					melt.push_back(i);
				else
					map[y][x] -= melt_count;
			}
		}		
		for (int i = 0; i < melt.size(); i++) {
			int target = melt[i];
			isDead[target] = true;
			pair<int, int>& target_pos = allive[target];
			map[target_pos.second][target_pos.first] = 0;
		}
		temp -= melt.size();
		day++;
	}
	int answer = 0;
	if (possible)
		answer = day;
	cout << answer;
}