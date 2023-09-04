#include <iostream>
#include <random>
using namespace std;

bool is_abletocut(int size, int *a, long long m, int n)
{
	long long sum = 0;
	for (int i = 0; i < size; ++i)
	{
		sum += a[i] / m;
	}
	return sum >= n;
}

int main(int argc, char const *argv[])
{
	int k, n;
	int *lan_cables;
	long long sum = 0, key_input, mid, start = 0, end, result;

	// for (int testcase = 0; testcase < 100; testcase++)
	// {
		k = rand() % 10000 + 1;
		n = rand() % (30000 - k - 1) + k;
		cin >> k >> n;
		lan_cables = new int[k];
		for (int i = 0; i < k; ++i)
		{
			// key_input = rand() % 30000 + 1;
			cin >> key_input;
			sum += key_input;
			lan_cables[i] = key_input;
		}
		end = sum / n;
		mid = (start + end) / 2;

		if (is_abletocut(k, lan_cables, end, n)) result = end;
		else 
		{
			while (start < end)
			{
				if (is_abletocut(k, lan_cables, mid, n))
				{
					start = mid + 1;
				}else
				{
					end = mid - 1;
				}
				mid = (start + end) / 2;
			}
			result = mid;
		}
		if (!is_abletocut(k, lan_cables, result, n)) result--;
		cout << result;
		// cout << "k: " << k << ", n: " << n << ", result: " << result << "\n======" << endl;
	// }
	delete[] lan_cables;
	return 0;
}