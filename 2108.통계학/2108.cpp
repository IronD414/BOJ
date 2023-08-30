#include <iostream>
#include <map>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;
typedef pair<int, int> ii;

int rounding(double x)
{
	return floor(x + 0.5);
}

int main(int argc, char const *argv[])
{
	int n;
	int *arr;
	int sum = 0;
	double mean;
	map<int, int> freq;
	int most;

	cin >> n;
	arr = new int[n];
	for (int i = 0; i < n; ++i)
	{
		cin >> arr[i];
		sum += arr[i];
		if (freq.count(arr[i]))
			freq[arr[i]]++;
		else freq[arr[i]] = 1;
	}
	sort(arr, arr+n);

	vector<ii> freqv(freq.begin(), freq.end());
	sort(freqv.begin(), freqv.end(), [](ii a, ii b)
	{
		if (a.second == b.second)
			return a.first < b.first;
		else return a.second > b.second;
	});
	
	mean = sum/(double)n;
	most = freqv[0].second == freqv[1].second ? freqv[1].first : freqv[0].first;
	
	cout << rounding(mean) << "\n" << arr[(n-1)/2] << "\n" << most << "\n" << arr[n-1] - arr[0];
	delete[] arr;
	return 0;
}