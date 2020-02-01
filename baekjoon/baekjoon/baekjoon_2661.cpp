#include <iostream>

using namespace std;
int sel[80];
int N;
bool check(int sel[], int size)
{
	if (size == 1)
		return true;
	if (sel[size - 2] ==sel[size-1])
		return false;	
	int start = 2;
	int left = size - 4;	
	while (left>=0)
	{		
		bool possible = false;
		for (int i = 0; i < start; i++)
		{
			if (sel[left + i] != sel[left + i + start]) {
				possible = true;
				break;
			}				
		}
		if (!possible)
			return false;
		left -= 2;
		start++;
	}
	return true;
	
}
bool solve(int r)
{
	if (r == N)	
		return true;
	for (int i = 1; i <= 3; i++)
	{
		if (r % 2 == 0)
		{
			sel[r] = i;
			bool possible = check(sel, r + 1);
			if (possible) {				
				bool res = solve(r + 1);
				if (res)
					return true;
			}			
		}
		else {
			sel[r] = i;
			bool possible = check(sel, r + 1);
			if (possible)
			{				
				bool res = solve(r + 1);
				if (res)
					return true;								
			}
		}
	}
	return false;
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	
	cin >> N;
	solve(0);
	for (int i = 0; i < N; i++)
		cout << sel[i];
	
}