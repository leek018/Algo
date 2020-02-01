#include <iostream>
#include <string>
#include <queue>
using namespace std;

string map[4];
int visit[4][4];
int N;
int dx[] = { -1,0,1,0 };
int dy[] = { 0,-1,0,1 };

void change(int start_x, int start_y,int type)
{
	for (int i = 0; i < 4; i++)
	{
		int k = 1; 
		while (true)
		{
			int nx = start_x + dx[i] * k;
			int ny = start_y + dy[i] * k;
			if (nx < 0 || nx >= N || ny < 0 || ny >= N)
				break;
			if (map[ny][nx] == 'X')
				break;
			visit[ny][nx] += type;
			k++;
		}
	}
}


int calVacant(int start_x, int start_y)
{
	int sum = 0;
	for (int i = 0; i < 4; i++)
	{
		int k = 1;
		while (true)
		{
			int nx = start_x + dx[i] * k;
			int ny = start_y + dy[i] * k;
			if (nx < 0 || nx >= N || ny < 0 || ny >= N)
				break;
			if (map[ny][nx] == 'X')
				break;
			sum++;
			k++;
		}
	}
	return sum;
}
struct Node {
	int x, y, cost;
	Node(int x_a, int y_a, int c)
	{
		x = x_a;
		y = y_a;
		cost = c;
	}
};

bool operator<(const Node& a, const Node& b)
{
	return a.cost > b.cost;
}
priority_queue<Node> pq;
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	while (true)
	{				
		cin >> N;
		if (N == 0)
			break;
		for (int i = 0; i < N; i++) {
			cin >> map[i];
			fill_n(visit[i], 4, 0);
		}
			
		
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < N; j++)
			{
				if (map[i][j] == '.')
				{
					int ret = calVacant(j, i);
					pq.push(Node(j, i, ret));
				}
			}
		}
		int answer = 0;
		while (!pq.empty())
		{
			Node ret = pq.top();
			pq.pop();
			if (visit[ret.y][ret.x] == 0)
			{
				answer++;
				visit[ret.y][ret.x] = 1;
				change(ret.x, ret.y, 1);
			}
		}
		cout << answer << "\n";
	}
}