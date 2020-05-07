#include <iostream>
#include <vector>
using namespace std;

vector<pair<int,int>> stack;
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int N; cin >> N;
	int global_max = 0;
	for (int i = 0; i <= N; i++)
	{		
		int height = 0; 
		if( i !=N)
			cin >> height;				
		while (!stack.empty())
		{
			pair<int, int> ret = stack.back();			
			if (ret.second >= height)
			{
				stack.pop_back();
				int width = i;
				if (stack.size() != 0)
					width = i-stack.back().first - 1;
				int area = width * ret.second;
				if (area > global_max)
					global_max = area;
			}
			else
				break;
		}
		stack.push_back({ i,height });
	}	
	cout << global_max;
	return 0;
}