#pragma once
#ifndef CODETABLE_H
#define CODETABLE_H

#include "utility.h"

struct charCode
{
	std::string character;
	std::string code;
};

struct Node {
	int frequency;
	int character;
	Node* left;
	Node* right;

	Node(int fr, int ch)
		: frequency(fr), character(ch), left(nullptr), right(nullptr) {}

	Node(int fr, int ch, Node* lt, Node* rt)
		: frequency(fr), character(ch), left(lt), right(rt) {}

	Node(int ch)
		: frequency(0), character(ch), left(nullptr), right(nullptr) {}

	Node()
		: frequency(0), character(-1), left(nullptr), right(nullptr) {}
};

struct CompareFrequency {
	bool operator()(Node const* n1, Node const* n2)
	{
		// true if freq n1 > freq n2 so that n2 gets prioritized
		return n1->frequency > n2->frequency;
	}
};

#endif
