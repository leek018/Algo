#include <iostream>
#include <vector>
#include <string>
#define ABS(X) ( (X) < 0 ? -(X) : (X) )
using namespace std;

pair<int,int> arr[10] = {
	{3,1},
	{0,0},
	{0,1},
	{0,2},
	{1,0},
	{1,1},
	{1,2},
	{2,0},
	{2,1},
	{2,2}
};
string soluition(vector<int> numbers, string hand)
{
	string answer = "";
	pair<int, int> left_pos = { 3,0 };
	pair<int, int> right_pos = { 3,2 };
	for (int i = 0; i < numbers.size(); i++)
	{
		int val = numbers[i];
		if (val == 1 || val == 4 || val == 7) {
			left_pos = arr[val];
			answer += "L";
		}
		else if (val == 3 || val == 6 || val == 9)
		{
			right_pos = arr[val];
			answer += "R";
		}
		else {
			int diff_from_left = ABS(left_pos.first - arr[val].first) + ABS(left_pos.second - arr[val].second);
			int diff_from_right = ABS(right_pos.first - arr[val].first) + ABS(right_pos.second - arr[val].second);
			if (diff_from_left < diff_from_right) {
				left_pos = arr[val];
				answer+= "L";
			}				
			else if (diff_from_left > diff_from_right) {
				right_pos = arr[val];
				answer += "R";
			}				
			else {
				if (hand == "left") {
					left_pos = arr[val];
					answer += "L";
				}					
				else {
					right_pos = arr[val];
					answer += "R";
				}					
			}
		}			
	}
	return answer;
}
int main()
{
	/*vector<int> number = { 1,3,4,5,8,2,1,4,5,9,5 };
	string hand = "right";*/
	/*vector<int> number = { 7,0,8,2,8,3,1,5,7,6,2 };
	string hand = "left";*/
	vector<int> number = { 1,2,3,4,5,6,7,8,9,0 };
	string hand = "right";
	string answer = soluition(number, hand);
	cout << answer;
	return 0;
}