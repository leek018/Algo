#include <iostream>
#include <vector>
using namespace std;

int N;
int heights[2000];
vector<int> LDS;
int bns(int ele)
{
	int left = 0;
	int right = LDS.size() - 1;
	int memory = right;
	while (left <= right)
	{
		int mid = (left + right) / 2;
		if (LDS[mid] < ele)
		{
			memory = mid;
			right = mid - 1;
		}
		else if (LDS[mid] == ele)
		{
			memory = mid;
			break;
		}
		else 
			left = mid + 1;		
	}
	return memory;
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N;
	for (int i = 0; i < N; i++)
		cin >> heights[i];
	for (int i = 0; i < N; i++)
	{
		int ele = heights[i];
		if (LDS.empty())
			LDS.push_back(ele);
		else {
			if (LDS.back() < ele)
			{
				int ret_idx = bns(ele);
				LDS[ret_idx] = ele;
			}
			else if(LDS.back() > ele)
				LDS.push_back(ele);
		}
	}
	int answer = N - LDS.size();
	cout << answer;		
	return 0;
}