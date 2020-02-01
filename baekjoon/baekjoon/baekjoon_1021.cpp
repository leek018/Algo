#include <iostream>
#include <cstring>
using namespace std;

int N, M;
int original[50];
int cop[50];

int findPos(int target)
{	
	for (int i = 0; i < N; i++)
	{
		if (original[i] == target)
			return i;
	}
	return -1;
}

void makeOirign(int targetPos)
{
	memcpy(cop, original, sizeof(int) * N);
	int start = (targetPos+1) % N;
	int rear = 0;
	while (start != targetPos)
	{
		original[rear++] = cop[start];
		start++;
		start %= N;
	}
	N--;
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N >> M;
	for (int i = 0; i < N; i++)
		original[i] = i + 1;
	
	int answer = 0;
	for (int i = 0; i < M; i++)
	{
		int target; cin >> target;
		int targetPos = findPos(target);
		if (targetPos != 0)		
			answer += N - targetPos < targetPos ? N - targetPos : targetPos;		
		makeOirign(targetPos);		
	}
	cout << answer;
}