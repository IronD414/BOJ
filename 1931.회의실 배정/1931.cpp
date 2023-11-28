#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

typedef struct {
	int start;
	int end;
}T;

struct compare {
	bool operator()(T a, T b) {
		if (a.end == b.end) {
			return a.start > b.start;
		}
		return a.end > b.end;
	}
};

int N, s, e, answer=0;
priority_queue<T, vector<T>, compare> Q;

int main()
{
	cin >> N;
	for (size_t i = 0; i < N; i++)
	{
		cin >> s >> e;
		T t = { s,e };
		Q.push(t);
	}
	int tmp_time = 0;
	while (!Q.empty()) {
		T tmp_T = Q.top();
		Q.pop();
		if (tmp_T.start >= tmp_time) {
			tmp_time = tmp_T.end;
			answer++;
		}
	}
	cout << answer;
}