#include <iostream>
#include <string>
using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int T; cin >> T;
	for (int i = 0; i < T; i++)
	{
		string a;
		int b;
		cin >> a >> b;
		int a_r = (a[1] - '1')%2; int a_c = (a[0] - 'A')%2;
		int a_type = (a_r + a_c) % 2;
		int b_r = ((b - 1) / 8) % 2; int b_c = ((b - 1) % 8) % 2;
		int b_type = (b_r + b_c) % 2;
		if (a_type == b_type)
			cout << "YES\n";
		else
			cout << "NO\n";
	}
	return 0;
}