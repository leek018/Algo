#include <iostream>
#include <queue>
#include <string>
using namespace std;

string map[800];
int record[800][800];
bool visit[800][800];
struct Bee {
	int x, y, time;
	Bee(int x_a, int y_a, int t)
	{
		x = x_a;
		y = y_a;
		time = t;
	}
};
int dx[] = { -1,0,1,0 };
int dy[] = { 0,-1,0,1 };
queue<Bee> Beeq;
int start_x, start_y;
int N,S;
//void print()
//{
//	for (int i = 0; i < N; i++)
//	{
//		for (int j = 0; j < N; j++)
//		{
//			cout << record[i][j];
//		}
//		cout << "\n";
//	}
//}
//void printVisit()
//{
//	for (int i = 0; i < N; i++)
//	{
//		for (int j = 0; j < N; j++)
//		{
//			cout << visit[i][j];
//		}
//		cout << "\n";
//	}
//}
bool bfs(int start_time)
{
	for (int i = 0; i < N; i++)
		fill_n(visit[i], 800, false);
	queue<pair<int,int>> gomq;
	visit[start_y][start_x] = true;
	gomq.push({ start_x,start_y });
	int Time = start_time;
	while (true)
	{
		for (int k = 0; k < S; k++)
		{			
			int len = gomq.size();
			if (len == 0)
				return false;
			for (int a = 0; a < len; a++)
			{
				if (gomq.empty())
					return false;
				pair<int, int> ret = gomq.front();				
				gomq.pop();							
				if (map[ret.second][ret.first] == 'D')
					return true;
				if (record[ret.second][ret.first] == Time)
					continue;
				for (int i = 0; i < 4; i++)
				{
					int nx = ret.first + dx[i];
					int ny = ret.second + dy[i];
					if (nx >= 0 && nx < N && ny >= 0 && ny < N && map[ny][nx] != 'T' && map[ny][nx] != 'H' && !visit[ny][nx])
					{
						if (record[ny][nx] > Time || map[ny][nx] == 'D')
						{							
							visit[ny][nx] = true;
							gomq.push({ nx,ny });
						}																			
					}
				}
			}
			
		}
		/*cout << "===================\n";
		printVisit();
		cout << "===================\n";*/
		Time++;
	}	
	return false;
}


int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N >> S;
	
	for (int i = 0; i < N; i++)
	{
		cin >> map[i];
		for (int j = 0; j < N; j++)
		{
			if (map[i][j] == 'H') {
				Beeq.push(Bee(j, i, 0));
				record[i][j] = 1;				
			}
				
			else if (map[i][j] == 'M')
			{
				start_x = j;
				start_y = i;
			}			
		}
	}
	int maxStartTime = 10000000;
	while (!Beeq.empty())
	{
		Bee ret = Beeq.front();
		if (map[ret.y][ret.x] == 'M')
		{
			maxStartTime = maxStartTime > ret.time ? ret.time : maxStartTime;
		}
		Beeq.pop();
		for (int i = 0; i < 4; i++)
		{
			int nx = ret.x + dx[i];
			int ny = ret.y + dy[i];
			if (nx >= 0 && nx < N && ny >= 0 && ny < N && map[ny][nx] != 'T' && map[ny][nx] != 'D')
			{
				int mapVal = record[ny][nx];
				if (mapVal == 0)
				{
					record[ny][nx] = ret.time + 1;
					Beeq.push(Bee(nx, ny, ret.time + 1));
				}
				else {
					if (mapVal > ret.time + 1)
					{
						record[ny][nx] = ret.time + 1;
						Beeq.push(Bee(nx, ny, ret.time + 1));
					}
				}
			}
		}
	}
	/*cout << "+++++++++++++++++=\n";
	print();
	cout << "+++++++++++++++++=\n";*/
	int answer = -1;
	int minStartTime = 0;
	maxStartTime--;
	while (minStartTime <= maxStartTime)
	{
		int mid = (minStartTime + maxStartTime) / 2;
		bool ret = bfs(mid);
		if (ret)
		{
			answer = answer < mid ? mid : answer;
			minStartTime = mid + 1;
		}
		else
		{
			maxStartTime = mid - 1;
		}
	}
	cout << answer;

}