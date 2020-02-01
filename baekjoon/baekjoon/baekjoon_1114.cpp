#include <iostream>
#include <algorithm>
#define abs(X) ((X) < 0 ? (-(X)) : (X) )
using namespace std;

int Pos[100001];
int L, K, C;
int bns(double target,int left,int right)
{	
	int mid = (left + right) / 2;
	while (left <= right)
	{
		mid = (left + right) / 2;
		double diff = (double)Pos[mid] - target;			
		if (abs((double)Pos[mid]- target) <=0.5)
			return mid;
		if ((double)Pos[mid] < target)
			left = mid + 1;
		else
			right = mid - 1;
	}
	return mid;
}



int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> L >> K >> C;
	for (int i = 0; i < K; i++)
		cin >> Pos[i];
	
	sort(Pos, Pos + K);
	int middle = L / 2;
	int longest = 0;
	int firstStart = 0;
	if (middle >= Pos[K - 1])
	{
		longest = L - Pos[K - 1];
		if (C > 1)
			firstStart = Pos[0];
		else
			firstStart = Pos[K - 1];
	}
	else if (middle <= Pos[0])
	{
		longest = L-Pos[0] > Pos[0] ? L-Pos[0] : Pos[0];
		firstStart = Pos[0];
	}
	else {
		
		longest = 1000000000;
		double q = (double)L / (C + 1);
		double target = q;
		int before = 0;
		int current = 0;
		int maxVal = 0;
		for (int i = 0; i < K; i++)
		{
			current = Pos[i];
			maxVal = current - before;			
			if (maxVal > longest)
				break;
			int count = 1;
			before = current;
			int startIdx = i;
			while (count != C)
			{
				int idx = bns(current + q, startIdx, K-1);
				current = Pos[idx];
				maxVal = maxVal < current - before ? current-before: maxVal;
				if (maxVal > longest)
					break;
				before = current;
				count++;
				startIdx = idx;
			}
			maxVal = maxVal < L - current ? L-current : maxVal;
			if (maxVal < longest)
			{
				firstStart = Pos[i];
				longest = maxVal;
			}
			before = 0;
		}
		
	}
	cout << longest << " " << firstStart;
}