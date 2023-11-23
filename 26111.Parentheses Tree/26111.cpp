#include <iostream>
#include <string>
using namespace std;
int main() {
	string input;
	cin >> input;
	int sum = 0, count = -1;
	for (int i = 0; i < input.length(); i++) {
		if (input[i] == '(') {
			count++;
		}
		if (input[i] == ')') {
			sum += count--;
		}
	}
	cout << sum;
	return 0;
}