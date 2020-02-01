#include <iostream>
using namespace std;


int map[1001][1001];
int answer[10001];
int color[6];

//우상 상 좌상 좌하 하 우하
int dx[] = { 1,0,-1,-1,0,1 };
int dy[] = { -1,-1,-1,1,1,1 };
int DirecCnt[6];
//좌상 좌하 하 우하 우상  상
int DirecFlow[6] = { 2,3,4,5,0,1 };
int DirectionDist[] = { 1,2,1,1,2,1 };
bool impossibleColor[6];
int predict(int x, int y)
{
	fill_n(impossibleColor, 6, false);
	for (int i = 0; i < 6; i++)
	{
		int nx = x + dx[i]*DirectionDist[i]; 
		int ny = y + dy[i]*DirectionDist[i];
		if (nx > 1000 || ny > 1000) {
			cout << "impossible";
			return -1;
		}
		int mapVal = map[ny][nx];
		if (mapVal != 0)
		{
			impossibleColor[mapVal] = true;
		}
	}
	int minColorCnt = 1000000;
	int minColor = -1;
	for (int i = 1; i < 6; i++)
	{
		if (!impossibleColor[i] && minColorCnt > color[i])
		{
			minColorCnt = color[i];
			minColor = i;
		}
	}
	return minColor;
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int startX = 500;
	int startY = 500;
	map[startY][startX] = 1;
	startX += 1;
	startY += -1;
	color[1] = 1;
	color[2] = 1;
	answer[1] = 1;
	answer[2] = 2;
	DirecCnt[0] = 1;
	int n = 2;
	int top = 0;
	while(n <= 10000)
	{		
		//0우상 1상 2좌상 3좌하 4하 5우하		
		int DirecType = DirecFlow[top];
		int howMany = DirecCnt[DirecType] + 1;
		DirecCnt[DirecType] = howMany;		
		for (int j = 0; j < howMany; j++)
		{						
			startX += dx[DirecType]*DirectionDist[DirecType];
			startY += dy[DirecType] * DirectionDist[DirecType];
			int selColor = predict(startX, startY);
			map[startY][startX] = selColor;
			color[selColor]++;
			answer[++n] = selColor;
			if (n > 10000)
				break;			
		}
		top++;
		top %= 6;
	}
	int T;
	cin >> T;
	for (int test_case = 1; test_case <= T; test_case++)
	{
		int N; cin >> N;
		cout << answer[N] << "\n";
	}
}