#include <iostream>
#include <cmath>
#define abs(X) ( (X) < 0 ? (-(X)) : (X) )
using namespace std;




int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	
	int x, y, d, t;	
	cin >> x>>y >> d >> t;

	double goal = sqrt(x * x + y * y);
	double answer = goal;
	
	for (int i = 1; i <= (int)goal - d +1; i++)
	{
		double temp = (goal - (double)i) / d
		double cal = i + (goal-i)/d
	}
	cout << fixed;
	cout.precision(9);
	cout << answer;
}