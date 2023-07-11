#include <iostream>
#include <math.h>
using namespace std;

bool isprime(int x)
{
	if (x==2) return true;
	else if (x==1) return false;
	for (int i = 2; i <= sqrt(x); ++i)
	{
		if (x%i == 0) return false;
	}
	return true;
}

int main(int argc, char const *argv[])
{
	int m; int n;
	cin >> m >> n;
	for (int i = m; i <= n; ++i)
	{
		if (isprime(i)) cout << i << "\n";
	}
	return 0;
}
//success!