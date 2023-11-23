#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

int N, M;
string D[500000];
string B[500000];
vector<string> answer;
vector<string>::iterator it;

int main() {
    cin >> N >> M;
    for (int i = 0; i < N; ++i) {
        cin >> D[i];
    }
    for (int i = 0; i < M; ++i) {
        cin >> B[i];
    }
    sort(D, D + N);
    sort(B, B + M);

    set_intersection(D, D + N, B, B + M, back_inserter(answer));
    //sort(answer.begin(), answer.begin() + answer.size());

    cout << answer.size() << "\n";
    for (it = answer.begin(); it != answer.end(); ++it) {
        cout << *it << "\n";
    }
}