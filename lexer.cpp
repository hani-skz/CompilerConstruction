#include "lexer.h"
#include <algorithm>
using namespace std;
// for printing tokens names, Same as the enum defined in lexer.h
string reserved[] = {
    "END_OF_FILE",
    "ERROR",
    "FUNC",
    "INT",
    "CHAR",
    "CALL",
    "IF",
    "ELIF",
    "ELSE",
    "FOR",
    "PRINT",
    "PRINTLN",
    "RETURN",
    "IN",
    "BEGIN",
    "END",
    "AO",
    "ADD",
    "SUB",
    "MUL",
    "DIV",
    "MOD",
    "EQ",
    "GT",
    "GE",
    "LT",
    "LE",
    "NE",
    "ID",
    "NL",
    "CL",
    "STR",
    "COMM",
    "COMMA",
    "HASH",
    "COLON",
    "SEMICOLON"};
token::token()
{
    this->lexeme = "";
    this->tokenType = TokenType::ERROR;
}
token::token(string lexeme, TokenType tokenType)
{
    this->lexeme = lexeme;
    this->tokenType = tokenType;
}
void token::Print()
{
    cout << "{" << lexeme << " , "
         << reserved[(int)tokenType] << "}\n";
}
int lexer::getCurrentPointer()
{
    return index;
}
void lexer::setCurrentPointer(int pos)
{
    if (pos >= 0 && pos < tokens.size())
        index = pos;
    else
        index = 0;
}
void lexer::Tokenize() // function that tokenizes your input stream
{
    vector<char>::iterator it = stream.begin();
    // your implementation goes here

    // constant state values
    const int INITIAL = 0, FINAL = 69, TRAP = -1, ID = 255, NL = 256, Plus = 257,
              Minus = 258, Multiply = 259, Divide = 260, Mod = 261, LT = 262, GT = 263,
              COMM = 264, AO = 265, EQ = 266, NE = 267, LE = 268, GE = 269, CL = 270, STR = 271;
    // string of keywords for token matching
    vector<string> keywords = {"func",
                               "int",
                               "char",
                               "call",
                               "if",
                               "elif",
                               "else",
                               "for",
                               "print",
                               "println",
                               "return",
                               "in",
                               "begin",
                               "end"};

    int state = INITIAL;
    string lexeme = "";
    vector<string>::iterator tempItr; // used in finding keyword matches
    TokenType tokentype;

    for (it; it != stream.end(); it++)
    {

        char c = *it; // current character

        if ((c == ' ' || c == '\n' || c == '\t') && state == INITIAL) // skip spaces
            continue;

        // DFA
        switch (state)
        {
        case INITIAL:
            // check for single character symbols
            if (c == '+')
            {
                tokentype = TokenType::ADD;
                lexeme = "+";
                state = FINAL;
                it--;
                break;
            }
            if (c == '-')
            {
                tokentype = TokenType::SUB;
                lexeme = "-";
                state = FINAL;
                it--;
                break;
            }
            if (c == '*')
            {
                tokentype = TokenType::MUL;
                lexeme = "*";
                state = FINAL;
                it--;
                break;
            }
            if (c == '/')
            {
                tokentype = TokenType::DIV;
                lexeme = "/";
                state = FINAL;
                it--;
                break;
            }
            if (c == '%')
            {
                tokentype = TokenType::MOD;
                lexeme = "%";
                state = FINAL;
                it--;
                break;
            }
            if (c == ',')
            {
                tokentype = TokenType::COMMA;
                lexeme = ",";
                state = FINAL;
                it--;
                break;
            }
            if (c == ':')
            {
                tokentype = TokenType::COLON;
                lexeme = ":";
                state = FINAL;
                it--;
                break;
            }
            if (c == ';')
            {
                tokentype = TokenType::SEMICOLON;
                lexeme = ";";
                state = FINAL;
                it--;
                break;
            }

            // change state based on type of input
            if (isalpha(c))
                state = 1;
            if (isdigit(c))
                state = 2;
            if (c == '=')
                state = 3;
            if (c == '<')
                state = 4;
            if (c == '>')
                state = 5;
            if (c == '#')
                state = 6;
            if (c == '~')
                state = 7;
            if (c == '\'')
                state = 8;
            if (c == '\"')
                state = 11;
            lexeme += c;
            break;

        // Midway States
        case 1:
            if (isalpha(c)) // Actually it should be if (isalpha(c) || isdigit(c)) inorder to incorporate digits into the identifier name.
                state = 1;
            else
                state = ID;
            lexeme += c;
            break;
        case 2:
            if (isdigit(c))
                state = 2;
            else
                state = NL;
            lexeme += c;
            break;
        case 3:
            state = EQ;
            lexeme += c;
            break;
        case 4:
            if (c == '-')
                state = AO;
            else if (c == '=')
                state = LE;
            else
                state = LT;
            lexeme += c;
            break;
        case 5:
            if (c == '=')
                state = GE;
            else
                state = GT;
            lexeme += c;
            break;
        case 6:
            if (c == '\n')
                state = COMM;
            else
                state = 6;
            lexeme += c;
            break;
        case 7:
            if (c == '=')
                state = NE;
            else
                state = TRAP;
            lexeme += c;
            break;

        case 8:
            state = 9;
            lexeme += c;
            break;
        case 9:
            if (c == '\'')
                state = 10;
            else
                state = TRAP;
            lexeme += c;
            break;
        case 10:
            state = CL;
            lexeme += c;
            break;
        case 11:
            if (c == '\"')
                state = 12;
            else
                state = 11;
            lexeme += c;
            break;
        case 12:
            state = STR;
            lexeme += c;
            break;

        // Second Last States to assign TokenType
        case ID:
            lexeme.pop_back();
            // check for keywords
            // match and give appropriate token type\

            tempItr = find(keywords.begin(), keywords.end(), lexeme);

            if (tempItr != keywords.end())
            {
                tokentype = TokenType(tempItr - keywords.begin() + 2);
            }
            else
            {
                tokentype = TokenType::ID;
            }

            state = FINAL;
            it--;
            it--;
            break;
        case AO:
            tokentype = TokenType::AO;
            state = FINAL;
            it--;
            break;
        case TRAP:
            tokentype = TokenType::ERROR;
            state = FINAL;
            it--;
            break;
        case NE:
            tokentype = TokenType::NE;
            state = FINAL;
            it--;
            break;
        case LE:
            tokentype = TokenType::LE;
            state = FINAL;
            it--;
            break;
        case GE:
            tokentype = TokenType::GE;
            state = FINAL;
            it--;
            break;

        case LT:
            lexeme.pop_back();
            tokentype = TokenType::LT;
            state = FINAL;
            it--;
            it--;
            break;
        case GT:
            lexeme.pop_back();
            tokentype = TokenType::GT;
            state = FINAL;
            it--;
            it--;
            break;
        case NL:
            lexeme.pop_back();
            tokentype = TokenType::NL;
            state = FINAL;
            it--;
            it--;
            break;
        case COMM:
            lexeme.pop_back();
            tokentype = TokenType::COMM;
            state = FINAL;
            it--;
            break;
        case EQ:
            lexeme.pop_back();
            tokentype = TokenType::EQ;
            state = FINAL;
            it--;
            it--;
            break;
        case CL:
            lexeme.pop_back();
            tokentype = TokenType::CL;
            state = FINAL;
            it--;
            it--;
            break;
        case STR:
            lexeme.pop_back();
            tokentype = TokenType::STR;
            state = FINAL;
            it--;
            it--;
            break;

        // Final State to push token
        case FINAL:
            tokens.push_back(token(lexeme, tokentype));
            state = INITIAL;
            lexeme = "";
            break;
        }
    }
    // push_back EOF token at end to identify End of File
    tokens.push_back(token(string(""), TokenType::END_OF_FILE));
}
lexer::lexer(const char filename[])
{
    // constructors: takes file name as an argument and store all
    // the contents of file into the class varible stream
    ifstream fin(filename);
    if (!fin) // if file not found
    {
        cout << "file not found" << endl;
    }
    else
    {
        char byte = 0;
        while (fin.get(byte))
        { // store file contents into stream
            if (byte != '\r')
                stream.push_back(byte);
        }
        stream.push_back(' '); // dummy spaces appended at the end
        stream.push_back(' ');
        // Tokenize function to get all the (token,lexeme) pairs
        Tokenize();
        // assigning tokens to iterator::pointer
        index = 0;
    }
}
lexer::lexer()
{
    index = -1;
}
void lexer::printRaw()
{
    // helper function to print the content of file
    vector<char>::iterator it = stream.begin();
    for (it = stream.begin(); it != stream.end(); it++)
    {
        cout << *it;
    }
    cout << endl;
}
token lexer::getNextToken()
{
    // this function will return single (token,lexeme) pair on each call
    // this is an iterator which is pointing to the beginning of vector of tokens
    token _token;
    if (index == tokens.size())
    {                       // return end of file if
        _token.lexeme = ""; // index is too large
        _token.tokenType = TokenType::END_OF_FILE;
    }
    else
    {
        _token = tokens[index];
        index = index + 1;
    }
    return _token;
}
void lexer::resetPointer()
{
    index = 0;
}
token lexer::peek(int howFar)
{
    if (howFar <= 0)
    { // peeking backward or in place is not allowed
        cout << "LexicalAnalyzer:peek:Error: non positive argument\n";
        exit(-1);
    }

    int peekIndex = index + howFar - 1;
    if (peekIndex > (tokens.size() - 1))
    {                                             // if peeking too far
        return token("", TokenType::END_OF_FILE); // return END_OF_FILE
    }
    else
        return tokens[peekIndex];
}