#include <fstream>
using namespace std;
#include "parser.h"

void parser::syntax_error()
{
    cout << "SYNTAX ERROR\n";
    exit(1);
}
token parser::expect(TokenType expected_type)
{
    token t = _lexer.getNextToken();
    while (t.tokenType == TokenType::COMM)
    {
        t = _lexer.getNextToken();
    }
    if (t.tokenType != expected_type)
        syntax_error();
    return t;
}
parser::parser(const char filename[])
{

    _lexer = lexer(filename);
}
void parser::readAndPrintAllInput() // read and print allinputs (provided)
{
    token t;
    t = _lexer.getNextToken();
    while (t.tokenType != TokenType::END_OF_FILE)
    {
        t.Print();
        t = _lexer.getNextToken();
    }
}
void parser::resetPointer()
{
    _lexer.resetPointer();
}

//----------------------------------------------------------------
/*Terminal functions goes here use peek and expect*/
void parser::FUNC()
{
    // cout<<"Hello Func\n";
    // cout<<"Token: "<<int(_lexer.peek(1).tokenType)<<endl;
    if ((_lexer.peek(1).tokenType == TokenType::FUNC))
    {
        expect(TokenType::FUNC);
        // cout<<"Bye Func\n";
    }
    /*else if(_lexer.peek(1).tokenType == TokenType::COMM){
        parser::expect(TokenType::COMM);
        FUNC();
    }*/
    else
    {
        syntax_error();
    }
}
void parser::INT_terminal()
{
    if ((_lexer.peek(1).tokenType == TokenType::INT))
    {
        expect(TokenType::INT);
    }
    else
    {
        syntax_error();
    }
}
void parser::CHAR_terminal()
{
    if ((_lexer.peek(1).tokenType == TokenType::CHAR))
    {
        expect(TokenType::CHAR);
    }
    else
    {
        syntax_error();
    }
}
void parser::CALL()
{
    if ((_lexer.peek(1).tokenType == TokenType::CALL))
    {
        expect(TokenType::CALL);
    }
    else
    {
        syntax_error();
    }
}
void parser::IF()
{
    if ((_lexer.peek(1).tokenType == TokenType::IF))
    {
        expect(TokenType::IF);
    }
    else
    {
        syntax_error();
    }
}
void parser::ELIF()
{
    if ((_lexer.peek(1).tokenType == TokenType::ELIF))
    {
        expect(TokenType::ELIF);
    }
    else
    {
        syntax_error();
    }
}
void parser::ELSE()
{
    if ((_lexer.peek(1).tokenType == TokenType::ELSE))
    {
        expect(TokenType::ELSE);
    }
    else
    {
        syntax_error();
    }
}
void parser::FOR()
{
    if ((_lexer.peek(1).tokenType == TokenType::FOR))
    {
        expect(TokenType::FOR);
    }
    else
    {
        syntax_error();
    }
}
void parser::PRINT()
{
    if ((_lexer.peek(1).tokenType == TokenType::PRINT))
    {
        expect(TokenType::PRINT);
    }
    else
    {
        syntax_error();
    }
}
void parser::PRINTLN()
{
    if ((_lexer.peek(1).tokenType == TokenType::PRINTLN))
    {
        expect(TokenType::PRINTLN);
    }
    else
    {
        syntax_error();
    }
}
void parser::RETURN()
{
    if ((_lexer.peek(1).tokenType == TokenType::RETURN))
    {
        expect(TokenType::RETURN);
    }
    else
    {
        syntax_error();
    }
}
void parser::IN()
{
    if ((_lexer.peek(1).tokenType == TokenType::IN))
    {
        expect(TokenType::IN);
    }
    else
    {
        syntax_error();
    }
}
void parser::BEGIN()
{
    if ((_lexer.peek(1).tokenType == TokenType::BEGIN))
    {
        expect(TokenType::BEGIN);
    }
    else
    {
        syntax_error();
    }
}
void parser::END()
{
    if ((_lexer.peek(1).tokenType == TokenType::END))
    {
        expect(TokenType::END);
    }
    else
    {
        syntax_error();
    }
}
void parser::AO()
{
    if ((_lexer.peek(1).tokenType == TokenType::AO))
    {
        expect(TokenType::AO);
    }
    else
    {
        syntax_error();
    }
}
void parser::ADD()
{
    if ((_lexer.peek(1).tokenType == TokenType::ADD))
    {
        expect(TokenType::ADD);
    }
    else
    {
        syntax_error();
    }
}
void parser::SUB()
{
    if ((_lexer.peek(1).tokenType == TokenType::SUB))
    {
        expect(TokenType::SUB);
    }
    else
    {
        syntax_error();
    }
}
void parser::MUL()
{
    if ((_lexer.peek(1).tokenType == TokenType::MUL))
    {
        expect(TokenType::MUL);
    }
    else
    {
        syntax_error();
    }
}
void parser::DIV()
{
    if ((_lexer.peek(1).tokenType == TokenType::DIV))
    {
        expect(TokenType::DIV);
    }
    else
    {
        syntax_error();
    }
}
void parser::MOD()
{
    if ((_lexer.peek(1).tokenType == TokenType::MOD))
    {
        expect(TokenType::MOD);
    }
    else
    {
        syntax_error();
    }
}
void parser::EQ()
{
    if ((_lexer.peek(1).tokenType == TokenType::EQ))
    {
        expect(TokenType::EQ);
    }
    else
    {
        syntax_error();
    }
}
void parser::GT()
{
    if ((_lexer.peek(1).tokenType == TokenType::GT))
    {
        expect(TokenType::GT);
    }
    else
    {
        syntax_error();
    }
}
void parser::GE()
{
    if ((_lexer.peek(1).tokenType == TokenType::GE))
    {
        expect(TokenType::GE);
    }
    else
    {
        syntax_error();
    }
}
void parser::LT()
{
    if ((_lexer.peek(1).tokenType == TokenType::LT))
    {
        expect(TokenType::LT);
    }
    else
    {
        syntax_error();
    }
}
void parser::LE()
{
    if ((_lexer.peek(1).tokenType == TokenType::LE))
    {
        expect(TokenType::LE);
    }
    else
    {
        syntax_error();
    }
}
void parser::NE()
{
    if ((_lexer.peek(1).tokenType == TokenType::NE))
    {
        expect(TokenType::NE);
    }
    else
    {
        syntax_error();
    }
}
string parser::ID()
{
    if ((_lexer.peek(1).tokenType == TokenType::ID))
    {
        string lex = _lexer.peek(1).lexeme;
        expect(TokenType::ID);
        return lex;
    }
    else
    {
        syntax_error();
    }
}
string parser::NL()
{
    if ((_lexer.peek(1).tokenType == TokenType::NL))
    {
        string lex = _lexer.peek(1).lexeme;
        expect(TokenType::NL);
        return lex;
    }
    else
    {
        syntax_error();
    }
}
string parser::CL()
{
    if ((_lexer.peek(1).tokenType == TokenType::CL))
    {
        string lex = _lexer.peek(1).lexeme;
        expect(TokenType::CL);
        return lex;
    }
    else
    {
        syntax_error();
    }
}
string parser::STR()
{
    if ((_lexer.peek(1).tokenType == TokenType::STR))
    {
        string lex = _lexer.peek(1).lexeme;
        expect(TokenType::STR);
        return lex;
    }
    else
    {
        syntax_error();
    }
}
void parser::COMMA()
{
    if ((_lexer.peek(1).tokenType == TokenType::COMMA))
    {
        expect(TokenType::COMMA);
    }
    else
    {
        syntax_error();
    }
}
// void parser::HASH ();
void parser::COLON()
{
    if ((_lexer.peek(1).tokenType == TokenType::COLON))
    {
        expect(TokenType::COLON);
    }
    else
    {
        syntax_error();
    }
}
void parser::SEMICOLON()
{
    if ((_lexer.peek(1).tokenType == TokenType::SEMICOLON))
    {
        expect(TokenType::SEMICOLON);
    }
    else
    {
        syntax_error();
    }
}
/*void parser::CH (){
    if( (_lexer.peek(1).tokenType == TokenType::CH)){
        expect(TokenType::CH);
    }
    else{
        syntax_error();
    }
}*/
/*void parser::NUM(){
    if( (_lexer.peek(1).tokenType == TokenType::NUM)){
        expect(TokenType::NUM);
    }
    else{
        syntax_error();
    }
}*/

//---------------------------------------------------------------------
// all your parser function goes here

// S -> FUNC Datatype ID Parameters COLON BEGIN Statement END S'
void parser::S()
{
    parser::FUNC();
    parser::Datatype();
    if (_lexer.peek(1).tokenType == TokenType::ID)
    {
        string funcName = _lexer.peek(1).lexeme;
        currentScope = funcName;
        currentScopeLineNumber = n;
    }
    parser::ID();
    parser::Parameters();
    parser::COLON();
    parser::BEGIN();
    parser::Statement();
    parser::END();
    parser::S_1();
    generateTAC();
}
// S'-> FUNC Datatype ID Parameters COLON BEGIN Statement END S' | ^
void parser::S_1()
{
    if ((_lexer.peek(1).tokenType == TokenType::FUNC))
    {
        parser::FUNC();
        parser::Datatype();
        if (_lexer.peek(1).tokenType == TokenType::ID)
        {
            string funcName = _lexer.peek(1).lexeme;
            currentScope = funcName;
            currentScopeLineNumber = n;
        }
        parser::ID();
        parser::Parameters();
        parser::COLON();
        parser::BEGIN();
        parser::Statement();
        parser::END();
        parser::S_1();
    }
    else
    { // Null
    }
}
// Parameters	-> ID Datatype Parameters' | ^
void parser::Parameters()
{
    if ((_lexer.peek(1).tokenType == TokenType::ID))
    {
        string id = _lexer.peek(1).lexeme;
        addSymbol(id);
        parser::ID();
        parser::Datatype();
        parser::Parameters_1();
    }
    else
    {
    }
}
// Parameters' 	-> COMMA ID Datatype Parameters' | ^

void parser::Parameters_1()
{
    if ((_lexer.peek(1).tokenType == TokenType::COMMA))
    {
        parser::COMMA();
        if (_lexer.peek(1).tokenType == TokenType::ID)
        {
            string id = _lexer.peek(1).lexeme;
            addSymbol(id);
        }
        parser::ID();
        parser::Datatype();
        parser::Parameters_1();
    }
    else
    {
    }
}
// Datatype	-> INT | CHAR
void parser::Datatype()
{
    if ((_lexer.peek(1).tokenType == TokenType::CHAR))
        parser::CHAR_terminal();
    else if ((_lexer.peek(1).tokenType == TokenType::INT))
        parser::INT_terminal();
    else
    {
        syntax_error();
    }
}
// Statement 	-> Declaration_St Statement' | For_St Statement' | Print_St Statement' |
// Input_St Statement ' | If_St Statement' | Return_St Statement ' | Call_St Statement'
void parser::Statement()
{
    if (_lexer.peek(1).tokenType == TokenType::ID)
    {
        Declaration_St();
        Statement_1();
    }
    else if (_lexer.peek(1).tokenType == TokenType::FOR)
    {
        For_St();
        Statement_1();
    }
    else if ((_lexer.peek(1).tokenType == TokenType::PRINT) || ((_lexer.peek(1).tokenType == TokenType::PRINTLN)))
    {
        Print_St();
        Statement_1();
    }
    else if (_lexer.peek(1).tokenType == TokenType::IN)
    {
        Input_St();
        Statement_1();
    }
    else if (_lexer.peek(1).tokenType == TokenType::IF)
    {
        If_St();
        Statement_1();
    }
    else if (_lexer.peek(1).tokenType == TokenType::RETURN)
    {
        Return_St();
        Statement_1();
    }

    else if (_lexer.peek(1).tokenType == TokenType::CALL)
    {
        Call_St();
        Statement_1();
    }
    else
    {
        syntax_error();
    }
}
// Statement' -> Declaration_St Statement' | For_St Statement' | Print_St Statement' |
// Input_St Statement' | If_St Statement' | Return_St Statement' | Call_St Statement' | ^
void parser::Statement_1()
{
    if (_lexer.peek(1).tokenType == TokenType::ID)
    {
        Declaration_St();
        Statement_1();
    }
    else if (_lexer.peek(1).tokenType == TokenType::FOR)
    {
        For_St();
        Statement_1();
    }
    else if ((_lexer.peek(1).tokenType == TokenType::PRINT) || ((_lexer.peek(1).tokenType == TokenType::PRINTLN)))
    {
        Print_St();
        Statement_1();
    }
    else if (_lexer.peek(1).tokenType == TokenType::IN)
    {
        Input_St();
        Statement_1();
    }
    else if (_lexer.peek(1).tokenType == TokenType::IF)
    {
        If_St();
        Statement_1();
    }
    else if (_lexer.peek(1).tokenType == TokenType::RETURN)
    {
        Return_St();
        Statement_1();
    }
    else if (_lexer.peek(1).tokenType == TokenType::CALL)
    {
        Call_St();
        Statement_1();
    }
    else
    {
    }
}
void parser::Declaration_St()
{ //-> ID Rest_of_Decl

    if (_lexer.peek(1).tokenType == TokenType::ID)
    {
        string id = _lexer.peek(1).lexeme;
        addSymbol(id);
    }
    string first_id = parser::ID();
    parser::Rest_of_Decl(first_id);
}
void parser::Rest_of_Decl(string first_id) //-> Init More_Decl Datatype SEMICOLON
{
    Init(first_id);
    More_Decl();
    Datatype_1();
    SEMICOLON();
}
void parser::More_Decl()
{ //-> COMMA ID Int_Init More_Int_Decl | ^
    if (_lexer.peek(1).tokenType == TokenType::COMMA)
    {
        parser::COMMA();
        if (_lexer.peek(1).tokenType == TokenType::ID)
        {
            string id = _lexer.peek(1).lexeme;
            addSymbol(id);
        }
        string id = parser::ID();
        parser::Init(id);
        parser::More_Decl();
    }
    else
    {
    }
}
void parser::Datatype_1()
{
    if ((_lexer.peek(1).tokenType == TokenType::CHAR))
        parser::CHAR_terminal();
    else if ((_lexer.peek(1).tokenType == TokenType::INT))
        parser::INT_terminal();
    else
    {
    }
}
void parser::Init(string id)
{ //  -> AO Expression | ^
    if (_lexer.peek(1).tokenType == TokenType::AO)
    {
        parser::AO();
        string v = parser::Value();
        emit(id + " = " + v);
    }
    else
    {
    }
}
string parser::Value()
{ //  -> AO Expression | ^
    if (_lexer.peek(1).tokenType == TokenType::CL)
    {
        string v = parser::CL();
        return v;
    }
    else if (_lexer.peek(1).tokenType == TokenType::NL || _lexer.peek(1).tokenType == TokenType::ID)
    {
        string v = parser::Expression();
        return v;
    }
    else
    {
        syntax_error();
    }
}

void parser::For_St()
{ //-> FOR For_Init COMMA Condition COMMA For_Init COLON BEGIN Statement END
    parser::FOR();
    string s = parser::For_Init();
    emit(s);
    parser::COMMA();
    int start = n;
    vector<int> v = parser::Condition();
    backpatch(v[0], to_string(n));
    parser::COMMA();
    s = parser::For_Init();
    parser::COLON();
    parser::BEGIN();
    parser::Statement();
    emit(s);
    emit("goto " + to_string(start));
    backpatch(v[1], to_string(n));
    parser::END();
}
string parser::For_Init()
{ //-> ID AO Expression
    string id = parser::ID();
    parser::AO();
    string v = parser::Expression();
    string s = id + " = " + v;
    return s;
}

void parser::If_St()
{ //-> IF Condition COLON BEGIN Statement END Second_Block
    parser::IF();
    vector<int> v = parser::Condition();
    backpatch(v[0], to_string(n));
    parser::COLON();
    parser::BEGIN();
    parser::Statement();
    int next = n;
    emit("goto");
    parser::END();
    parser::Second_Block(v[1]);
    backpatch(next, to_string(n));
}
void parser::Second_Block(int f)
{ //-> Else_St | Elif_St | ^
    if (_lexer.peek(1).tokenType == TokenType::ELSE)
    {
        parser::Else_St(f);
    }
    else if (_lexer.peek(1).tokenType == TokenType::ELIF)
    {
        parser::Elif_St(f);
    }
    else
    {
    }
}
void parser::Else_St(int f)
{ //-> ELSE COLON BEGIN Statement END
    parser::ELSE();
    backpatch(f, to_string(n));
    parser::COLON();
    parser::BEGIN();
    parser::Statement();
    parser::END();
}
void parser::Elif_St(int f)
{ //-> ELIF Condition COLON BEGIN Statement END Second_Block
    parser::ELIF();
    backpatch(f, to_string(n));
    vector<int> v = parser::Condition();
    backpatch(v[0], to_string(n));
    parser::COLON();
    parser::BEGIN();
    parser::Statement();
    int next = n;
    emit("goto");
    parser::END();
    parser::Second_Block(v[1]);
    backpatch(next, to_string(n));
}

void parser::Print_St()
{ //-> PRINT Print_Param SEMICOLON | PRINTLN Print_Param SEMICOLON
    if (_lexer.peek(1).tokenType == TokenType::PRINT)
    {
        parser::PRINT();
        string s = parser::Print_Param();
        parser::SEMICOLON();
        emit("out " + s);
    }
    else if (_lexer.peek(1).tokenType == TokenType::PRINTLN)
    {
        parser::PRINTLN();
        string s = parser::Print_Param();
        parser::SEMICOLON();
        emit("out " + s + "\n");
    }
    else
    {
        syntax_error();
    }
}

string parser::Print_Param()
{ //-> STR | Expression
    if (_lexer.peek(1).tokenType == TokenType::STR)
    {
        string s = parser::STR();
        return s;
    }
    else
    {
        string s = parser::Expression();
        return s;
    }
}
void parser::Return_St()
{ //->
    parser::RETURN();
    string v = parser::Return_Param();
    parser::SEMICOLON();
    emit("ret " + v);
}
string parser::Return_Param()
{ //-> Expression | CL
    if (_lexer.peek(1).tokenType == TokenType::CL)
    {
        string lex = parser::CL();
        return lex;
    }
    else
    {
        string v = parser::Expression();
        return v;
    }
}
vector<int> parser::Condition()
{ //
    vector<int> v;

    string s1 = parser::Expression();
    string op = parser::RelationalOp();
    string s2 = parser::Expression();
    v.push_back(n);
    emit("if " + s1 + " " + op + " " + s2 + " goto");
    v.push_back(n);
    emit("goto");
    return v;
}

//------------------Expressions------------------------------------------
string parser::Expression()
{
    string s1 = parser::T();
    string s2 = parser::E_1(s1);
    cout << s2 << endl;
    return s2;
} //-> T E'
string parser::E_1(string s0)
{
    if (_lexer.peek(1).tokenType == TokenType::ADD)
    {
        parser::ADD();
        string s1 = parser::T();
        string s2 = parser::E_1(s1);
        string newVar = newTmp();
        string s3 = (newVar + " = " + s0 + "+" + s1);
        emit(s3);
        return newVar;
    }
    if (_lexer.peek(1).tokenType == TokenType::SUB)
    {
        parser::SUB();
        string s1 = parser::T();
        string s2 = parser::E_1(s1);
        string newVar = newTmp();
        string s3 = (newVar + " = " + s0 + "-" + s1);
        emit(s3);
        return newVar;
    }
    else
    {
        return "";
    }
} //-> ADD T E' | SUB T E' | ^
string parser::T()
{
    string s1 = parser::F();
    string s2 = parser::T_1(s1);
    return s1;
} //-> F T'
string parser::T_1(string s0)
{
    if (_lexer.peek(1).tokenType == TokenType::MUL)
    {
        parser::MUL();
        string s1 = parser::F();
        string s2 = parser::T_1(s1);
        string newVar = newTmp();
        string s3 = (newVar + " = " + s0 + "*" + s1);
        emit(s3);

        return newVar;
    }
    if (_lexer.peek(1).tokenType == TokenType::DIV)
    {
        parser::DIV();
        string s1 = parser::F();
        string s2 = parser::T_1(s1);
        string newVar = newTmp();
        string s3 = (newVar + " = " + s0 + "/" + s1);
        emit(s3);
        return newVar;
    }
    if (_lexer.peek(1).tokenType == TokenType::MOD)
    {
        parser::MOD();
        string s1 = parser::F();
        string s2 = parser::T_1(s1);
        string newVar = newTmp();
        string s3 = (newVar + "=" + s0 + "%" + s1);
        emit(s3);
        return newVar;
    }
    else
    {
        return "";
    }
} //-> MUL F T' | DIV F T' | MOD F T' | ^
string parser::F()
{
    if (_lexer.peek(1).tokenType == TokenType::ID)
    {
        string lex = parser::ID();
        return lex;
    }
    else if (_lexer.peek(1).tokenType == TokenType::NL)
    {
        string lex = parser::NL();
        return lex;
    }
    else
    {
        syntax_error();
    }
} //-> ID | NL

string parser::RelationalOp()
{ //-> EQ | GT | LT | GE | LE | NE
    if (_lexer.peek(1).tokenType == TokenType::EQ)
    {
        parser::EQ();
        return "==";
    }
    else if (_lexer.peek(1).tokenType == TokenType::GT)
    {
        parser::GT();
        return ">";
    }
    else if (_lexer.peek(1).tokenType == TokenType::LT)
    {
        parser::LT();
        return "<";
    }
    else if (_lexer.peek(1).tokenType == TokenType::GE)
    {
        parser::GE();
        return ">=";
    }
    else if (_lexer.peek(1).tokenType == TokenType::LE)
    {
        parser::LE();
        return "<=";
    }
    else if (_lexer.peek(1).tokenType == TokenType::NE)
    {
        parser::NE();
        return "~=";
    }
    else
    {
        syntax_error();
    }
}

void parser::Input_St()
{
    parser::IN();
    string lex = parser::ID();
    parser::SEMICOLON();
    emit("in " + lex);

} //-> IN ID SEMICOLON

void parser::Call_St()
{
    parser::CALL();
    string s3 = parser::ID();
    int s4 = parser::Param_Id();
    parser::SEMICOLON();
    string newVar = newTmp();
    string s1 = ("call" + s3 + "," + to_string(s4) + newVar);
    emit(s1);
    // return s1;

} //-> CALL ID Param_Id SEMICOLON
int parser::Param_Id()
{
    if (_lexer.peek(1).tokenType == TokenType::ID)
    {
        string lex = parser::ID();
        emit("param " + lex);
        int c = parser::Param_Id_1();
        return c + 1;
    }
    else
    {
        int c = 0;
        return c;
    }
} //-> ID Param_Id' | ^
int parser::Param_Id_1()
{
    if (_lexer.peek(1).tokenType == TokenType::COMMA)
    {
        parser::COMMA();
        string lex = parser::ID();
        emit("param " + lex);
        int c = parser::Param_Id_1();
        return c + 1;
    }
    else
    {
        int c = 0;
        return c;
    }
} //-> COMMA ID Param_Id' | ^

// this function is for sample purposes only
/*
void parser::statements()
{
    //statements-- > COLON LPAREN start RPAREN
    if (_lexer.peek(1).tokenType == TokenType::COLON)
    {
        expect(TokenType::COLON);
        if (_lexer.peek(1).tokenType == TokenType::LPAREN)
        {
            expect(TokenType::LPAREN);
            start();
            if (_lexer.peek(1).tokenType == TokenType::RPAREN)
            {
                expect(TokenType::RPAREN);
                return true;
            }
        }
    }
    return false;
}*/

void parser::addSymbol(string id)
{
    string symbols = "";
    if (symbolTable.find(currentScope) != symbolTable.end())
    {
        symbols = symbolTable[currentScope];
    }
    else
    {
        symbolTable[currentScope] = "";
    }

    if (symbols.find("\n" + id + " ") == string::npos)
    {
        string type;
        int i = 1;
        while (_lexer.peek(i).tokenType != TokenType::INT && _lexer.peek(i).tokenType != TokenType::CHAR && _lexer.peek(i).tokenType != TokenType::END_OF_FILE)
            i++;

        if (_lexer.peek(i).tokenType == TokenType::INT)
        {
            type = "INT";
        }
        else if (_lexer.peek(i).tokenType == TokenType::CHAR)
        {
            type = "CHAR";
        }
        else
        {
            cout << "Missing datatype for: " << id << endl;
            syntax_error();
        }

        string value;
        if (_lexer.peek(2).tokenType == TokenType::AO)
        {
            value = _lexer.peek(3).lexeme;
        }
        else
        {
            value = "NULL";
        }
        string entry = "\n" + id + " " + type + " " + value + " ";
        symbolTable[currentScope] += entry;
        ofstream table;
        table.open("symbol_table.txt", ios_base::trunc);
        unordered_map<string, string>::iterator itr;
        for (itr = symbolTable.begin(); itr != symbolTable.end(); itr++)
        {
            table << itr->first << ":" << itr->second << endl;
        }
        table.close();
    }
}

void parser::emit(string s)
{
    TAC.push_back(to_string(n) + " " + s);
    n++;
}

void parser::backpatch(int n, string s)
{
    TAC[n - 1] += (" " + s);
}

string parser::newTmp()
{
    addSymboltmp("tmp" + to_string(tmp));
    return ("tmp" + to_string(tmp));
    tmp++;
}

void parser::addSymboltmp(string id)
{
    string symbols = "";
    if (symbolTable.find(currentScope) != symbolTable.end())
    {
        symbols = symbolTable[currentScope];
    }
    else
    {
        symbolTable[currentScope] = "Address: " + to_string(currentScopeLineNumber);
    }

    if (symbols.find("\n" + id + " ") == string::npos)
    {
        string type = "INT"; // not needed
        string value = "NULL";
        string entry = "\n" + id + " " + type + " " + value + " ";
        symbolTable[currentScope] += entry;
        ofstream table;
        table.open("symbol_table.txt", ios_base::trunc);
        unordered_map<string, string>::iterator itr;
        for (itr = symbolTable.begin(); itr != symbolTable.end(); itr++)
        {
            table << itr->first << ":" << itr->second << endl;
        }
        table.close();
    }
}

void parser::generateTAC()
{
    ofstream tac;
    tac.open("TAC.txt", ios_base::trunc);
    for (int i = 0; i < TAC.size(); i++)
    {
        tac << TAC[i] << endl;
    }
    tac.close();
}