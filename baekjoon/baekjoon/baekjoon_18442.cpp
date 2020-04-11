#include <iostream>
#include <vector>
#include <algorithm>
#define ABS(X) ( (X) < 0 ? (-(X)) : (X))
using namespace std;
long long pos[20];
vector<pair<int,long long>> dist;
bool comp(const pair<int, long long> &a, const pair<int, long long> &b)
{
	if (a.second == b.second)
		return a.first < b.first;
	return a.second < b.second;
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int V, P, L; cin >> V >> P >> L;
	for (int i = 0; i < V; i++)
		cin >> pos[i];
	for (int i = 0; i < V; i++)
	{
		dist.push_back({ pos[i],0LL });
		for (int j = 0; j < V; j++)
		{
			long long diff = ABS(pos[i] - pos[j]);
			if (diff > L - diff)
				diff = L - diff;
			dist[i].second += diff;
		}
	}
	sort(dist.begin(), dist.end(),comp);
	long long sum = 0LL;
	for (int i = 0; i < P; i++)
		sum += dist[i].second;
	cout << sum << "\n";
	for (int i = 0; i < P; i++)
		cout << dist[i].first << " ";
	return 0;
}