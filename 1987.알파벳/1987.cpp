#include <iostream>
#include <utility>
using namespace std;

int R, C,answer=0;
char B[20][20];
bool disc[26];
int dx[4] = { 0,0,-1,1 };
int dy[4] = { -1,1,0,0 };

void dfs(int y, int x, int parse) {
	disc[B[y][x] - 65] = true;
	for (int i = 0; i < 4; i++) {
		int yp = y + dy[i], xp = x + dx[i];
		if (yp < 0 || yp >= R || xp < 0 || xp >= C)continue;
		if (disc[B[yp][xp]-65])continue;
		dfs(yp, xp, parse+1);
	}
	disc[B[y][x] - 65] = false;
	answer = max(answer, parse);
}

int main() {
	cin >> R >> C;
	for (int i = 0; i < R; i++)
		for (int j = 0; j < C; j++)
			cin >> B[i][j];
	dfs(0,0,1);
	cout << answer;
}