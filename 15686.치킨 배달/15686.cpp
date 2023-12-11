#include <iostream>
#include <algorithm>
#include <vector>
#include <climits>
using namespace std;

int N, M, h=0,c=0; // house#, chicken#
int city[50][50];
pair<int, int> hpos[100], cpos[13];
int dist[100][13];
vector<int> city_dist;

int get_dist(pair<int, int> a, pair<int, int> b) {
	return abs(a.first - b.first) + abs(a.second - b.second);
}
int get_min(int house, vector<int> v) {
	int min_dist = INT_MAX;
	for (int i : v) {
		if (dist[house][i] < min_dist) min_dist = dist[house][i];
	}
	return min_dist;
}
vector<int> V;
void comb(int no, int idx, vector<int> v) {
	v.push_back(idx);
	if (no == 1) {
		int sum = 0;
		for (int i = 0; i < h; i++) sum += get_min(i, v);
		city_dist.push_back(sum);
		return;
	}
	for (int i = idx + 1; i <= c - no + 1; i++) comb(no - 1, i, v);
}

int main() {
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> city[i][j];
			if (city[i][j] == 1) {
				hpos[h++] = { i,j };
			}
			if (city[i][j] == 2) {
				cpos[c++] = { i,j };
			}
		}
	}
	for (int i = 0; i < h; i++) {
		for (int j = 0; j < c; j++) {
			dist[i][j] = get_dist(hpos[i], cpos[j]);
		}
	}
	for (int idx = 0; idx < c - M + 1; idx++) {
		V.clear();
		comb(M, idx, V);
	}
	cout << *min_element(city_dist.begin(), city_dist.end());
}