#include <iostream>
#include <queue>
using namespace std;

struct cmp {
	bool operator()(const int &a, const int &b)
	{
		return a < b;
	}
};
priority_queue<int,vector<int>,cmp> pq;
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int N; cin >> N;
	for (int i = 0; i < N; i++)
	{
		int x; cin >> x;
		if (x == 0)
		{
			if (pq.empty())
				cout << 0 << "\n";
			else {
				cout << pq.top() << "\n";
				pq.pop();
			}
		}
		else
			pq.push(x);
	}
	return 0;
}