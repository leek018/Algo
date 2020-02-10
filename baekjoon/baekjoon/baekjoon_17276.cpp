#include <iostream>
#define ABS(X) ( (X) < 0 ? (-(X)) : (X) )
using namespace std;
int map[500][500];
int lookupTable[2][4][4];
int copy_map[4][500];
int dx[] = { -1,0,1,1 };
int dy[] = { 1,1,1,0 };
int start_x[4];
int start_y[4];
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	for (int i = 0; i < 4; i++)
	{
		fill_n(lookupTable[0][i], 4, -1);
		fill_n(lookupTable[1][i], 4, -1);
	}
	for (int i = 0; i < 4; i++)
	{
		for (int j = 3; j > i; j--)
		{
			lookupTable[0][i][j] = 1;
			lookupTable[1][i][3 - j] = 1;
		}
	}
	int T; cin >> T;
	for (int test_case = 0; test_case < T; test_case++)
	{		
		cout << "---------------\n";
		int N,theta; cin >> N >> theta;		
		for (int i = 0; i < N; i++)
		{			
			for (int j = 0; j < N; j++)
				cin >> map[i][j];
		}
		start_x[0] = N - 1; start_y[0] = 0; start_x[1] = N / 2; start_y[1] = 0; start_x[2] = 0; start_y[2] = 0; start_x[3] = 0; start_y[3] = N / 2;
		for (int i = 0; i < 4; i++)
		{
			int x = start_x[i]; int y = start_y[i];
			for (int j = 0; j < N; j++) {
				copy_map[i][j] = map[y][x];
				x += dx[i]; y += dy[i];
			}			
		}
		if (ABS(theta) > 180) {
			theta = 360 - ABS(theta);
			theta *= -1;
		}
		int q = ABS(theta)/45-1;
		if (q >= 0) {
			int r = 0;
			if (theta < 0)
				r = 1;
			for (int i = 0; i < 4; i++)
			{
				int rem = (i + q+1) % 4;
				if (theta > 0)
					rem = (i - (q+1) + 4) % 4;
				int flow = lookupTable[r][q][i];
				int paste_start_x = start_x[rem]; int paste_start_y = start_y[rem]; int inc = 1;
				if (flow < 0)
				{
					paste_start_x += (N-1) * dx[rem]; paste_start_y += (N-1) * dy[rem]; inc = -1;
				}
				for (int j = 0; j < N; j++)
				{
					map[paste_start_y][paste_start_x] = copy_map[i][j];
					paste_start_x += flow * dx[rem]; paste_start_y += flow * dy[rem];
				}
			}
		}
		cout << "---------------\n";
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < N; j++)
				cout << map[i][j] << " ";
			cout << "\n";
		}				
	}
	return 0;
}