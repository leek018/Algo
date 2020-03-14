#include <iostream>
#include <vector>
#define NOTRANS 0
#define TRANS 1
using namespace std;

bool isUseSticker[100];
pair<int, int> stickers[100];
bool visit[100][100];
int answer = 0;
int candidateCount = 0;
int H, W, N;
struct Info {
	bool type;
	int index, width;
	Info() {}
	Info(bool type_, int index_, int width_) :type(type_), index(index_), width(width_) {}
};
vector<Info> map[100][100];
bool isPlacePossible(int row, int col, int h, int w)
{
	if (row + h - 1 >= H || col + w - 1 >= W)
		return false;
	return true;
}
int makeCheck(int row, int col, int h, int w, bool value)
{
	int tempCandidateCount = 0;
	for (int i = row; i < row + h; i++)
	{
		for (int j = col; j < col + w; j++) {
			visit[i][j] = value;
			int len = map[i][j].size();
			tempCandidateCount += len;
		}

	}
	return tempCandidateCount;
}
void makeReady()
{
	for (int i = 0; i < H; i++)
	{
		for (int j = 0; j < W; j++)
		{
			for (int k = 0; k < N; k++)
			{
				if (isPlacePossible(i, j, stickers[k].second, stickers[k].first)) {
					map[i][j].push_back(Info(NOTRANS, k, stickers[k].first * stickers[k].second ));
					candidateCount++;
				}
				if (isPlacePossible(i, j, stickers[k].first, stickers[k].second)) {
					map[i][j].push_back(Info(TRANS, k, stickers[k].first * stickers[k].second ));
					candidateCount++;
				}
			}
		}
	}
}
void simulation() {
	for (int i = 0; i < map[0][0].size(); i++)
	{
		int copyCandidate = candidateCount;
		Info& ret = map[0][0][i];
		isUseSticker[ret.index] = true;
		if(ret.type==NOTRANS)
			copyCandidate -= makeCheck(0, 0, stickers[ret.index].second, stickers[ret.index].first, true);
		else
			copyCandidate -= makeCheck(0, 0, stickers[ret.index].first, stickers[ret.index].second, true);
		if (copyCandidate <= 0)
			continue;
		int localAnswer = ret.width;
		for (int r = 0; r < H; r++)
		{
			for (int c = 0; c < W; c++)
			{
				if (!visit[r][c])
				{
					for (int k = 0; k < map[r][c].size(); k++)
					{
						if (!isUseSticker[map[r][c][k].index])
						{
							int tempAnswer = localAnswer + map[r][c][k].width;
							if (answer < tempAnswer)
								answer = tempAnswer;
						}
					}
				}
			}
		}
		isUseSticker[ret.index] = false;
		if (ret.type == NOTRANS)
			copyCandidate -= makeCheck(0, 0, stickers[ret.index].second, stickers[ret.index].first, false);
		else
			copyCandidate -= makeCheck(0, 0, stickers[ret.index].first, stickers[ret.index].second, false);
	}
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> H >> W >> N;
	for (int i = 0; i < N; i++)
		cin >> stickers[i].second >> stickers[i].first;
	makeReady();
	simulation();
	cout << answer;
	return 0;
}