#ifndef UTILITY_H
#define UTILITY_H

#include <iostream>
#include <iomanip>
#include <limits>
#include <cmath>
#include <cstdlib>
#include <cstddef>
#include <fstream>
#include <cctype>
#include <ctime>
#include <string>
#include <cstdlib>
#include <vector>
#include <algorithm>
#include <assert.h>
#include <queue>
#include <set>
#include <map>
#include <unordered_map> 
#include <stack>
#include <bitset>
#include <sstream>

using namespace std;

struct Node {
	int frequency;
	int character;
	Node* left;
	Node* right;

	Node(int fr, int ch)
		: frequency(fr), character(ch), left(nullptr), right(nullptr) {}

	Node(int fr, int ch, Node* lt, Node* rt)
		: frequency(fr), character(ch), left(lt), right(rt) {}
};

struct CompareFrequency {
	bool operator()(Node const* n1, Node const* n2)
	{
		// true if freq n1 > freq n2 so that n2 gets prioritized
		return n1->frequency > n2->frequency;
	}
};

#endif //UTILITY_H