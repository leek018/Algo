#include <iostream>
#include <algorithm>
#include <map>
using namespace std;
int arr[1000000];
int copy_arr[1000000];
map<int, int> pos;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int N; cin >> N;
	for (int i = 0; i < N; i++) {
		int input; cin >> input;
		arr[i] = input;
		copy_arr[i] = input;
	}
	sort(copy_arr, copy_arr + N);
	int start = 0;
	for (int i = 0; i < N; i++)
	{
		pair<map<int, int>::iterator, bool> ret = pos.insert({ copy_arr[i],start });
		if (ret.second)
			start++;
	}
	for (int i = 0; i < N; i++)	
		cout << pos[arr[i]] << " ";	
	return 0;
}