#include <iostream>


using namespace std;

int main()
{
	int x, y, w, h;
	cin >> x >> y >> w >> h;

	int answer = x;
	answer = answer > w - x ? w - x : answer;
	answer = answer > y ? y : answer;
	answer = answer > h - y ? h - y : answer;
	cout << answer;
	return 0;

}