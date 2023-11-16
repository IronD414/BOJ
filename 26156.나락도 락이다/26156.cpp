#include <iostream>
#include <string>
#include <cmath>
using namespace std;

int dp_K(string *input, int pos){
	int Kpos = input->find("K", pos);
	if (Kpos == string::npos){
		cout << 0;
		return 0;
	}
	if (input->find("K", Kpos+1) == string::npos){
		return pow(2, Kpos-pos);
	}
	return 2*dp_K(input, Kpos+1)*pow(2, Kpos-pos);	
}

int dp_CK(string *input, int pos){
	int Cpos = input->find("C", pos);
	if (Cpos == string::npos){
		cout << 0;
		return 0;
	}
	int Kpos = input->find("K", Cpos+1);
	if (Kpos == string::npos){
		cout << 0;
		return 0;
	}
	if (input->find("C", Cpos+1) == string::npos){
		return pow(2, Cpos-pos)*dp_K(input, Cpos+1);
	}
	return 2*dp_CK(input, Cpos+1)*pow(2, Cpos-pos);
}

int dp_OCK(string *input, int pos){
	int Opos = input->find("O", pos);
	if (Opos == string::npos){
		cout << 0;
		return 0;
	}
	int Cpos = input->find("C", Opos+1);
	if (Cpos == string::npos){
		cout << 0;
		return 0;
	}
	int Kpos = input->find("K", Cpos+1);
	if (Kpos == string::npos){
		cout << 0;
		return 0;
	}
	if (input->find("O", Opos+1) == string::npos){
		return pow(2, Opos-pos)*dp_CK(input, Opos+1);
	}
	return 2*dp_OCK(input, Opos+1)*pow(2, Opos-pos);
}

int dp_ROCK(string *input, int pos){
	int Rpos = input->find("R", pos);
	if (Rpos == string::npos){
		cout << 0;
		return 0;
	}
	int Opos = input->find("O", Rpos+1);
	if (Opos == string::npos){
		cout << 0;
		return 0;
	}
	int Cpos = input->find("C", Opos+1);
	if (Cpos == string::npos){
		cout << 0;
		return 0;
	}
	int Kpos = input->find("K", Cpos+1);
	if (Kpos == string::npos){
		cout << 0;
		return 0;
	}
	if (input->find("R", Rpos+1) == string::npos){
		return dp_OCK(input, Rpos+1)*pow(2, Rpos-pos);
	}
	return 2*dp_OCK(input, Rpos+1)*pow(2, Rpos-pos);
}

int main(int argc, char const *argv[])
{
	int N, result = 0;
	string input;
	cin >> N;
	cin >> input;

	cout << dp_ROCK(&input, 0);

	return 0;
}