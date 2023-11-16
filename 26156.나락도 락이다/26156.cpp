#include <iostream>
#include <string>
#include <cmath>
#include <algorithm>
using namespace std;

int dpK(string s, int n);
int dpC(string s, int n);
int dpO(string s, int n);
int dpR(string s, int n);

int N;
string str;	// KCOR
// KCKCOR
// KKCOR
// KCORR
// 2(받고+안받고)*이번거 찾으러간다 + 1(받고)*다음거 찾으러간다

int dpK(string s, int n){
	int result = 0;
	for (int i=0; i<n-3; i++){
		if (s[i]=='K'){
			result += 2*dpK(s.substr(i+1, n-i-1), n-i-1) + dpC(s.substr(i+1, n-i-1), n-i-1);
			return result;
		}
	}
	return result;
}
int dpC(string s, int n){
	int result = 0, mul = 1;
	for (int i=0; i<n-2; i++){
		if (s[i]=='C'){
			result += 2*dpC(s.substr(i+1, n-i-1), n-i-1) + dpO(s.substr(i+1, n-i-1), n-i-1);
			return result*mul;
		}else mul *= 2;
	}
	return result;
}
int dpO(string s, int n){
	int result = 0, mul = 1;
	for (int i=0; i<n-1; i++){
		if (s[i]=='O'){
			result += 2*dpO(s.substr(i+1, n-i-1), n-i-1) + dpR(s.substr(i+1, n-i-1), n-i-1);
			return result;
		}else mul *= 2;
	}
	return result;
}
int dpR(string s, int n){
	int result = 0, mul = 1;
	for (int i=0; i<n; i++){
		if (s[i]=='R'){
			result += 2*dpR(s.substr(i+1, n-i-1), n-i-1) + 1;
			return result*mul;
		}else mul *= 2;
	}
	return result;
}

int main(int argc, char const *argv[])
{
	int result = 0;
	cin >> N;
	cin >> str;
	reverse(str.begin(), str.end());
	cout << dpK(str, N);

	return 0;
}