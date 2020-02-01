#include <iostream>
#include <string>
#include <list>
using namespace std;
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	list<char> l;
	string input;	cin >> input;	
	for (int i = 0; i < input.size(); i++)
		l.push_back(input[i]);	
	int N;
	cin >> N;
	int top = input.size();
	list<char>::iterator it = l.end();
	for (int i = 0; i < N; i++)
	{
		char instruction; cin >> instruction;
		if (instruction == 'L')
		{
			if (top > 0)
			{
				top--;
				it--;
			}
		}
		else if (instruction == 'D')
		{
			if (top < l.size())
			{
				top++;
				it++;
			}
		}
		else if (instruction == 'B')
		{
			if (top > 0)
			{
				top--;				
				it--;
				it = l.erase(it);
			}
		}
		else {
			top++;
			char target; cin >> target;
			l.insert(it,target);
		}		
	}
	for (it = l.begin(); it != l.end(); it++)
		cout << *it;
	return 0;

}