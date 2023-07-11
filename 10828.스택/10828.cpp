#include <iostream>
#include <string>
#include <stack>
using namespace std;

int main(int argc, char const *argv[])
{
	int n; string operation; int value;
	stack<int> mystack;
	cin >> n;
	for (int i = 0; i < n; ++i)
	{
		cin >> operation;
		if (operation == "push")
		{
			cin >> value;
			mystack.push(value);
		}else if (operation == "pop")
		{
			if (mystack.empty())
			{
				cout << -1 << endl;
			}else
			{
				value = mystack.top();
				mystack.pop();
				cout << value << endl;
			}
		}else if (operation == "size")
		{
			cout << mystack.size() << endl;
		}else if (operation == "empty")
		{
			cout << mystack.empty() << endl;
		}else if (operation == "top")
		{
			if (mystack.empty())
			{
				cout << -1 << endl;
			}else
			{
				cout << mystack.top() << endl;
			}
		}
	}
	return 0;
}

// success!