#include <iostream>
#include <queue>
#define INF 2000
using namespace std;


struct node {
	pair<int, int> to;
	int cost;
	node( pair<int, int> t, int c) :to(t), cost(c) {}
};

bool operator<(const node& a, const node& b)
{
	return a.cost > b.cost;
}
priority_queue<node> pq;
int dist[125][125];
int map[125][125];

int dx[] = { -1,0,1,0 };
int dy[] = { 0,-1,0,1 };
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int N;
	cin >> N;
	int test_case = 1;
	while (N != 0)
	{
		for (int i = 0; i < N; i++)
			fill_n(dist[i], N, INF);
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < N; j++)
				cin >> map[i][j];
		}		
		pq.push(node({ 0,0 }, map[0][0]));
		while (!pq.empty())
		{
			node ret = pq.top();
			pq.pop();
			if (dist[ret.to.second][ret.to.first] > ret.cost)
			{
				dist[ret.to.second][ret.to.first] = ret.cost;
				for (int i = 0; i < 4; i++)
				{
					int nx = ret.to.first + dx[i];
					int ny = ret.to.second + dy[i];
					if (nx >= 0 && nx < N && ny >= 0 && ny < N)
					{
						pq.push(node({ nx,ny }, ret.cost + map[ny][nx]));
					}
				}
			}
		}
		cout << "Problem " << test_case << ": " << dist[N - 1][N - 1] << "\n";
		cin >> N;
		test_case++;
	}
	return 0;
}