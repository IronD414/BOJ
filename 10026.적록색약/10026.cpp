#include <iostream>
#include <cstring>
using namespace std;

int dx[4] = { 0,0,-1,1 };
int dy[4] = { -1,1,0,0 };
int N;
char input;
char A[100][100];	// normal
char B[100][100];	// special
bool DA[100][100] = { {false,}, };	// discovered_normal
bool DB[100][100] = { {false,}, };	// discovered_special

// search from x, y; only one color
void dfs_normal(int x, int y, char color){
	DA[y][x] = true;
	for (int i = 0; i < 4; ++i) {
		int xp = x + dx[i], yp = y + dy[i];
		if (xp < 0 || xp >= N || yp < 0 || yp >= N) continue;
		if (DA[yp][xp]) continue;
		if (A[yp][xp] != color) continue;
		dfs_normal(xp, yp, color);
	}
}

void dfs_special(int x, int y, int color){
	DB[y][x] = true;
	for (int i = 0; i < 4; ++i) {
		int xp = x + dx[i], yp = y + dy[i];
		if (xp < 0 || xp >= N || yp < 0 || yp >= N) continue;
		if (DB[yp][xp]) continue;
		if (color=='B' && B[yp][xp] != 'B') continue;
		if (color != 'B' && B[yp][xp] == 'B') continue;
		dfs_special(xp, yp, color);
	}
}

int main() {
	cin >> N;
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			cin >> input;
			A[i][j] = input;
			B[i][j] = input;
		}
	}
	int ans_normal = 0, ans_special = 0;
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			if (!DA[i][j]) {
				dfs_normal(j, i, A[i][j]);
				ans_normal++;
			}
		}
	}
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			if (!DB[i][j]) {
				dfs_special(j, i, B[i][j]);
				ans_special++;
			}
		}
	}
	cout << ans_normal << " " << ans_special;
}