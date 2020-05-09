#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int N, K;
int arr[100];
int same_count[1000];
bool visit[1000];
struct Node {
	vector<int> ele;
	bool operator==(const Node& another)
	{
		for (int i = 0; i < K; i++)
		{
			if (ele[i] != another.ele[i])
				return false;
		}
		return true;
	}
	bool operator<(const Node& anoher)
	{
		for (int i = 0; i < K; i++)
		{
			if (ele[i] == anoher.ele[i])
				continue;
			return ele[i] < anoher.ele[i];			
		}		
	}
};
vector<Node> Root;
vector<Node> child;
bool compareRootandChild()
{
	bool possible = false;
	int Root_start = 0; int child_start = 0;
	while (Root_start < Root.size() && child_start < child.size())
	{
		if (Root[Root_start] == child[child_start] && !visit[Root_start])
		{
			visit[Root_start] = true;
			possible = true;
			same_count[Root_start]++;
		}
		if (Root[Root_start] < child[child_start])
			Root_start++;
		else
			child_start++;
	}
	return possible;
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> N >> K;
	int M; cin >> M;
	for (int i = 0; i < M; i++) {
		//cin >> arr[i];		
	}		
	for (int i = 0; i <= M - K; i++)
	{
		Root.push_back(Node());
		for (int j = 0; j < K; j++)
			Root.back().ele.push_back(arr[i + j]);
	}
	Root.erase(unique(Root.begin(), Root.end()), Root.end());
	sort(Root.begin(), Root.end());	
	for (int i = 1; i < N; i++)
	{		
		fill_n(visit, 1000, false);
		child.clear();
		cin >> M;
		for (int j = 0; j < M; j++)
			cin >> arr[j];
		for (int j = 0; j < M - K; j++)
		{
			child.push_back(Node());
			for (int k = 0; k < K; k++)
				child.back().ele.push_back(arr[j + k]);
		}
		child.erase(unique(child.begin(), child.end()), child.end());
		sort(child.begin(), child.end());
		bool ret_forward = compareRootandChild();
		for (int j = 0; j < child.size(); j++)
			reverse(child[j].ele.begin(), child[j].ele.end());
		sort(child.begin(), child.end());
		bool ret_backward = compareRootandChild();
		if (!ret_forward && !ret_backward) {
			cout << "NO";
			break;
		}			
	}	
	for (int i = 0; i < Root.size(); i++)
	{
		if (same_count[i] == N - 1) {
			cout << "YES";
			break;
		}					
	}
	return 0;
}