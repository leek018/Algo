#include <iostream>
#include <vector>
#define ROW 0
#define COL 1
#define BLOCK 2
using namespace std;

int map[9][9];
bool visit[3][10][10];
void switching(int r, int c, bool type,int value)
{
	visit[ROW][r][value] = type;
	visit[COL][c][value] = type;
	int block_num = (r / 3) * 3 + (c / 3);
	visit[BLOCK][block_num][value] = type;
}
vector<int> getCandidate(int r, int c)
{
	vector<int> output;
	int block_num = (r / 3) * 3 + (c / 3);
	for (int i = 1; i < 10; i++)
	{
		if (!visit[ROW][r][i] && !visit[COL][c][i] && !visit[BLOCK][block_num][i])
			output.push_back(i);
	}
	return output;
}
bool solve(int num)
{
	if (num == 81)
		return true;
	int r = num / 9; int c = num % 9;
	int val = map[r][c];
	if (val != 0)
	{
		if (solve(num + 1))
			return true;
	}		
	else {
		vector<int> candidate = getCandidate(r, c);
		for (int i = 0; i < candidate.size(); i++)
		{
			int ele = candidate[i];
			map[r][c] = ele;
			switching(r, c, true, ele);
			if (solve(num + 1))
				return true;
			map[r][c] = 0;
			switching(r, c, false, ele);			
		}
	}
	return false;
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	for (int i = 0; i < 9; i++)
	{
		for (int j = 0; j < 9; j++)
		{
			char input; cin >> input;
			int target = input - '0';
			map[i][j] = target;
			switching(i, j, true, target);
		}
	}
	solve(0);
	for (int i = 0; i < 9; i++)
	{
		for (int j = 0; j < 9; j++)
			cout << map[i][j];
		cout << "\n";
	}
	return 0;
}