#include <iostream>
#include <vector>
using namespace std;
int N, M, K1, K2;

int trollPick[301];
vector<int> group_a[301];
vector<int> group_b[301];

int min_a = 300;
int min_b = 300;



void solve(int idx, int sum,int &min_count,vector<int> *group)
{
	if (sum >= min_count)
		return;
	if (idx == N + 1)
	{
		min_count = sum;
		return;
	}		
	bool possible = false;
	for (int i = 0; i < group[idx].size(); i++)
	{
		int pickAble = group[idx][i];
		if (trollPick[pickAble] == 0)
		{
			trollPick[pickAble] = idx;
			possible = true;
			solve(idx + 1, sum + 1, min_count, group);
			trollPick[pickAble] = 0;
		}
	}
	if (!possible)
	{
		solve(idx + 1, sum, min_count, group);
		for (int i = 0; i < group[idx].size(); i++)
		{
			int pickAble = group[idx][i];
			
		}
	}
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N >> M >> K1 >> K2;
	for (int i = 0; i < K1; i++)
	{
		int player, favorite;
		cin >> player >> favorite;
		group_a[player].push_back(favorite);
	}
	for (int i = 0; i < K2; i++)
	{
		int player, favorite;
		cin >> player >> favorite;
		group_b[player].push_back(favorite);
	}





}