#include <iostream>
#include <string>
#include <deque>
using namespace std;
int main(void)
{
	int n; string opr; int value;
	deque<int> myq;
	cin >> n;
	for (int i = 0; i < n; ++i)
	{
		cin >> opr;
		if (opr == "push_front")
		{
			cin >> value;
			myq.push_front(value);
		}else if (opr == "push_back")
		{
			cin >> value;
			myq.push_back(value);
		}else if (opr == "pop_front")
		{
			if (myq.empty())
			{
				cout << -1 << endl;
			}else
			{
				value = myq.front();
				myq.pop_front();
				cout << value << endl;
			}
		}else if (opr == "pop_back")
		{
			if (myq.empty())
			{
				cout << -1 << endl;
			}else
			{
				value = myq.back();
				myq.pop_back();
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