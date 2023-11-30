#include <iostream>
#include <vector>
using namespace std;

int N, M, answer = 0, num, x=0,y=0;
bool truth[51] = { false, };
int DS[51];
vector<int> party[51];

int ds_find(int a) {
	int tmp = a;
	while (DS[tmp] != tmp) {
		tmp = DS[tmp];
	}
	return tmp;
}
void ds_union(int a, int b) {
	if (ds_find(a) != ds_find(b)) {
		DS[ds_find(a)] = ds_find(b);
	}
}

int main() {
	cin >> N >> M;
	for (int i = 0; i < N + 1; i++)
	{
		DS[i] = i;
	}
	cin >> num;
	for (int i = 0; i < num; i++)
	{
		cin >> x;
		truth[x] = true;
	}
	for (int i = 0; i < M; i++)
	{
		cin >> num;
		for (int j = 0; j < num; j++) {
			cin >> x;
			if (j == 0) y = x;
			party[i].push_back(x);
			ds_union(x, y);
		}
	}
	for (int i = 0; i <= N; i++)
	{
		if (truth[i]) {
			truth[ds_find(i)] = true;
		}
	}
	for (int i = 0; i < N; i++)
	{
		if (truth[ds_find(i)]) {
			truth[i] = true;
		}
	}
	for (int i = 0; i < M; i++)
	{
		if (!truth[ds_find(party[i].at(0))]) answer++;
	}
	cout << answer;
}