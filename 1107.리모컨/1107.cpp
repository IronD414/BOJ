#include <iostream>
#include <string>
using namespace std;

int N,M,input;
unsigned buttons = 0x3FF;

bool possible(int x){
	string s = to_string(x);
	int l = s.length();
	for (int i = 0; i < l; ++i)
	{
		if (!(buttons & (0x1 << s[i]-48))) return false;
	}
	return true;
}

int main(int argc, char const *argv[])
{
	cin >> N >> M;
	for (int i=0;i<M;i++){
		cin >> input;
		buttons &= ~(0x1 << input);
	}
	int x = abs(N - 100);
	int a,b;
	a = N;
	b = N;
	while (1){
		if (to_string(a).length() + abs(a - N) >= x){
			break;
		}else if (possible(a))
			break;
		a++;
	}
	while (1){
		if (to_string(b).length() + abs(N - b) >= x){
			break;
		}else if (possible(b) || b<0)
			break;
		b--;
	}
	x = x < to_string(a).length() + abs(a - N) ? x : to_string(a).length() + abs(a - N);
	if (b>=0) x = x < to_string(b).length() + abs(b - N) ? x : to_string(b).length() + abs(N - b);
	cout << x;
	return 0;
}