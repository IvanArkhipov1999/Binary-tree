/*
 * Binary_tree.h
 *
 *  Created on: 9 сент. 2018 г.
 *      Author: ivan-arhipych
 */

#ifndef BINARY_TREE_H_
#define BINARY_TREE_H_

#include <iostream>
#include <queue>

class tree_node {
public:
	tree_node *left;
	tree_node *right;
	int data;

	tree_node(tree_node *left, tree_node *right, int data) {
			this->left = left;
			this->right = right;
			this->data = data;
		}
};

class Binary_tree {
private:
	tree_node *root;

public:

	Binary_tree() {
		this->root = NULL;
	}

	Binary_tree(tree_node *root) {
		this->root = root;
	}

	void Insert(int a);
	bool Search(int a);
	bool Delete(int a);
	void Traversing_recursive(int i);
	void Traversing_queue();
	void Insert_sequence(int *a, int n);
};



#endif /* BINARY_TREE_H_ */
