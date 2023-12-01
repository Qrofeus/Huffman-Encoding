#include "utility.h"
#include "codetable.h"

using namespace std;

void encode_and_write_to_file(const unordered_map<string, string> codetable, string read_file, string write_file) {
    ifstream in_file(read_file);
    ofstream out_file(write_file);

    if (!in_file.is_open()) {
        cerr << read_file << " file could not be opened." << endl;
        exit(1);
    }

    if (!out_file.is_open()) {
        cerr << write_file << " file could not be opened." << endl;
        exit(1);
    }

    char current_char;
    while (in_file.get(current_char)) {
        string char_string(1, current_char);
        out_file << codetable.at(char_string);
    }

    in_file.close();
    out_file.close();
}

unordered_map<string, string> read_codetable(string codetable_file) {
    ifstream codetable(codetable_file);

    if (!codetable.is_open()) {
        cerr << codetable_file << " file could not be opened.";
        exit(1);
    }

    unordered_map<std::string, std::string> codes;

    string character;
    string code;

    while (codetable >> character >> code) {
        if (character == "LF")
            character = "\n";
        else if (character == "SP")
            character = " ";

        codes[character] = code;
    }

    codetable.close();
    return codes;
}

//Node* generate_huffman_tree(const unordered_map<string, string> codetable) {
//    Node* root_node = new Node();
//    Node* current_node;
//
//    for (auto iterator : codetable) {
//        cout << "Generating branch " << iterator.first << endl;
//        current_node = root_node;
//        string code = iterator.second;
//        cout << "Code " << code << endl;
//
//        for (char bit : code) {
//            if (current_node == nullptr)
//                current_node = new Node();
//            if (bit == '0') {
//                cout << "Turning left" << endl;
//                current_node = current_node->left;
//            }
//            if (bit == '1') {
//                cout << "Turning right" << endl;
//                current_node = current_node->right;
//            }
//        }
//
//        cout << "Character [" << iterator.first[0] << "] -> [" << (int)iterator.first[0] << "]\n";
//        current_node->character = (int)iterator.first[0];
//        cout << "Node set to new character" << endl;
//    }
//
//    return root_node;
//}
//
//
//int main() {
//    const string CODETABLE = "codetable.txt";
//	unordered_map<string, string> codetable = read_codetable(CODETABLE);
//    for (auto iterator : codetable)
//        cout << iterator.first << "->" << iterator.second << endl;
//
//    cout << "Generating Huffman Tree" << endl;
//    Node* huffman_root = generate_huffman_tree(codetable);
//    cout << "Huffman Tree generated" << endl;
//
//    string input = "1101001110";
//    Node* current_node = huffman_root;
//    cout << "Reading input " << input << endl;
//    for (char ch : input) {
//        if(ch == '0')
//            current_node = current_node->left;
//        if (ch == '1')
//            current_node = current_node->right;
//        if (current_node->character != NULL) {
//            cout << current_node->character;
//            current_node = huffman_root;
//        }
//    }
//
//
//    return 0;
//}