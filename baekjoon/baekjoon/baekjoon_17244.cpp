#include <iostream>
#include <queue>
#include <string>
using namespace std;


int R,C;
int start_x, start_y, goal_x, goal_y;
int record[50][50];
string map[50];
bool visit[50][50];
int dist[7][7];
int productSize = 1;
pair<int, int> product[6];
int dx[] = { -1,0,1,0 };
int dy[] = { 0,-1,0,1 };
void bfs(int start_x, int start_y,int index)
{
	for (int i = 0; i < R; i++)
		fill_n(visit[i], 50, false);
	queue<pair<int, int>> q;
	q.push({ start_x,start_y });
	visit[start_y][start_x] = true;
	int count = 1;
	while (!q.empty())
	{
		int len = q.size();
		for (int i = 0; i < len; i++)
		{
			pair<int, int> ret = q.front();
			q.pop();
			for (int j = 0; j < 4; j++)
			{
				int nx = ret.first + dx[j];
				int ny = ret.second + dy[j];
				if (nx >= 0 && nx < C && ny >= 0 && ny < R && map[ny][nx] != '#' && !visit[ny][nx])
				{
					visit[ny][nx] = true;
					int mapVal = record[ny][nx];
					if (mapVal >= 0)
					{
						dist[index][mapVal] = count;
						dist[mapVal][index] = count;
					}
					q.push({nx,ny});
				}
			}

		}
		count++;
	}

}

int answer = 10000000;
bool solveVisit[7];
void solve(int index,int sel,int sum)
{
	if (sum >= answer)
		return;
	if (sel == productSize - 1)
	{
		answer = answer > sum + dist[index][productSize] ? sum + dist[index][productSize] : answer;
		return;
	}
	for (int i = 1; i < productSize; i++)
	{
		if (!solveVisit[i])
		{
			solveVisit[i] = true;
			solve(i, sel + 1, sum + dist[index][i]);
			solveVisit[i] = false;
		}		
	}
}

void printDist()
{
	cout << "========================\n";
	for (int i = 0; i <= productSize; i++)
	{
		for (int j = 0; j <= productSize; j++)
			cout << dist[i][j];
		cout << "\n";
	}
}


int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> C >> R;
	for (int i = 0; i < R; i++)
		fill_n(record[i], 50, -1);
	for (int i = 0; i < R; i++) {
		cin >> map[i];
		for (int j = 0; j < C; j++)
		{
			if (map[i][j] == 'S')
			{
				start_x = j;
				start_y = i;
				record[i][j] = 0;
			}
			else if (map[i][j] == 'E')
			{
				goal_x = j;
				goal_y = i;
			}
			else if (map[i][j] == 'X')
			{
				record[i][j] = productSize;
				product[productSize++] = { j,i };
			}
		}
	}	
	record[goal_y][goal_x] = productSize;
	bfs(start_x, start_y, 0);
	if (productSize == 1)
		cout << dist[0][productSize];
	else {
		for (int i = 1; i < productSize; i++)
			bfs(product[i].first, product[i].second, i);
		//printDist();
		solveVisit[0] = true;
		solve(0, 0, 0);
		cout << answer;
	}
	

}