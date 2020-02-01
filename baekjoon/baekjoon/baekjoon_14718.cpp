#include <iostream>
#include <algorithm>;
#include <vector>
using namespace std;

struct enemy {
	int power, agil, inteli;
};


int N, K;
enemy enemies[100];

bool cmp(const enemy& a, const enemy& b)
{
	return a.power < b.power;
}



int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> N >> K;	
	for (int i = 0; i < N; i++)
	{
		int p, a, intel;
		cin >> p >> a >> intel;		
		enemies[i].power = p;
		enemies[i].agil = a;
		enemies[i].inteli = intel;
	}	
	sort(enemies, enemies + N, cmp);
	
	
	//cout << answer;
	return 0;

}