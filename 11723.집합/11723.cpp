#include <iostream>
#include <string>
using namespace std;

int main(int argc, char const *argv[])
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int M; unsigned S = 0x00; int x;
	string input;
	cin >> M;
	for (int i = 0; i < M; ++i)
	{
		cin >> input;
		if (input == "add")
		{
			cin >> x;
			S |= (0x1 << x);
		}if (input == "remove")
		{
			cin >> x;
			S &= ~(0x1 << x);
		}if (input == "check")
		{
			cin >> x;
			cout << !!(S & (0x1 << x)) << "\n";
		}if (input == "toggle")
		{
			cin >> x;
			S ^= (0x1 << x);
		}if (input == "all")
		{
			S = 0x1fffff;
		}if (input == "empty")
		{
			S = 0x00;
		}
	}
	return 0;
}