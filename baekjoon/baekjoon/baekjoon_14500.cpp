#include <iostream>

using namespace std;
int typeLen[5] = { 2,1,8,4,4 };
int typeDx[5][24] = {
	{1,2,3,0,0,0},
	{1,1,0},
	{0,0,1,0,0,-1,1,2,2,1,2,2,0,0,1,0,0,-1,-1,-2,-2,-1,-2,-2 },
	{0,1,1,0,-1,-1,1,1,2,1,1,2},
	{1,2,1,1,2,1,0,0,1,0,0,-1}
};

int typeDy[5][24] = {
	{0,0,0,1,2,3},
	{ 0,1,1},
	{1,2,2,1,2,2,0,0,1,0,0,-1,-1,-2,-2,-1,-2,-2,0,0,1,0,0,-1 },
	{1,1,2,1,1,2,0,-1,-1,0,1,1},
	{0,0,1,0,0,-1,1,2,1,1,2,1}
};

int map[500][500];
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int N, M;
	cin >> N >> M;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
			cin >> map[i][j];
	}
	int answer = 0;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			for (int k = 0; k < 5; k++)
			{
				int types = typeLen[k];
				for (int l = 0; l < 3 * types; l += 3)
				{
					int m = -1;
					int sum = map[i][j];
					for (m = l; m < l + 3; m++)
					{
						int nx = j + typeDx[k][m];
						int ny = i + typeDy[k][m];
						if (nx >= 0 && nx < M && ny >= 0 && ny < N)
							sum += map[ny][nx];						
						else
							break;
					}
					if (m == l + 3)					
						answer = answer < sum ? sum : answer;					
				}
			}
		}
	}
	cout << answer;



}