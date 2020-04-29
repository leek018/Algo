#include <iostream>
#include <vector>
using namespace std;
vector<int> arr;
vector<int> answer;
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int N, K; cin >> N >> K;	
	for (int i = 1; i <= N; i++)
		arr.push_back(i);
	int len = N;
	int pos = 0;
	for (int i = 0; i < N; i++)
	{
		pos = (pos + K - 1)%len;
		int target = arr[pos];
		answer.push_back(target);
		arr.erase(arr.begin() + pos);
		len--;
	}
	cout << "<" << answer[0];
	for (int i = 1; i < answer.size(); i++)
		cout << ", " << answer[i];
	cout << ">";
	return 0;
}