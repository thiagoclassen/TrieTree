//============================================================================
// Name        : Cadeia.cpp
// Author      : Thiago
//============================================================================

#include <iostream>
#include <fstream>
#include "TrieTree.h"
using namespace std;

TrieNode *root = getNode();

int main() {

	ifstream file;
	file.open("words.txt");
	string palavra;
	palavra.clear();
	bool punct = false;

	int cont = 0;

	while (file >> palavra) {
		for (int i = 0; i < palavra.size(); i++) {
			if (ispunct(palavra.at(i))){
				palavra.erase(i);
				punct = true;
			}
		}
		insert(root, palavra.c_str(), cont);

		if(punct)
			cont++;
		cont += palavra.size()+1;
		punct = false;
		palavra.clear();
	}

	search(root, "Lorem");

	return 0;
}
