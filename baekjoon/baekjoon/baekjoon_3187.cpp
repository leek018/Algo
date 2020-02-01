#include <iostream>
#include <string>
#include <queue>
using namespace std;

pair<int, int> sheepShekki[62500];
pair<int, int> wolf[62500];

int sheepLen = 0;
int wolfLen = 0;
string map[250];
bool visit[250][250];
int dx[] = { -1,0,1,0 };
int dy[] = { 0,-1,0,1 };
int R, C;
pair<int,int> bfs(int start_x, int start_y,char equal,char target)
{
	queue<pair<int, int>> q;
	q.push({ start_x,start_y });
	visit[start_y][start_x] = true;
	int target_count = 0;
	int equal_count = 0;
	while (!q.empty())
	{
		pair<int, int> ret = q.front();
		q.pop();
		char val = map[ret.second][ret.first];
		if (val == equal)		
			equal_count++;					
		else if(val == target)
			target_count++;
		for (int i = 0; i < 4; i++)
		{
			int nx = ret.first + dx[i];
			int ny = ret.second + dy[i];
			if (nx >= 0 && nx < C && ny >= 0 && ny < R && !visit[ny][nx] && map[ny][nx] != '#')
			{
				q.push({ nx,ny });
				visit[ny][nx] = true;
			}
		}
	}
	if (equal_count > target_count)
		return { 1,target_count };
	else if (equal_count < target_count)
		return { -1,equal_count };
	return { 0,target_count };
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	
	cin >> R >> C;
	for (int i = 0; i < R; i++) {
		cin >> map[i];
		for (int j = 0; j < C; j++)
		{
			char input = map[i][j];
			if (input == 'k')
				sheepShekki[sheepLen++] = { j,i };
			else if (input == 'v')
				wolf[wolfLen++] = { j,i };
		}
	}
	int wolfAnswer = wolfLen;
	int sheepAnswer = sheepLen;
	if (wolfLen < sheepLen)
	{
		for (int i = 0; i < wolfLen; i++)
		{
			int start_x = wolf[i].first;
			int start_y = wolf[i].second;
			if (!visit[start_y][start_x])
			{
				pair<int, int> ret = bfs(start_x, start_y, 'v', 'k');
				if (ret.first >= 0)
					sheepAnswer -= ret.second;
				else
					wolfAnswer -= ret.second;
			}
		}
	}
	else {
		for (int i = 0; i < sheepLen; i++)
		{
			int start_x = sheepShekki[i].first;
			int start_y = sheepShekki[i].second;
			if (!visit[start_y][start_x])
			{
				pair<int, int> ret = bfs(start_x, start_y, 'k', 'v');
				if (ret.first > 0)
					wolfAnswer -= ret.second;
				else
					sheepAnswer -= ret.second;
			}
		}
	}
	cout << sheepAnswer << " " << wolfAnswer;
	
}