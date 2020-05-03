#include <iostream>
using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int H, M; cin >> H >> M;
	if (H == 0)
		H = 24;
	int sum = H * 60 + M;
	sum -= 45;
	H = sum / 60;
	M = sum % 60;
	if (H == 24)
		H = 0;
	cout << H << " " << M;
	return 0;
}