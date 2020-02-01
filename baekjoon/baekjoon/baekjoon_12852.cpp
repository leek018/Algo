#include <iostream>
using namespace std;
int memo[1000001];
int bestAnswer[1000001];
int minCount(int X)
{
	if (X == 1)
		return 0;		
	int localMin = 1e9;
	int localBest = -1;
	int memoVal = memo[X];
	if (memoVal > 0)
		return memoVal;
	if (X % 3 == 0)
	{
		int minA = minCount(X / 3)+1;		
		if (minA < localMin) {
			localBest = X / 3;
			localMin = minA;
		}
			
	}
	if (X % 2 == 0)
	{
		int minB = minCount(X / 2) + 1;
		if (minB < localMin) {
			localBest = X / 2;
			localMin = minB;
		}			
	}
	int minC = minCount(X-1) + 1;
	if (minC < localMin)
	{
		localBest = X - 1;
		localMin = minC;
	}	
	bestAnswer[X] = localBest;
	return memo[X] = localMin;
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int N; cin >> N;
	int answer = minCount(N);	
	cout << answer << "\n";
	int history = N;
	while (history != 0)
	{
		cout << history << " ";
		history = bestAnswer[history];
	}	
	return 0;
}