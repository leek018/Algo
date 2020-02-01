#include <iostream>
#include <string>
using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int T;
	cin >> T;
	for (int test_case = 1; test_case <= T; test_case++)
	{
		int N;
		cin >> N;
		string input;
		cin >> input;
		int limit = 8 * N;
		int i = 0;
		int j = 8;
		string answer;
		while (j <= limit)
		{
			char a = 0;
			for (int k = j - 1; k >= i; k--)
			{
				if (input[k] == 'I')
					a += (1 << (j-1 - k));
			}
			answer += a;
			i = j;
			j += 8;
		}
		cout << "Case #" << test_case << ": " << answer << "\n";
	}
	return 0;
}