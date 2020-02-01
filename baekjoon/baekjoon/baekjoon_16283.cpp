#include <iostream>

using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int a, b, n, w;
	cin >> a >> b >> n >> w;
	int sheep = -1;
	int goat = -1;
	bool possible = true;
	for (int i = 1; i < n; i++)
	{
		if (i * a + (n - i) * b == w)
		{
			if (sheep == -1 && goat == -1)
			{
				sheep = i;
				goat = n - i;

			}
			else {
				possible = false;
				break;
			}				
		}
	}
	if ( (sheep == -1 && goat == -1) || !possible)
		cout << -1;
	else
		cout << sheep << " " << goat << "\n";	
		
	return 0;
}