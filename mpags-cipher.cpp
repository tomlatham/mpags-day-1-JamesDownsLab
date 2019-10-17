#include <vector>
#include <iostream>
#include <string>
int main(int argc, char* argv[])
{
	const std::string version_number{"0.0.1"};

	const std::vector<std::string> cmdLineArgv{ argv, argv+argc};
	typedef std::vector<std::string>::size_type size_type;
	const size_type nCmdLineArgs {cmdLineArgv.size()};

	// Variables for flags
	bool print_help{false};
	bool print_version{false};

	// Variables for options
	bool output_flag{false};
	bool input_flag{false};
	std::string output_file;
	std::string input_file;

	// start loop at 1 to ignore program name
	for (size_type i{1}; i < nCmdLineArgs; i++)
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
			if (i == nCmdLineArgs-1) {
				std::cerr << "[error] -o requires a filename argument" << std::endl;
				// exit main with non-zero return to indicate failure
				return 1;
			}
			i++;
			output_flag = true;
			output_file = cmdLineArgv[i];
		}

		else if (cmdLineArgv[i] == "-i"){
			if (i == nCmdLineArgs-1) {
				std::cerr << "[error] -i requires a filename argument" << std::endl;
				// exit main with non-zero return to indicate failure
				return 1;
			}
			i++;
			input_flag = true;
			input_file = cmdLineArgv[i];
		}

		else {
			// Have an unknown flag to output error message and return non-zero
			// exit status to indicate failure
			std::cerr << "[error] unknown argument '" << cmdLineArgv[i] << "'\n";
			return 1;
		}
	}	

	// print statements for options and flags
	if (print_help == true){
		std::cout
			<< "Usage: mpags-cipher [-i <file>] [-o <file>]\n\n"
			<< "Encrypts/Decrypts input alphanumeric text using classical ciphers\n\n"
			<< "Available options:\n\n"
			<< "  -h|--help        Print this help message and exit\n\n"
			<< "  --version        Print version information\n\n"
			<< "  -i FILE          Read text to be processed from FILE\n"
			<< "                   Stdin will be used if not supplied\n\n"
			<< "  -o FILE          Write processed text to FILE\n"
			<< "                   Stdout will be used if not supplied\n\n";
		// Help requires no further action, so return from main
		// with 0 used to indicate success
		return 0;
	}

	if (print_version == true){
		std::cout << "Version: " << version_number << "\n";
		return 0;
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

	// read each character in the input
	while (std::cin >> in_char){

		// If inchar is alphanumeric either turn into a number of capitalise
		if (std::isalnum(in_char))
		{
			switch (in_char)
			{
				case '0':
					output += "ZERO";
					break;

				case '1':
					output += "ONE";
					break;
				case '2':
					output += "TWO";
					break;

				case '3':
					output += "THREE";
					break;

				case '4':
					output += "FOUR";
					break;

				case '5':
					output += "FIVE";
					break;

				case '6':
					output += "SIX";
					break;

				case '7':
					output += "SEVEN";
					break;

				case '8':
					output += "EIGHT";
					break;

				case '9':
					output += "NINE";
					break;

				default:	//capitalise if not a number
					output += std::toupper(in_char);
					break;
			}
		}
	}
	std::cout << output << "\n";
}

