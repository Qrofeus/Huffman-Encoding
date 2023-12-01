#include "utility.h"
#include "codetable.h"

using namespace std;

static void encode_and_write_to_file(const unordered_map<char, string>& codetable, string read_file, string write_file) {
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

    char current_char;
    while (in_file.get(current_char))
        out_file << codetable.at(current_char);

    in_file.close();
    out_file.close();

    cout << "Encoded file written to: " << write_file << endl;
}

static unordered_map<char, string> read_codetable(string codetable_file) {
    ifstream codetable(codetable_file);

    if (!codetable.is_open()) {
        cerr << codetable_file << " file could not be opened.";
        codetable.close();
        exit(1);
    }

    unordered_map<char, string> codes;

    string key, code;
    char character;

    while (codetable >> key >> code) {
        if (key == "LF")
            character = '\n';
        else if (key == "SP")
            character = ' ';
        else
            character = key[0];
        codes[character] = code;
    }

    codetable.close();
    return codes;
}

static Node* generate_huffman_tree(const unordered_map<char, string>& codetable) {
    Node* root_node = new Node();
    Node* current_node;

    for (auto iterator : codetable) {
        current_node = root_node;
        string code = iterator.second;

        for (char bit : code) {
            if (bit == '0') {
                if (current_node->left == nullptr)
                    current_node->left = new Node();
                current_node = current_node->left;
            }
            if (bit == '1') {
                if (current_node->right == nullptr)
                    current_node->right = new Node();
                current_node = current_node->right;
            }
        }

        current_node->character = (int)iterator.first;
    }

    return root_node;
}

static void decode_and_write_to_file(string read_file, string write_file, Node* root) {
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

    char currentChar;
    Node* current_node = root;
    while (in_file.get(currentChar)) {
        if (currentChar == '0')
            current_node = current_node->left;
        else
            current_node = current_node->right;
        
        if (current_node->character != -1) {
            out_file << (char)current_node->character;
            current_node = root;
        }
    }

    in_file.close();
    out_file.close();

    cout << "Decoded file written to: " << write_file << endl;
}
