#include <iostream>
#include <cstring>
using namespace std;

int map[100][100];
int temp[100][100];

void solve_one(int (*answer)[100], int(*save)[100] ,const int& N, const int& M)
{	
	for (int i = 0; i < N ; i++)
	{
		for (int j = 0; j < M; j++)
		{
			answer[N - 1 - i][j] = save[i][j];
		}
	}
}

void solve_two(int(*answer)[100], int(*save)[100], const int& N, const int& M)
{
	for (int j = 0; j < M; j++)
	{
		for (int i = 0; i < N; i++)
		{
			answer[i][M - 1 - j] = save[i][j];
		}
	}
}

void solve_three(int(*answer)[100], int(*save)[100], const int& N, const int& M)
{
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			answer[j][N - 1 - i] = save[i][j];
		}
	}
}

void solve_four(int(*answer)[100], int(*save)[100], const int& N, const int& M)
{
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			answer[M - 1 - j][i] = save[i][j];
		}
	}
}


void solve_five(int(*answer)[100], int(*save)[100], const int& N, const int& M)
{	
	int direc_x[] = { 0,M / 2,M / 2,0 };
	int direc_y[] = { 0,0,N / 2,N / 2 };
	int ds_x[] = { M / 2,0,-(M / 2),0 };
	int ds_y[] = { 0,N / 2,0,-(N / 2) };
	int limit_x[] = { M / 2,M ,M,M/2 };
	int limit_y[] = { N / 2,N / 2,N,N };
	for (int k = 0; k < 4; k++)
	{
		int start_x = direc_x[k];
		int start_y = direc_y[k];
		for (int i = start_y; i < limit_y[k]; i++)
		{
			for (int j = start_x; j < limit_x[k]; j++)
			{
				answer[i + ds_y[k]][j + ds_x[k]] = save[i][j];
			}
		}
	}
}

void solve_six(int(*answer)[100], int(*save)[100], const int& N, const int& M)
{
	int direc_x[] = { 0,0,M / 2,M/2 };
	int direc_y[] = { 0,N / 2,N / 2,0 };
	int ds_x[] = { 0,M/2,0,-(M/2) };
	int ds_y[] = {N/2,0,-(N / 2),0 };
	int limit_x[] = { M / 2,M/2 ,M,M };
	int limit_y[] = { N / 2,N,N,N/2 };
	for (int k = 0; k < 4; k++)
	{
		int start_x = direc_x[k];
		int start_y = direc_y[k];
		for (int i = start_y; i < limit_y[k]; i++)
		{
			for (int j = start_x; j < limit_x[k]; j++)
			{
				answer[i + ds_y[k]][j + ds_x[k]] = save[i][j];
			}
		}
	}
}

void swap_p(int (**a)[100], int (**b)[100])
{
	int (*temp)[100] = *a;
	*a = *b;
	*b = temp;
}
void swap_idx(int* N, int *M)
{
	int temp = *N;
	*N = *M;
	*M = temp;
}
void print(int (*temp)[100],int N, int M)
{
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
			cout << temp[i][j] << " ";
		cout << "\n";
	}
}
int main()
{
	freopen("sample_17470.txt", "r", stdin);
	ios::sync_with_stdio(0);
	cin.tie(0);
	int N, M,R;
	cin >> N >> M >> R;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			cin >> map[i][j];
		}
	}
	int (*a)[100] = map;
	int (*s)[100] = temp;
	for (int i = 0; i < R; i++)
	{
		int r;
		cin >> r;
		if (r == 1)
		{
			solve_one(s, a, N, M);
		}
		else if (r == 2)
		{
			solve_two(s, a, N, M);
		}
		else if (r == 3)
		{
			solve_three(s, a, N, M);
			swap_idx(&N, &M);
		}
		else if (r == 4)
		{
			solve_four(s, a, N, M);
			swap_idx(&N, &M);
		}
		else if (r == 5)
		{
			solve_five(s, a, N, M);
		}
		else {
			solve_six(s, a, N, M);
		}
		swap_p(&s, &a);				
	}
	print(a, N, M);
	return 0;
}