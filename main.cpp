//#include "part_one.h"
//#include "PartTwo.cpp"
#include "PartThree.cpp"

using namespace std;

//Team 6: Dasari, Deshpande, Kulkarni S., Nidumukkala, Pandit, Phirke

//---
const string READ_FILE_1 = "clear.txt";
const string WRITE_FILE_1 = "freq.txt";

const string FILE_CODETABLE = "codetable.txt";
const string FILE_CODED_3 = "coded.txt";
const string FILE_DECODED_3 = "decoded.txt";
//---

int main() {
	////Part 1:
	////Generate character count from given text file
	//PartOne part_one;
	//part_one.generate_character_counts(READ_FILE_1);
	//part_one.write_to_file(WRITE_FILE_1);

	//// Part 2: Generate huffman codetable
	//// Author: Arushi Pandit
	//generateCodeTable();

	//Part 3A:
	unordered_map<char, string> codetable = read_codetable(FILE_CODETABLE);
	encode_and_write_to_file(codetable, READ_FILE_1, FILE_CODED_3);

	//Part 3B:
	Node* huffman_root = generate_huffman_tree(codetable);
	decode_and_write_to_file(FILE_CODED_3, FILE_DECODED_3, huffman_root);

	return 0;
}
