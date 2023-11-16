#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main(int argc, char const *argv[])
{
	/* Initialize starts */
	int N;	// # of pokemons in pokedex
	int M;	// # of questions
	cin >> N >> M;
	string inputPokedex;
	vector<string> pokedex;
	for (int i=0; i<N; i++){
		cin >> inputPokedex;
		pokedex.push_back(inputPokedex);
	}
	string inputQuestion;
	vector<string> answer;
	/* Initialize ends */

	for (int i=0; i<M; i++){
		cin >> inputQuestion;
		int qNumber;
		try{
			qNumber = stoi(inputQuestion);
			answer.push_back(pokedex[qNumber-1]);
		}catch(invalid_argument const& ex){
			for (int j=0; j<N; j++){
				if (pokedex[j] == inputQuestion){ 
					answer.push_back(to_string(j+1));
				}
			}
		}
	}
	for (auto s : answer){
		cout << s << "\n";
	}

	return 0;
}