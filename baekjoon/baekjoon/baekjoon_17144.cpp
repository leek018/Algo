#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int map[50][50];
int temp_map[50][50];
vector<pair<int,int>> plan_a;
vector<pair<int, int>> plan_b;
int dx[] = { -1,0,1,0 };
int dy[] = { 0,-1,0,1 };
int R, C,T;
void swap(int src, int dst,vector<pair<int,int>> &plan)
{
	pair<int, int> &src_pos = plan[src];
	pair<int, int>& dst_pos = plan[dst];
	int temp = map[src_pos.second][src_pos.first];
	map[src_pos.second][src_pos.first] = map[dst_pos.second][dst_pos.first];
	map[dst_pos.second][dst_pos.first] = temp;
}

void work_cleaner()
{
	// 위쪽
	map[plan_a[0].second][plan_a[0].first] = 0;
	for (int i = 1; i < plan_a.size(); i++)
		swap(i - 1, i, plan_a);
	
	// 아래쪽
	map[plan_b[0].second][plan_b[0].first] = 0;
	for (int i = 1; i < plan_b.size(); i++)
		swap(i - 1, i, plan_b);
}

void print()
{
	for (int i = 0; i < R; i++)
	{
		for (int j = 0; j < C; j++)
		{
			cout << map[i][j] << " ";
		}
		cout << "\n";
	}
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> R >> C >> T;
	pair<int, int> cleaner[2];
	int cleaner_len = 0;
	for (int i = 0; i < R; i++)
	{
		for (int j = 0; j < C; j++) {
			int input;
			cin >> input;
			if (input == -1)
				cleaner[cleaner_len++] = { j,i };			
			map[i][j] = input;
		}			
	}
	//plan_a	
	for (int i = cleaner[0].second- 1; i >= 0; i--)	
		plan_a.push_back({ 0,i });
	
	for (int j = 1; j < C; j++)
		plan_a.push_back({ j,0 });

	for (int i = 1; i <= cleaner[0].second; i++)
		plan_a.push_back({ C - 1,i });

	for (int j = C - 2; j >= 1; j--)
		plan_a.push_back({ j,cleaner[0].second });
	   	


	//plan_b
	for (int i = cleaner[1].second+1; i < R; i++)
		plan_b.push_back({ 0,i });

	for (int j = 1; j < C ; j++)
		plan_b.push_back({ j,R - 1 });

	for (int i = R - 2; i >= cleaner[1].second; i--)
		plan_b.push_back({ C - 1,i });

	for (int j = C - 2; j >= 1; j--)
		plan_b.push_back({ j,cleaner[1].second });

	/*for (int i = 0; i < plan_b.size(); i++) {
		cout << "(" << plan_b[i].first << "," << plan_b[i].second << ")" << "->";
	}
	cout << "\n";*/

	/*work_cleaner();
	*/

	int time = 0;
	while (time != T)
	{
		queue<pair<int, int>> q;
		for (int i = 0; i < R; i++)
		{
			for (int j = 0; j < C; j++)
			{
				int val = map[i][j]/5;
				if (val >0)				
					q.push({ j,i });				
			}
		}
		for (int i = 0; i < R; i++)
			fill_n(temp_map[i], 50, 0);
		while (!q.empty())
		{
			pair<int, int> target = q.front();
			q.pop();
			int val = map[target.second][target.first] / 5;
			int count = 0;
			for (int i = 0; i < 4; i++)
			{
				int nx = target.first + dx[i];
				int ny = target.second + dy[i];
				if (nx >= 0 && nx < C && ny >= 0 && ny < R && map[ny][nx] != -1) {
					temp_map[ny][nx] += val;
					count++;
				}					
			}
			temp_map[target.second][target.first] += (-1) * val * count;
		}
		for (int i = 0; i < R; i++)
		{
			for (int j = 0; j < C; j++)
			{
				map[i][j] += temp_map[i][j];
			}
		}
		/*cout << "============확산=======\n";
		print();
		cout << "============청소=======\n";*/
		work_cleaner();
		/*print();*/
		time++;
	}
	int sum = 0;
	for (int i = 0; i < R; i++)
	{
		for (int j = 0; j < C; j++)
		{
			if (map[i][j] != -1 && map[i][j] != 0)
				sum += map[i][j];
		}
	}
	cout << sum;
	return 0;
}