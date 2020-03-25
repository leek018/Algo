#include <iostream>
#include <map>
#include <string>
using namespace std;
map<string, int> entrance;
string dae[1000];
bool visit[1000];
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int N; cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> dae[i];
		entrance.insert({ dae[i],i });
	}
	int answer = 0;
	int daeindex = 0;
	for (int i = 0; i < N; i++)
	{
		string input; cin >> input;
		int val = entrance.find(input)->second;
		visit[val] = true;
		if (input != dae[daeindex])
			answer++;					
		else {			
			while (daeindex < N) {
				if (visit[daeindex])
					daeindex++;
				else
					break;
			}				
		}			
	}
	cout << answer;
	return 0;
}