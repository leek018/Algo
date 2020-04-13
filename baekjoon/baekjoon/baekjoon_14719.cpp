#include <iostream>

using namespace std;
int heights[500];
int H, W;
pair<int,int> findBlock(int start)
{	
	int h = heights[start];
	while (h > 0)
	{
		int w = start + 1;
		while (w < W)
		{
			if (heights[w] >= h)
				return {h,w};
			w++;
		}
		h--;
	}	
	return { -1,-1 };
}

int solve()
{
	int start = 0;
	int sum = 0;
	while (start < W - 1)
	{
		pair<int,int> posOfBlock = findBlock(start);
		if (posOfBlock.first < 0)
			break;
		if (posOfBlock.second - start == 1) {
			start++;
			continue;
		}			
		sum += (posOfBlock.second - start - 1)*posOfBlock.first;
		for (int i = start + 1; i < posOfBlock.second; i++)
			sum -= heights[i];
		start = posOfBlock.second;
	}
	return sum;
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> H >> W;
	for (int i = 0; i < W; i++)
		cin >> heights[i];
	int answer = solve();
	cout << answer;
	return 0;
}