#include <iostream>
#include <vector>
using namespace std;

int map[101][101];
int dp[101][101];
bool visit[101][101][4];
int M, N;// 세로,가로
int goal_y, goal_x, goal_direc;
int dx[] = { 0,1,-1,0,0 };
int dy[] = { 0,0,0,1,-1 };
int solve(int start_x, int start_y, int start_direc)
{
	if (visit[start_y][start_x][start_direc])
		return -1;
	if (start_x == goal_x && start_y == goal_y && goal_direc && start_direc)	
		return 0;
	for(int i = 0 ; i < )
	


}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> M >> N;
	for (int i = 0; i < M; i++)
	{
		for (int j = 0; j < N; j++)
			cin >> map[i][j];
	}
	int start_y, start_x, start_direc;
	
	cin >> start_y >> start_x >> start_direc >> goal_y >> goal_x >> goal_direc;
	

}