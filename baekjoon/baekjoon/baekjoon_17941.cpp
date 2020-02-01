#include <iostream>
#include <cstring>
#include <vector>
#define VERTICAL 1
#define HORIZON 0
using namespace std;
int map[501][501];
int maxSheep[501][501];
int N, M;
//cctv는 상하좌우 반대로 이동
int dx[5] = { 0,0,0,1,-1 };
int dy[5] = { 0,1,-1,0,0 };
struct QuerySet {
	int cctvX, cctvY, R, C, K, D, flow;
	QuerySet() {}
	QuerySet(int cx, int cy, int r, int c, int k, int d, int fl)
	{
		cctvX = cx;
		cctvY = cy;
		R = r;
		C = c;
		K = k;
		D = d;
		flow = fl;
	}
};
vector<QuerySet> queries[501][2];
int answer[50000];
int getMax(int Y, int X, int R, int C, bool Movigtype)
{
	int bottom = Y + R - 1;
	if (bottom > N)
		bottom = N;
	int right = X + C - 1;
	if (right > M)
		right = M;
	int maxVal = -1;
	if (Movigtype == HORIZON)
	{
		for (int i = X; i <= right; i++)
		{
			if (maxVal < maxSheep[bottom][i])
				maxVal = maxSheep[bottom][i];
		}
	}
	else {
		for (int i = Y; i <= bottom; i++)
		{
			if (maxVal < maxSheep[i][right])
				maxVal = maxSheep[i][right];
		}
	}
	return maxVal;
}
void makeMax(int reference, bool Movigtype)
{
	memcpy(maxSheep, map, sizeof(int) * 501 * 501);
	if (Movigtype == HORIZON)
	{
		for (int j = 1; j <= M; j++)
		{
			for (int i = reference + 1; i <= N; i++)
			{
				if (maxSheep[i - 1][j] > maxSheep[i][j])
					maxSheep[i][j] = maxSheep[i - 1][j];
			}
		}
	}
	else {
		for (int i = 0; i <= N; i++)
		{
			for (int j = reference + 1; j <= M; j++)
			{
				if (maxSheep[i][j - 1] > maxSheep[i][j])
					maxSheep[i][j] = maxSheep[i][j - 1];
			}
		}
	}
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> N >> M;
	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= M; j++)
			cin >> map[i][j];
	}
	int Q;
	cin >> Q;
	int maxRange = -1;
	for (int i = 0; i < Q; i++)
	{
		int y, x, R, C, K, D;
		cin >> y >> x >> R >> C >> K >> D;
		if (D == 1 || D == 2)
			queries[x][VERTICAL].push_back(QuerySet(x, y, R, C, K, D, i));
		else
			queries[y][HORIZON].push_back(QuerySet(x, y, R, C, K, D, i));
		if (maxRange < y)
			maxRange = y;
		if (maxRange < x)
			maxRange = x;
	}
	//query를 담고 돌린다 왜냐하면 중복해서 maxSheep을 구하는 것을 막기 위해서
	for (int i = 1; i <= maxRange; i++)
	{
		for (int movingDirection = 0; movingDirection < 2; movingDirection++)
		{
			if (!queries[i][movingDirection].empty())
			{
				makeMax(i, movingDirection);
				int querylen = queries[i][movingDirection].size();
				for (int j = 0; j < querylen; j++)
				{
					QuerySet& query = queries[i][movingDirection][j];
					for (int k = 0; k < query.K; k++)
					{
						int val = getMax(query.cctvY, query.cctvX, query.R, query.C, movingDirection);
						answer[query.flow] ^= val;
						query.cctvX += dx[query.D];
						query.cctvY += dy[query.D];
					}
				}
			}
		}
	}
	for (int i = 0; i < Q; i++)
		cout << answer[i] << "\n";	
	return 0;
}