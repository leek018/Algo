#include <iostream>
#include <vector>
using namespace std;

int N, M;

int PersonState[51];
vector<int> Party[50];
int answer = 0;

void Recover(vector<int>& TargetParty, vector<int>& copy)
{
	for (int i = 0; i < TargetParty.size(); i++)
	{
		int PersonNumber = TargetParty[i];
		PersonState[PersonNumber] = copy[i];
	}
}

void Talk(vector<int>& TargetParty, int talk)
{
	for (int i = 0; i < TargetParty.size(); i++)
	{
		int PersonNumber = TargetParty[i];
		PersonState[PersonNumber] = talk;
	}
}
bool solve(int idx,int lieCnt)
{
	if (idx == M)
	{
		answer = answer < lieCnt ? lieCnt : answer;
		return true;
	}
	vector<int> copyState;
	int TCnt = 0;
	int Fcnt = 0;
	for (int i = 0; i < Party[idx].size(); i++)
	{
		int PersonNumber = Party[idx][i];
		int state = PersonState[PersonNumber];
		if (state == 1)
			TCnt++;
		else if (state == 2)
			Fcnt++;
		copyState.push_back(state );
	}
	
	if (TCnt ==0 && Fcnt == 0)
	{
		Talk(Party[idx], 2);
		bool ret = solve(idx + 1, lieCnt + 1);
		if (ret)
			return true;
		else
		{
			Talk(Party[idx], 1);
			bool retSub = solve(idx + 1, lieCnt);
			if (retSub)
				return true;
			else {
				Recover(Party[idx], copyState);
				return false;
			}
		}
	}
	else if (TCnt == 0 && Fcnt > 0)
	{
		Talk(Party[idx], 2);
		bool ret = solve(idx + 1, lieCnt + 1);
		if (ret)
			return true;
		else {
			Recover(Party[idx], copyState);
			return false;
		}
	}
	else if (TCnt > 0 && Fcnt > 0)
	{
		Recover(Party[idx], copyState);
		return false;
	}
	else 
	{
		Talk(Party[idx], 1);
		bool ret = solve(idx + 1, lieCnt);
		if (ret)
			return true;
		else {
			Recover(Party[idx], copyState);
			return false;
		}
	}
}




int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int TrueCnt;
	cin >> N >> M >> TrueCnt;

	for (int i = 0; i < TrueCnt; i++)
	{
		int PersonNumber;
		cin >> PersonNumber;
		PersonState[PersonNumber] = 1;
	}
	for (int i = 0; i < M; i++)
	{
		int PeopleNum;
		cin >> PeopleNum;
		for (int j = 0; j < PeopleNum; j++)
		{
			int participant;
			cin >> participant;
			Party[i].push_back(participant);
		}						
	}
	solve(0, 0);
	cout << answer;

}