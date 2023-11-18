#include <iostream>
#include <string>
#include <cmath>
using namespace std;

int endswithK(string *s, int spos, int n, int **ptrK){
	string S = *s;
	if ((*ptrK)[spos] > 0) return (*ptrK)[spos];
	if (spos == n-1) return S[spos]=='K' ? 1 : 0;
	int pos = n-1;
	int result = 0;
	while (pos >= spos){
		if (S[pos]=='K') result += endswithK(S, )
		pos--;
	}
}

int main(int argc, char const *argv[])
{
	int result = 0;
	int N;
	cin >> N;
	string S;
	cin >> S;

	int *K = new int[N];
	int *CK = new int[N];
	int *OCK = new int[N];
	for (int i = 0; i < N; ++i)
	{
		K[i]=0;
		CK[i]=0;
		OCK[i]=0;
	}


	
	cout << result % 1000000007; 
	delete[] K,CK,OCK;
	return 0;
}