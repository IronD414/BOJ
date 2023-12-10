#include <iostream>
#include <deque>
#include <vector>
using namespace std;

string S, bomb;
deque<char> st;
vector<char> ans;
int main() {
	cin >> S >> bomb;
	int cur = -1;
	for (int i = 0; i < S.length(); i++) {
		if (cur == bomb.length() - 2 && S[i] == bomb[cur + 1]) {
			for (int j = 0; j < bomb.length() - 1; j++)st.pop_back();
			if (st.empty()) cur = -1;
			else cur = bomb.find(st.back());
		}
		else if (S[i] == bomb[0]) {
			cur = 0;
			st.push_back(S[i]);
		}
		else if (S[i] == bomb[cur + 1]) {
			cur++;
			st.push_back(S[i]);
		}
		else {
			while (!st.empty()) {
				char x = st.front();
				ans.push_back(x);
				st.pop_front();
			}
			ans.push_back(S[i]);
			cur = -1;
		}
	}
	while (!st.empty()) {
		char x = st.front();
		ans.push_back(x);
		st.pop_front();
	}
	if (ans.empty())cout << "FRULA";
	else for (char c : ans)cout << c;
}