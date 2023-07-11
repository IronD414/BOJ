#include <iostream>
#include <map>
using namespace std;
ios_base::sync_with_stdio(false);
int main(int argc, char const *argv[])
{
	int n; int value;
	cin >> n;
	map<int, int> mymap;
	for (int i = 0; i < n; ++i)
	{
		cin >> value;
		if (mymap.find(value) != mymap.end())
		{
			mymap.find(value)->second++;
		}else
		{
			mymap.insert(make_pair(value, 1));
		}
	}
	for (int i = 0; i < 10000; ++i)
	{
		value = mymap.find(i+1)->second;
		if (value > 0)
		{
			for (int j = 0; j < value; ++j)
			{
				cout << i+1 << "\n";
			}
		}
	}
	return 0;
}
// success!