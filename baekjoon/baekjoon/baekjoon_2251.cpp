#include <iostream>
#include <set>

using namespace std;
bool visit[201][201][201];
int water[3];
int Cap[3];
set<int> answer;
void solve()
{
	if (visit[water[0]][water[1]][water[2]])
		return;
	if (water[0] == 0)
		answer.insert(water[2]);
	visit[water[0]][water[1]][water[2]] = true;
	for (int i = 0; i < 3; i++)
	{
		int save_i = water[i];
		if (save_i == 0)
			continue;
		for (int j = 1; j <= 2; j++)
		{
			int target = (i + j) % 3;
			
			int save_j = water[target];			
			if (save_i <= Cap[target] - save_j)
			{
				water[target] += save_i;
				water[i] = 0;
			}
			else {
				water[target] = Cap[target];
				water[i] = save_i - (Cap[target] - save_j);
			}
			solve();
			water[target] = save_j;
			water[i] = save_i;
		}
	}
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	for (int i = 0; i < 3; i++)
		cin >> Cap[i];
	water[2] = Cap[2];
	solve();	
	for (set<int>::iterator it = answer.begin(); it != answer.end(); it++)
		cout << *it << " ";
	return 0;
}