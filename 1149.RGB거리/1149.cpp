#include <iostream>
using namespace std;

#define R 0
#define G 1
#define B 2

int N,cost_r,cost_g,cost_b,answer;
int minimum[1000][3] = { {0,}, };

int main() {
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> cost_r >> cost_g >> cost_b;
		if (i == 0) {
			minimum[i][R] = cost_r;
			minimum[i][G] = cost_g;
			minimum[i][B] = cost_b;
			continue;
		}
		minimum[i][R] = minimum[i - 1][G] < minimum[i - 1][B] ? cost_r + minimum[i - 1][G] : cost_r + minimum[i - 1][B];
		minimum[i][G] = minimum[i - 1][B] < minimum[i - 1][R] ? cost_g + minimum[i - 1][B] : cost_g + minimum[i - 1][R];
		minimum[i][B] = minimum[i - 1][R] < minimum[i - 1][G] ? cost_b + minimum[i - 1][R] : cost_b + minimum[i - 1][G];
	}
	answer = minimum[N - 1][R] < minimum[N - 1][G] ? minimum[N - 1][R] : minimum[N - 1][G];
	answer = answer < minimum[N - 1][B] ? answer : minimum[N - 1][B];
	cout << answer;
}