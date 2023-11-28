#include <iostream>
#include <queue>
using namespace std;

typedef struct {
	int x, y,dist;
}pos;

int N, M, answer=0;
queue<pos> Q;
int wall[100][100];
int dx[4] = { 0,0,-1,1 };
int dy[4] = { -1,1,0,0 };

void bfs() {
	pos p0 = { 0,0,1 };
	Q.push(p0);
	wall[0][0] = 0;
	while (!Q.empty()) {
		pos pp = Q.front();
		Q.pop();
		int x = pp.x, y = pp.y, dist = pp.dist;
		int xp, yp;
		for (size_t i = 0; i < 4; i++)
		{
			xp = x + dx[i], yp = y + dy[i];
			if (xp < 0 || xp >= M || yp < 0 || yp >= N)continue;
			if (wall[yp][xp] == 0)continue;
			if (xp == M - 1 && yp == N - 1) {
				answer = dist + 1;
				return;
			}
			pos next_pos = { xp,yp,dist + 1 };
			Q.push(next_pos);
			wall[yp][xp] = 0;
		}
	}
}

int main()
{
	cin >> N >> M;
	for (size_t i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++) {
			scanf_s(" %1d", &wall[i][j]);
		}
	}
	bfs();
	cout << answer;
}