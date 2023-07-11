#include <iostream>
#include <vector>
#include <array>
#include <algorithm>
using namespace std;

bool mycomp(array<int, 2> i, array<int, 2> j)
{
	return i[1]<j[1] || (i[1]==j[1] && i[0]<j[0]);
}

int main(void)
{
	int n; cin >> n;
	int x; int y;
	array<int, 2> a;
	vector<array<int, 2>> dots(n, a);
	for (int i = 0; i < n; ++i)
	{
		cin >> dots[i][0] >> dots[i][1];
	}
	sort(dots.begin(), dots.end(), mycomp);
	for (int i = 0; i < n; ++i)
	{
		cout << dots[i][0] << ' ' << dots[i][1] << "\n";
	}
	return 0;
}
// success!