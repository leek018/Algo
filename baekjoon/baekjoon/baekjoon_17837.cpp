#include <iostream>
#include <vector>
using namespace std;
int mapColor[12][12];
int N,K;
struct mal {
	int x, y, z, dir,indx;
	mal() {}
	mal(int x_, int y_, int z_, int dir_,int index) :x(x_), y(y_), z(z_), dir(dir_),indx(index) {}
};
//©Л аб ╩С го
int dx[] = { 1,-1,0,0 };
int dy[] = { 0,0,-1,1 };
int accross[] = { 1,0,3,2 };
mal arr[10];
vector<mal> Whererecord[12][12];

int nextMapColorType(int index)
{
	mal target = arr[index];
	int nx = target.x + dx[target.dir]; int ny = target.y + dy[target.dir];
	if (nx >= 0 && nx < N && ny >= 0 && ny < N)	
		return mapColor[ny][nx];			
	return 2;
}
void rotate(int index)
{
	arr[index].dir = accross[arr[index].dir];
}
void move_white(int index)
{
	mal target = arr[index];
	int nx = target.x + dx[target.dir]; int ny = target.y + dy[target.dir]; int z = target.z;
	for (int z_indx = z; z_indx < Whererecord[target.y][target.x].size(); z_indx++)
	{		
		int nz = Whererecord[ny][nx].size();
		int ni = Whererecord[target.y][target.x][z_indx].indx;
		int ndir = arr[ni].dir;
		Whererecord[ny][nx].push_back(mal(nx, ny, nz, ndir, ni));		
		arr[ni] = Whererecord[ny][nx][nz];
	}
	int pop_num = Whererecord[target.y][target.x].size() - z;
	for (int cnt = 0; cnt < pop_num; cnt++)
		Whererecord[target.y][target.x].pop_back();
}
void move_red(int index)
{
	mal target = arr[index];
	int nx = target.x + dx[target.dir]; int ny = target.y + dy[target.dir]; int z = target.z;
	int pop_num = Whererecord[target.y][target.x].size() - z;
	for (int cnt = 0; cnt < pop_num; cnt++)
	{
		int nz = Whererecord[ny][nx].size();
		int ni = Whererecord[target.y][target.x].back().indx;
		int ndir = arr[ni].dir;;
		Whererecord[ny][nx].push_back(mal(nx, ny, nz, ndir, ni));
		arr[ni] = Whererecord[ny][nx][nz];
		Whererecord[target.y][target.x].pop_back();
	}
}
void move_blue(int index)
{
	rotate(index);	
	int nextColor = nextMapColorType(index);
	if (nextColor == 0)
		move_white(index);
	else if (nextColor == 1)
		move_red(index);			
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> N >> K;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
			cin >> mapColor[i][j];
	}
	for (int k = 0; k < K; k++)
	{
		int y, x, dir; cin >> y >> x >> dir;
		arr[k] = mal(x-1, y-1, 0, dir-1, k);
		Whererecord[y - 1][x - 1].push_back(arr[k]);
	}
	int turn = 1;
	int answer = -1;
	while (true)
	{
		if (turn > 1000)
			break;	
		for (int i = 0; i < K; i++)
		{			
			int nextColor = nextMapColorType(i);
			if (nextColor == 0)
				move_white(i);
			else if (nextColor == 1)
				move_red(i);
			else
				move_blue(i);
			if(Whererecord[arr[i].y][arr[i].x].size() >=4)
			{
				answer = turn;
				break;
			}			
		}		
		if (answer != -1)
			break;
		turn++;
	}
	cout << answer;
	return 0;
}