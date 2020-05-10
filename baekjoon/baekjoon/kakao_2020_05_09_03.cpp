#include <iostream>
#include <vector>
#include <string>
#include <map>	
#include <deque>
using namespace std;
map<string, int> word2idx;
bool visit[100000];
vector<int> solution(vector<string> gems)
{
	vector<int> answer(2);
	int min_lenth = gems.size() + 1;
	int idx = 0;
	for (int i = 0; i < gems.size(); i++)
	{		
		pair<map<string, int>::iterator, bool> result = word2idx.insert({ gems[i],NULL });
		if (result.second)		
			result.first->second = idx++;		
	}
	deque<pair<int, int>> deq;
	int count = 0;
	int goal = word2idx.size();
	for (int i = 0; i < gems.size(); i++)
	{
		int targetIdx = word2idx[gems[i]];
		if (deq.empty())
			deq.push_back({targetIdx,i });
		else {
			if (deq.back().first == targetIdx)
				deq.pop_back();			
			if (!deq.empty() && deq.front().first == targetIdx)
				deq.pop_front();
			deq.push_back({ targetIdx,i });			
		}
		if (!visit[targetIdx])
		{
			visit[targetIdx] = true;
			count++;
		}
		if (count == goal)
		{
			pair<int, int> front_ret = deq.front();			
			visit[front_ret.first] = false;
			count--;
			int local_length = i - front_ret.second + 1;
			if (min_lenth > local_length)
			{
				answer[0] = front_ret.second+1;
				answer[1] = i + 1;
				min_lenth = local_length;
			}
		}
	}
	return answer;
}

int main()
{
	//vector<string> test = {"DIA", "RUBY", "RUBY", "DIA", "DIA", "EMERALD", "SAPPHIRE", "DIA"};
	//vector<string> test = {"AA", "AB", "AC", "AA", "AC"};
	//vector<string> test = {"XYZ", "XYZ", "XYZ"};
	vector<string> test = {"ZZZ", "YYY", "NNNN", "YYY", "BBB"};
	vector<int> ret = solution(test);
	cout << ret[0] << "," << ret[1];
	return 0;
}