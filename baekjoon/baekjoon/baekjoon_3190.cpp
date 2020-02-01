#include <iostream>

using namespace std;
bool visit[101][101];
int map[101][101];
int dx[] = { -1,0,1,0 };
int dy[] = { 0,-1,0,1 };
int N;
char changes[10001];
struct snake {
	int direc;	
	int head;
	int tail;
	pair<int, int> body[10000];
	snake() {
		direc = 2;
		visit[1][1] = true;
		tail = 0;
		head = 0;
		body[head] = { 1,1 };
	}	

	void changeDirec(char direc)
	{
		if (this->direc == 0)
		{
			if (direc == 'L')
				this->direc = 3;
			else
				this->direc = 1;
		}
		else if (this->direc == 1)
		{
			if (direc == 'L')
				this->direc = 0;
			else
				this->direc = 2;
		}
		else if (this->direc == 2)
		{
			if (direc == 'L')
				this->direc = 1;
			else
				this->direc = 3;
		}
		else {
			if (direc == 'L')
				this->direc = 2;
			else
				this->direc = 0;
		}
	}

	bool move_head()
	{
		pair<int, int> &h = body[head];
		pair<int, int> next = { h.first + dx[this->direc],h.second + dy[this->direc] };
		if (next.first <= 0 || next.first > N || next.second <= 0 || next.second > N || visit[next.second][next.first])
			return false;
		if (!map[next.second][next.first]) {			
			move_tail();
		}		
		else {
			map[next.second][next.first] = 0;
		}
		visit[next.second][next.first] = true;
		head++;
		head %= 10000;
		body[head] = next;
		return true;
	}

	void move_tail()
	{
		pair<int, int>& before = body[tail];
		visit[before.second][before.first] = false;
		tail++;
		tail %= 10000;
	}
};

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> N;
	int M;
	cin >> M;
	for (int i = 0; i < M; i++)
	{
		int r, c;
		cin >> r >> c;
		map[r][c] = 1;
	}
	/*for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= N; j++)
			cout << map[i][j] << " ";
		cout << "\n";
	}*/
	int L;
	cin >> L;
	for (int i = 0; i < L; i++)
	{
		int t;
		char type;
		cin >> t >> type;
		changes[t] = type;
	}
	snake my_snake;
	int time = 0;
	while (time <= 10000)
	{
		time++;		
		bool ret = my_snake.move_head();
		if (!ret)
			break;
		char type = changes[time];
		if (type > 0)
			my_snake.changeDirec(type);				
	}
	cout << time;
	return 0;
}