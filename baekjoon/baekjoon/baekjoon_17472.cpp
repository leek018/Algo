//비교연산자를 사용할 경우
//변수화 한다음 비교를 진행하자
// 안그러면 또 실수 한다
//if( temp > l )
//{
//	dist[island][other_island] = l-1;.... 
//	이 부분!!!
//}
//그리고 알고리즘은 무조건 나이브하게 먼저 짜고
//최적화를 진행하기로 생각하자
// 


#include <iostream>
#include <queue>
using namespace std;

struct island {
	pair<int, int> left_top,right_bottom;	
};

struct node {
	int from, to, cost;
	node(int f, int t, int c) :from(f), to(t), cost(c) {}
};


struct cmp {
	bool operator()(const node &a, const node &b)
	{
		return a.cost > b.cost;
	}
};

int dist[7][7];
int dx[] = { -1,0,1,0 };
int dy[] = { 0,-1,0,1 };
island island_arr[7];
int map[10][10];
bool visit[10][10];
//세로,가로
int N, M;

void bfs(int start_x, int start_y,const int &island_idx)
{
	int min_x = start_x;
	int min_y = start_y;
	int max_x = start_x;
	int max_y = start_y;
	queue<pair<int, int>> q;
	q.push({ start_x,start_y });	
	visit[start_y][start_x] = true;
	pair<int, int> ret;
	while (!q.empty())
	{
		ret = q.front();		
		q.pop();
		for (int i = 0; i < 4; i++)
		{
			int nx = ret.first + dx[i];
			int ny = ret.second + dy[i];
			if ( nx >= 0 && nx < M && ny >=0 && ny < N && map[ny][nx] != 0 && !visit[ny][nx])
			{
				map[ny][nx] = island_idx;
				visit[ny][nx] = true;
				q.push({ nx,ny });
				min_x = min_x > nx ? nx : min_x;
				max_x = max_x < nx ? nx : max_x;
				min_y = min_y > ny ? ny : min_y;
				max_y = max_y < ny ? ny : max_y;
			}
		}
	}
	island_arr[island_idx].left_top.first = min_x;
	island_arr[island_idx].left_top.second = min_y;
	island_arr[island_idx].right_bottom.first = max_x;
	island_arr[island_idx].right_bottom.second = max_y;
}

void find_dist(int island_idx)
{
	
	pair<int, int>& l_t = island_arr[island_idx].left_top;
	pair<int, int>& r_b = island_arr[island_idx].right_bottom;

	for (int i = l_t.second; i <= r_b.second; i++)
	{
		for (int j = l_t.first; j <= r_b.first; j++)
		{
			if (map[i][j] != island_idx)
				continue;
			for (int k = 0; k < 4; k++)
			{
				int l = 1;
				while (true)
				{
					int nx = j + dx[k] * l;
					int ny = i + dy[k] * l;
					if (nx < 0 || nx >= M || ny < 0 || ny >= N || map[ny][nx] == island_idx)
						break;
					if (map[ny][nx] == 0)
						l++;
					else {
						if (l > 2)
						{
							int local_min = l - 1;
							int other_island = map[ny][nx];
							int temp = dist[island_idx][other_island];
							if (!temp || temp > local_min)
							{
								dist[island_idx][other_island] = local_min;
								dist[other_island][island_idx] = local_min;
							}
						}
						break;
					}
				}				
			}
		}
	}	
}
int group[7];

int find_root(int target)
{
	if (group[target] == target)
		return target;
	group[target] = find_root(group[target]);
	return group[target];
}

void union_group(int a, int b)
{
	int root_a = find_root(a);
	int root_b = find_root(b);
	group[root_b] = root_a;
}

void print(int N, int M)
{
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
			cout << map[i][j] << " ";
		cout << "\n";
	}
}

void print_dst(int island_cnt)
{
	for (int i = 1; i < island_cnt;i++)
	{
		for (int j = 1; j < island_cnt; j++)		
			cout << dist[i][j] << " ";
		cout << "\n";
	}
}
priority_queue<node, vector<node>, cmp> pq;
int main()
{
	freopen("sample_17472.txt", "r", stdin);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> N >> M;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
			cin >> map[i][j];
	}
	int island_cnt = 1;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			if (map[i][j] == 1 && !visit[i][j]) {
				map[i][j] = island_cnt;
				bfs(j, i, island_cnt);
				island_cnt++;
			}				
		}
	}
	//print(N, M);
	//cout << "========================\n";
	for (int i = 1; i < island_cnt; i++)	
		find_dist(i);
	//print_dst(island_cnt);
	for (int i = 1; i < island_cnt; i++)
	{
		for (int j = i+1; j < island_cnt; j++)
		{
			if (dist[i][j] != 0)
				pq.push(node(i, j, dist[i][j]));
		}
	}
	for (int i = 1; i < island_cnt; i++)
		group[i] = i;
	int count = 0;
	int dist = 0;
	while (count != island_cnt - 2 && !pq.empty())
	{
		node ret = pq.top();
		pq.pop();
		if (find_root(ret.from) != find_root(ret.to))
		{
			count++;
			dist += ret.cost;
			union_group(ret.from, ret.to);
		}
	}
	int answer = -1;
	if (count == island_cnt - 2)
		answer = dist;
	cout << answer << "\n";
	return 0;
}