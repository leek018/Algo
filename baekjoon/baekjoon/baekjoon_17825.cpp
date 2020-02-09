#include <iostream>
#include <vector>
using namespace std;
vector<int> map[8];
//course,pos
pair<int, int> malpos[4];
bool isEnd[4];
int dice[10];
bool isvisit(pair<int,int> newPos)
{	
	for (int i = 0; i < 4; i++)
	{
		if (malpos[i].first !=-1)
		{
			if (malpos[i] == newPos)
				return true;
			if (malpos[i].first == 6 && malpos[i].second == 3 && newPos.first == 7 && newPos.second == 5)
				return true;
			if (malpos[i].first == 7 && malpos[i].second == 5 && newPos.first == 6 && newPos.second == 3)
				return true;
		}
	}
	return false;
}
pair<int,int> move(int malIdx, int moveCnt)
{
	pair<int, int> currentCourseAndPos = malpos[malIdx];
	int currentCourse = currentCourseAndPos.first;
	int pos = currentCourseAndPos.second;
	int courseLen = map[currentCourse].size();	
	pair<int, int> newCourseAndPos;
	if (pos + moveCnt == courseLen - 1)
	{
		if (currentCourse == 0)
			newCourseAndPos.first = 1;
		else if(currentCourse == 1)
			newCourseAndPos.first = 6;
		else if (currentCourse == 2)
			newCourseAndPos.first = 3;
		else if (currentCourse == 3)
			newCourseAndPos.first = 6;
		else if (currentCourse == 4)
			newCourseAndPos.first = 5;
		else if (currentCourse == 5)
			newCourseAndPos.first = 6;
		else 
			newCourseAndPos.first = -1;			
		newCourseAndPos.second = 0;
	}
	else if(pos+moveCnt < courseLen-1)
	{
		newCourseAndPos.first = currentCourse; newCourseAndPos.second = pos + moveCnt;
	}
	else {
		if (currentCourse == 0)		
			newCourseAndPos.first = 2; 		
		else if(currentCourse == 1 || currentCourse == 3 || currentCourse == 5)		
			newCourseAndPos.first = 6;		
		else if (currentCourse == 2)		
			newCourseAndPos.first = 4;		
		else if (currentCourse == 4)		
			newCourseAndPos.first = 7;		
		else
			newCourseAndPos.first = -1;		
		newCourseAndPos.second = moveCnt - (courseLen - 1 - pos);
	}
	return newCourseAndPos;
}
int answer = -1;
void solve(int tern, int sum)
{
	if (tern == 10)
	{
		if (answer < sum)
			answer = sum;
		return;
	}
	for (int i = 0; i < 4; i++)
	{
		if (!isEnd[i])
		{
			pair<int, int> save = malpos[i];
			pair<int, int> newpos = move(i, dice[tern]);
			if (isvisit(newpos))
				continue;
			malpos[i] = newpos;
			int tempSum = 0;
			if (newpos.first == -1)
				isEnd[i] = true;
			else
				tempSum = map[newpos.first][newpos.second];			
			solve(tern + 1, sum + tempSum);
			if (newpos.first == -1)
				isEnd[i] = false;
			malpos[i] = save;
		}
	}
	return;
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	map[0] = { 0,2,4,6,8,10 };
	map[1] = { 10,13,16,19,25 };
	map[2] = { 10,12,14,16,18,20 };
	map[3] = { 20,22,24,25 };
	map[4] = { 20,22,24,26,28,30 };
	map[5] = { 30,28,27,26,25 };
	map[6] = { 25,30,35,40,0 };
	map[7] = { 30,32,34,36,38,40,0 };
	for (int i = 0; i < 10; i++)
		cin >> dice[i];
	solve(0, 0);	
	cout << answer;
	return 0;
}