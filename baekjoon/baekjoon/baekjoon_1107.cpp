#include <iostream>
using namespace std;

bool notAllowed[10];
int isAvailable(int N)
{	
	int temp = N;
	int count = 1;
	while (true)
	{		
		int r = temp % 10;
		if (notAllowed[r])
			return -1;
		temp /= 10;
		if (temp == 0)
			break;
		count++;
	}
	return count;
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int N,M; cin >> N >> M;
	for (int i = 0; i < M; i++)
	{
		int val; cin >> val;
		notAllowed[val] = true;
	}
	int answer = 5000000;
	if (N == 100)
		answer = 0;
	else if (N > 100)
	{
		int left = N - 1;
		int right = N;
		int l_avail = -1;
		while (left > 100)
		{
			l_avail = isAvailable(left);
			if (l_avail > 0)
				break;
			left--;
		}
		if (l_avail > 0)		
			answer = l_avail + N - left;
		answer = answer > N - 100 ? N - 100 : answer;
		int r_avail = -1;
		while (right < 1000000)
		{
			r_avail = isAvailable(right);
			if (r_avail > 0)
				break;
			right++;
		}
		if (r_avail > 0)
			answer = answer > r_avail + right - N ? r_avail + right - N : answer;
	}
	else {
		int left = N - 1;
		int right = N;
		int l_avail = -1;
		while (left >= 0)
		{			
			l_avail = isAvailable(left);
			if (l_avail > 0)
				break;
			left--;
		}
		if (l_avail > 0) 
			answer = l_avail + N - left;		
		int r_avail = -1;
		while (right < 100)
		{
			r_avail = isAvailable(right);
			if (r_avail > 0)
				break;
			right++;
		}
		if (r_avail > 0)		
			answer = answer > r_avail + right - N ? r_avail+right-N : answer;
		answer = answer > 100 - N ? 100-N : answer;
	}
	cout << answer;
	return 0;
}