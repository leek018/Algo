#include <iostream>

using namespace std;
bool visit[10][10];

int map[10][10];
int answer = 26;
int len[] = { 0,1,2,3,4,5 };
int chance[] = { 0,5,5,5,5,5 };

void change(int changeType,int paperType, int x,int y,int limitX,int limitY)
{
	bool visitType = false;
	if (changeType == 0) {
		chance[paperType]--;
		visitType = true;
	}
	else
		chance[paperType]++;
	for (int i = y; i < limitY; i++)
	{
		for (int j = x; j < limitX; j++)
		{
			visit[i][j] = visitType;
			map[i][j] = changeType;
		}
	}
	
	
}

void print()
{
	cout << "==================\n";
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 10; j++)
			cout << map[i][j] << " ";
		cout << "\n";
	}
	cout << "==================\n";
}
int findOne(int x, int y, int limitX,int limitY)
{
	int sum = 0;
	for (int i = y; i < limitY; i++)
	{
		for (int j = x; j < limitX; j++)
		{
			if (map[i][j])			
				sum++;			
		}
	}
	return sum;
}

void solve(int x, int y,int count,int oneCnt)
{	
	
	if (count >= answer)
		return;
	if (x == 9 && y == 9)
	{
		if (map[y][x] == 1 )
		{
			if(chance[1] > 0)
				answer = count + 1;			
		}
		else
			answer = count;
		return;
	}	
	if (visit[y][x] || map[y][x] ==0)
	{
		if (x == 9)
			solve(0, y + 1, count,oneCnt);
		else
			solve(x + 1, y,count,oneCnt);
	}
	else {
		for (int i = 1; i <= 5; i++)
		{
			int limitX = x + i;
			int limitY = y + i;
			if (limitX <= 10 && limitY <= 10)
			{
				int ret = findOne(x, y, limitX, limitY);
				if (ret == i * i && chance[i] > 0)
				{
					change(0, i, x, y, limitX, limitY);
					/*if (x == 0 && y == 1 && i == 5) {
						print();
						cout << "change 5here\n";
					}
						
					if (x == 6 && y == 2 && i == 4)
						cout << "change 4here\n";
					if (x == 1 && y == 7 && i == 3)
						cout << "change 3here\n";
					if (x == 5 && y == 7 && i == 2)
						cout << "change 2here\n";
					if (x == 9 && y == 9 && i == 1)
						cout << "change Last here\n";*/
					
					solve(limitX - 1, y, count + 1, oneCnt - ret);
					/*if (x == 0 && y == 1)
						cout << "recover here\n";*/
					change(1, i, x, y, limitX, limitY);
				}
			}
		}
	}
	
	
}




int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int oneCount = 0;
	
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			int input;
			cin >> input;
			if (input == 1)
			{
				oneCount++;
				map[i][j] = input;
			}						
		}			
	}
	if (oneCount > 0)
		solve(0, 0, 0, oneCount);
	else
		answer = 0;
	if (answer == 26)
		answer = -1;
	cout << answer;
}