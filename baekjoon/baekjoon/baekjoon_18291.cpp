#include <iostream>
using namespace std;	
long long LIMIT = 1000000007;
long long pow(long long N)
{	
	if (N == 0LL)
		return 1;
	if (N == 1LL)
		return 2LL;
	long long ret = pow(N / 2LL)%LIMIT ;
	ret = (ret * ret) % LIMIT;
	if (N % 2LL == 1LL)
		ret = (ret * 2LL) % LIMIT;
	return ret;
}

int main()
{		
	ios::sync_with_stdio(0);
	cin.tie(0);
	int T;
	cin >> T;
	for (int test_case = 0; test_case < T; test_case++)
	{
		long long N; cin >> N;
		long long answer = 1;
		if (N != 1)
			answer = pow(N-2);
		cout << answer << endl;
	}
	return 0;
}