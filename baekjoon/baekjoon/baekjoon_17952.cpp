#include <iostream>
#define MAXDAY 1000000
using namespace std;
int arr[2][MAXDAY];
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int N;
	cin >> N;
	int top = -1;
	int answer = 0;
	for (int i = 0; i < N; i++)
	{
		int type; cin >> type;
		if (type == 0)
		{
			if (top >= 0)
			{
				arr[0][top]--;
				if (arr[0][top] == 0) {
					answer += arr[1][top];
					top--;
				}
			}
		}
		else {
			int score, time; cin >> score >> time;
			arr[0][++top] = time-1;			
			arr[1][top] = score;
			if (arr[0][top] == 0) {
				answer += arr[1][top];
				top--;
			}
		}		
	}
	cout << answer;
	return 0;
}