#include <iostream>

using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int x, y, p1, p2; cin >> x >> y >> p1 >> p2;
	int answer = -1;
	int rem = p1 - p2;
	int div = y;
	int mul = x;
	if (p1 <= p2)
	{
		rem = p2 - p1;
		div = x;
		mul = y;
	}
	for (int i = 0; i < div; i++)
	{
		if ((rem + mul * i) % div == 0)
		{
			int target = (rem + mul * i) / div;
			if (p1 > p2)
				answer = p2 + y * target;
			else
				answer = p1 + x * target;
			break;
		}
	}		
	cout << answer;
	return 0;
}