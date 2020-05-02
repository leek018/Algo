#include <iostream>
using namespace std;

int getCount(int target,int N)
{
	int count = 0;
	for (int i = target; i <= N; i *= target)
		count += N / i;
	return count;
}
int main()
{
	int N; cin >> N;
	int two = getCount(2, N);
	int five = getCount(5, N);
	int answer = five;
	if (two < five)
		answer = two;
	cout << answer;
}