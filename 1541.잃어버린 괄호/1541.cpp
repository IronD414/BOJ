#include <iostream>
#include <string>
using namespace std;

int previous = 0, current = 0, answer = 0;
string input, sub;

int get_sum(string s, int start_pos, int end_pos) {
	// [start, end)
	int sum = 0;
	int p = start_pos, c;
	while ((c = s.find('+', p)) != string::npos && c < end_pos) {
		string substr = s.substr(p, c - p);
		sum += stoi(substr);
		p = c+1;
	}
	sum += stoi(s.substr(p, end_pos - p));
	return sum;
}

int main()
{
	cin >> input;
	current = input.find('-', previous);
	if (current != string::npos) {
		answer += get_sum(input, previous, current);
		previous = current+1;
		while ((current = input.find('-', previous)) != string::npos) {
			answer -= get_sum(input, previous, current);
			previous = current+1;
		}
		answer -= get_sum(input, previous, input.size());
	}else{
		answer += get_sum(input, previous, input.size());
	}
	cout << answer;
}