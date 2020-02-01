#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<pair<int, long long>> edge[100001];
bool nonCandidate[100001];
struct Node
{
	int from;
	long long cost;
	Node(int f, long long c)
	{
		from = f;
		cost = c;
	}
};

bool operator < (const Node& a, const Node& b)
{
	return a.cost > b.cost;
}
priority_queue<Node> pq;
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int N, M, K;
	cin >> N >> M >> K;
	for (int i = 0; i < M; i++)
	{
		int u, v;
		long long c;
		cin >> u >> v >> c;
		edge[u].push_back({ v,c });
	}
	long long maxDistance = 0;
	int maxCity = 0;
	for (int i = 0; i < K; i++)
	{
		int k; cin >> k;
		nonCandidate[k] = true;
	}

	for (int i = 1; i <= N; i++)
	{
		if (!nonCandidate[i])
		{	
			while (!pq.empty())
				pq.pop();
			pq.push({ i,0LL });
			long long localMin =0;			
			while (!pq.empty())
			{
				Node ret = pq.top();
				pq.pop();				
				if (nonCandidate[ret.from])
				{					
					localMin = ret.cost;
					break;					
				}								
				for (int i = 0; i < edge[ret.from].size(); i++)
				{
					pair<int, long long> target = edge[ret.from][i];					
					pq.push(Node( target.first,ret.cost+target.second ));
				}
			}
			if (maxDistance < localMin)
			{
				maxCity = i;
				maxDistance = localMin;
			}			
		}
	}
	cout << maxCity <<"\n" << maxDistance;
}