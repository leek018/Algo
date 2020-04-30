#include <iostream>
#include <string>

using namespace std;
string map[8] = { "000","001","010","011","100","101","110","111" };
int main()
{
	string N; cin >> N;
	string answer ="";
	if (N == "0")
		answer = "0";	
	else {
		for (int i = 0; i < N.size(); i++)		
			answer += map[N[i] - '0'];		
		int start = 0;
		while (answer[start] != '1')
			start++;
		answer = answer.substr(start, string::npos);
	}
	cout << answer;	
	return 0;
}