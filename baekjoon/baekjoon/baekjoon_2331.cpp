#include <iostream>
#include <vector>
using namespace std;

int arr[236197];
vector<int> answer;
int main()
{
	int A, P; cin >> A >> P;	
	int start = A;
	
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
			int temp = 1;
			for (int i = 0; i < P; i++)
				temp *= r;
			sum += temp;
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