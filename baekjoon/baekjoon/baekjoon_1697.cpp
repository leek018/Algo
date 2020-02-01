#include <iostream>
#include <queue>
using namespace std;

bool visit[100001];
int bfs(int n,int k)
{	
	queue<int> q;
	q.push(n);
	visit[n] = true;
	int count = 0;
	while (!q.empty())
	{		
		int len = q.size();		
		for (int i = 0; i < len; i++)
		{
			int ret = q.front();			
			q.pop();
			if (ret == k)
				return count;
			if (ret - 1 >= 0 && !visit[ret - 1])
			{
				visit[ret - 1] = true;
				q.push(ret - 1);
			}
			if (ret + 1 <= 100000 && !visit[ret + 1])
			{
				visit[ret + 1] = true;
				q.push(ret + 1);
			}
			if (ret * 2 <= 100000 && !visit[ret * 2])
			{
				visit[ret * 2] = true;
				q.push(2 * ret);
			}
		}		
		count++;		
	}
	return count;
}


int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int N, K;
	cin >> N >> K;
	if (N >= K)	
		cout << N - K;	
	else {
		int answer = bfs(N, K);		
		cout << answer;
	}
	
}