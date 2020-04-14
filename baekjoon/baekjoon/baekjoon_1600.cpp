#include <iostream>
#include <queue>
using namespace std;
int K, W, H;
int map[200][200];
int chance[200][200];
bool visit[200][200];
int dx[] = { -1,0,1,0 };
int dy[] = { 0,-1,0,1 };
int malDx[] = { -2,-1,1,2,2,1,-1,-2 };
int malDy[] = { -1,-2,-2,-1,1,2,2,1 };
struct Monkey {
	int x, y, k;
	Monkey(int x, int y, int k)
	{
		this->x = x;
		this->y = y;
		this->k = k;
	}
};


bool RangeCheck(int &x, int &y)
{
	if (x >= 0 && x < W && y >= 0 && y < H && map[y][x] == 0)
		return true;
	return false;
}

bool ChangePossible(int srcCount, int srcChance, int targetCount, int targetChance)
{
	//true일 때 굴러온 돌이 있던 돌 밀어냄
	//나보다 카운트가 많은 놈이 들어왔음
	if (srcCount < targetCount)
	{
		//나보다 기회가 많은 놈이 옴
		if (srcChance < targetChance)
		{
			//나보다 찬스가 많은 놈이 왔는데 계산해보니 나보다 좋은놈이야
			if (targetCount - 3 * (targetChance - srcChance) < srcCount)
				return true;
			else
				return false;
		}
		else //내가 더 기회가 많음
			return false;
	}
	else if (srcCount == targetCount)
	{
		if (srcChance < targetChance)
			return true;
		else
			return false;
	}
	else {//나보다 카운트가 적은 놈이 들어옴

		//내가 들어온 놈보다 기회가 많을 때
		if (srcChance > targetChance)
		{
			//내가 그 놈만큼 기회를 써봐서 카운트가 작아 진다면
			if (srcCount - 3 * (srcChance - targetChance) <= targetCount)
				return false;
			else
				return true;
		}
		else { //내가 들어온 놈보다 기회가 적다면 
			return true;
		}
	}
}
queue<Monkey> q;
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> K >> W >> H;
	for (int i = 0; i < H; i++)
	{
		for (int j = 0; j < W; j++)
			cin >> map[i][j];
	}
	int answer = 0;
	if (H==1 && W ==1)
		answer = 0;
	else {
		q.push(Monkey(0, 0, K));
		visit[0][0] = true;
		chance[0][0] = K;
		int count = 0;
		while (!q.empty())
		{
			int len = q.size();
			bool possible = false;
			for (int i = 0; i < len; i++)
			{
				Monkey ret = q.front();
				q.pop();
				if (ret.x == W - 1 && ret.y == H - 1)
				{
					answer = count;
					possible = true;
					break;
				}
				//기회를 사용하지 않을 때
				for (int j = 0; j < 4; j++)
				{
					int nx = ret.x + dx[j];
					int ny = ret.y + dy[j];
					if (RangeCheck(nx, ny))
					{
						if (!visit[ny][nx])
						{
							chance[ny][nx] = ret.k;
							q.push(Monkey(nx, ny, ret.k));
							visit[ny][nx] = true;
						}
						else {
							if (chance[ny][nx] < ret.k) {
								q.push(Monkey(nx, ny, ret.k));
								chance[ny][nx] = ret.k;
							}

						}
					}
				}
				//기회를 사용 할 때
				if (ret.k > 0) {
					for (int j = 0; j < 8; j++)
					{
						int nx = ret.x + malDx[j];
						int ny = ret.y + malDy[j];
						if (RangeCheck(nx, ny))
						{
							if (!visit[ny][nx])
							{
								chance[ny][nx] = ret.k - 1;
								q.push(Monkey(nx, ny, ret.k - 1));
								visit[ny][nx] = true;
							}
							else {
								if (chance[ny][nx] < ret.k - 1) {
									q.push(Monkey(nx, ny, ret.k - 1));
									chance[ny][nx] = ret.k - 1;
								}

							}
						}
					}
				}
			}
			if (possible)
				break;
			count++;
		}
		if (answer == 0)
			answer = -1;		
	}
	cout << answer;
	return 0;
}
