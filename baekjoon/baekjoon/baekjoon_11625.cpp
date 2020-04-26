#include <iostream>
#include <algorithm>
using namespace std;
long long arr[100000];
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int N; cin >> N;		
	for (int i = 0; i < N; i++)
		cin >> arr[i];
	sort(arr, arr + N);
	long long answer = arr[0];
	int count = 1;
	int MaxCount = 1;
	long long beforeval = arr[0];
	for (int i = 1; i < N; i++)
	{
		if (arr[i] == beforeval)		
			count++;
		else {
			if (MaxCount < count) {
				MaxCount = count;
				answer = beforeval;
			}
			count = 1;			
		}
		beforeval = arr[i];
	}
	if (MaxCount < count) 	
		answer = beforeval;
	cout << answer;
	return 0;
}