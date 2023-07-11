#include <iostream>
#include <string>
#include <queue>
using namespace std;
int main(void)
{
	int n; string opr; int value;
	queue<int> myq;
	cin >> n;
	for (int i = 0; i < n; ++i)
	{
		cin >> opr;
		if (opr == "push")
		{
			cin >> value;
			myq.push(value);
		}else if (opr == "pop")
		{
			if (myq.empty())
			{
				cout << -1 << endl;
			}else
			{
				value = myq.front();
				myq.pop();
				cout << value << endl;
			}
		}else if (opr == "size")
		{
			cout << myq.size() << endl;
		}else if (opr == "empty")
		{
			cout << myq.empty() << endl;
		}else if (opr == "front")
		{
			if (myq.empty())
			{
				cout << -1 << endl;
			}else
			{
				cout << myq.front() << endl;
			}
		}else if (opr == "back")
		{
			if (myq.empty())
			{
				cout << -1 << endl;
			}else
			{
				cout << myq.back() << endl;
			}
		}
	}
	return 0;
}

// success!