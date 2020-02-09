#include <iostream>
#define abs(X) ( (X) < 0 ? (-(X)) : (X) )
using namespace std;
int arr[100000];
int N;
int bns(int left,int right,int target)
{
	int l = left; int r = right;
	target *= -1;
	int mid = 0;
	while (l <= r)
	{
		mid = (l + r) / 2;
		int midVal = arr[mid];
		if (midVal < target)
			l = mid + 1;
		else if (midVal > target)
			r = mid - 1;
		else
			return mid;
	}	
	return mid;
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> N;
	for (int i = 0; i < N; i++)
		cin >> arr[i];
	int answerMin = 2147483647;
	int answerA = -1; int answerB = -1;
	for (int i = 0; i < N; i++)
	{
		int ret = bns(0, N - 1, arr[i]);
		if (ret != i)
		{
			if (answerMin > abs(arr[i] + arr[ret]))
			{
				answerA = arr[i]; answerB = arr[ret];
				answerMin = abs(arr[i] + arr[ret]);
			}
		}
	}
	if (answerA > answerB)
	{
		int temp = answerA;
		answerA = answerB;
		answerB = temp;
	}
	cout << answerA << " " << answerB;
	return 0;
}