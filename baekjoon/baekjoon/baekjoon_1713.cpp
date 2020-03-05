#include <iostream>
#include <algorithm>
using namespace std;
struct Frame {
	int own, ttabong, when;
	Frame() {}
	Frame(int own_, int ttabong_, int when_) :own(own_), ttabong(ttabong_), when(when_) {}
};
bool cmp(const Frame &a,const Frame &b) {
	if (a.ttabong == b.ttabong)
		return a.when < b.when;
	return a.ttabong < b.ttabong;
}
bool cmp_two(const Frame& a, const Frame& b)
{
	return a.own < b.own;
}
Frame arr[20];
int top = 0;
int isTargetInArray(int target)
{
	for (int i = 0; i < top; i++)
	{
		if (arr[i].own == target)
			return i;
	}
	return -1;
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int N, End; cin >> N >> End;
	int start = 0;
	while (start < End)
	{
		int target; cin >> target;
		int targetIdx = isTargetInArray(target);
		if (targetIdx != -1)		
			arr[targetIdx].ttabong++;
		else {
			Frame newFrame = Frame(target, 1, start);
			if (top == N)
				arr[0] = newFrame;
			else
				arr[top++] = newFrame;
		}
		sort(arr, arr + top, cmp);
		start++;
	}
	sort(arr, arr + top, cmp_two);
	for (int i = 0; i < top; i++)
		cout << arr[i].own << " ";
	return 0;	
}