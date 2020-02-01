#include <iostream>
#include <queue>
#include <string>
using namespace std;

struct line{
	int x, y, type, change;
	line(int x_a, int y_a, int t, int c)
	{
		x = x_a;
		y = y_a;
		type = t;
		change = c;
	}
};

bool operator<(const line& a, const line& b)
{
	return a.change > b.change;
}

bool visit[2][500][500];
char type[] = {'\\','/'};
string map[500];
int dx[] = { -1,0,1,0,-1,1,1,-1};
int dy[] = { 0,-1,0,1,-1,-1,1,1};
int typeDirec[2][2] = { { 4,6 },{5,7} };
priority_queue<line> pq;
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int N,M;
	cin >> N >> M;
	for (int i = 0; i < 2; i++)
	{
		for (int j = 0; j < N; j++)
			fill_n(visit[i][j], 500, false);
	}
	for (int i = 0; i < N; i++)	
		cin >> map[i];	
	int count = 0;
	if (map[0][0] == type[1])
		count = 1;
	visit[0][0][0] = true;
	pq.push(line(0, 0, 0, count));
	int answer = -1;
	while (!pq.empty())
	{
		line ret = pq.top();
		pq.pop();
		if (ret.y == N - 1 && ret.x == M - 1 && ret.type == 0)
		{
			answer = ret.change;
			break;
		}
		for (int i = 0; i < 4; i++)
		{
			int nx = ret.x + dx[i];
			int ny = ret.y + dy[i];
			if (nx >= 0 && nx < M && ny >= 0 && ny < N)
			{				
				if (!visit[(ret.type + 1) % 2][ny][nx])
				{
					char mapVal = map[ny][nx];
					visit[(ret.type + 1) % 2][ny][nx] = true;
					int count = ret.change;
					if (mapVal == type[ret.type])
						count++;
					pq.push(line(nx, ny, (ret.type + 1) % 2, count));
				}								
			}
		}
		for (int i = 0; i < 2; i++)
		{
			int ndir = typeDirec[ret.type][i];
			int nx = ret.x + dx[ndir];
			int ny = ret.y + dy[ndir];
			if (nx >= 0 && nx < M && ny >= 0 && ny < N)
			{
				if (nx >= 0 && nx < M && ny >= 0 && ny < N)
				{
					if (!visit[ret.type][ny][nx])
					{
						char mapVal = map[ny][nx];
						visit[ret.type][ny][nx] = true;
						int count = ret.change;
						if (mapVal != type[ret.type])
							count++;
						pq.push(line(nx, ny, ret.type, count));
					}
				}
			}
		}
		
	}
	if (answer == -1)
		cout << "NO SOLUTION";
	else
		cout << answer;
}