#include <iostream>
#include <vector>
using namespace std;
int N, M, K;
bool visit[40][40];
void rotate(vector<pair<int,int>> &sticker)
{	
	int xmin = 0;
	int ymin = 0;
	for (int i = 0; i < sticker.size(); i++)
	{
		pair<int, int>& ele = sticker[i];
		int temp = ele.first;
		ele.first = -ele.second;
		ele.second = temp;		
		if (ele.first < xmin)
			xmin = ele.first;
		if (ele.second < ymin)
			ymin = ele.second;		
	}
	for (int i = 0; i < sticker.size(); i++)
	{
		pair<int, int>& ele = sticker[i];
		ele.first += xmin * (-1);
		ele.second += ymin * (-1);
	}
}
bool check(int xoffset, int yoffset, vector<pair<int, int>>& sticker)
{
	vector<pair<int, int>> temp;
	for (int i = 0; i < sticker.size(); i++)
	{
		pair<int, int>& ele = sticker[i];
		int xhat = ele.first + xoffset;
		int yhat = ele.second + yoffset;
		if (xhat < 0 || xhat >= M || yhat < 0 || yhat >= N || visit[yhat][xhat])
			return false;
		temp.push_back({ xhat,yhat });
	}
	for (int i = 0; i < temp.size(); i++)
	{
		pair<int, int>& ele = temp[i];
		visit[ele.second][ele.first] = true;
	}
	return true;
}
bool test(vector<pair<int,int>> &sticker)
{
	for (int rotationNum = 0; rotationNum < 4; rotationNum++)
	{
		for (int r = 0; r < N; r++)
		{
			for (int c = 0; c < M; c++)
			{								
				if (check(c, r, sticker))
					return true;				
			}
		}
		if(rotationNum <3)
			rotate(sticker);
	}
	return false;
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> N >> M >> K;
	int answer = 0;
	for (int i = 0; i < K; i++)
	{
		int H, W; cin >> H >> W;
		vector < pair<int, int>> sticker;
		for (int r = 0; r < H; r++)
		{
			for (int c = 0; c < W; c++)
			{
				int val; cin >> val;
				if (val > 0)
					sticker.push_back({ c,r });
			}
		}		
		if (test(sticker))
			answer += sticker.size();					
	}	
	cout << answer;
	return 0;
}