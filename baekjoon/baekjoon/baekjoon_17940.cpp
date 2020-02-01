#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<pair<int, int>> edge[1000];
int type[1000];
int dist[2][1000];
struct subway {
	int transCnt, currentPos,time;
	subway(int tC, int cP,int t)
	{
		transCnt = tC;		
		currentPos = cP;
		time = t;
	}
};

bool operator<(const subway& a, const subway& b)
{
	return a.transCnt > b.transCnt;
}
priority_queue<subway> pq;
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int N, M;
	cin >> N >> M;
	for (int i = 0; i < N; i++)
		cin >> type[i];
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			int cost;
			cin >> cost;
			if (cost != 0)			
				edge[i].push_back({ j,cost });			
		}
	}
	fill_n(dist[0], 1000, 1000000);
	fill_n(dist[1], 1000, 1000000);
	pq.push(subway(0,0,0));
	dist[0][0] = 0;
	while (!pq.empty())
	{
		subway ret = pq.top();
		pq.pop();
		for (int i = 0; i < edge[ret.currentPos].size(); i++)
		{
			pair<int, int> link = edge[ret.currentPos][i];
			int tranCount = ret.transCnt;
			if (type[ret.currentPos] != type[link.first])
				tranCount++;
			int time = ret.time + link.second;
			if (dist[0][link.first] > tranCount) {
				dist[0][link.first] = tranCount;
				dist[1][link.first] = time;
				pq.push(subway(tranCount, link.first, time));
			}
			else if (dist[0][link.first] == tranCount)
			{
				if (dist[1][link.first] > time)
				{
					dist[1][link.first] = time;
					pq.push(subway(tranCount, link.first, time));
				}
			}							
		}								
	}
	cout << dist[0][M] << " " << dist[1][M];
}