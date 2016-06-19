/*
 * TrieTree.h
 *
 *  Created on: 18 de jun de 2016
 *      Author: Thiago
 */

#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <cctype>
#include <iostream>
#include <list>
#include <iomanip>
#ifndef TRIETREE_H_
#define TRIETREE_H_

#define TAM (26)

struct TrieNode
{
	struct TrieNode *children[TAM];
	bool folha;
	int nr;
	std::list<int> *pos;
}typedef TrieNode;

TrieNode *getNode(void);
void insert(TrieNode *root, const char *key, int pos);
bool search(TrieNode *root, const char *key);
int getPos(char l);
void traverse(TrieNode* node, std::string key);

#endif /* TRIETREE_H_ */
