#include <iostream>	
#include <vector>	
#include <queue>
using namespace std;

vector<pair<int, unsigned int>> roadNflight[50000];
struct Node{
	int target;
	unsigned int cost;
	int chance;
	int before;
	Node(int t,int cha,int b,unsigned int c)
	{
		target = t;
		cost = c;
		chance = cha;
		before = b;
	}
};
bool operator<(const Node& a, const Node& b)
{
	return a.cost > b.cost;
}
priority_queue<Node> q;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, m, f,s, t;
	cin >> n >> m >> f >> s >> t;
	for (int i = 0; i < m; i++)
	{
		int from, to;
		unsigned int cost;
		cin >> from >> to >> cost;
		roadNflight[from].push_back({ to,cost });
		roadNflight[to].push_back({ from,cost });
	}
	for (int i = 0; i < f; i++)
	{
		int from, to;
		cin >> from >> to;
		roadNflight[from].push_back({ to,0 });
	}	
	q.push(Node(s, 1,-1, 0));
	unsigned int minCost = 2500000000;
	while (!q.empty())
	{
		Node ret = q.top();
		q.pop();
		if (ret.target == t)
		{
			minCost = ret.cost;
			break;
		}		
		for (int i = 0; i < roadNflight[ret.target].size(); i++)
		{			
			pair<int, int> linked = roadNflight[ret.target][i];
			if (linked.first == ret.before)
				continue;
			if (linked.second == 0 && ret.chance == 1)			
				q.push(Node(linked.first, 0,ret.target, ret.cost));
			else if(linked.second >0){
				q.push(Node(linked.first, ret.chance, ret.target,ret.cost + linked.second));
			}
		}
	}
	cout << minCost;


}