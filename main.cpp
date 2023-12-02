//#include "part_one.h"
//#include "PartTwo.cpp"
#include "PartThree.cpp"
#include "PartFour.cpp"

using namespace std;

//Team 6: Dasari, Deshpande, Kulkarni S., Nidumukkala, Pandit, Phirke

//---
const string READ_FILE = "clear.txt";
const string FILE_CHAR_FREQUENCY = "freq.txt";

const string FILE_CODETABLE = "codetable.txt";
const string FILE_CODED = "coded.txt";
const string FILE_DECODED = "decoded.txt";

const string FILE_CODEDALT = "codedalt.txt";
const string FILE_DECODEDALT = "decodedalt.txt";
//---

int main() {
	////Part 1:
	////Generate character count from given text file
	//PartOne part_one;
	//part_one.generate_character_counts(READ_FILE);
	//part_one.write_to_file(FILE_CHAR_FREQUENCY);

	//// Part 2: Generate huffman codetable
	//// Author: Arushi Pandit
	//generateCodeTable();

	//Part 3A:
	unordered_map<char, string> codetable = read_codetable(FILE_CODETABLE);
	//encode_and_write_to_file(codetable, READ_FILE, FILE_CODED);

	//Part 3B:
	Node* huffman_root = generate_huffman_tree(codetable);
	//decode_and_write_to_file(FILE_CODED, FILE_DECODED, huffman_root);

	//Part 4A:
	encode_bitset(codetable, READ_FILE, FILE_CODEDALT);

	//Part 4B:
	decode_bitset(huffman_root, FILE_CODEDALT, FILE_DECODEDALT);

	return 0;
}
