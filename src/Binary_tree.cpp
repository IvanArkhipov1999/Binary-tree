/*
 * Binary_tree.cpp
 *
 *  Created on: 13 сент. 2018 г.
 *      Author: ivan-arhipych
 */

#include "Binary_tree.h"

void Binary_tree::Insert(int a) {
	tree_node* new_node = new tree_node(nullptr, nullptr, a);

	if (this->root == nullptr) {
		this->root = new_node;
		return;
	}

	tree_node *p = this->root;
	while (p != nullptr) {
		if (a > p->data && p->right != nullptr)
			p = p->right;
		else if (a > p->data && p->right == nullptr) {
			p->right = new_node;
			p = NULL;
		} else if (a < p->data && p->left != nullptr)
			p = p->left;
		else if (a < p->data && p->left == nullptr) {
			p->left = new_node;
			p = nullptr;
		}
	}
}

bool Binary_tree::Search(int a) {
	if (this->root == nullptr)
		return false;

	tree_node *p = this->root;
	while (true) {
		if (a > p->data && p->right != nullptr)
			p = p->right;
		else if (a > p->data && p->right == nullptr)
			return false;
		else if (a < p->data && p->left != nullptr)
			p = p->left;
		else if (a < p->data && p->left == nullptr)
			return false;
		else
			return true;
	}
}

bool Binary_tree::Delete(int a) {
	tree_node *p = this->root;
	tree_node *parent_p = nullptr;
	tree_node *v = nullptr;
	tree_node *parent_v = nullptr;
	tree_node *child_v = nullptr;

	while (p != nullptr && p->data != a) {
		parent_p = p;
		if (a > p->data)
			p = p->right;
		else
			p = p->left;
	}
	if (p == nullptr)
		return false;
	if (p->right == nullptr)
		v = p->left;
	else if (p->left == nullptr)
		v = p->right;
	else {
		parent_v = p;
		v = p->right;
		child_v = v->left;
		while (child_v != nullptr) {
			parent_v = v;
			v = child_v;
			child_v = v->left;
		}
		if (parent_v != p) {
			parent_v->left = v->right;
			v->right = p->right;
		}
		v->left = p->left;
	}
	if (parent_p == nullptr)
		this->root = v;
	else if (p == parent_p->left)
		parent_p->left = v;
	else
		parent_p->right = v;
	delete (p);

	return true;
}

void Binary_tree::Traversing_recursive(int i = 0) {
	if (root != NULL) {
		for (int j = 0; j < i; j++)
			std::cout << " ";
		std::cout << root->data;
		std::cout << " " << std::endl;
		i++;
		tree_node *left = this->root->left;
		Binary_tree left_tree(left);
		left_tree.Traversing_recursive(i);

		tree_node *right = this->root->right;
		Binary_tree right_tree(right);
		right_tree.Traversing_recursive(i);
	}
}

void Binary_tree::Traversing_queue() {
	std::queue<tree_node*> q;
	tree_node *top;

	q.push(this->root);
	while (!q.empty()) {
		top = q.front();
		q.pop();
		std::cout << top->data << std::endl;
		if (top->left != nullptr)
			q.push(top->left);
		if (top->right != nullptr)
			q.push(top->right);
	}
}


void Binary_tree::Insert_sequence(int *a, int n) {
	int i = 0;

	if (this->root == nullptr) {
		tree_node *t = new tree_node(nullptr, nullptr, a[0]);
		this->root = t;
		tree_node *p = this->root;
		for (int k = 1; k < n; k++) {
			tree_node *v = new tree_node(nullptr, nullptr, a[k]);
			p->right = v;
			p = p->right;
		}
		return;
	}
	while (a[i] < this->root->data && i < n)
		i++;
	if (this->root->left == nullptr) {
		tree_node *p = this->root;
		for (int j = i - 1; j > -1; j--) {
			tree_node *t = new tree_node(nullptr, nullptr, a[j]);
			p->left = t;
			p = p->left;
		}
	}
	else {
		tree_node *left = this->root->left;
		Binary_tree left_tree(left);
		left_tree.Insert_sequence(a, i);
	}
	if (this->root->right == nullptr) {
		tree_node *p = this->root;
		for (int j = i; j < n; j++) {
			tree_node *t = new tree_node(nullptr, nullptr, a[j]);
			p->right = t;
			p = p->right;
		}
	}
	else {
		tree_node *right = this->root->right;
		Binary_tree right_tree(right);
		right_tree.Insert_sequence(a + i, n - i);
	}
}
