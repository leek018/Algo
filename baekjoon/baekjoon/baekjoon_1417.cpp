#include <iostream>
#include <queue>
using namespace std;
int N;
struct cmp {
	bool operator()(const int &a,const int &b) {
		return a < b;
	}
};
priority_queue<int, vector<int>, cmp> pq;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N;
	int dasom;
	cin >> dasom;
	for (int i = 0; i < N - 1; i++) {
		int input;
		cin >> input;
		pq.push(input);
	}
	int count = 0;
	while (!pq.empty())
	{		
		int ret = pq.top();
		pq.pop();
		if (dasom > ret)
			break;
		if(ret !=0)
			pq.push(ret - 1);
		dasom++;
		count++;
	}
	cout << count;
}