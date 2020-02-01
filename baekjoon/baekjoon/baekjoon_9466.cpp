#include <iostream>
#include <cstring>
#include <vector>
#define MAXNUM 100000
bool visit[MAXNUM];
int pointing[MAXNUM];
using namespace std;

int search(int source)
{
	vector<int> buffer;
	int start = source;
	while (true)
	{
		if (!visit[start])
		{
			buffer.push_back(start);
			visit[start] = true;
			start = pointing[start];
		}
		else {
			for (int i = 0; i < buffer.size(); i++)
			{
				if (buffer[i] == start)
					return i;
			}
			return buffer.size();
		}
	}

}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int T; cin >> T;
	for (int test_case = 1; test_case <= T; test_case++)
	{
		int answer = 0;
		int n; cin >> n;
		memset(visit, 0, sizeof(bool) * n);
		
		for (int i = 0; i < n; i++)
		{
			int target; cin >> target;
			pointing[i] = target - 1;
		}
		for (int i = 0; i < n; i++)
		{
			if (!visit[i])
			{
				answer += search(i);
			}
		}
		cout << answer << "\n";
	}
	return 0;
}