#include <iostream>
#include <vector>
#include <algorithm>
#define ABS(X) ( (X) < 0 ? (-(X)) : (X))
using namespace std;
int V, P;
long long L;
long long pos[20];
bool check[20];
vector<long long> record;
long long answer = -1;
long long findMinDistFromPos(int index)
{
	int left = (index - 1 + V) % V;
	int right = (index + 1) % V;	
	while (left != index)
	{
		if (check[left])
			break;
		left = (left - 1 +V)%V;		
	}
	while (right != index)
	{
		if (check[right])
			break;
		right = (right + 1) % V;
	}
	long long left_diff = ABS(pos[index] - pos[left]);
	if (index < left)
		left_diff = L - left_diff;
	long long right_diff = ABS(pos[index] - pos[right]);
	if (index > right)
		right_diff = L - right_diff;
	if (left_diff < right_diff)
		return left_diff;
	return right_diff;
}
void combi(int start,int count)
{
	if (count == P)
	{
		long long sum = 0;
		for (int i = 0; i < V; i++)
		{
			if (!check[i])			
				sum += findMinDistFromPos(i);			
		}
		if (answer < 0 || answer > sum) {
			answer = sum;
			int temp = 0;
			for (int i = 0; i < V; i++)
			{
				if (check[i])
					record[temp++] = pos[i];
			}
		}			
	}
	for (int i = start; i < V; i++)
	{
		check[i] = true;
		combi(i + 1,count+1);
		check[i] = false;
	}
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> V >> P >> L;
	record.resize(P);
	for (int i = 0; i < V; i++)
		cin >> pos[i];	
	combi(0,0);
	sort(record.begin(), record.end());
	cout << answer << "\n";
	for (int i = 0; i < P; i++)
		cout << record[i] << " ";
	return 0;
}