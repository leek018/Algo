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
	//true�� �� ������ ���� �ִ� �� �о
	//������ ī��Ʈ�� ���� ���� ������
	if (srcCount < targetCount)
	{
		//������ ��ȸ�� ���� ���� ��
		if (srcChance < targetChance)
		{
			//������ ������ ���� ���� �Դµ� ����غ��� ������ �������̾�
			if (targetCount - 3 * (targetChance - srcChance) < srcCount)
				return true;
			else
				return false;
		}
		else //���� �� ��ȸ�� ����
			return false;
	}
	else if (srcCount == targetCount)
	{
		if (srcChance < targetChance)
			return true;
		else
			return false;
	}
	else {//������ ī��Ʈ�� ���� ���� ����

		//���� ���� �𺸴� ��ȸ�� ���� ��
		if (srcChance > targetChance)
		{
			//���� �� ��ŭ ��ȸ�� ����� ī��Ʈ�� �۾� ���ٸ�
			if (srcCount - 3 * (srcChance - targetChance) <= targetCount)
				return false;
			else
				return true;
		}
		else { //���� ���� �𺸴� ��ȸ�� ���ٸ� 
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
				//��ȸ�� ������� ���� ��
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
				//��ȸ�� ��� �� ��
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
