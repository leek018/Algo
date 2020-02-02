#include <iostream>
#include <vector>
#include <algorithm>
struct contry {
	int index;
	int gold, silver, bronze;
	contry(int index_, int gold_, int silver_, int bronze_) :index(index_), gold(gold_), silver(silver_), bronze(bronze_) {}
};
using namespace std;
bool cmp(const contry& a, const contry& b)
{
	if (a.gold == b.gold)
	{
		if (a.silver == b.silver)
		{
			if (a.bronze == b.bronze)
				return a.index > b.index;
			return a.bronze > b.bronze;
		}
		return a.silver > b.silver;
	}
	return a.gold > b.gold;
}
vector<contry> arr;
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int N, M;
	cin >> N >> M;
	for (int i = 0; i < N; i++)
	{
		int ind, g, s, b;
		cin >> ind >> g >> s >> b;
		arr.push_back(contry(ind, g, s, b));
	}
	sort(arr.begin(), arr.end(), cmp);
	int rank = 1;
	int befor_rank = 1;
	int answer = arr[0].index;
	for (int i = 1; i < N; i++)
	{
		contry& before = arr[i - 1];
		contry& current = arr[i];
		if (!(before.gold == current.gold && before.silver == current.silver && before.bronze == current.bronze))
			rank = i+1;		
		if (current.index == M)
		{
			answer = rank;
			break;
		}			
	}
	cout << answer;
	return 0;
}