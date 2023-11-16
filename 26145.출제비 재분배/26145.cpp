#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
	int N, M, money_move;
	cin >> N >> M;
	int *S = new int[N+M+1];
	for (int i = 1; i <= N; ++i)
	{
		cin >> S[i];
	}
	for (int i = 1; i <= N; ++i)
	{
		for (int j = 1; j <= N+M; ++j)
		{
			cin >> money_move;
			S[i] -= money_move;
			S[j] += money_move;
		}
	}
	for (int i = 1; i <= N+M; ++i)
	{
		cout << S[i] << " ";
	}
	return 0;
}