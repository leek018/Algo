#include <iostream>
using namespace std;

int arr[100001];
int maxProfit[100001];
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int N;
	cin >> N;
	for (int i = 1; i <= N; i++)	
		cin >> arr[i];
	int maxVal = 0;
	for (int i = 1; i <= N - 1; i++)
	{
		if (arr[i] < arr[i + 1])
		{
			int j = i;
			int tempSum = 0;
			while (j > 0 && arr[i + 1] > arr[j]) {
				tempSum += arr[j];
				j--;				
			}
			int tempMax = arr[i + 1] * (i - j) - tempSum;
			maxVal = tempMax + maxProfit[j] > maxVal ? tempMax + maxProfit[j] : maxVal;
			maxProfit[i + 1] = maxVal;
		}
		else
			maxProfit[i + 1] = maxProfit[i];
	}
	cout << maxVal;
}