#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
vector<pair<int,int>> arr;
int N,K;
bool isPossible(int index, int timeSum, int ClassSum, int Target)
{
	if (ClassSum >= Target)
		return true;
	for (int i = index; i < K; i++)
	{
		int time = timeSum + arr[i].first; int cls = ClassSum + arr[i].second;
		if (time > N)
			break;
		if (isPossible(i + 1, time, cls, Target))
			return true;
	}
	return false;
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> N >> K;
	for (int i = 0; i < K; i++)
	{		
		int point, time; cin >> point >> time;
		arr.push_back({ time,point });
	}
	sort(arr.begin(), arr.end());
	int left = 0; int right = 10000000;
	int answer = 0;
	while (left <= right)
	{
		int mid = (left + right) / 2;
		if (isPossible(0, 0, 0, mid)) {
			answer = mid;
			left = mid + 1;
		}
		else
			right = mid - 1;
	}
	cout << answer;
	return 0;
}