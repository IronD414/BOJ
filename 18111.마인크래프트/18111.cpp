#include <iostream>
#include <algorithm>
#include <limits.h>
using namespace std;

#define INF LLONG_MAX;

long long* findRangeInSquare(long long **square, long long n, long long m)
{
	long long *range = new long long[2]; // min 0 max 1
	range[0] = INF;
	range[1] = 0;
	for (long long i = 0; i < n; ++i)
	{
		for (long long j = 0; j < m; ++j)
		{
			if (square[i][j] > range[1])
			{
				range[1] = square[i][j];
			}
			if (square[i][j] < range[0])
			{
				range[0] = square[i][j];	
			}
		}
	}
	return range;
}

int main(int argc, char const *argv[])
{
	long long N, M, B;
	long long **ground;
	cin >> N >> M >> B;
	ground = new long long*[N];
	for (long long i = 0; i < N; ++i)
	{
		ground[i] = new long long[M];
		for (long long j = 0; j < M; ++j)
		{
			cin >> ground[i][j];
		}
	}

	long long *range = findRangeInSquare(ground, N, M);
	long long min = range[0];
	long long max = range[1];
	long long requiredDirt = 0;
	for (long long i = 0; i < N; ++i)
	{
		for (long long j = 0; j < M; ++j)
		{
			requiredDirt += max - ground[i][j];
		}
	}
	long long resultTime = INF;
	long long buildingTime = 0, diggingTime = 0; 
	long long resultMax;
	for (; max >= min; max--)
	{
		buildingTime = 0;
		if (B >= requiredDirt)
		{
			for (long long i = 0; i < N; ++i)
			{
				for (long long j = 0; j < M; ++j)
				{
					buildingTime += max - ground[i][j];
				}
			}
			if (diggingTime+buildingTime < resultTime)
			{
				resultTime = diggingTime+buildingTime;
				resultMax = max;
			} 
		}
		for (long long i = 0; i < N; ++i)
		{
			for (long long j = 0; j < M; ++j)
			{
				if (ground[i][j] == max)
				{
					ground[i][j]--;
					diggingTime += 2;
					B++;
					requiredDirt++;
				}
			}
		}
		requiredDirt -= N*M;
	}
	cout << resultTime << " " << resultMax << "\n";

	for (long long i = 0; i < N; ++i)
	{
		delete[] ground[i];
	}
	delete[] ground;

	return 0;
}