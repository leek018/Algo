#include <iostream>
#include <string>
#include <cstring>
using namespace std;

int map[51][51];
string candi[6];

int answer = 250000;
int N, M, K;
int target[51][51];
void rotate()
{
	for (int i = 0; i < K; i++)
	{
		int r = candi[i][0] - 48;
		int c = candi[i][1] - 48;
		int s = candi[i][2] - 48;
		int count = 2 * s + 1;
		int start_x = c - s;
		int start_y = r - s;
		while (count != 1)
		{
			int temp_a = target[start_y][start_x + count - 1];
			for (int i = 0; i < count - 1; i++)
			{
				int dx = count - 1 - i;
				target[start_y][start_x + dx] = target[start_y][start_x + dx - 1];
			}
			start_x += count - 1;
			int temp_b = target[start_y + count - 1][start_x];
			for (int i = 0; i < count - 1; i++)
			{
				int dy = count - 1 - i;
				target[start_y + dy][start_x] = target[start_y + dy - 1][start_x];
			}
			target[start_y + 1][start_x] = temp_a;
			start_y += count - 1;
			int temp_c = target[start_y][start_x - count + 1];
			for (int i = 0; i < count - 1; i++)
			{
				int dx = count - 1 - i;
				target[start_y][start_x - dx] = target[start_y][start_x - dx + 1];
			}
			target[start_y][start_x - 1] = temp_b;
			start_x -= count - 1;
			for (int i = 0; i < count - 1; i++)
			{
				target[start_y - count + 1 + i][start_x] = target[start_y - count + 2 + i][start_x];
			}
			target[start_y - 1][start_x] = temp_c;
			start_y -= count - 1;
			start_x += 1;
			start_y += 1;
			count -= 2;
		}
	}
}
void swap(int src, int dst)
{
	string temp = candi[src];
	candi[src] = candi[dst];
	candi[dst] = temp;
}
void print()
{
	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= M; j++)
		{
			cout << target[i][j] << " ";
		}
		cout << "\n";
	}
	cout << "here------------------\n";
}
void sol(int idx)
{
	if (idx == K) {
		memcpy(target, map, sizeof(map));
		cout << "here------------------\n";
		rotate();
		print();
		for (int i = 1; i <= N; i++)
		{
			int sum = 0;
			for (int j = 1; j <= M; j++)
			{
				sum += target[i][j];
			}
			answer = answer > sum ? sum : answer;
		}
		return;
	}

	for (int i = idx; i < K; i++)
	{
		swap(idx, i);
		sol(idx + 1);
		swap(i, idx);
	}
}



int main()
{

	//freopen("sample_17406.txt", "r", stdin);
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N >> M >> K;
	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= M; j++)
			cin >> map[i][j];
	}
	for (int i = 0; i < K; i++)
	{
		int r, c, s;
		cin >> r >> c >> s;
		string temp;
		temp += (r + '0');
		temp += (c + '0');
		temp += (s + '0');
		candi[i] = temp;
	}
	sol(0);
	cout << answer << "\n";

	return 0;

}