#include <fstream>
#include <iostream>
#include <vector>
#include <string>
using namespace std;

vector<char> TAC;

//first read TAC into vector of struct quad
//next execute quad with pc
struct quad{
    string op;
    string arg1;
    string arg2;
    string res;
};

void readTAC(const char filename[]){
    ifstream fin(filename);
    if (!fin) // if file not found
    {
        cout << "file not found" << endl;
    }
    else
    {
        char byte = 0;
        while (fin.get(byte))
        { // store file contents into readTACData
            if (byte != '\r')
                TAC.push_back(byte);
        }
        TAC.push_back(' '); // dummy spaces appended at the end
        TAC.push_back(' ');
    }
}

int main(int argc, char* argv[])
{
	//asking for file name as command line arguments
	if (argc == 2)
	{
		//read TAC
        readTAC(argv[1]);
        for (int i = 0; i < TAC.size(); i++)
        {
            cout << TAC[i];
        }
		
		
	}
	else if (argc > 2)
	{ //argument limit exceeds
		cout << "Too many arguments" << endl;
	}
	else //if file name is'nt given
	{
		cout << "Please provide a TAC file name" << endl;
	}
	return 0;
}
