#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
bool cmp(const pair<int, int>& a, const pair<int, int>& b)
{
	if (a.second == b.second)
		return a.first < b.first;
	return a.second > b.second;
}
int N;
pair<int, int> arr[50000];
int originalArr[50000];
bool visit[50000];
void dfs(int index,int beforeVal)
{
	if (visit[index] || index <0 || index >=N)
		return;
	if (originalArr[index] >= beforeVal)
		return;
	visit[index] = true;
	dfs(index - 1, originalArr[index]);
	dfs(index + 1, originalArr[index]);
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	vector<int> answer;
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> originalArr[i];
		arr[i].first = i;		
		arr[i].second = originalArr[i];
	}
	sort(arr, arr + N, cmp);	
	for (int i = 0; i < N; i++)
	{
		if (!visit[arr[i].first]) {
			dfs(arr[i].first,10001);
			answer.push_back(arr[i].first);
		}
	}
	sort(answer.begin(), answer.end());
	for (int i = 0; i < answer.size(); i++)
		cout << answer[i] + 1 << "\n";
	return 0;
}