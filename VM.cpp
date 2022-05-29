#include <cstring>
#include <fstream>
#include <iostream>
#include <map>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

vector<int[4]> quad;

map<string, int> ds;

map<string, int> functionTable;
map<int, int> valueTable;
map<int, string> stringTable;

map<string, int> opCodeTable{
    {"out", 0},
    {"in", 1},
    {"+", 2},
    {"-", 3},
    {"=", 4},
    {"/", 5},
    {"%", 6},
    {">", 7},
    {"<", 8},
    {"<=", 9},
    {">=", 10},
    {"==", 11},
    {"!=", 12},
    {"param", 13},
    {"goto", 14},
    {"call", 15},
    {"ret", 16},
};

bool is_number(const std::string &s)
{
    std::string::const_iterator it = s.begin();
    while (it != s.end() && std::isdigit(*it))
        ++it;
    return !s.empty() && it == s.end();
}

void convertTACintoQuad(string fname1, string fname2)
{
    fstream tac;
    tac.open(fname1);
    fstream st;
    st.open(fname2);
    string line;

    // create a datasegment
    int valueTableIndex = 0;
    while (getline(st, line))
    {
        if (line[line.length() - 1] != ':')
        {
            istringstream ss(line);
            string word;
            ss >> word;
            string type;
            ss >> type;
            string value;
            ss >> value;
            if (value != "NULL")
            {
                int val = stoi(value);
                valueTable[valueTableIndex] = val;
            }
            ds[word] = valueTableIndex++;
        }
        else
        {
            istringstream ss(line);
            string word;
            ss >> word;
            string addr;
            ss >> addr;
            addr.pop_back();
            functionTable[word] = stoi(addr);
        }
    }
    int quadIndex = 0;
    int stringTableIndex = 0;
    while (getline(tac, line))
    {
        // cout << line << endl;
        vector<string> words;
        istringstream ss(line);
        string word;
        while (ss >> word)
        {
            words.push_back(word);
        }
        if (opCodeTable.count(words[0]))
        { // not an assignment
            quad[quadIndex][0] = opCodeTable[words[0]];
            if (words[0] == "out")
            {
                string str;

                for (int i = 1; i < words.size(); i++)
                {
                    str += words[i] + " ";
                }
                str.pop_back();
                ds[str] = valueTableIndex++;
                stringTable[ds[str]] = str;
                quad[quadIndex][1] = ds[str];
            }
            else if (words[0] == "call")
            {
            }
            quad[quadIndex][1] = ds[words[1]];
        }
        else if (words[0] == "if")
        {
            quad[quadIndex][0] = opCodeTable[words[2]];
            if (ds.count(words[1]))
            {
                quad[quadIndex][1] = ds[words[1]];
            }
            else
            {
                if (is_number(words[1]))
                {
                    int num = stoi(words[1]);
                    valueTable[valueTableIndex] = num;
                    ds[words[1]] = valueTableIndex++;
                    quad[quadIndex][1] = ds[words[1]];
                }
                cout << "ERROR: " << words[1] << "IS NOT DECLARED" << endl;
                return;
            }
            if (ds.count(words[3]))
            {
                quad[quadIndex][3] = ds[words[3]];
            }
            else
            {
                if (is_number(words[3]))
                {
                    int num = stoi(words[3]);
                    valueTable[valueTableIndex] = num;
                    ds[words[3]] = valueTableIndex++;
                    quad[quadIndex][3] = ds[words[3]];
                }
                else
                {
                    cout << "ERROR: " << words[3] << "IS NOT DECLARED" << endl;
                    return;
                }
            }
            quad[quadIndex][3] = stoi(words[5]);
        }
        else
        { // an assignment
            if (ds.count(words[0]))
            {
                quad[quadIndex][1] = ds[words[0]];
            }
            else
            {
                cout << "ERROR: " << words[0] << "IS NOT DECLARED" << endl;
                return;
            }
            if (ds.count(words[2]))
            {
                quad[quadIndex][2] = ds[words[2]];
            }
            else
            {
                if (is_number(words[2]))
                {
                    int num = stoi(words[2]);
                    valueTable[valueTableIndex] = num;
                    ds[words[2]] = valueTableIndex++;
                    quad[quadIndex][2] = ds[words[2]];
                }
                else
                {
                    cout << "ERROR: " << words[2] << "IS NOT DECLARED" << endl;
                    return;
                }
            }
            if (words.size() > 3)
            { // assignment of expression
                if (is_number(words[4]))
                {
                    int num = stoi(words[4]);
                    valueTable[valueTableIndex] = num;
                    ds[words[4]] = valueTableIndex++;
                    quad[quadIndex][4] = ds[words[4]];
                }
                else
                {
                    cout << "ERROR: " << words[4] << "IS NOT DECLARED" << endl;
                    return;
                }
                if (opCodeTable.count(words[3]))
                {
                    quad[quadIndex][0] = opCodeTable[words[3]];
                }
                else
                {
                    cout << "ERROR: " << words[3] << "IS NOT A VALID OPERATOR" << endl;
                    return;
                }
            }
            else
            { // simple assignment
                quad[quadIndex][0] = opCodeTable[words[1]];
            }
        }
        quadIndex++;
    }
}

int main(int argc, char *argv[])
{
    // asking for file name as command line arguments
    if (argc == 3)
    {
        // read TAC
        convertTACintoQuad(argv[1], argv[2]);
    }
    else // if file name is'nt given
    {
        cout << "Please provide a TAC file name and a symbol table" << endl;
    }
    return 0;
}
