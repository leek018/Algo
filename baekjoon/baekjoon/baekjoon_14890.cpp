#include <iostream>

using namespace std;

int map[100][100];
bool visit[100][100];
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int N, L;
	cin >> N >> L;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
			cin >> map[i][j];
	}
	int answer = 0;
	for (int i = 0; i < N; i++)
	{		
		int j = 0;
		while (j < N - 1)
		{
			int diff = map[i][j + 1] - map[i][j];
			if (diff == 1)
			{
				bool possible = true;
				if (j + 1 - L >= 0)
				{

					for (int k = j + 1 - L; k <= j; k++)
					{
						if (visit[i][k]) {
							possible = false;
							break;
						}
					}
					if (possible)
					{
						for (int k = j + 1 - L; k <= j; k++)
							visit[i][k] = true;
						j++;
					}
					else
						break;
				}
				else
					break;
			}
			else if (diff == -1) {
				if (j + L < N)
				{
					bool possible = true;
					for (int k = j + 1; k <= j + L; k++)
					{
						if (map[i][k] != map[i][j+1] || visit[i][k]) {
							possible = false;
							break;
						}
					}
					if (possible)
					{
						for (int k = j + 1; k <= j + L; k++)
						{
							visit[i][k] = true;
						}
						j += L;
					}
					else 
						break;
				}
				else
					break;
			}
			else if (diff == 0)
				j++;
			else
				break;
		}
		if (j == N - 1)
			answer++;
	}
	for (int i = 0; i < N; i++)
		fill_n(visit[i], N, false);

	for (int j = 0; j < N; j++)
	{
		int i = 0;
		while (i < N - 1)
		{
			int diff = map[i+1][j] - map[i][j];
			if (diff == 1)
			{
				bool possible = true;
				if (i + 1 - L >= 0)
				{

					for (int k = i + 1 - L; k <= i; k++)
					{
						if (visit[k][j]) {
							possible = false;
							break;
						}
					}
					if (possible)
					{
						for (int k = i + 1 - L; k <= i; k++)
							visit[k][j] = true;
						i++;
					}
					else
						break;
				}
				else
					break;
			}
			else if (diff == -1) {
				if (i + L < N)
				{
					bool possible = true;
					for (int k = i + 1; k <= i + L; k++)
					{
						if (map[k][j] != map[i+1][j] || visit[k][j]) {
							possible = false;
							break;
						}
					}
					if (possible)
					{
						for (int k = i + 1; k <= i + L; k++)
						{
							visit[k][j] = true;
						}
						i += L;
					}
					else
						break;
				}
				else
					break;
			}
			else if (diff == 0)
				i++;
			else
				break;
		}
		if (i == N - 1)
			answer++;		
	}
	cout << answer;
	return 0;
}