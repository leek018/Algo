#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
pair<int,int> arr[200000];
int N;
bool cmp(const pair<int, int> &a, const pair<int, int> &b)
{
	if (a.first == b.first)
		return a.second < b.second;
	return a.first < b.first;
}
bool check()
{
	int key = arr[0].first;
	vector<int> compare;
	int start = 0;
	while (start < N && key == arr[start].first)	
		compare.push_back(arr[start++].second);
	while (start < N)
	{
		if (key == arr[start].first)
			return false;
		key = arr[start].first;
		for (int j = 0; j < compare.size(); j++)
		{
			if (start >= N || key != arr[start].first || arr[start].second != compare[j])
				return false;
			start++;
		}
	}
	return true;	
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int T; cin >> T;
	for (int test_case = 0; test_case < T; test_case++)
	{
		cin >> N;
		for (int i = 0; i < N; i++)
			cin >> arr[i].first >> arr[i].second;
		sort(arr, arr + N);
		if (check())
			cout << "BALANCED\n";
		else
			cout << "NOT BALANCED\n";
	}	
	return 0;
}