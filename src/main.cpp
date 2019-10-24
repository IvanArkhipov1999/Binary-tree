/*
 * main.cpp
 *
 *  Created on: 9 сент. 2018 г.
 *      Author: ivan-arhipych
 */

#include <iostream>
#include "Binary_tree.h"

using namespace std;

int main() {
	Binary_tree a;
	int k[6] = {13, 16 ,17, 18, 45, 46};

	a.Insert(10);
	a.Insert(5);
	a.Insert(20);
	a.Insert(15);
	a.Insert(30);
	a.Insert(25);
	a.Insert(40);
	a.Traversing_recursive(0);
	printf("\n");
	a.Insert_sequence(k, 6);
	a.Traversing_recursive(0);

	return 0;
}

