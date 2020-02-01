#include <iostream>
#include <vector>


using namespace std;

int map[9][6] = {
	{0,},
	{0,2,4,6,8,10},
	{10,12,14,16,18,20},
	{10,13,16,19,25},
	{20,22,24,26,28,30},
	{20,22,24,25},
	{25,30,35,40,0},
	{30,32,34,36,38,0},
	{30,28,27,26,25}
};

int mapLen[9] = { 0,6,6,5,6,4,5,6,5 };
int link(int target,int state)
{
	if (target == 6 || target == 7)
		return target;
	if (target == 1)
	{
		if (state < 0)
			return 1;
		else if(state == 0)
			return 3;
		return 2;
	}
	if (target == 2)
	{
		if (state < 0)
			return 2;
		else if(state ==0)
			return 5;
		return 4;
	}
	if (target == 3)
	{
		if (state < 0)
			return 3;
		return 6;
	}
	if (target == 4)
	{
		if (state < 0)
			return 4;
		else if (state ==0)
			return 8;
		return 7;
	}
	if (target == 5)
	{
		if (state < 0)
			return 5;
		return 6;
	}
	if (target == 8)
	{
		if (state < 0)
			return 8;
		return 6;
	}
}

struct mal {
	int x, y;
	mal()
	{
		x = 0;
		y = 1;
	}
	int move(int diceVal)
	{
		int diff = diceVal+x - (mapLen[y]-1);
		int nLink = link(y, diff);
		if (diff < 0)
			x = x + diceVal;
		else {
			if (nLink == 6 || nLink == 7)
			{
				if (y != nLink)
					x = diff;
				else
					x = x + diceVal;
				if (x >= mapLen[nLink]-1)				
					return -1;								
			}			
			x = diff;
			y = nLink;
		}
		return map[y][x];		
	}
};


mal arr[4];
vector<int> eachFlow[4];
bool isOver[4];
int diceflow[10];
int answer = 0;
bool posCheck(int target)
{
	for (int i = 0; i < 4; i++)
	{
		if (!isOver[i] && i!=target)
		{
			if (arr[i].x == arr[target].x && arr[i].y == arr[target].y)
				return false;
		}				
	}
	return true;
}
void print()
{
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < eachFlow[i].size(); j++)
		{
			cout << eachFlow[i][j] << ",";
		}
		cout << "\n";
	}
}


int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	
	//vector<int> temp = { 1,2,3,4,1,2 };
	//for (int i = 0; i < temp.size(); i++)
	//{
	//	cout << "before\n";
	//	cout << "link : " << arr[0].y << " " << arr[0].x << "\n";
	//	int ret = arr[0].move(temp[i]);
	//	cout << "ret : " << ret << "\n";
	//	cout << "after\n";
	//	cout << "link : " << arr[0].y << " " << arr[0].x << "\n";
	//}



	
	
	
	for (int i = 0; i < 10; i++)
	{		
		cin >> diceflow[i];		
	}
	for (int i = 0; i < 7; i++)
	{
		eachFlow[0].clear();
		for (int i_a = 0; i_a < i + 1; i_a++)
			eachFlow[0].push_back(diceflow[i_a]);
		for (int j = i + 1; j < 8; j++)
		{
			eachFlow[1].clear();
			for (int j_a = i+1; j_a < j+1; j_a++)				
				eachFlow[1].push_back(diceflow[j_a]);
			for (int k = j + 1; k < 9; k++)
			{
				eachFlow[2].clear();
				for (int k_a = j+1; k_a < k + 1; k_a++)				
					eachFlow[2].push_back(diceflow[k_a]);
				eachFlow[3].clear();
				for (int l_a = k + 1; l_a < 10; l_a++)
					eachFlow[3].push_back(diceflow[l_a]);

				int sum = 0;
				bool possible = true;
				for (int tern = 0; tern < 4; tern++)
				{
					arr[tern].y = 1; arr[tern].x = 0;
					isOver[tern] = false;
				}
				cout << "=======\n";
				print();
				cout << "======\n";
				for (int tern = 0; tern < 4; tern++)
				{
					for (int flow = 0; flow < eachFlow[tern].size(); flow++)
					{
						int ret = arr[tern].move(eachFlow[tern][flow]);
						if (ret == -1) {
							isOver[tern] = true;
							break;
						}
							
						else
							sum += ret;
					}
					cout << tern << " : tern" << " " << sum << "\n";
					if (!posCheck(tern)) {
						possible = false;
						break;
					}						
				}
				if (possible)
					answer = answer < sum ? sum : answer;
			}
		}
	}
	cout << answer;

}