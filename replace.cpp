//Author: Illia Dovhoshliubnyi
//Date of last modification: 27/04/23
//Modify input file
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include "BST.h"

using namespace std;

int main(int args, char* argv[])
{
	// Get the input file name from command line argument.
	string file_name = argv[1];

	// Create a new file name by removing the last character from the input file name and adding a 'o' at the end.
	string new_file_name = file_name;
	new_file_name.pop_back();
	new_file_name.push_back('o');

	// Open the output file for writing and the input file for reading.
	ofstream Write_file(new_file_name);
	ifstream Read_file(file_name);

	// Declare some variables to hold temporary values and tokens.
	string buffer, tmp_name, tmp_value, token;

	// Create a binary search tree to hold the defined constants.
	BST def_const;

	// Flag to indicate if a constant has just been defined.
	bool flag = false;

	// Read the input file line by line.
	while (getline(Read_file, buffer))
	{
		// Parse each line into tokens using a string stream.
		stringstream stream(buffer);

		// Process each token in the line.
		while (stream >> token)
		{
			// Check if the token is a preprocessor directive for defining a constant.
			if (token == "#define")
			{
				// Get the name and value of the constant from the next two tokens.
				stream >> tmp_name;
				stream >> tmp_value;

				// Insert the constant into the binary search tree.
				def_const.insert_constant(tmp_name, tmp_value);

				// Set the flag to indicate that a constant has just been defined.
				flag = true;
				break;
			}

			// Check if the token is a defined constant.
			tmp_value = def_const.get_value(token);
			if (tmp_value != "")
			{
				// If the token is a defined constant, replace it with its value in the output file.
				Write_file << tmp_value << " ";
				continue;
			}

			// If the token is not a defined constant, write it to the output file.
			Write_file << token << " ";
		}

		// If a constant has just been defined, skip writing the line break in the output file.
		if (flag)
		{
			flag = false;
			continue;
		}

		// Write a line break to the output file.
		Write_file << '\n';
	}

	// Close the input and output files.
	Write_file.close();
	Read_file.close();

	// Return 0 to indicate success.
	return 0;
}