#include <iostream>
#include <string>
#include <stack>
using namespace std;

bool isbalanced(string s)
{
	stack<int> brackets; // 0:() 1:[]
	for (int i = 0; i < s.length(); ++i)
	{
		if (s[i] == '(') brackets.push(0);
		else if (s[i] == '[') brackets.push(1);
		else if (s[i] == ')')
		{
			if (!brackets.empty() && brackets.top() == 0) brackets.pop();
			else return false;
		}
		else if (s[i] == ']')
		{
			if (!brackets.empty() && brackets.top() == 1) brackets.pop();
			else return false;
		}
	}
	if (!brackets.empty()) return false;
	else return true;
}

int main(int argc, char const *argv[])
{
	string line; string result = "";
	while(1)
	{
		getline(cin, line);
		
		if (line == ".") break;
		else if (isbalanced(line)) result += "yes";
		else result += "no";
		result += "\n";
	}
	cout << result;
	return 0;
}
// success!