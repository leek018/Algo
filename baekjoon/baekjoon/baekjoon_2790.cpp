#include <iostream>
#include <algorithm>
using namespace std;
int arr[300000];
bool cmp(const int &a, const int &b)
{
	return a > b;
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int N; cin >> N;
	for (int i = 0; i < N; i++)
		cin >> arr[i];
	sort(arr, arr + N,cmp);
	int answer = 1;
	int localmax = arr[0] + 1;
	for (int i = 1; i < N; i++)
	{
		int currentVal = arr[i];
		if (localmax <= currentVal + N)
			answer++;					
		else
			break;
		if (currentVal + i + 1 > localmax)
			localmax = currentVal + i + 1;
	}
	cout << answer;
	return 0;	
}