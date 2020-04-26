#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;
struct Score {
	int math, kor, eng;
	string name;
	Score(string name_, int kor_, int eng_, int math_) :kor(kor_), eng(eng_), math(math_), name(name_) {}
};
vector<Score> students;
bool comp(const Score& a, const Score& b)
{
	if (a.kor == b.kor)
	{
		if (a.eng == b.eng) {
			if (a.math == b.math)
				return a.name.compare(b.name) < 0;
			return a.math > b.math;
		}			
		return a.eng < b.eng;
	}
	return a.kor > b.kor;
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int N; cin >> N;
	for (int i = 0; i < N; i++)
	{
		string name;
		int kor, eng, math;
		cin >> name >> kor >> eng >> math;
		students.push_back(Score(name, kor, eng, math));
	}
	sort(students.begin(), students.end(), comp);
	for (Score ele : students)	
		cout << ele.name << "\n";
	return 0;
}