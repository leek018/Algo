#include <cstdio>
#include <string>
using namespace std;
int map[50][5];
//열오른쪽 행위쪽 열왼쪽 행아래쪽
int dx[] = { -1,0,1,0 };
int dy[] = { 0,-1,0,1 };
int start_x = 5000;
int start_y = 5000;
int cnt = 1;
int len = 1;
int gx, gy,limitX,limitY;
int totalCnt;
int findDigit(int target)
{
	int temp = target;
	int count = 0;
	while (temp != 0)
	{
		temp /= 10;
		count++;
	}
	return count;
}
int r1, c1, r2, c2;
bool check(int nx, int ny)
{	
	if (nx >= 0 && nx <= limitX && ny >= 0 && ny <= limitY)
		return true;
	return false;
}
void makeTonado(int direc)
{
	for (int i = 0; i < len; i++)
	{
		start_x += dx[direc];
		start_y += dy[direc];		
		int mapping_x = start_x + gx;
		int mapping_y = start_y + gy;
		cnt++;
		if (check(mapping_x, mapping_y)) {
			map[mapping_y][mapping_x] = cnt;
			totalCnt--;
		}			
	}	
}
int main()
{	
	scanf("%d %d %d %d", &r1, &c1, &r2, &c2);
	gx = 0 - c1;
	gy = 0 - r1;
	limitX = c2 + gx;
	limitY = r2 + gy;
	start_y = 0;
	start_x = 0;
	totalCnt = (limitX + 1) * (limitY + 1);
	int mapping_x = start_x + gx;
	int mapping_y = start_y + gy;
	if (check(mapping_x, mapping_y))
	{
		totalCnt--;
		map[mapping_y][mapping_x] = 1;
	}

	
	while (true)
	{		
		makeTonado(2);
		if (totalCnt == 0)
			break;

		makeTonado(1);
		if (totalCnt == 0)
			break;
		len++;
		makeTonado(0);
		if (totalCnt == 0)
			break;
		makeTonado(3);
		if (totalCnt == 0)
			break;
		len++;		
	}
	
	
	
	int maxVal = 0;
	for (int i = 0; i <= limitY; i++)
	{
		for (int j = 0; j <= limitX; j++)
		{
			maxVal = maxVal < map[i][j] ? map[i][j] : maxVal;
		}		
	}
	string maxValS = to_string(maxVal);
	int goalDigit = maxValS.size();
	for (int i = 0; i <= limitY; i++)
	{
		for (int j = 0; j <= limitX; j++)
		{
			int target = map[i][j];
			int digit = findDigit(target);
			int diff = goalDigit - digit;
			if (diff > 0)
			{
				for (int k = 0; k < diff; k++)
					printf(" ");
			}
			printf("%d ", target);
		}
		printf("\n");
	}

}