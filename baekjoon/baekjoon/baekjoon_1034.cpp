#include <iostream>
#include <string>
#include <map>
using namespace std;

using light_map = map<string, int>;
light_map my_map;
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	
	int N, M, K;
	cin >> N >> M ;
	for (int i = 0; i < N; i++)
	{
		string input;
		cin >> input;
		pair<light_map::iterator, bool> ret = my_map.insert({ input, 1 });
		if (!ret.second)
			ret.first->second++;
	}
	cin >> K;
	int answer = 0;
	int flag = (K % 2 == 1);
	for (auto it = my_map.begin(); it != my_map.end(); it++)
	{
		string ele = it->first;
		int count = 0;
		for (int i = 0; i < ele.size(); i++)
		{
			if (ele[i] == '0')
				count++;
		}
		if (count % 2 == flag && count <= K)
			answer = it->second > answer ? it->second : answer;
	}
	cout << answer;
	return 0;
}