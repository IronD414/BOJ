#include <iostream>
#include <algorithm>
using namespace std;

int columns[15];
int N;
int answer = 0;

bool promising(int row){
	int x = columns[row];
	for (int i = 0; i < row; ++i)
	{
		if (x==columns[i] || x-row == columns[i]-i || x+row == columns[i]+i) return false;
	}
	return true;
}

void dfs(int row){
	if (row==N){
		answer++;
		return;
	}
	for (int col = 0; col < N; ++col)
	{
		columns[row] = col;
		if (promising(row)) dfs(row+1);
	}
}

int main(int argc, char const *argv[])
{
	ios::sync_with_stdio(0);
	cin >> N;
	int result = 0;k

	dfs(0);

	cout << answer;

	return 0;
}