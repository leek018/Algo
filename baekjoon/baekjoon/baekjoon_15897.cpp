#include <iostream>
#include <cmath>
using namespace std;

//long long sola(long long N)
//{	
//	long long sum = N;
//	for (int i = 1; i <= N; i++)
//	{
//		sum += (N - 1) / i;
//	}
//	return sum;
//}
//
//long long solb(long long N)
//{
//	
//	return answer;
//}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);


	long long N;
	long long answer = 0;
	cin >> N;

	cout << answer << "\n";
	/*for (int i = 1; i <= 50; i++)
	{
		cout << i << "\n";
		if (sola(i) != solb(i))
			cout << "sola : " << sola(i) << "solb : " << solb(i) <<"\n";
	}*/
	long long answer = 0;
	if (N == 1)
		answer = 1;
	else if (N == 2)
		answer = 3;
	else if (N == 3)
		answer = 6;
	else if (N == 4)
		answer = 9;
	else {
		long long i = 1;
		int before = N - 1;
		while (true)
		{
			long long current = (N - 1) / i;
			answer += current;
			if (i * i > N - 1)
				break;
			answer += (i - 1) * (before - current);
			before = current;
			if (i == current)
				break;
			i++;
		}
		if (i * i == N)
			answer += i - 1;
		answer += N;
	}
	
	
	
}