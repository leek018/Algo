#include <iostream>
using namespace std;

int type[4][4] = {
	{2,1,2,1},
	{1,2,2,1},
	{1,2,1,2},
	{2,1,1,2}
};
int flow[4][6] = {
	{3,1,2,0,2,0},
	{3,1,2,1,2,0},
	{3,1,3,1,2,0},
	{3,0,3,1,2,0}
};
int input_flow[6];
int input_type[4];
int input_value[6];
int type_check()
{
	for (int i = 0; i < 4; i++)
	{
		bool isFind = true;
		for (int j = 0; j < 4; j++)
		{
			if (type[i][j] != input_type[j])
			{
				isFind = false;
				break;
			}
		}
		if (isFind)
			return i;
	}
	return -1;
}
int getArea[4][4] = { { 0,1,3,4 },{0,5,2,3},{4,5,1,2},{3,4,0,1} };
int findStart(int start_type)
{
	for (int i = 0; i < 6; i++)
	{
		bool isFind = true;
		for (int j = 0; j < 6; j++)
		{
			if (input_flow[(i + j) % 6] != flow[start_type][j])
			{
				isFind = false;
				break;
			}
		}
		if (isFind)
			return i;
	}
	return -1;
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int K; cin >> K;
	
	for (int i = 0; i < 6; i++)
	{
		int dir, value; cin >> dir >> value;
		input_type[dir - 1]++;
		input_flow[i] = dir - 1;
		input_value[i] = value;
	}
	int target_type = type_check();
	int target_start_pos = findStart(target_type);
	int temp[4];
	for (int i = 0; i < 4; i++)	
		temp[i] = (target_start_pos + getArea[target_type][i]) % 6;
	int answer = input_value[temp[0]] * input_value[temp[1]] - (input_value[temp[2]] * input_value[temp[3]]);
	cout << answer*K;
	return 0;
}