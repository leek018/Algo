#include <iostream>
#define MAXLIMIT 2000000
using namespace std;
int point[100000];
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int N, K;
	cin >> N >> K;
	int left = 0;
	int right = 0;
	for (int i = 0; i < N; i++) {
		int input; cin >> input;				
		point[i] = input;
		right += input;
	}			
	int answer = 0;		
	while (left <= right)
	{
		int mid = (left + right) / 2;		
		int group = 0;		
		int groupSum = 0;		
		for (int i = 0; i < N; i++)
		{
			groupSum += point[i];
			if (groupSum >= mid)
			{				
				group++;
				groupSum = 0;
			}
		}		
		if (group >= K) {
			left = mid + 1;
			answer = answer < mid ? mid : answer;
		}			
		else
			right = mid - 1;
	}		
	cout << answer;
	return 0;
}