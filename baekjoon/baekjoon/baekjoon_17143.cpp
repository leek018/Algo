#include <iostream>
using namespace std;
#define DECREASE 0
#define INCREASE 1
int map[100][100];
int howmany[100][100];
//up down right left
int dx[] = { 0,0,1,-1 };
int dy[] = { -1,1,0,0 };
int accross[4] = { 1,0,3,2 };
int type[] = { DECREASE,INCREASE,INCREASE,DECREASE };
int R, C, M;
struct Shark {
	int y, x, dir, vol, sp;
	bool isDead;
};
Shark sharks[10000];
void moveShark(int target)
{
	int x = sharks[target].x;
	int y = sharks[target].y;
	int sp = sharks[target].sp;
	int dir = sharks[target].dir;
	int vol = sharks[target].vol;
	int my_type = type[dir];
	if (my_type == INCREASE)
	{
		int wall = C - 1;
		int offset = wall - x;
		if (dir == 1)
		{
			wall = R - 1;
			offset = wall - y;
		}
		int T = sp - offset;
		if (T < 0)
		{
			if (dir == 1)
				y += sp;
			else
				x += sp;
		}
		else {
			int Q = T / wall;
			int Rem = T % wall;
			int lastPos = Rem;
			int lastDir = dir;
			if (Q % 2 == 0)
			{
				lastPos = wall - Rem;
				lastDir = accross[dir];
			}
			if (dir == 2)
				x = lastPos;
			else
				y = lastPos;
			dir = lastDir;
		}
	}
	else {
		int offset = x;
		int wall = C - 1;
		if (dir == 0)
		{
			offset = y;
			wall = R - 1;
		}
		int T = sp - offset;
		if (T < 0)
		{
			if (dir == 0)
				y -= sp;
			else
				x -= sp;
		}
		else {
			int Q = T / wall;
			int Rem = T % wall;
			int lastPos = Rem;
			int lastDir = accross[dir];
			if (Q % 2 == 1)
			{
				lastPos = wall - Rem;
				lastDir = dir;
			}
			if (dir == 0)
				y = lastPos;
			else
				x = lastPos;
			dir = lastDir;
		}
	}
	sharks[target].x = x;
	sharks[target].y = y;
	sharks[target].dir = dir;
	int mapVal = map[y][x];
	if (mapVal >= 0)
	{
		if (sharks[mapVal].vol > vol)
			sharks[target].isDead = true;
		else {
			map[y][x] = target;
			sharks[mapVal].isDead = true;
		}
	}
	else
		map[y][x] = target;
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> R >> C >> M;
	for (int i = 0; i < R; i++)
		fill_n(map[i], 100, -1);
	for (int i = 0; i < M; i++)
	{
		int r, c, s, d, z;
		cin >> r >> c >> s >> d >> z;
		sharks[i].y = r - 1; sharks[i].x = c - 1; sharks[i].sp = s; sharks[i].dir = d - 1; sharks[i].vol = z; sharks[i].isDead = false;
		map[sharks[i].y][sharks[i].x] = i;
	}
	int start = -1;
	int answer = 0;
	while (true)
	{		
		start++;
		if (start == C)
			break;
		for (int i = 0; i < R; i++)
		{
			int mapVal = map[i][start];
			if (mapVal >= 0)
			{
				answer += sharks[mapVal].vol;
				sharks[mapVal].isDead = true;
				break;
			}
		}
		for (int i = 0; i < R; i++)
			fill_n(map[i], C, -1);
		for (int i = 0; i < M; i++)
		{
			if (!sharks[i].isDead)
				moveShark(i);
		}
	}
	cout << answer;
	return 0;
}