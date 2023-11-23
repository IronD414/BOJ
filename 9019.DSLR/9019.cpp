#include <iostream>
#include <string>
#include <queue>
#include <cmath>
using namespace std;

int T,A,B;
string *answer;
queue<char> Q;

int D(int a){return (2*a)%10000;}

int S(int a){
	if (a==0) return 9999;
	return a-1;
}

int L(int a){
	int a1 = 10*a;
	if (a1 > 9999){
		return a1/10000 + a1%10000;
	}
	return a1;
}

int R(int a){
	int a1 = a/10;
	if (a1 < 1){
		return a*1000;
	}
	return (a%10)*1000 + a1;
}

string cal(int a, int b){
	string from_D="", from_S="", from_L="", from_R="";
	
}

int main(int argc, char const *argv[])
{
	cin>>T;
	answer = new string[T];
	for (int i=0;i<T;++i){
		cin>>A>>B;
		answer[i] = cal(A,B);
	}
	for (int i=0;i<T;++i){
		cout<<answer[i]<<"\n";
	}
	delete[] answer;
	return 0;
}