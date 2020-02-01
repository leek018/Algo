#include <iostream>
#include <vector>
using namespace std;

int main()
{
	int N; 
	cin >> N;
	int temp = N;
	vector<int> answer;
	if (temp == 0)
		cout << 0;
	else {
		while (temp != 0)
		{
			int rem = temp % -2;
			temp /= -2;
			if (rem == -1) {
				temp++;
				rem *= -1;
			}
			answer.push_back(rem);
		}
		for (int i = answer.size() - 1; i >= 0; i--)
			cout << answer[i];
	}
	
	return 0;
}