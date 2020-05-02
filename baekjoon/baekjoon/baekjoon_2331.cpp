#include <iostream>
#include <vector>
using namespace std;

int arr[6600];

int main()
{
	int A, P; cin >> A >> P;	
	int start = A;
	vector<int> answer;
	while (true)
	{
		if (arr[start] == 2)
			break;
		arr[start]++;
		answer.push_back(start);
		int sum = 0;		
		while (start != 0)
		{
			int r = start % 10;
			for (int i = 1; i < P; i++)
				r *= r;
			sum += r;
			start /= 10;
		}
		start = sum;
	}
	int i;
	for (i = 0; i < answer.size(); i++)
	{
		if (answer[i] == start)
			break;
	}
	cout << i;
	return 0;
}