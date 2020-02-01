#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

bool visit[10000][4];
int map[10000];
vector<pair<int,int>> candidate;
int N;
int buffer[2][4];
vector<int> stack(10000);
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> N;
	
	for (int i = 0; i < N; i++) {
		cin >> map[i];		
	}
	int answer = N;	
	for (int i = 0; i <= N - 4; i++)
	{
		fill_n(buffer[0], 4, 0);
		fill_n(buffer[1], 4, 0);
		for (int j = i; j < i + 4; j++) {
			buffer[0][map[j]]++;
			buffer[1][map[j]] = j;
		}

		if (buffer[0][1] == 1)
		{
			if (buffer[0][2] == 3 || buffer[0][3] == 3)
			{
				int type = 2;
				if (buffer[0][3] == 3)
					type = 3;
				int target = buffer[1][1];
				if (!visit[target][type])
				{
					candidate.push_back({ target,type });
					visit[target][type] = true;
				}
			}
		}
		else if (buffer[0][2] == 1)
		{
			if (buffer[0][1] == 3 || buffer[0][3] == 3)
			{
				int type = 1;
				if (buffer[0][3] == 3)
					type = 3;
				int target = buffer[1][2];
				if (!visit[target][type])
				{
					candidate.push_back({ target,type });
					visit[target][type] = true;
				}
			}

		}
		else if (buffer[0][3] == 1)
		{
			if (buffer[0][1] == 3 || buffer[0][2] == 3)
			{
				int type = 1;
				if (buffer[0][2] == 3)
					type = 2;
				int target = buffer[1][3];
				if (!visit[target][type])
				{
					candidate.push_back({ target,type });
					visit[target][type] = true;
				}
			}
		}
	}

	if (candidate.size() != 0) {
		int copyMap[10000];
		for (int i = 0; i < candidate.size(); i++)
		{
			memcpy(copyMap, map, sizeof(map));
			pair<int, int> ret = candidate[i];
			copyMap[ret.first] = ret.second;
			
			int top = -1;
			for (int j = 0; j <= ret.first; j++) 
				stack[++top] = copyMap[j];
			
			for (int j = ret.first + 1; j < N; j++)
			{
				int color = stack[top];
				if (color != copyMap[j])
				{					
					int topCopy = top;
					while (topCopy != -1 && stack[topCopy] == color)					
						topCopy--;
					if (top - topCopy >= 4)					
						top = topCopy;																				
				}				
				stack[++top] = copyMap[j];
			}
			int color = stack[top];
			int topCopy = top;
			while (topCopy != -1 && stack[topCopy] == color)			
				topCopy--;
			if (top - topCopy >= 4)
				top = topCopy;							
			answer = answer > top+1 ? top+1 : answer;			
		}
	}
	cout << answer;
	
}