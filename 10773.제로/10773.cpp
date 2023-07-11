#include <iostream>
#include <stack>
using namespace std;

int main(int argc, char const *argv[])
{
	stack<int> mystack;
	int k; cin >> k;
	int x;
	for (int i = 0; i < k; ++i)
	{
		cin >> x;
		if (x==0) mystack.pop();
		else mystack.push(x);
	}
	int result = 0;
	while (!mystack.empty())
	{
		result += mystack.top();
		mystack.pop();
	}
	cout << result;
	return 0;
}
// success!!