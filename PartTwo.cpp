#include "utility.h"

inline void writeCodeTable(Node* node, string code, ostream& codetable)
{
	if (node == nullptr)
		return;

	string left_code = code + '0';
	writeCodeTable(node->left, left_code, codetable);

	if (node->character != -1)
	{
		if (node->character == 10)
			codetable << "LF" << " " << code << endl;

		else if (node->character == 32)
			codetable << "SP" << " " << code << endl;

		else
			codetable << static_cast<char>(node->character) << " " << code << endl;
	}

	string right_code = code + '1';
	writeCodeTable(node->right, right_code, codetable);

	delete node; //free the memory
}

inline void generateCodeTable()
{
	ifstream freqFile;
	freqFile.open("freq.txt");

	priority_queue< Node*, vector<Node*>, CompareFrequency > q;
	string char_str;
	string freq_str;
	int freq;
	stringstream char_to_int; //to convert from char to int

	while (freqFile >> char_str >> freq_str)
	{
		char_to_int.clear();
		char_to_int.str(freq_str);
		char_to_int >> freq; // convert freq to int
		Node* node = nullptr;

		if (char_str == "LF")
			node = new Node(freq, 10);

		else if (char_str == "SP")
			node = new Node(freq, 32);

		else
			node = new Node(freq, static_cast<int>(char_str[0]));

		q.push(node);
	}
	freqFile.close();

	Node* internal = nullptr;
	Node* min1 = nullptr;
	Node* min2 = nullptr;
	bool flag = true;

	//building Huffman Tree
	do {
		min1 = q.top(); // least frequency node
		q.pop();

		if (!q.empty())
		{
			min2 = q.top(); // second least frequency node
			q.pop();
		}
		else
			// last node is the parent
			flag = false;

		if (flag)
		{
			internal = new Node(min1->frequency + min2->frequency, -1, min1, min2); //-1 ASCII to indicate internal node
			q.push(internal);
		}

	} while (!q.empty() && flag);

	ofstream codetable;
	codetable.open("codetable.txt", fstream::out);

	writeCodeTable(min1, "", codetable); //prints the code table

	codetable.close();
}