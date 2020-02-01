#include <iostream>
#include <algorithm>
using namespace std;

int arr[10001];
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int N;
	cin >> N;
	int max = 0;
	for (int i = 0; i < N; i++)
	{
		int a;
		cin >> a;
		max = max < a ? a : max;
		arr[a]++;
	}
	for (int i = 1; i <= max; i++)
	{
		int val = arr[i];
		if (val > 0)
		{
			for (int j = 0; j < val; j++)
				cout << i << "\n";
		}
	}
	return 0;
}