#include <iostream>
#include <string>
using namespace std;
string A, B;
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> A >> B;
	int ASize = A.size();
	int BSize = B.size();
	int maxEqual = 0;
	for (int i = 0; i <= BSize - ASize; i++)
	{
		int sum = 0;
		for (int j = 0; j < ASize; j++)
		{
			if (B[i + j] == A[j])
				sum++;
		}
		maxEqual = maxEqual < sum ? sum : maxEqual;
	}
	cout << ASize - maxEqual;
}