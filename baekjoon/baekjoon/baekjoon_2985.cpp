#include <iostream>
#include <string>
using namespace std;


int main()
{
	//freopen("sample_2985.txt", "r", stdin);
	ios::sync_with_stdio(0);
	cin.tie(0);
	int a, b, c;
	cin >> a >> b >> c;		
	if (a + b == c)
		cout << a << "+" << b << "=" << c;
	else if(a*b == c)
		cout << a << "*" << b << "=" << c;
	else if(a/b == c)
		cout << a << "/" << b << "=" << c;
	else if(a-b == c)
		cout << a << "-" << b << "=" << c;
	else if( a == b+ c)
		cout << a << "=" << b << "+" << c;
	else if (a == b * c)
		cout << a << "=" << b << "*" << c;
	else if (a == b / c)
		cout << a << "=" << b << "/" << c;
	else 
		cout << a << "=" << b << "-" << c;
	return 0;
		
}