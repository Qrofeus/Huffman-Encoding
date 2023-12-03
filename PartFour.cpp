#include "utility.h"
#include "codetable.h"

using namespace std;

//Team 6: Dasari, Deshpande, Kulkarni S., Nidumukkala, Pandit, Phirke

const int WORD_LENGTH = 8;

// This implementation uses unordered_map<> codetable and Node* Huffman Tree generated in part 3A and part 3B respectively
// To implement PartFour.cpp independently copy the functions from PartThree.cpp:
// static unordered_map<char, string> read_codetable(string codetable_file) {...}
// static Node* generate_huffman_tree(const unordered_map<char, string>& codetable) {...}

static void encode_bitset(unordered_map<char, string> codes, string read_file, string write_file) {
    ifstream in_file(read_file);
    ofstream out_file(write_file);

    if (!in_file.is_open()) {
        cerr << read_file << " file could not be opened." << endl;
        in_file.close();
        out_file.close();
        exit(1);
    }

    if (!out_file.is_open()) {
        cerr << write_file << " file could not be opened." << endl;
        in_file.close();
        out_file.close();
        exit(1);
    }

    bitset<WORD_LENGTH> word;
    int bit_index = 0;
    char current_char;

    while (in_file.get(current_char)) {
        string code = codes.at(current_char);
        for (char ch : code) {
            if (ch == '1')
                word.set(bit_index++);
            else
                word.reset(bit_index++);
            if (bit_index == WORD_LENGTH) {
                out_file << (char)word.to_ulong();
                bit_index = 0;
            }
        }
    }
    //Write any leftover bits in the word, reset the last unused bits
    if (bit_index > 0)
        out_file << (char)word.to_ulong();

    in_file.close();
    out_file.close();

    cout << "Encoded file written to: " << write_file << endl;
}


static void decode_bitset(Node* root, string read_file, string write_file) {
    ifstream in_file(read_file, ios::binary);
    ofstream out_file(write_file);

    if (!in_file.is_open()) {
        cerr << read_file << " file could not be opened." << endl;
        in_file.close();
        out_file.close();
        exit(1);
    }

    if (!out_file.is_open()) {
        cerr << write_file << " file could not be opened." << endl;
        in_file.close();
        out_file.close();
        exit(1);
    }

    int currentChar;
    Node* current_node = root;
    int bit_index;

    while ((currentChar = in_file.get()) != EOF) {
        bit_index = 0;
        bitset<WORD_LENGTH> word((unsigned long)currentChar);

        while (bit_index < WORD_LENGTH) {
            if (word.test(bit_index++))
                current_node = current_node->right;
            else
                current_node = current_node->left;

            if (current_node->character != -1) {
                out_file << (char)current_node->character;
                current_node = root;
            }
        }
    }

    in_file.close();
    out_file.close();

    cout << "Decoded file written to: " << write_file << endl;
}
