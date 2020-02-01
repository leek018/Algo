#include <iostream>

using namespace std;
int card[1000000];
int skill[1000000];
int N;
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N;
	int top = -1;
	int bot = 0;
	
	for (int i = 0; i < N; i++)	
		cin >> skill[i];			

	int start = 1;
	for (int i = N-1; i >= 0; i--)
	{		
		if (skill[i] == 1) {
			++top;
			top %= N;
			card[top] = start++;
		}
		else if (skill[i] == 2)
		{
			int temp = card[top];
			card[top] = start++;
			top++;
			top %= N;
			card[top] = temp;
		}
		else {
			bot += (-1 + N);
			bot %= N;
			card[bot] = start++;
		}
	}
	int k = top;
	do
	{
		cout << card[top] << " ";
		top += (-1 + N);
		top %= N;
	} while (top != k);
	return 0;
}