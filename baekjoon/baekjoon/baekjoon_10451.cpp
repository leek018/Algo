#include <iostream>
using namespace std;
int arr[1001];
bool visit[1001];


bool dfs(const int &target,int next)
{
	if (visit[next])	
		return next == target;
	visit[next] = true;
	bool ret = dfs(target, arr[next]);
	if (!ret) {
		visit[next] = false;
		return false;
	}		
	return true;
}


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
		for (int i = 1; i <= N; i++)
			cin >> arr[i];
		fill_n(visit, 1001, false);
		int count = 0;
		for (int i = 1; i <= N; i++)
		{			
			if (!visit[i])
			{
				visit[i] = true;
				bool res = dfs(i, arr[i]);
				if (res)
					count++;
				else
					visit[i] = false;
			}
		}		
		cout << count << "\n";		
	}
	return 0;
	
}