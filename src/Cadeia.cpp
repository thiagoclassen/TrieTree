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
	file.open("historia.txt");
	string palavra;
	palavra.clear();
	bool punct = false;

	int cont = 0;

	while (file >> palavra) {
		for (int i = 0; i < palavra.size(); i++) {
			if (ispunct(palavra.at(i))) {
				palavra.erase(i);
				punct = true;
			}
		}

			insert(root, palavra.c_str(), cont);

		if (punct)
			cont++;
		cont += palavra.size() + 1;
		punct = false;
		palavra.clear();
	}

	int op = 0;
	std::string aux;

	do {
		std::cout << std::endl<< std::endl;
		cout << "1 - Imprimir palavra invertida." << endl;
		cout << "2 - Buscar palavra." << endl;
		cout << "3 - Sair." << endl;

		cin >> op;
		std::cout << std::endl<< std::endl;
		switch (op) {
		case 1:
			aux.clear();
			traverse(root, aux);
			break;
		case 2:
			aux.clear();
			cout << "Qual palavra." << endl;
			cin>>aux;
			if(!search(root, aux.c_str()))
				std::cout << "Palavra não encontrada." << std::endl;
			break;
		}

	} while (op != 3);

	return 0;
}
