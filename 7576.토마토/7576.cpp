#include <iostream>
#include <queue>
using namespace std;

typedef struct{
	int x;
	int y;
}xy;
int M,N,s;
int **T;
queue<xy> Q;
// up, down, left, right
int dx[4] = {0, 0, -1, 1};
int dy[4] = {1, -1, 0, 0};

void bfs(){
	int day = 0;
	while (!Q.empty()){
		xy root = Q.front();
		Q.pop();
		int x=root.x, y=root.y;
		int dist = T[y][x];
		for (int i=0; i<4; ++i){
			int xx = x+dx[i], yy = y+dy[i];
			xy s = {xx,yy};
			if (xx<0 || xx>=M || yy<0 || yy>=N) continue;	// out of range
			if (T[yy][xx]==0){
				T[yy][xx] = dist+1;
				Q.push(s);
			}
		}
	}
}

int main(int argc, char const *argv[])
{
	ios::sync_with_stdio(0);
	cin.tie(NULL);
	cout.tie(NULL);
	cin>>M>>N;
	T = new int*[N];
	bool is_result_0 = true;
	for(int i=0;i<N;++i){
		T[i] = new int[M];
		for(int j=0;j<M;++j){
			xy s = {j,i};
			cin >> T[i][j];
			if (T[i][j]==0) is_result_0 = false;
			if (T[i][j]==1) Q.push(s);
		}
	}
	if (is_result_0){
		cout << 0;
		return 0;
	}
	bfs();
	int answer = 0;
	for (int i=0;i<N;++i){
		for (int j=0;j<M;++j){
			if (T[i][j]==0){
				answer = 0;
				break;
			}
			if (T[i][j]>answer) answer = T[i][j];
		}
	}
	cout << answer-1;
	return 0;
}