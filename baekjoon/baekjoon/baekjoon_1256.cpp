#include <iostream>
#include <string>
using namespace std;


int dp[101][101];
int N, M, K;

int cal(int N_rem, int M_rem)
{	
	if (N_rem == 0 || M_rem == 0)
		return dp[N_rem][M_rem] = 1;
	if (dp[N_rem][M_rem] > 0)
		return dp[N_rem][M_rem];
	int temp = cal(N_rem - 1, M_rem) + cal(N_rem, M_rem - 1);
	if (temp > 1000000000)
		temp = 1000000001;	
	return dp[N_rem][M_rem] = temp;
}


int main()
{
	freopen("sample_1256.txt", "r", stdin);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> N >> M >> K;

	if (K > cal(N, M))
		cout << -1 << "\n";
	else {
		string answer;
		while (K >=0)
		{
			if (N == 0)
			{
				for (int i = 0; i < M; i++)
					answer.push_back('z');
				break;
			}
			if (M == 0)
			{
				for (int i = 0; i < N; i++)
					answer.push_back('a');
				break;
			}
			int count = cal(N - 1, M);
			if (K <= count)
			{
				answer.push_back('a');
				N -= 1;
			}
			else {
				answer.push_back('z');
				M -= 1;
				K -= count;
			}
		}
		cout << answer << "\n";
	}	
	return 0;
}