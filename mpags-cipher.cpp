#include <vector>
#include <iostream>
#include <string>
int main(int argc, char* argv[])
{
	const std::vector<std::string> cmdLineArgv{ argv, argv+argc};
	const std::string input{cmdLineArgv[1]};

	bool print_help{false};
	
	bool print_version{false};

	int output_loc;
	bool output_given{false};
	int input_file_loc;
	bool input_file_given{false};

	// start loop at 1 to ignore program name
	for (size_t i{1}; i < cmdLineArgv.size(); i++)
	{
		// std::cout << cmdLineArgv[i] << "\n";	// This line prints each command line argument

		if (cmdLineArgv[i] == "-h" || cmdLineArgv[i] == "--help"){
			print_help = true;
		}

		if (cmdLineArgv[i] == "--version"){
			print_version = true;
		}

		if (cmdLineArgv[i] == "-o"){
			output_loc = i + 1;
			output_given = true;
		}

		if (cmdLineArgv[i] == "-i"){
			input_file_loc = i + 1;
			input_file_given = true;
		}
	}	

	if (print_help == true){
		std::cout << "This is the help text" << "\n";
	}

	if (print_version == true){
		std::cout << "Version: 0.0.1" << "\n";
	}

	std::string output_filename;
	if (output_given == true){
		output_filename = cmdLineArgv[output_loc];
		std::cout << "Output File is " << output_filename << "\n";
	}

	std::string input_filename;
	if (input_file_given == true){
		input_filename = cmdLineArgv[input_file_loc];
		std::cout << "Input File is " << input_filename << "\n";
	}
		

	std::string output;
	char in_char('x');
	char out_char;
	for (size_t i{0}; i<input.size(); i++)
	{
		in_char = input[i];
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

				default:
	
					out_char = std::toupper(in_char);
					output = output + out_char;
					break;
			}
		}
	}
	std::cout << output << "\n";
}

