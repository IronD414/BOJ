#include <iostream>
#include <limits>
using namespace std;

int N;
int answer[1000001] = {0,};

int main()
{
	cin >> N;
	int i = 1;
	while (++i <= N) {
		int tmp1 = answer[i - 1] + 1, tmp2=INT_MAX, tmp3=INT_MAX;
		if (i % 2 == 0) tmp2 = answer[i / 2] + 1;
		if (i % 3 == 0) tmp3 = answer[i / 3] + 1;
		answer[i] = tmp2 < tmp3 ? tmp2 : tmp3;
		answer[i] = tmp1 < answer[i] ? tmp1 : answer[i];
	}
	cout << answer[N];
}