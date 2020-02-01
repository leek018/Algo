#include <iostream>
#include <queue>
#include <string>
using namespace std;
string map[100];
int visit[100][100];
struct GM {
	int x, y, count;
	GM(int x_a, int y_a, int c_a)
	{
		x = x_a;
		y = y_a;
		count = c_a;
	}
};
bool operator<(const GM& a, const GM& b)
{
	return a.count > b.count;
}
priority_queue<GM> pq;
int dx[] = { -1,0,1,0 };
int dy[] = { 0,-1,0,1 };
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int C, R;
	cin >> C >> R;
	for (int i = 0; i < R; i++) {
		cin >> map[i];
		fill_n(visit[i], 100, -1);
	}	
	visit[0][0] = 0;
	pq.push({ 0,0,0 });
	int answer = 0;
	while (!pq.empty())
	{		
		GM ret = pq.top();
		pq.pop();
		if (ret.y == R - 1 && ret.x == C - 1)
		{
			answer = ret.count;			
			break;
		}
		for (int i = 0; i < 4; i++)
		{
			int nx = ret.x + dx[i];
			int ny = ret.y + dy[i];
			if (nx >= 0 && nx < C && ny >= 0 && ny < R)
			{
				int visitVal = visit[ny][nx];
				if (map[ny][nx] == '1')
				{					
					if (visitVal < 0)
					{
						visit[ny][nx] = ret.count + 1;
						pq.push({ nx,ny,ret.count + 1 });
					}
					else {
						if (visitVal > ret.count + 1)
						{
							visit[ny][nx] = ret.count + 1;
							pq.push({ nx,ny,ret.count + 1 });
						}
					}
				}
				else {
					if (visitVal < 0)
					{
						visit[ny][nx] = ret.count;
						pq.push({ nx,ny,ret.count});
					}
					else {
						if (visitVal > ret.count)
						{
							visit[ny][nx] = ret.count;
							pq.push({ nx,ny,ret.count});
						}
					}
				}
			}
		}
	}
	cout << answer;		
}