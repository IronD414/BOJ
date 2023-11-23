#include <iostream>
#include <vector>
using namespace std;

typedef struct{
	bool disc[50][50] = {{false,},};
}D;
int N,M,x0,y0,p,answer=0;
int W[50][50];
// up, down, left, right
int dx[4] = {0,0,-1,1};
int dy[4] = {1,-1,0,0};

// dfs by expanding direction
// 지금까지 total만큼 물을 받았고 prev의 방향으로 이동해 현재 x,y 위치이고 p 만큼 재료가 남아있다. 발견된 상태는 d에 저장돼 있다.
void backtrack(int p, int prev, int x, int y, int total, D d){
	if (p < 0) return;
	if (p == 0){
		if (total > answer) answer = total;
		else return;
	}
	if (d.disc[y][x]){
		return;
	}
	d.disc[y][x] = true;
	for (int i=0;i<4;++i){
		int xx=x+dx[i], yy=y+dy[i];
		if (p == 1) backtrack(p-1, i, xx, yy, total+W[y][x], d);
		if (p == 2) backtrack(p-2, i, xx, yy, total+W[y][x], d);
		if (xx<0 || xx>=M || yy<0 || yy>=N) continue;
		if (prev == i){
			backtrack(p-1, i, xx, yy, total+W[y][x], d);
		}else backtrack(p-2, i, xx, yy, total+W[y][x], d);
	}
}

int main(int argc, char const *argv[])
{
	cin>>N>>M;
	for (int i=0;i<N;++i){
		for (int j=0;j<M;++j){
			cin>>W[i][j];
		}
	}
	cin>>x0>>y0>>p;

	D d;
	d.disc[y0][x0] = true;
	for (int i=0;i<4;++i){
		int xx=x0+dx[i], yy=y0+dy[i];
		if (xx<0 || xx>=M || yy<0 || yy>=N) continue;
		backtrack(p, i, xx, yy, W[y0][x0], d);
	}
	cout << answer;

	return 0;
}