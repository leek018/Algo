#include <iostream>
#include <vector>
using namespace std;


struct my_heap {
	int arr[100001];
	int last = 0;
	bool isEmpty()
	{
		return last == 0;
	}

	void push(int x)
	{
		arr[++last] = x;
		int child = last;
		while (child != 1 && arr[child] < arr[child/2])
		{			
			swap(child, child / 2);
			child /= 2;							
		}
	}

	int pop()
	{
		if (isEmpty())
			return 0;
		int ele = arr[1];
		arr[1] = arr[last--];
		int pointer = 1;
		while (pointer * 2 <= last || pointer * 2 + 1 <= last)
		{
			int left_child = 2 * pointer;
			int right_child = 2 * pointer + 1;
			if (right_child <= 2 * last)
			{
				if (arr[left_child] < arr[right_child])
				{
					if (arr[pointer] > arr[right_child]) {
						swap(left_child, pointer);
						pointer = left_child;
					}
					else {

					}
					
				}
				else {
					swap(right_child, pointer);
					pointer = right_child;
				}
			}
			else if (left_child <= 2 * last)
			{
				if (arr[left_child] < arr[right_child])
				{
					swap(left_child, pointer);
					pointer = left_child;
				}
			}
		}
		return ele;
	}
	void swap(int src, int dst)
	{
		int temp = arr[src];
		arr[src] = arr[dst];
		arr[dst] = temp;
	}
};
my_heap heap;
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	vector<int> answer;
	int N;
	cin >> N; 
	for (int i = 0; i < N; i++)
	{
		int query;
		cin >> query;
		if (query == 0)
			answer.push_back(heap.pop());
		else if (query > 0)
			heap.push(query);
	}
	for (int i = 0; i < answer.size(); i++)
		cout << answer[i] << "\n";
	return 0;
}