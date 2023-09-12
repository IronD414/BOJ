#include <iostream>
using namespace std;

bool can_popped(int n, int* arr, int sub)
{
	int i, quan = 0;

	for (i = 0; i < sub - 1; ++i)
	{
		if (arr[sub] < arr[i] && arr[i] < arr[sub-1]) quan++;
	}

	return quan == arr[sub-1] - arr[sub] - 1;
}

int* createArr(int n, int* arr)
{
	int i, j, m = 0;
	int progress = 0;
	int *answer = new int[n*2];

	for (i = 0; i < n; ++i)
	{
		if (arr[i] > progress)
		{
			for (j = 0; j < arr[i] - progress; ++j)
			{
				answer[m++] = 1;
			}
			answer[m++] = 0;
			progress = arr[i];
		}else if (arr[i] == arr[i-1] - 1 || can_popped(n, arr, i))
		{
			answer[m++] = 0;
		}else return NULL;
	}

	return answer;
}

int main(int argc, char const *argv[])
{
	int i, n, key_input;
	int *arr;

	cin >> n;
	arr = new int[n];
	for (i = 0; i < n; ++i)
	{
		cin >> key_input;
		arr[i] = key_input;
	}
	int *answer = createArr(n, arr);
	if (answer == NULL) cout << "NO\n";
	else
	{
		for (int i = 0; i < n*2; ++i)
		{
			if (answer[i] == 1) cout << "+\n";
			else cout << "-\n";
		}
	}

	delete[] arr, answer;
	return 0;
}