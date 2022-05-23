#include <iostream>
#include "parser.h"
using namespace std;

int main(int argc, char* argv[])
{
	//asking for file name as command line arguments
	if (argc == 2)
	{
		//Starting production --> rest follows
		parser _parser(argv[1]);
		_parser.S();
		
		
	}
	else if (argc > 2)
	{ //argument limit exceeds
		cout << "Too many arguments" << endl;
	}
	else //if file name is'nt given
	{
		cout << "Please provide a file name" << endl;
	}
	return 0;
}
