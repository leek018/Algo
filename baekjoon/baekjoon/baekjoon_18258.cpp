#include <iostream>
#include <string>
using namespace std;

struct queue {
	int buffer[2000001];
	int front;
	int rear;
	queue() {
		front = 0;
		rear = 0;
	}
	void push(int x)
	{
		buffer[++rear] = x;
	}
	bool isEmpty()
	{
		return front == rear;
	}
	int pop()
	{
		if (isEmpty())
			return -1;
		int ret = buffer[++front];
		return ret;
	}
	int size() {
		return rear - front;
	}
	int front_() {
		if (isEmpty())
			return -1;
		return buffer[front + 1];
	}
	int back() {
		if (isEmpty())
			return -1;
		return buffer[rear];
	}
};
queue q;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int N; cin >> N;
	for (int i = 0; i < N; i++)
	{
		string query;
		cin >> query;
		if (query == "push")
		{
			int X; cin >> X;
			q.push(X);
		}
		else if (query == "pop")
			cout << q.pop() << "\n";
		else if (query == "size")
			cout << q.size() << "\n";
		else if (query == "empty")
			cout << q.isEmpty() << "\n";
		else if (query == "front")
			cout << q.front_() << "\n";
		else
			cout << q.back() << "\n";
	}
	return 0;
}