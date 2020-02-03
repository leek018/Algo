#include <iostream>
#include <string>
using namespace std;
string map[100];
int record[100][100];
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int N,M; cin >> N >> M;
	for (int i = 0; i < N; i++) {
		fill_n(record[i], 100, -1);
		cin >> map[i];
	}		
	for (int j = M-1; j >=0; j--)
	{
		for (int i = 0; i < N; i++)
		{
			if (map[i][j] == 'c')
			{
				int time = 0;
				for (int k = j; k < M; k++)
				{
					if (record[i][k] < 0)
						record[i][k] = time++;
					else break;					
				}
			}
		}
	}
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
			cout << record[i][j] << " ";
		cout << "\n";
	}
	return 0;
}