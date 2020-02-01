#include <iostream>
#include <string>
#include <queue>
using namespace std;

int N, M;
string map[3000];
bool visit[3000][3000];
int dx[] = { -1,0,1,0 };
int dy[] = { 0,-1,0,1 };
queue<pair<int, int>> bird_q;
queue<pair<int, int>> food_q;

int solve()
{
	int count = 0;
	while (!bird_q.empty())
	{
		int len = bird_q.size();
		for (int i = 0; i < len; i++)
		{
			pair<int, int> ret = bird_q.front();
			bird_q.pop();
			for (int j = 0; j < 4; j++)
			{
				int nx = ret.first + dx[j];
				int ny = ret.second + dy[j];
				if (nx >= 0 && nx < M && ny >= 0 && ny < N && map[ny][nx] !='1')
				{
					if (!visit[ny][nx])
					{
						map[ny][nx] = '2';
						visit[ny][nx] = true;
						bird_q.push({ nx,ny });
					}
					else {
						if (map[ny][nx] - '0' > 2)
						{
							return 2 * count + 1;
						}
					}
				}
			}
		}
		count++;
		len = food_q.size();
		for (int i = 0; i < len; i++)
		{
			pair<int, int> ret = food_q.front();
			food_q.pop();
			for (int j = 0; j < 4; j++)
			{
				int nx = ret.first + dx[j];
				int ny = ret.second + dy[j];
				if (nx >= 0 && nx < M && ny >= 0 && ny < N && map[ny][nx] != '1')
				{
					if (!visit[ny][nx])
					{
						map[ny][nx] = '3';
						visit[ny][nx] = true;
						food_q.push({ nx,ny });
					}
					else {
						if (map[ny][nx] == '2')
						{
							return 2 * count;
						}
					}
				}
			}
		}		
	}
	return -1;
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	
	cin >> N >> M;
	for (int i = 0; i < N; i++)
	{
		cin >> map[i];
		for (int j = 0; j < M; j++)
		{
			if (map[i][j] == '2') {
				bird_q.push({ j,i });
				visit[i][j] = true;
			}
			else if (map[i][j] - '0' > 2)
			{
				food_q.push({ j,i });
				visit[i][j] = true;
			}
		}		
	}
	int answer = solve();
	if (answer == -1)
		cout << "NIE";
	else	
		cout << "TAK\n" << answer << "\n";
	return 0;
	

}