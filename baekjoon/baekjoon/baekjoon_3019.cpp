#include <iostream>
#include <vector>
using namespace std;
vector<int> dx[7];
vector<vector<int>> checktable[7];
int map[100];
int getrightplace(int C,int type)
{
	type -= 1;
	int count = 0;
	if (type == 0)
		count = C;	
	for (int i = 0; i < dx[type].size(); i++)
	{
		int testLength = dx[type][i];
		for (int x = 0; x < C; x++)
		{
			if (x + testLength > C)
				break;
			bool possible = true;
			for (int j = 0; j < testLength - 1; j++)
			{
				if (map[x + j] - map[x + j + 1] != checktable[type][i][j])
				{
					possible = false;
					break;
				}
			}
			if (possible)
				count++;
		}		
	}
	return count;
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	dx[0] = { 4 }; dx[1] = { 2 }; dx[2] = { 3,2 }; dx[3] = { 3,2 }; dx[4] = { 3,2,2,3 }; dx[5] = { 3,2,3,2 }; dx[6] = { 3,2,3,2 };	
	checktable[0].push_back({ 0,0,0 }); checktable[1].push_back({ 0 });
	checktable[2].push_back({ 0,-1 }); checktable[2].push_back({ 1 });
	checktable[3].push_back({ 1,0 }); checktable[3].push_back({ -1 });
	checktable[4].push_back({ 0,0 }); checktable[4].push_back({ 1 }); checktable[4].push_back({-1}); checktable[4].push_back({ 1,-1 });
	checktable[5].push_back({ 0,0 }); checktable[5].push_back({ 0 }); checktable[5].push_back({ -1,0 }); checktable[5].push_back({ 2 });
	checktable[6].push_back({ 0,0 }); checktable[6].push_back({ -2 }); checktable[6].push_back({ 0,1 }); checktable[6].push_back({ 0 });
	int C,Type; cin >> C >> Type;
	for (int i = 0; i < C; i++)
		cin >> map[i];
	int ret = getrightplace(C, Type);
	cout << ret;
	return 0;		
}