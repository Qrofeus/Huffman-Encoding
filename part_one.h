#pragma once

#include "utility.h"

const int ASCII_CHARACTERS_COUNT = 128;

class PartOne {
public:
	void generate_character_counts(std::string file_name);
	void write_to_file(std::string file_name);
private:
	std::vector<int> character_counts;
};
