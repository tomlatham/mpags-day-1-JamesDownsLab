#include <vector>
#include <iostream>
#include <string>
int main(int argc, char* argv[])
{
	const std::string version_number{"0.0.1"};
	const std::vector<std::string> cmdLineArgv{ argv, argv+argc};
	
	// Variables for arguments
	std::string input{""};

	// Variables for flags
	bool print_help{false};
	bool print_version{false};

	// Variables for options
	bool output_flag{false};
	bool input_flag{false};
	std::string output_file;
	std::string input_file;

	// start loop at 1 to ignore program name
	for (size_t i{1}; i < cmdLineArgv.size(); i++)
	{

		// Test flags
		if (cmdLineArgv[i] == "-h" || cmdLineArgv[i] == "--help"){
			print_help = true;
		}

		else if (cmdLineArgv[i] == "--version"){
			print_version = true;
		}

		// Test options
		else if (cmdLineArgv[i] == "-o"){
			i++;
			output_flag = true;
			output_file = cmdLineArgv[i];
		}

		else if (cmdLineArgv[i] == "-i"){
			i++;
			input_flag = true;
			input_file = cmdLineArgv[i];
		}

		else {
			input = cmdLineArgv[i];
		}
	}	

	// print statements for options and flags
	if (print_help == true){
		std::cout << "This is the help text" << "\n";
	}

	if (print_version == true){
		std::cout << "Version: 0.0.1" << "\n";
	}

	if (output_flag == true){
		std::cout << "Output file is " << output_file << "\n";
	}

	if (input_flag == true){
		std::cout << "Input File is " << input_file << "\n";
	}


	// Actual cipher
	std::string output;
	char in_char('x');
	char out_char;

	if (input != ""){
		// read each character in the input
		for (size_t i{0}; i<input.size(); i++)
		{
			in_char = input[i];

			// If inchar is alphanumeric either turn into a number of capitalise
			if (std::isalnum(in_char) != 0)
			{;
				switch (in_char)
				{
					case '0':
						output = output + "ZERO";
						break;
					
					case '1':
						output = output + "ONE";
						break;
					case '2':
						output = output + "TWO";
						break;

					case '3':
						output = output + "THREE";
						break;

					case '4':
						output = output + "FOUR";
						break;

					case '5':
						output = output + "FIVE";
						break;

					case '6':
						output = output + "SIX";
						break;

					case '7':
						output = output + "SEVEN";
						break;

					case '8':
						output = output + "EIGHT";
						break;

					case '9':
						output = output + "NINE";
						break;

					default:	//capitalise if not a number

						out_char = std::toupper(in_char);
						output = output + out_char;
						break;
				}
			}
		}
	}
	std::cout << output << "\n";
}

