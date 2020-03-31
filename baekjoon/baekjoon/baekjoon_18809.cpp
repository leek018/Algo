#include <iostream>
#include <vector>
#include <queue>
#define RED 0
#define GREEN 1
#define FLOWER 2
using namespace std;

int map[50][50];
int typemap[50][50];
int timemap[50][50];
int R_N, G_N;
int N, M;
int dx[] = { -1,0,1,0 };
int dy[] = { 0,-1,0,1 };
int answer = 0;
vector<pair<int, int>> baeyang_possible_places;
vector<int> combi1_targets;
void simulation(vector<int>& R, vector<int>& G)
{
	for (int i = 0; i < N; i++) {
		fill_n(typemap[i], 50, -1);
		fill_n(timemap[i], 50, -1);
	}		
	queue<pair<int, int>> r_q;
	queue<pair<int, int>> g_q;
	for (int i = 0; i < R.size(); i++)
	{
		pair<int, int> target = baeyang_possible_places[R[i]];
		r_q.push(target);
		timemap[target.second][target.first] = 0;
		typemap[target.second][target.first] = RED;
	}
	for (int i = 0; i < G.size(); i++)
	{
		pair<int, int> target = baeyang_possible_places[G[i]];
		g_q.push(target);
		timemap[target.second][target.first] = 0;
		typemap[target.second][target.first] = GREEN;
	}
	int time = 0;
	int local_answer = 0;
	while (!r_q.empty() || !g_q.empty())
	{
		int R_len = r_q.size();
		for (int i = 0; i < R_len; i++)
		{
			pair<int, int> ret = r_q.front();
			r_q.pop();
			if (typemap[ret.second][ret.first] == FLOWER)
			{
				local_answer++;
				continue;
			}
			for (int j = 0; j < 4; j++)
			{
				int nx = ret.first + dx[j];
				int ny = ret.second + dy[j];
				if (nx >= 0 && nx < M && ny >= 0 && ny < N && typemap[ny][nx] != RED && typemap[ny][nx] != FLOWER && map[ny][nx] != 0)
				{
					if (typemap[ny][nx] == -1)
					{
						typemap[ny][nx] = RED;
						timemap[ny][nx] =  time + 1;
						r_q.push({ nx,ny });
					}
					else if (typemap[ny][nx] == GREEN)
					{
						if (timemap[ny][nx] != time)
							typemap[ny][nx] = FLOWER;
					}
				}
			}			
		}
		int G_len = g_q.size();
		for (int i = 0; i < G_len; i++)
		{
			pair<int, int> ret = g_q.front();
			g_q.pop();
			if (typemap[ret.second][ret.first] == FLOWER)
			{
				local_answer++;
				continue;
			}
			for (int j = 0; j < 4; j++)
			{
				int nx = ret.first + dx[j];
				int ny = ret.second + dy[j];
				if (nx >= 0 && nx < M && ny >= 0 && ny < N && typemap[ny][nx] != GREEN && typemap[ny][nx] != FLOWER && map[ny][nx] != 0)
				{
					if (typemap[ny][nx] == -1)
					{
						typemap[ny][nx] = GREEN;
						timemap[ny][nx] = time + 1;
						g_q.push({ nx,ny });
					}
					else if (typemap[ny][nx] == RED)
					{
						if (timemap[ny][nx] != time)
							typemap[ny][nx] = FLOWER;
					}
				}
			}
		}
		time++;
	}
	answer = answer < local_answer ? local_answer : answer;
}
void combi2(int current, int R_cnt, bool* visit,vector<int> &R)
{
	if (R_cnt == R_N)
	{
		vector<int> G;
		for (int i = 0; i < R_N + G_N; i++)
		{
			if (!visit[i])
				G.push_back(combi1_targets[i]);
		}
		simulation(R, G);
		return;
	}
	for (int i = current; i < R_N+G_N; i++)
	{
		R[R_cnt] = combi1_targets[i];
		visit[i] = true;
		combi2(i + 1, R_cnt + 1, visit, R);
		visit[i] = false;
	}
}

void combi1(int current, int choose_cnt)
{
	if (choose_cnt == R_N + G_N)
	{
		bool visit[10];
		vector<int> R(R_N);
		fill_n(visit, 10, false);
		combi2(0, 0, visit,R);
		return;
	}
	for (int i = current; i < baeyang_possible_places.size(); i++)
	{
		combi1_targets[choose_cnt] = i;
		combi1(i + 1, choose_cnt + 1);
	}
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N >> M >> R_N >> G_N;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			cin >> map[i][j];
			if (map[i][j] == 2)
				baeyang_possible_places.push_back({ j,i });
		}
	}
	combi1_targets.resize(R_N + G_N);
	combi1(0, 0);
	cout << answer;
	return 0;
}