#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;

int rounding(double x)
{
	return floor(x + 0.5);
}

int main(int argc, char const *argv[])
{
	int n;
	int *arr; int *freq;
	int sum = 0;
	int count = 1; int freq_count = 1; int max = 0;
	double mean;

	cin >> n;
	arr = new int[n]; freq = new int[n];
	for (int i = 0; i < n; ++i)
	{
		cin >> arr[i];
		sum += arr[i];
	}
	sort(arr, arr+n);
	for (int i = 1; i < n; ++i)
	{
		if (i == n-1 || arr[i] != arr[i-1])
		{
			if (count > max)
			{
				delete[] freq;
				freq = new int[n];
				freq[0] = arr[i-1];
				max = count;
				count = 1;
				freq_count = 1;
			}else if (count == max)
			{
				freq[freq_count++] = arr[i-1];
				count = 1;
			}
		}else if (arr[i] == arr[i-1])
		{
			count++;
		}
	}
	sort(freq, freq+freq_count);
	
	mean = sum/(double)n;
	max = freq_count > 1 ? freq[1] : freq[0];

	cout << rounding(mean) << "\n" << arr[(n-1)/2] << "\n" << max << "\n" << arr[n-1] - arr[0];
	delete[] arr;
	delete[] freq;
	return 0;
}