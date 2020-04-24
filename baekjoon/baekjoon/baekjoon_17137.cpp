#include <iostream>
#include <algorithm>
#define REF 1000000007
using namespace std;
int my_num[201];
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int T; cin >> T;
	for (int test_case = 0; test_case < T; test_case++)
	{
		int N; cin >> N;
		int answer = 0;
		for (int i = 0; i < N; i++)		
			cin >> my_num[i];
		sort(my_num, my_num + N + 1);
		int length = my_num[N - 1];
		int start = my_num[N];
		int last = start - length + 1;
		for(int i = 0 ; i < )
		cout << answer << "\n";		
	}
	return 0;
}