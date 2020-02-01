#include <iostream>
#include <cmath>
#include <queue>
#include <set>
using namespace std;
int group[3000];
bool visit[3000];
struct Enemy {
	int x, y;
	double r;
	Enemy(){}
	Enemy(int x_a, int y_a, double r_a)
	{
		x = x_a;
		y = y_a;
		r = r_a;
	}
};


int findRoot(int target)
{
	if (target == group[target])
		return target;
	group[target] = findRoot(group[target]);
	return group[target];
}

void unionGroup(int rootA, int rootB)
{
	group[rootB] = rootA;
}
int N;
Enemy enemies[3000];
void bfs(int targetEnemy)
{
	visit[targetEnemy] = true;
	queue<int> q;
	q.push(targetEnemy);
	while (!q.empty())
	{
		int target = q.front();
		q.pop();
		Enemy ret = enemies[target];
		for (int i = 0; i < N; i++)
		{
			if (!visit[i])
			{
				Enemy next = enemies[i];
				int x_diff = ret.x - next.x;
				int y_diff = ret.y - next.y;
				int xSquare = x_diff * x_diff;
				int ySquare = y_diff * y_diff;
				double d = sqrt(xSquare + ySquare);
				if (d <= ret.r + next.r) {
					unionGroup(findRoot(target), findRoot(i));
					visit[i] = true;
					q.push(i);
				}					
			}
		}
	}

}
set<int> distinctGroup;


int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int T;
	cin >> T;
	for (int test_case = 1; test_case <= T; test_case++)
	{
		distinctGroup.clear();
		fill_n(visit, 3000, false);
		cin >> N;		
		for (int i = 0; i < N; i++)
		{
			group[i] = i;			
			cin >> enemies[i].x >> enemies[i].y >> enemies[i].r;
		}
		for (int i = 0; i < N; i++)
		{
			if (!visit[i])
				bfs(i);
		}
		for (int i = 0; i < N; i++)
		{
			int root = findRoot(i);
			distinctGroup.insert(root);
		}
		cout << distinctGroup.size() << "\n";
	}


}