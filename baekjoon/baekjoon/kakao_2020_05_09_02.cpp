#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <string>
#define ABS(X) ( (X) < 0 ? -(X) : (X))
using namespace std;
vector<vector<char>> simulation;
void shuffle(int start,vector<char>& temp)
{
	if (start == temp.size())
	{
		simulation.push_back(temp);
		return;
	}
	for (int i = start; i < temp.size(); i++)
	{
		swap(temp[start], temp[i]);
		shuffle(start + 1, temp);
		swap(temp[i], temp[start]);
	}
}
vector<string> get_posterior(string& expression, vector<char>& flow)
{
	map<string, int> word2idx;
	for (int i = 0; i < flow.size(); i++)
	{
		string ch(1,flow[i]);
		word2idx[ch] = i;
	}
	vector<string> posterior;
	vector<string> stack;
	string temp = "";
	for (int i = 0; i < expression.size(); i++)
	{
		if (expression[i] >= '0' && expression[i] <= '9')		
			temp += expression[i];
		else {
			posterior.push_back(temp);
			temp = "";
			string root(1, expression[i]);
			int root_priority = word2idx[root];
			while (!stack.empty())
			{
				int child_priority = word2idx[stack.back()];
				if (child_priority < root_priority)				
					break;
				else {
					posterior.push_back(stack.back());
					stack.pop_back();
				}
			}
			stack.push_back(root);
		}
	}
	posterior.push_back(temp);
	while (!stack.empty()) {
		posterior.push_back(stack.back());
		stack.pop_back();
	}
	return posterior;
}
long long calculator(vector<string> post)
{	
	vector<long long> stack;
	for (int i = 0; i < post.size(); i++)
	{
		if (post[i] == "*" || post[i] =="-" || post[i] == "+")
		{
			long long b = stack.back();
			stack.pop_back();
			long long a = stack.back(); 
			stack.pop_back();
			if (post[i] == "*")
				stack.push_back(a * b);
			else if (post[i] == "-")
				stack.push_back(a - b);
			else
				stack.push_back(a + b);			
		}
		else 
			stack.push_back(stoll(post[i]));		
	}
	return stack.back();
}
long long solution(string expression)
{	
	long long answer = 0;
	int start = 0;
	vector<char> temp;
	for (int i = 0; i < expression.size(); i++)
	{
		if (expression[i] == '*' || expression[i] == '+' || expression[i] == '-')
			temp.push_back(expression[i]);
	}
	sort(temp.begin(), temp.end());
	temp.erase(unique(temp.begin(), temp.end()), temp.end());
	shuffle(0, temp);
	for (int i = 0; i < simulation.size(); i++)
	{
		vector<string> ret = get_posterior(expression, simulation[i]);
		long long cal_result = ABS(calculator(ret));
		if (answer < cal_result)
			answer = cal_result;					
	}
	return answer;
}
int main()
{
	//string test = "100-200*300-500+20";
	string test = "50*6-3*2";
	long long result = solution(test);	
	cout << result;
	return 0;
}