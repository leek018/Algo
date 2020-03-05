#include <iostream>
using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int N, B, H, W; cin >> N >> B >> H >> W;
	int answer = 500001;
	for (int i = 0; i < H; i++)
	{
		int price; cin >> price;
		for (int j = 0; j < W; j++)
		{
			int availpeople; cin >> availpeople;
			if (availpeople >= N)
			{
				int predictBudget = N * price;
				if (predictBudget <= B)
				{
					if (predictBudget < answer)
						answer = predictBudget;
				}
			}			
		}			
	}
	if (answer == 500001)
		cout << "stay home";
	else
		cout << answer;
	return 0;
}