#include <iostream>

using namespace std;

int map[20][20];
bool visit[20][20];
pair<int, int> candidate[400];
int candidateSize = 0;
int N,M;

int dx[] = { -1,0,1,0 };
int dy[] = { 0,-1,0,1 };
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N >> M;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			if (map[i][j] == 2)
			{
				for (int k = 0; k < 4; k++)
				{

				}
			}
		}
	}


}