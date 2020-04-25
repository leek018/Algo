#include <iostream>
#include <algorithm>
#define REF 1000000007
using namespace std;
int my_num[201];
int memo[201][201];
int N;
int solve2(int student, int before_num)
{
	if (student == N)
		return my_num[N] - before_num + 1;
	int memoval = memo[student][before_num];
	if (memoval > 0)
		return memoval;
	int sum = 0;
	for (int i = before_num; i <= my_num[student]; i++)
		sum = (sum + (long long)solve2(student + 1, i)) % REF;
	return memo[student][before_num] = sum;
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);		
	int T; cin >> T;
	for (int test_case = 0; test_case < T; test_case++)
	{
		cin >> N;
		fill_n(memo[0], 201, 0);
		for (int i = 1; i <= N; i++) {
			cin >> my_num[i];
			fill_n(memo[i], 201, 0);
		}			
		sort(my_num+1, my_num + N + 1);		
		my_num[0] = 1;
		int ret = solve2(0, 1);
		int answer = ((long long)ret * N) % REF;
		cout << answer << "\n";		
	}
	return 0;
}