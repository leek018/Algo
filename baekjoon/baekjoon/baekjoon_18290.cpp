#include <iostream>
using namespace std;
int N, M, K;
int map[10*10];
bool visit[10*10];
int answer = -1e8;
int dx[4] = { -1,0,1,0 };
int dy[4] = { 0,-1,0,1 };
bool isRight(int index)
{
	int r = index / M; int c = index % M;
	for (int i = 0; i < 4; i++)
	{
		int nr = r + dy[i]; int nc = c + dx[i];
		if (nr >= 0 && nr < N && nc >= 0 && nc < M)
		{
			int nindex = nr * M + nc; 
			if (visit[nindex])
				return false;
		}
	}
	return true;
}
void findMax(int start,int sum, int selCnt)
{
	if (selCnt == K)
	{
		if (answer < sum)
			answer = sum;
		return;
	}
	for (int i = start; i < N * M; i++)
	{
		bool rightRet = isRight(i);
		if (rightRet)
		{
			visit[i] = true;
			findMax(i + 1, sum + map[i], selCnt + 1);
			visit[i] = false;
		}
	}
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> N >> M >> K;
	for (int i = 0; i < M*N; i++)	
		cin >> map[i];
	findMax(0, 0, 0);
	cout << answer;	
}