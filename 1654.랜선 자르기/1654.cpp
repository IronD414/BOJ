#include <iostream>
using namespace std;

int cut_made(int *l, int n, int c)
{
	int amount = 0;
	for (int i = 0; i < n; ++i)
	{
		amount += l[i] / c;
	}
	return amount;
}

int main(int argc, char const *argv[])
{
	int k, n, key_input;
	int *lan_cables;
	long sum = 0; int cut;

	cin >> k >> n;
	lan_cables = new int[k];
	for (int i = 0; i < k; ++i)
	{
		cin >> key_input;
		sum += key_input;
		lan_cables[i] = key_input;
	}
	cut = sum / n;
	while (cut_made(lan_cables, k, cut) < n)
	{
		cut--;
	}
	cout << cut;

	delete[] lan_cables;
	return 0;
}