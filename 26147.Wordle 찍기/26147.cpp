#include <iostream>
#include <string>
using namespace std;
int main(int argc, char const *argv[])
{
	int N;
	cin >> N;
	string *judge = new string[N];
	char **output = new char*[N];
	for (int i = 0; i < N; ++i)
	{
		output[i] = new char[5];
	}
	bool is_impossible = false;
	for (int i = 0; i < N; ++i)
	{
		cin >> judge[i];
		if (judge[i]=="YGGGG"||judge[i]=="GYGGG"||judge[i]=="GGYGG"||judge[i]=="GGGYG"||judge[i]=="GGGGY") is_impossible = true;
	}
	if (is_impossible){
		cout << "IMPOSSIBLE";
		return 0;
	}
	string answer = "ABCDE";
	for (int i = 0; i < N; ++i)
	{
		string j = judge[i];
		int ynum = 0, gnum = 0, bpos, ypos;
		for (int k = 0; k < 5; ++k)
		{
			if (j[k]=='G'){
				output[i][k] = answer[k];
				gnum++;	
			} else if (j[k]=='B') {
				output[i][k] = 'Z';
				bpos = k;
			}else {
				ypos = k;
				ynum++;	
			} 
		}
		if (ynum == 1){
			output[i][ypos] = answer[bpos];
		}else if (ynum > 0){
			int *yposs = new int[ynum];
			int l=0;
			for (int k=0;k<5; ++k)
			{
				if (j[k]=='Y'){
					yposs[l++] = k;
				}
			}
			for (int k = 0; k < ynum; ++k)
			{
				output[i][yposs[k]] = answer[yposs[(k+1)%ynum]];
			}
		}
	}
	cout << answer << "\n";
	for (int i = 0; i < N; ++i)
	{
		cout << output[i] << "\n";
	}
	for (int i = 0; i < N; ++i)
	{
		delete[] output[i];
	}
	delete output, judge;
	return 0;
}