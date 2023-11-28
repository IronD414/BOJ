#include <iostream>
#include <vector>
#include <functional>
#include <queue>
using namespace std;

priority_queue<int, vector<int>, greater<int>> minHeap;
int N, x, k=0;
int answer[100000];

int main()
{
	cin >> N;
	for (size_t i = 0; i < N; i++)
	{
		cin >> x;
		if (x > 0) {
			minHeap.push(x);
		}
		else {
			if (minHeap.empty()) {
				answer[k++] = 0;
			}
			else {
				answer[k++] = minHeap.top();
				minHeap.pop();
			}
		}
	}
	for (size_t i = 0; i < k; i++)
	{
		cout << answer[i] << "\n";
	}
}