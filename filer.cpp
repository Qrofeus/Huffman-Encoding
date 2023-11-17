#include "filer.h"

using namespace std;

string Filer::read_from_file(string filename) {
	string file_content = "";

	ifstream file_pointer;
	file_pointer.open(filename);

	if (!file_pointer.is_open()) {
		cout << "File could not be opened.";
		file_pointer.close();
		exit(1);
	}

	string line;
	while (getline(file_pointer, line)) {
		file_content += line;
		file_content += '\n';
	}

	file_pointer.close();

	return file_content;
}