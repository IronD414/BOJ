#include <iostream>
#include <queue>
using namespace std;

int pos[100001] = {0,};
int N, K;
queue<int> Q;

void search() {
	Q.push(N);
	while (!Q.empty()) {
		int idx = Q.front();
		Q.pop();
		if (idx - 1 >= 0 && pos[idx - 1] == 0) {
			if (idx - 1 == K) {
				pos[K] = pos[idx] + 1;
				return;
			}
			if (idx-1 != N) {
				pos[idx - 1] = pos[idx] + 1;
				Q.push(idx - 1);
			}
		}
		if (idx > K) continue;
		if (idx!=0 && idx * 2 <= 100000 && pos[idx * 2] == 0) {
			if (idx * 2 == K) {
				pos[K] = pos[idx] + 1;
				return;
			}
			pos[idx * 2] = pos[idx] + 1;
			Q.push(idx * 2);
		}
		if (idx + 1 <= 100000 && pos[idx + 1] == 0) {
			if (idx + 1 == K) {
				pos[K] = pos[idx] + 1;
				return;
			}
			pos[idx + 1] = pos[idx] + 1;
			Q.push(idx + 1);
		}
	}
}

int main() {
	cin >> N >> K;
	if (N == K) {
		cout << 0;
		return 0;
	}
	search();
	cout << pos[K];
}