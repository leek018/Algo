#include <iostream>
#include <vector>
#include <queue>
using namespace std;
bool visit[100][100];
bool distanceVisit[100][100];
int islandMap[100][100];
int map[100][100];
int N;

struct island {
	int leftUpX, leftUpY, rightDownX, rightDownY;
	island() {}
	island(int lux, int luy, int rDx, int rDy)
	{
		leftUpX = lux;
		leftUpY = luy;
		rightDownX = rDx;
		rightDownY = rDy;
	}
};
int dx[] = { -1,0,1,0 };
int dy[] = { 0,-1,0,1 };
vector<island> arr;
void bfs(int start_x, int start_y)
{
	int lux = start_x; int luy = start_y;
	int rdx = start_x; int rdy = start_y;
	visit[start_y][start_x] = true;
	queue<pair<int, int>> q;
	q.push({ start_x,start_y });
	while (!q.empty())
	{
		pair<int, int> ret = q.front();
		q.pop();
		islandMap[ret.second][ret.first] = arr.size();
		if (ret.first < lux)		
			lux = ret.first;
		if (ret.second < luy)
			luy = ret.second;
		if (ret.second > rdy)
			rdy = ret.second;
		if (ret.first > rdx)
			rdx = ret.first;
		for (int i = 0; i < 4; i++)
		{
			int nx = ret.first + dx[i];
			int ny = ret.second + dy[i];
			if (nx >= 0 && nx < N && ny >= 0 && ny < N && !visit[ny][nx] && map[ny][nx] == 1)
			{
				visit[ny][nx] = true;
				q.push({ nx,ny });
			}
		}
	}
	arr.push_back(island(lux, luy, rdx, rdy));
}
int answer = 10000;
int getDistance(int target)
{
	island ret = arr[target];
	for (int i = 0; i < N; i++)
		fill_n(distanceVisit[i], 100, false);
	queue<pair<int, int>> q;
	for (int i = ret.leftUpY; i <= ret.rightDownY; i++)
	{
		for (int j = ret.leftUpX; j <= ret.rightDownX; j++)
		{
			if (islandMap[i][j] == target)
			{
				distanceVisit[i][j] = true;
				q.push({ j,i });
			}			
		}
	}
	int count = 0;
	while (!q.empty())
	{
		int len = q.size();
		for (int i = 0; i < len; i++)
		{
			pair<int, int> ret = q.front();
			q.pop();
			int val = islandMap[ret.second][ret.first];
			if (val >= 0 && val != target)
			{
				return count - 1;
			}
			for (int j = 0; j < 4; j++)
			{
				int nx = ret.first + dx[j];
				int ny = ret.second + dy[j];
				if (nx >= 0 && nx < N && ny >= 0 && ny < N && !distanceVisit[ny][nx])
				{
					distanceVisit[ny][nx] = true;
					q.push({ nx,ny });
				}
			}
		}	
		count++;
	}
	return -1;
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> N;
	
	for (int i = 0; i < N; i++)
	{
		fill_n(islandMap[i], 100, -1);
		for (int j = 0; j < N; j++)
		{
			cin >> map[i][j];
		}
	}
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (map[i][j] == 1 && !visit[i][j])			
				bfs(j, i);			
		}
	}
	
	for (int i = 0; i < arr.size(); i++) {
		int ret = getDistance(i);
		if (ret > 0)		
			answer = answer > ret ? ret : answer;		
	}			
	cout << answer;

}