#include "TrieTree.h"

TrieNode *getNode(void) {
	struct TrieNode *aux = NULL;

	aux = (struct TrieNode *) malloc(sizeof(struct TrieNode));

	if (aux) {
		int i;

		aux->folha = false;
		aux->nr = 0;
		aux->pos = new std::list<int>;

		for (i = 0; i < TAM; i++)
			aux->children[i] = NULL;
	}
	return aux;
}

void insert(TrieNode *root, const char *key, int pos) {
	int i;
	int idx;

	TrieNode *aux = root;

	for (i = 0; i < strlen(key); i++) {
		idx = getPos(key[i]);
		if (!aux->children[idx]) {
			aux->children[idx] = getNode();
		}
		aux = aux->children[idx];
	}
	aux->folha = true;
	aux->nr++;
	aux->pos->push_back(pos);
}

bool search(TrieNode *root, const char *key) {
	int i;
	int idx;
	bool result = false;
	TrieNode *aux = root;

	for (i = 0; i < strlen(key); i++) {
		idx = getPos(key[i]);

		if (!aux->children[idx])
			return false;

		aux = aux->children[idx];
	}

	if (aux != NULL && aux->folha) {
		std::cout << "Palavra '" << key << "' encontrada com " << aux->nr
				<< " ocorrencias" << std::endl;
		std::cout << "Posições: ";
		for (std::list<int>::iterator it = aux->pos->begin();
				it != aux->pos->end(); ++it) {
			std::cout << " " << *it;
		}
		result = true;
	}

	return result;
}

int getPos(char l) {
	int teste = (int) tolower(l) - (int) 'a';
	return teste;
}

void traverse(TrieNode* node, std::string key) {
	static int teste = 0;
	if (node->folha) {

		std::cout << key << " | encontrada: " << node->nr << " vezes, Posições: ";
		for (std::list<int>::iterator it = node->pos->begin(); it != node->pos->end(); ++it) {
			std::cout << " " << *it;
		}
		std::cout << std::endl;
		teste++;
	}

	for (int i = 0; i < 26; i++) {
		TrieNode* child = node->children[i];
		if (child) {
			key += ((char) (97 + i));
			traverse(child, key);
			key.erase(key.size() - 1);
		}
	}

//	std::cout <<"palavras total :=> " << teste<<std::endl;;
}
