#include <algorithm>
#include <cstring>
#include <fstream>
#include <iostream>
#include <map>
#include <queue>
#include <sstream>
#include <stack>
#include <string>
#include <vector>

using namespace std;

vector<vector<int>> quad;

map<string, int> ds;

map<string, pair<int, int>> functionTable;
vector<pair<int, string>> funcLineNumbers;

map<int, int> valueTable;
map<int, string> stringTable;
map<string, vector<int>> paramTable;

stack<int> stk;
stack<string> function;

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

void executeQuad()
{
    string func = function.top();
    function.pop();
    int params = functionTable[func].second;
    int lineNumber = functionTable[func].first - 1;
    if (params != paramTable[func].size())
    {
        cout << "ERROR: "
             << "PARAMETERS NUMBER MISMATCH" << endl;
        return;
    }
    int dst = stk.top();
    stk.pop();
    for (int i = 0; i < params; i++)
    {
        valueTable[paramTable[func][i]] = valueTable[stk.top()];
        stk.pop();
    }

    int temp, dest, s1, s2;
    string str;
    for (int pc = lineNumber; pc < quad.size(); ++pc)
    {
        switch (quad[pc][0])
        {       // Examine opcode
        case 0: // out
            temp = quad[pc][1];
            if (temp != -1)
            {
                str = stringTable[temp];
                str.pop_back();
                str.erase(0, 1);
                cout << str;
            }
            else
            {
                cout << valueTable[quad[pc][2]];
            }
            break;
        case 1: // in
            temp;
            cin >> temp;
            dest = quad[pc][1];
            valueTable[dest] = temp;
            break;
        case 2: //+
            dest = quad[pc][1];
            s1 = quad[pc][2];
            s2 = quad[pc][3];
            valueTable[dest] = valueTable[s1] + valueTable[s2];
            break;
        case 3: //-
            dest = quad[pc][1];
            s1 = quad[pc][2];
            s2 = quad[pc][3];
            valueTable[dest] = valueTable[s1] - valueTable[s2];
            break;
        case 4: //  =
            dest = quad[pc][1];
            s1 = quad[pc][2];
            valueTable[dest] = valueTable[s1];
            break;
        case 5: // div
            dest = quad[pc][1];
            s1 = quad[pc][2];
            s2 = quad[pc][3];
            valueTable[dest] = valueTable[s1] / valueTable[s2];
            break;
        case 6: // mod
            dest = quad[pc][1];
            s1 = quad[pc][2];
            s2 = quad[pc][3];
            valueTable[dest] = valueTable[s1] % valueTable[s2];
            break;
        case 7: // GT
            dest = quad[pc][3];
            s1 = quad[pc][1];
            s2 = quad[pc][2];
            if (valueTable[s1] > valueTable[s2])
            {
                pc = dest - 2;
            }
            break;
        case 8: // LT
            dest = quad[pc][3];
            s1 = quad[pc][1];
            s2 = quad[pc][2];
            if (valueTable[s1] < valueTable[s2])
            {
                pc = dest - 2;
            }
            break;
        case 9: // LE
            dest = quad[pc][3];
            s1 = quad[pc][1];
            s2 = quad[pc][2];
            if (valueTable[s1] <= valueTable[s2])
            {
                pc = dest - 2;
            }
            break;
        case 10: // GE
            dest = quad[pc][3];
            s1 = quad[pc][1];
            s2 = quad[pc][2];
            if (valueTable[s1] >= valueTable[s2])
            {
                pc = dest - 2;
            }
            break;
        case 11: // EQ
            dest = quad[pc][3];
            s1 = quad[pc][1];
            s2 = quad[pc][2];
            if (valueTable[s1] == valueTable[s2])
            {
                pc = dest - 2;
            }
            break;
        case 12: // NE
            dest = quad[pc][3];
            s1 = quad[pc][1];
            s2 = quad[pc][2];
            if (valueTable[s1] != valueTable[s2])
            {
                pc = dest - 2;
            }
            break;
        case 13: // param
            stk.push(quad[pc][1]);
            break;
        case 14: // goto
            pc = quad[pc][1] - 2;
            break;
        case 15: // call
            stk.push(quad[pc][3]);
            for (auto &itr : funcLineNumbers)
            {
                if (itr.first == quad[pc][1])
                {
                    function.push(itr.second);
                }
            }
            executeQuad();
            break;
        case 16: // ret
            valueTable[dst] = valueTable[quad[pc][1]];
            return;
            break;
        }
    }
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
    string func = "";
    int numParams = 0;
    while (getline(st, line))
    {

        if (line[line.length() - 1] == ':')
        {
            istringstream ss(line);
            string word;
            ss >> word;
            string addr;
            ss >> addr;
            string paramNum;
            ss >> paramNum;
            numParams = stoi(paramNum);
            functionTable[word] = make_pair(stoi(addr), numParams);
            func = word;
        }
        else
        {
            istringstream ss(line);
            string word;
            ss >> word;
            string type;
            ss >> type;
            string value;
            ss >> value;
            if (numParams == 0)
            {
                if (value != "NULL")
                {
                    int val = stoi(value);
                    valueTable[valueTableIndex] = val;
                }
                ds[func + word] = valueTableIndex++;
            }
            else
            {
                if (value != "NULL")
                {
                    int val = stoi(value);
                    valueTable[valueTableIndex] = val;
                }
                ds[func + word] = valueTableIndex;
                paramTable[func].push_back(valueTableIndex++);
                numParams--;
            }
        }
    }
    int quadIndex = 0;
    int stringTableIndex = 0;

    for (auto &it : functionTable)
    {
        funcLineNumbers.push_back(make_pair(it.second.first - 1, it.first));
    }
    sort(funcLineNumbers.begin(), funcLineNumbers.end());
    func = "";
    while (getline(tac, line))
    {
        for (auto &it : funcLineNumbers)
        {
            if (quadIndex == it.first)
                func = it.second;
        }
        // cout << line << endl;
        vector<string> words;
        istringstream ss(line);
        string word;
        vector<int> quadRow(4, 0);
        while (ss >> word)
        {
            words.push_back(word);
        }
        if (opCodeTable.count(words[0]))
        { // not an assignment
            quadRow[0] = opCodeTable[words[0]];
            if (words[0] == "out")
            {
                if (words[1][0] == '"')
                {

                    string str;

                    for (int i = 1; i < words.size(); i++)
                    {
                        str += words[i] + " ";
                    }
                    str.pop_back();
                    ds[str] = valueTableIndex++;
                    stringTable[ds[str]] = str;
                    quadRow[1] = ds[str];
                }
                else
                {
                    quadRow[1] = -1;
                    quadRow[2] = ds[func + words[1]];
                }
            }
            else if (words[0] == "call")
            {
                words[1].pop_back();
                if (functionTable.count(words[1]))
                {
                    quadRow[1] = functionTable[words[1]].first - 1;
                    words[2].pop_back();
                    quadRow[2] = stoi(words[2]);
                    if (ds.count(func + words[3]))
                    {
                        quadRow[3] = ds[func + words[3]];
                    }
                    else
                    {
                        cout << "ERROR: " << words[3] << " IS NOT DECLARED" << endl;
                        return;
                    }
                }
                else
                {
                    cout << "FUNCTION ERROR: " << words[1] << " IS NOT DECLARED" << endl;
                    return;
                }
            }
            else if (words[0] == "goto")
            {
                quadRow[1] = stoi(words[1]);
            }
            else if (words[0] == "param")
            {
                if (is_number(words[1]))
                {
                    int num = stoi(words[1]);
                    valueTable[valueTableIndex] = num;
                    ds[func + words[1]] = valueTableIndex++;
                    quadRow[1] = ds[func + words[1]];
                }
                else
                {
                    quadRow[1] = ds[func + words[1]];
                }
            }
            else if (words[0] == "in")
            {
                quadRow[1] = ds[func + words[1]];
            }
            else if (words[0] == "ret")
            {
                if (is_number(words[1]))
                {
                    int num = stoi(words[1]);
                    valueTable[valueTableIndex] = num;
                    ds[func + words[1]] = valueTableIndex++;
                    quadRow[1] = ds[func + words[1]];
                }
                else
                {
                    quadRow[1] = ds[func + words[1]];
                }
            }
            else
            {
                quadRow[1] = ds[func + words[1]];
            }
        }
        else if (words[0] == "if")
        {
            quadRow[0] = opCodeTable[words[2]];
            if (ds.count(func + words[1]))
            {
                quadRow[1] = ds[func + words[1]];
            }
            else
            {
                if (is_number(words[1]))
                {
                    int num = stoi(words[1]);
                    valueTable[valueTableIndex] = num;
                    ds[words[1]] = valueTableIndex++;
                    quadRow[1] = ds[words[1]];
                }
                else
                {
                    cout << "ERROR: " << words[1] << " IS NOT DECLARED" << endl;
                    return;
                }
            }
            if (ds.count(func + words[3]))
            {
                quadRow[2] = ds[func + words[3]];
            }
            else
            {
                if (is_number(words[3]))
                {
                    int num = stoi(words[3]);
                    valueTable[valueTableIndex] = num;
                    ds[words[3]] = valueTableIndex++;
                    quadRow[2] = ds[words[3]];
                }
                else
                {
                    cout << "ERROR: " << words[3] << " IS NOT DECLARED" << endl;
                    return;
                }
            }
            quadRow[3] = stoi(words[5]);
        }
        else
        { // an assignment
            if (ds.count(func + words[0]))
            {
                quadRow[1] = ds[func + words[0]];
            }
            else
            {
                cout << "ERROR: " << words[0] << "IS NOT DECLARED" << endl;
                return;
            }
            if (ds.count(func + words[2]))
            {
                quadRow[2] = ds[func + words[2]];
            }
            else
            {
                if (is_number(words[2]))
                {
                    int num = stoi(words[2]);
                    valueTable[valueTableIndex] = num;
                    ds[words[2]] = valueTableIndex++;
                    quadRow[2] = ds[words[2]];
                }
                else
                {
                    cout << "ERROR: " << words[2] << " IS NOT DECLARED" << endl;
                    return;
                }
            }
            if (words.size() > 3)
            { // assignment of expression
                if (ds.count(func + words[4]))
                {
                    quadRow[3] = ds[func + words[4]];
                }
                else if (is_number(words[4]))
                {
                    int num = stoi(words[4]);
                    valueTable[valueTableIndex] = num;
                    ds[words[4]] = valueTableIndex++;
                    quadRow[3] = ds[words[4]];
                }
                else
                {
                    cout << "ERROR: " << words[4] << " IS NOT DECLARED" << endl;
                    return;
                }
                if (opCodeTable.count(words[3]))
                {
                    quadRow[0] = opCodeTable[words[3]];
                }
                else
                {
                    cout << "ERROR: " << words[3] << " IS NOT A VALID OPERATOR" << endl;
                    return;
                }
            }
            else
            { // simple assignment
                quadRow[0] = opCodeTable[words[1]];
            }
        }
        quad.push_back(quadRow);
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
        stk.push(-1);

        if (!functionTable.count("main"))
        {
            cout << "ERROR: MAIN FUNCTION IS NOT DEFINED" << endl;
            return 0;
        }
        function.push("main");
        executeQuad();
    }
    else // if file name is'nt given
    {
        cout << "Please provide a TAC file name and a symbol table" << endl;
    }
    return 0;
}
