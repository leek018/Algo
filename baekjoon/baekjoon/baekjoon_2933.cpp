#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <string>
#include <cstring>
using namespace std;
string map[100];
bool cluster[100][100];
bool visit[100][100];
int dx[] = { -1,0,1,0 };
int dy[] = { 0,-1,0,1 };
int R, C;
int MN = 0;
bool cmp(const pair<int,int> &a, const pair<int,int> &b)
{
	return a.second > b.second;
}
int howManyMoveDown(int start_x, int start_y)
{
	int count = 1;	
	while (true)
	{
		int ny = start_y + count;
		if (ny >= R || (map[ny][start_x] == 'x' && !cluster[ny][start_x]) ) {
			count--;
			break;
		}			
		count++;
	}
	return count;
}
void moveBufferList(vector<pair<int,int>> &buffer)
{	
	int localmoveMinCount = 100;
		memset(cluster, false, sizeof(bool) * 10000);
	for(int i = 0 ; i < buffer.size(); i++)	
		cluster[buffer[i].second][buffer[i].first] = true;	
	for(int i = 0 ; i < buffer.size(); i++)
	{		
		int ret = howManyMoveDown(buffer[i].first, buffer[i].second);
		localmoveMinCount = localmoveMinCount > ret ? ret : localmoveMinCount;	
	}	
	for (int i = 0; i < buffer.size(); i++)	
		map[buffer[i].second][buffer[i].first] = '.';		
	for (int i = 0; i < buffer.size(); i++)
		map[buffer[i].second+localmoveMinCount][buffer[i].first] = 'x';
}
void bfs(int start_x,int start_y)
{
	memset(visit, false, sizeof(bool) * 10000);
	queue<pair<int, int>> clusterQ;
	visit[start_y][start_x] = true;
	clusterQ.push({ start_x,start_y });
	vector < pair<int, int>> buffer;
	while (!clusterQ.empty())
	{
		pair<int, int> ret = clusterQ.front();
		if (ret.second == R - 1)
			return;
		clusterQ.pop();
		buffer.push_back(ret);
		for (int i = 0; i < 4; i++)
		{
			int nx = ret.first + dx[i];
			int ny = ret.second + dy[i];
			if (nx >= 0 && nx < C && ny >= 0 && ny < R && !visit[ny][nx] && map[ny][nx] == 'x')
			{
				visit[ny][nx] = true;
				clusterQ.push({ nx,ny });
			}
		}
	}
	if (buffer.size() == MN)
		return;
	moveBufferList(buffer);
}
void simulation(int startX,int throwR,int dir)
{
	//던진다
	int nx = startX;
	while (nx >=0 && nx <C)
	{
		if (map[throwR][nx] == 'x')
			break;
		nx += dx[dir];
	}
	if (nx < 0 || nx >= C)
		return;
	//미네랄 찾음	
	int brokenX = nx;
	map[throwR][brokenX] = '.';	
	MN--;	
	for (int i = 0; i < 4; i++)
	{
		nx = brokenX + dx[i];
		int ny = throwR + dy[i];
		if (nx >= 0 && nx < C && ny >= 0 && ny < R && map[ny][nx] == 'x')
		{
			visit[throwR][brokenX] = true;
			bfs(nx, ny);
		}			
	}		
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> R >> C;
	for (int i = 0; i < R; i++)
	{
		cin >> map[i];
		for (int j = 0; j < C; j++)
		{
			if (map[i][j] == 'x')
				MN++;
		}
	}
	int N; cin >> N;
	for (int i = 0; i < N; i++)
	{
		int throwR; cin >> throwR;
		throwR = R - throwR;
		int startX = 0;
		int dir = 2;
		if (i % 2 == 1)
		{
			startX = C - 1;
			dir = 0;
		}
		simulation(startX, throwR, dir);
	}
	for (int i = 0; i < R; i++)
		cout << map[i] << "\n";
	return 0;	
}