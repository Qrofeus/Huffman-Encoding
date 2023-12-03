#include "utility.h"
#include "codetable.h"

using namespace std;

//Team 6: Dasari, Deshpande, Kulkarni S., Nidumukkala, Pandit, Phirke

const int WORD_LENGTH = 8;

//static unordered_map<char, string> read_codetable(string codetable_file) {
//    ifstream codetable(codetable_file);
//
//    if (!codetable.is_open()) {
//        cerr << codetable_file << " file could not be opened.";
//        codetable.close();
//        exit(1);
//    }
//
//    unordered_map<char, string> codes;
//
//    string key, code;
//    char character;
//
//    while (codetable >> key >> code) {
//        if (key == "LF")
//            character = '\n';
//        else if (key == "SP")
//            character = ' ';
//        else
//            character = key[0];
//        codes[character] = code;
//    }
//
//    codetable.close();
//    return codes;
//}
//
//static Node* generate_huffman_tree(const unordered_map<char, string>& codetable) {
//    Node* root_node = new Node();
//    Node* current_node;
//
//    for (auto iterator : codetable) {
//        current_node = root_node;
//        string code = iterator.second;
//
//        for (char bit : code) {
//            if (bit == '0') {
//                if (current_node->left == nullptr)
//                    current_node->left = new Node();
//                current_node = current_node->left;
//            }
//            if (bit == '1') {
//                if (current_node->right == nullptr)
//                    current_node->right = new Node();
//                current_node = current_node->right;
//            }
//        }
//
//        current_node->character = (int)iterator.first;
//    }
//
//    return root_node;
//}

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
    //if (bit_index < WORD_LENGTH) {
    //    while (bit_index < WORD_LENGTH)
    //        word.reset(bit_index++);
    //    out_file << (char)word.to_ulong();
    //}
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
