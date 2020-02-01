#include <iostream>
#include <vector>	
using namespace std;

int arr[40000];
vector<int> x;

int bns(int target)
{
	int left = 0; int right = x.size()-1;
	while (left <= right)
	{
		int mid = (left + right) / 2;
		if (x[mid] > target)
		{
			right = mid - 1;
		}
		else if (x[mid] < target)
		{
			left = mid + 1;
		}
		else
			return mid;
	}
	return left;
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int N;
	cin >> N;
	for (int i = 0; i < N; i++)	
		cin >> arr[i];
	
	int answer = 0;
	x.push_back(0);
	for (int i = 0; i < N; i++)
	{		
		int myLink = arr[i];
		if (x.back() < myLink)
			x.push_back(myLink);
		else {
			int smallIdx = bns(myLink);
			if(smallIdx )
			x[smallIdx] = myLink;
		}						
	}
	answer = x.size() - 1;
	cout << answer;
}