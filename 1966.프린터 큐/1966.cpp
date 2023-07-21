#include <iostream>
#include <queue>
using namespace std;

int main(int argc, char const *argv[])
{
	int num; cin >> num;
	int n; int request; int x; int order; bool is_mip; // is_most important process
	int *myq; int *results = new int[num];
	for (int i = 0; i < num; ++i)
	{
		cin >> n >> request;
		myq = new int[n];

		for (int j = 0; j < n; ++j)
		{
			cin >> x;
			myq[j] = x;
		}

		order = 0;

		while (1)
		{
			is_mip = true;
			for (int k = 1; k < n; ++k)
			{
				if (myq[k] > myq[0]) is_mip = false;
			}

			if (request == 0)
			{
				if (is_mip)
				{
					order++;
					break;
				}else
				{
					int tmp_delayed = myq[0];
					for (int k = 0; k < n-1; ++k)
					{
						myq[k] = myq[k+1];
					}
					myq[n-1] = tmp_delayed;
					request = n-1;
				}
			}else
			{
				if (is_mip)
				{
					request--; n--;
					for (int k = 0; k < n; ++k)
					{
						myq[k] = myq[k+1];
					}
					order++;
				}else
				{
					int tmp_delayed = myq[0];
					for (int k = 0; k < n; ++k)
					{
						myq[k] = myq[k+1];
					}
					myq[n-1] = tmp_delayed;
					request--;
				}
			}
		}
		results[i] = order;
		delete[] myq;
	}
	for (int i = 0; i < num; ++i)
	{
		cout << results[i] << endl;
	}
	delete[] results;
	return 0;
}
/*
			there are 4 cases;
			1: it is target and executed
			2: it is target and delayed
			3: not target and executed
			4: not target and delayed
			*/