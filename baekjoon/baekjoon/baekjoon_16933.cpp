#include <iostream>
#include <string>
#include <queue>
using namespace std;
string map[1000];
int visit[2][1000][1000];
struct Node {
	int x, y, chance;
	Node(int x_a, int y_a, int c_a)
	{
		x = x_a;
		y = y_a;
		chance = c_a;
	}
};

int dx[] = { -1,0,1,0 };
int dy[] = { 0,-1,0,1 };
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int N, M,K;
	cin >> N >> M >> K;
	for (int i = 0; i < N; i++) {
		fill_n(visit[0][i], 1000, -1);
		fill_n(visit[1][i], 1000, -1);		
		cin >> map[i];
	}

	queue<Node> q;
	q.push(Node(0, 0, K));
	visit[1][0][0] = K;
	int answer = -1;
	int count = 1;
	while (!q.empty())
	{
		bool possible = false;
		int len = q.size();
		for (int i = 0; i < len; i++)
		{
			Node ret = q.front();
			q.pop();
			if (ret.x == M - 1 && ret.y == N - 1)
			{
				answer = count;
				possible = true;
				break;
			}
			for (int j = 0; j < 4; j++)
			{
				int nx = ret.x + dx[j];
				int ny = ret.y + dy[j];
				if (nx >= 0 && nx < M && ny >= 0 && ny < N)
				{
					if (map[ny][nx] == '1')
					{
						if (count % 2 == 1) {
							if (ret.chance > 0)
							{
								int visitVal = visit[0][ny][nx];
								if (visitVal < 0) {
									visit[0][ny][nx] = ret.chance - 1;
									q.push(Node(nx, ny, ret.chance - 1));
								}
								else {
									if (visitVal < ret.chance - 1)
									{
										visit[0][ny][nx] = ret.chance - 1;
										q.push(Node(nx, ny, ret.chance - 1));
									}
								}
							}
						}
						else {
							int visitVal = visit[1][ret.y][ret.x];
							if (visitVal < 0) {
								visit[1][ret.y][ret.x] = ret.chance;
								q.push(Node(ret.x, ret.y, ret.chance));
							}
							else {
								if (visitVal < ret.chance)
								{
									visit[1][ret.y][ret.x] = ret.chance;
									q.push(Node(ret.x, ret.y, ret.chance));
								}
							}
						}
						
					}
					else {
						int visitVal = visit[(count+1)%2][ny][nx];
						if (visitVal <0)
						{
							visit[(count + 1) % 2][ny][nx] = ret.chance;
							q.push(Node(nx, ny, ret.chance));
						}
						else {
							if (visitVal < ret.chance)
							{
								visit[(count + 1) % 2][ny][nx] = ret.chance;
								q.push(Node(nx, ny, ret.chance));
							}
						}
						
					}
				}
			}
		}
		if (possible)
			break;
		count++;
	}
	cout << answer;

}