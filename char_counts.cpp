#include "char_counts.h"

using namespace std;

void ChCounts::generate_character_counts(string file_name) {
	ifstream file_pointer;
	file_pointer.open(file_name);

	if (!file_pointer.is_open()) {
		cout << "File could not be opened.";
		file_pointer.close();
		exit(1);
	}

	this->character_counts.assign(ASCII_CHARACTERS, 0);
	char ch;

	while (file_pointer.get(ch)) {
		if (ch == EOF)
			continue;

		this->character_counts[(int)ch] += 1;
	}

	file_pointer.close();
}

void ChCounts::write_to_file(string file_name) {
	ofstream file_pointer;
	file_pointer.open(file_name);

	if (!file_pointer.is_open()) {
		cout << "File could not be opened.";
		file_pointer.close();
		exit(1);
	}

	for (int i = 0; i < ASCII_CHARACTERS; i++) {
		//Non-printable line-feed character '\n' as 'LF'
		if (i == 10) {
			file_pointer << "LF " << this->character_counts[i] << endl;
			continue;
		}

		//Printable ASCII Characters start from index 32 -> " "
		//https://en.cppreference.com/w/cpp/language/ascii
		if (i < 32)
			continue;

		if (i == 32) {
			file_pointer << "SP " << this->character_counts[i] << endl;
			continue;
		}

		//Ignore characters with count == 0
		if (this->character_counts[i] == 0)
			continue;

		file_pointer << char(i) << ' ' << this->character_counts[i] << endl;
	}

	file_pointer.close();
	cout << "Character counts written to file: " << file_name << endl;
}
