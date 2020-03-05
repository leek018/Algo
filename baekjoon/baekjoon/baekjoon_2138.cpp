#include <iostream>
#include <string>
using namespace std;
int N;
string current_state;
string goal_state;
string copy_current_state;
bool isOne(int index)
{
	return copy_current_state[index] == '1';
}
void push(int index)
{
	if (index - 1 >= 0)
	{
		if (isOne(index - 1))
			copy_current_state[index - 1] = '0';
		else
			copy_current_state[index - 1] = '1';
	}
	if(isOne(index))
		copy_current_state[index] = '0';
	else
		copy_current_state[index] = '1';
	if (index + 1 < N) {
		if (isOne(index+1))
			copy_current_state[index + 1] = '0';
		else
			copy_current_state[index + 1] = '1';
	}		
}
int simulation()
{
	int count = 0;
	for (int i = 1; i < N; i++)
	{
		if (copy_current_state[i - 1] != goal_state[i - 1])
		{
			push(i);
			count++;
		}
	}
	return count;
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> N >> current_state >> goal_state;
	copy_current_state = current_state;
	int answer = -1;
	int res = simulation();
	if (copy_current_state[N - 1] == goal_state[N - 1])
		answer = res;
	copy_current_state = current_state;
	push(0);
	res = simulation() + 1;
	if (copy_current_state[N - 1] == goal_state[N - 1])
	{
		if (answer == -1)
			answer = res;
		else if(answer >res)
			answer = res;
	}
	cout << answer;
	return 0;
}