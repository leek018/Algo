#include <iostream>
using namespace std;
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int N;
	cin >> N;		
	int left = 0;
	int right = 2*N-2;
	for (int i = 0; i < N; i++)
	{		
		for (int j = 0; j <= right; j++)
		{
			if (j >= left )
				cout << "*";
			else
				cout << " ";
		}
		cout << "\n";
		left++; right--;				
	}
	left = N-2; right = N;
	for (int i = N; i < 2 * N - 1; i++)
	{
		for (int j = 0; j <= right; j++)
		{
			if (j >= left)
				cout << "*";
			else
				cout << " ";
		}
		cout << "\n";
		left--; right++;
	}	
}