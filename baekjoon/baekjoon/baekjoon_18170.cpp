#include <iostream>
#include <string>
#include <queue>
using namespace std;
bool visit[4][20][20][20][20];
string map[20];
int dx[] = { -1,0,1,0 };
int dy[] = { 0,-1,0,1 };
int N, M;
struct coinset {
	pair<int, int> coins[2];
};

bool rangeCheck(int x, int y)
{
	if (x < 0 || y < 0 || x >= M || y >= N)
		return false;
	return true;
}

bool visitCheck(int x1, int y1,int x2,int y2,int direc)
{
	if (visit[direc][y1][x1][y2][x2])
		return false;
	return true;
}
coinset myCoin;
int bfs()
{
	queue<coinset> q;
	q.push(myCoin);

	int count = 0;
	while (!q.empty())
	{
		count++;
		int len = q.size();
		for (int i = 0; i < len; i++)
		{			
			coinset ret = q.front();			
			q.pop();						
			for (int j = 0; j < 4; j++)
			{								
				pair<int, int> coin1 = ret.coins[0];
				pair<int, int> coin2 = ret.coins[1];
				int nx1 = coin1.first + dx[j];
				int ny1 = coin1.second + dy[j];
				int nx2 = coin2.first + dx[j];
				int ny2 = coin2.second + dy[j];
				bool rc1 = rangeCheck(nx1, ny1);
				bool rc2 = rangeCheck(nx2, ny2);
				if ( rc1 ^ rc2)				
					return count;
				if (rc1 && rc2)
				{
					if (map[ny1][nx1] == '#') {
						nx1 = coin1.first;
						ny1 = coin1.second;
					}
					if (map[ny2][nx2] == '#')
					{
						nx2 = coin2.first;
						ny2 = coin2.second;
					}
					if (!visitCheck(nx1, ny1, nx2, ny2, j))
						continue;
					visit[j][ny1][nx1][ny2][nx2] = true;
					coinset nCoinset;
					nCoinset.coins[0] = { nx1,ny1 };
					nCoinset.coins[1] = { nx2,ny2 };
					q.push(nCoinset);
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
	int coinFound = 0;
	
	for (int i = 0; i < N; i++) {
		cin >> map[i];
		for (int j = 0; j < M; j++)
		{
			if (map[i][j] == 'o')			
				myCoin.coins[coinFound++] = { j,i };
		}
	}
	int ret = bfs();
	cout << ret;
	return 0;		
}