#include "part_one.h"

using namespace std;

//Team 6: Dasari, Deshpande, Kulkarni S., Nidumukkala, Pandit, Phirke

void PartOne::generate_character_counts(string file_name) {
	ifstream file_pointer;
	file_pointer.open(file_name);

	if (!file_pointer.is_open()) {
		cout << file_name << " file could not be opened.";
		file_pointer.close();
		exit(1);
	}

	this->character_counts.assign(ASCII_CHARACTERS_COUNT, 0);
	char ch;

	while (file_pointer.get(ch)) {
		if (ch == EOF)
			break;

		this->character_counts[(int)ch] += 1;
	}

	file_pointer.close();
}

void PartOne::write_to_file(string file_name) {
	ofstream file_pointer;
	file_pointer.open(file_name);

	if (!file_pointer.is_open()) {
		cout << file_name << " file could not be opened.";
		file_pointer.close();
		exit(1);
	}

	//'\n' ASCII 10 -> 'LF'
	file_pointer << "LF " << this->character_counts[10] << endl;
	//' ' ASCII 32 -> 'SP'
	file_pointer << "SP " << this->character_counts[32] << endl;

	//Printable ASCII Characters start from index 32 -> " "
	//https://en.cppreference.com/w/cpp/language/ascii
	for (int i = 33; i < ASCII_CHARACTERS_COUNT; i++)
		if (this->character_counts[i] != 0)
			file_pointer << char(i) << ' ' << this->character_counts[i] << endl;

	
	file_pointer.close();
	cout << "Character counts written to file: " << file_name << endl;
}
