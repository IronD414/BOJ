#include <iostream>
#include <vector>
#include <map>
#include <string>
using namespace std;

int main(int argc, char const *argv[])
{
	/* Initialize starts */
	int N;	// # of pokemons in pokedex
	int M;	// # of questions
	cin >> N >> M;
	string inputPokedex;
	map<string, int> pokedexByName;
    map<int, string> pokedexByNumber;
	for (int i=0; i<N; i++){
		cin >> inputPokedex;
		pokedexByName[inputPokedex] = i+1;
        pokedexByNumber[i+1] = inputPokedex;
	}
	string inputQuestion;
	vector<string> answer;
	/* Initialize ends */

	for (int i=0; i<M; i++){
		cin >> inputQuestion;
		int qNumber;
		try{
			qNumber = stoi(inputQuestion);
			answer.push_back(pokedexByNumber.find(qNumber)->second);
		}catch(invalid_argument const& ex){
            answer.push_back(to_string(pokedexByName.find(inputQuestion)->second));
		}
	}
	for (auto s : answer){
		cout << s << "\n";
	}

	return 0;
}