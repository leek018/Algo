#include <iostream>

using namespace std;

long long arr[10000001];
long long sum = 0;
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int N;
	cin >> N;	
	int maxH = 0;
	for (int i = 0; i < N*N; i++)
	{
		int input;
		cin >> input;
		maxH = maxH < input ? input : maxH;
		sum += (long long)input;		
		arr[input]++;
	}
	for (int i = maxH - 1; i >= 1; i--)	
		arr[i] += arr[i + 1];	
	if (sum ==0 )
		cout << 0;
	else {
		long long temp = arr[1];
		int count = 1;
		while (temp*2 < sum)
			temp += arr[++count];
		cout << count;
	}		
}