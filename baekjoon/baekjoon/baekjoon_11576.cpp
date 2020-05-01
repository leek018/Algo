#include <iostream>
#include <vector>
using namespace std;
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int sum = 0;
	int A, B, m; cin >> A >> B >> m;
	for (int i = 0; i < m; i++)
	{
		int val; cin >> val;		
		for (int j = 1; j < m - i; j++)
			val *= A;
		sum += val;
	}
	vector<int> answer;
	if (sum == 0)
		cout << 0;
	else {
		while (sum != 0)
		{
			answer.push_back(sum % B);
			sum /= B;
		}
		for (int i = answer.size() - 1; i >= 0; i--)
			cout << answer[i] << " ";
	}
	return 0;
}