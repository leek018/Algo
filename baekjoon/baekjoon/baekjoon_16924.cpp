#include <iostream>
#include <vector>
using namespace std;
struct AnswerForm {
	int x, y, d;
	AnswerForm(int x_, int y_, int d_) :x(x_), y(y_), d(d_) {}
};
vector<AnswerForm> answerArray;
char map[101][101];
bool visit[101][101];
int N, M;
int startCount = 0;
int dx[] = { -1,0,1,0 };
int dy[] = { 0,-1,0,1 };
int isLookingForPlace(int startR, int startC,int distance)
{
	int starfound = 0;
	for (int i = 0; i < 4; i++)
	{
		int nx = startC + dx[i]*distance;
		int ny = startR + dy[i]*distance;
		if (nx <= 0 || ny <= 0 || nx > M || ny > N || map[ny][nx] == '.')
			return -1;				
	}
	if (!visit[startR][startC])
	{
		starfound++;
		visit[startR][startC] = true;
	}		
	for (int i = 0; i < 4; i++)
	{
		int nx = startC + dx[i]*distance;
		int ny = startR + dy[i]*distance;
		if (!visit[ny][nx])
		{
			starfound++;
			visit[ny][nx] = true;
		}
	}	
	return starfound;
}
void findCross()
{
	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= M; j++)
		{
			if (startCount == 0)
				return;
			if (map[i][j] == '*')
			{
				int testDistance = 1;
				while (true)
				{
					int ret = isLookingForPlace(i, j, testDistance);
					if (ret < 0)
						break;
					answerArray.push_back(AnswerForm(j, i, testDistance));
					startCount -= ret;
					testDistance++;
				}
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
		{
			cin >> map[i][j];
			if (map[i][j] == '*')
				startCount++;
		}
	}
	findCross();
	if (startCount != 0)
		cout << -1;
	else
	{
		cout << answerArray.size() << "\n";
		for (int i = 0; i < answerArray.size(); i++)
			cout << answerArray[i].y << " " << answerArray[i].x << " " << answerArray[i].d << "\n";
	}				
	return 0;
}