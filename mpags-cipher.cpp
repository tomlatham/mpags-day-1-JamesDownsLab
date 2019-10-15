#include <vector>
#include <iostream>
#include <string>
int main(int argc, char* argv[])
{
	const std::vector<std::string> cmdLineArgv{ argv, argv+argc};
	const std::string input{cmdLineArgv[1]};
	bool print_help{false};
	// start loop at 1 to ignore program name
	for (size_t i{1}; i < cmdLineArgv.size(); i++)
	{
		std::cout << cmdLineArgv[i] << "\n";	
		if (cmdLineArgv[i] == "-h"){
			print_help = true;
		}
		if (cmdLineArgv[i] == "--help"){
			print_help = true;
		}
	}	

	if (print_help == true){
		std::cout << "This is the help text" << "\n";
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

