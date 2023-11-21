#include <iostream>
#include <queue>
using namespace std;

typedef struct{
	int x;
	int y;
	int z;
}xyz;
int M,N,H,s;
int ***T;
queue<xyz> Q;
queue<xyz> sources;
// up, down, left, right, above, below
int dx[6] = {0, 0, -1, 1, 0, 0};
int dy[6] = {1, -1, 0, 0, 0, 0};
int dz[6] = {0, 0, 0, 0, 1, -1};

void print_status(){
	for (int i=0;i<H;++i){
		for (int j=0;j<N;++j){
			for (int k=0;k<M;++k){
				cout << T[i][j][k] << " ";
			}
			cout << "\n";
		}
		cout << "\n";
	}
}

int bfs(){
	// T[?][?][?] = 2*distance(from source) + 1(discovered)/0(undiscovered)  or  -1(wall)
	while (!sources.empty()){
		Q.push(sources.front());
		sources.pop();
		int dist;
		while (!Q.empty()){
			xyz root = Q.front();
			Q.pop();
			int x=root.x, y=root.y, z=root.z;
			dist = T[z][y][x];
			for (int i=0; i<6; ++i){
				int xx = x+dx[i], yy = y+dy[i], zz = z+dz[i];
				xyz s = {xx,yy,zz};
				if (xx<0 || xx>=M || yy<0 || yy>=N || zz<0 || zz>=H) continue;	// out of range
				int t = T[zz][yy][xx];
				if (t==-1) continue;	// wall
				if (t==0 || t > dist+2){
					T[zz][yy][xx] = dist+2;	// mark as discovered & record distance
					Q.push(s);
				}
			}
		}
	}
	int answer = 0;
	for (int i=0;i<H;++i){
		for (int j=0;j<N;++j){
			for (int k=0;k<M;++k){
				if (T[i][j][k] > answer) answer = T[i][j][k];
				if (T[i][j][k]==0) return -1;
			}
		}
	}
	return (answer-1)/2;
}

int main(int argc, char const *argv[])
{
	cin>>M>>N>>H;
	T = new int**[H];
	bool is_result_0 = true;
	for(int i=0;i<H;++i){
		T[i] = new int*[N];
		for(int j=0;j<N;++j){
			T[i][j] = new int[M];
			for(int k=0;k<M;++k){
				xyz s = {k,j,i};
				cin >> T[i][j][k];
				if (T[i][j][k]==0) is_result_0 = false;
				if (T[i][j][k]==1) sources.push(s);
			}
		}
	}
	if (is_result_0){
		cout << 0;
		return 0;
	}
	int answer = bfs();
	cout << answer;
	return 0;
}