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
void parser::ID()
{
    if ((_lexer.peek(1).tokenType == TokenType::ID))
    {
        expect(TokenType::ID);
    }
    else
    {
        syntax_error();
    }
}
void parser::NL()
{
    if ((_lexer.peek(1).tokenType == TokenType::NL))
    {
        expect(TokenType::NL);
    }
    else
    {
        syntax_error();
    }
}
void parser::CL()
{
    if ((_lexer.peek(1).tokenType == TokenType::CL))
    {
        expect(TokenType::CL);
    }
    else
    {
        syntax_error();
    }
}
void parser::STR()
{
    if ((_lexer.peek(1).tokenType == TokenType::STR))
    {
        expect(TokenType::STR);
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
    if(_lexer.peek(1).tokenType == TokenType::ID){
        string funcName = _lexer.peek(1).lexeme;
        currentScope = funcName;
    }
    parser::ID();
    parser::Parameters();
    parser::COLON();
    parser::BEGIN();
    parser::Statement();
    parser::END();
    parser::S_1();
}
// S'-> FUNC Datatype ID Parameters COLON BEGIN Statement END S' | ^
void parser::S_1()
{
    if ((_lexer.peek(1).tokenType == TokenType::FUNC))
    {
        parser::FUNC();
        parser::Datatype();
        if(_lexer.peek(1).tokenType == TokenType::ID){
            string funcName = _lexer.peek(1).lexeme;
            currentScope = funcName;
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
        if(_lexer.peek(1).tokenType == TokenType::ID){
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

    if(_lexer.peek(1).tokenType == TokenType::ID){
        string id = _lexer.peek(1).lexeme;
        addSymbol(id);
    }
    parser::ID();
    parser::Rest_of_Decl();
}
void parser::Rest_of_Decl() //-> Init More_Decl Datatype SEMICOLON
{
    Init();
    More_Decl();
    Datatype_1();
    SEMICOLON();
}
void parser::More_Decl()
{ //-> COMMA ID Int_Init More_Int_Decl | ^
    if (_lexer.peek(1).tokenType == TokenType::COMMA)
    {
        parser::COMMA();
        if(_lexer.peek(1).tokenType == TokenType::ID){
            string id = _lexer.peek(1).lexeme;
            addSymbol(id);
        }
        parser::ID();
        parser::Init();
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
void parser::Init()
{ //  -> AO Expression | ^
    if (_lexer.peek(1).tokenType == TokenType::AO)
    {
        parser::AO();
        parser::Value();
    }
    else
    {
    }
}
void parser::Value()
{ //  -> AO Expression | ^
    if (_lexer.peek(1).tokenType == TokenType::CL)
    {
        parser::CL();
    }
    else if (_lexer.peek(1).tokenType == TokenType::NL || _lexer.peek(1).tokenType == TokenType::ID)
    {
        parser::Expression();
    }
    else
    {
        syntax_error();
    }
}

void parser::For_St()
{ //-> FOR For_Init COMMA Condition COMMA For_Init COLON BEGIN Statement END
    parser::FOR();
    parser::For_Init();
    parser::COMMA();
    parser::Condition();
    parser::COMMA();
    parser::For_Init();
    parser::COLON();
    parser::BEGIN();
    parser::Statement();
    parser::END();
}
void parser::For_Init()
{ //-> ID AO Expression
    parser::ID();
    parser::AO();
    parser::Expression();
}

void parser::If_St()
{ //-> IF Condition COLON BEGIN Statement END Second_Block
    parser::IF();
    parser::Condition();
    parser::COLON();
    parser::BEGIN();
    parser::Statement();
    parser::END();
    parser::Second_Block();
}
void parser::Second_Block()
{ //-> Else_St | Elif_St | ^
    if (_lexer.peek(1).tokenType == TokenType::ELSE)
    {
        parser::Else_St();
    }
    else if (_lexer.peek(1).tokenType == TokenType::ELIF)
    {
        parser::Elif_St();
    }
    else
    {
    }
}
void parser::Else_St()
{ //-> ELSE COLON BEGIN Statement END
    parser::ELSE();
    parser::COLON();
    parser::BEGIN();
    parser::Statement();
    parser::END();
}
void parser::Elif_St()
{ //-> ELIF Condition COLON BEGIN Statement END Second_Block
    parser::ELIF();
    parser::Condition();
    parser::COLON();
    parser::BEGIN();
    parser::Statement();
    parser::END();
    parser::Second_Block();
}

void parser::Print_St()
{ //-> PRINT Print_Param SEMICOLON | PRINTLN Print_Param SEMICOLON
    if (_lexer.peek(1).tokenType == TokenType::PRINT)
    {
        parser::PRINT();
        parser::Print_Param();
        parser::SEMICOLON();
    }
    else if (_lexer.peek(1).tokenType == TokenType::PRINTLN)
    {
        parser::PRINTLN();
        parser::Print_Param();
        parser::SEMICOLON();
    }
    else
    {
        syntax_error();
    }
}

void parser::Print_Param()
{ //-> STR | Expression
    if (_lexer.peek(1).tokenType == TokenType::STR)
    {
        parser::STR();
    }
    else
    {
        parser::Expression();
    }
}
void parser::Return_St()
{ //->
    parser::RETURN();
    parser::Return_Param();
    parser::SEMICOLON();
}
void parser::Return_Param()
{ //-> Expression | CL
    if (_lexer.peek(1).tokenType == TokenType::CL)
    {
        parser::CL();
    }
    else
    {
        parser::Expression();
    }
}
void parser::Condition()
{ //
    parser::Expression();
    parser::RelationalOp();
    parser::Expression();
}

//------------------Expressions------------------------------------------
void parser::Expression()
{
    parser::T();
    parser::E_1();
} //-> T E'
void parser::E_1()
{
    if (_lexer.peek(1).tokenType == TokenType::ADD)
    {
        parser::ADD();
        parser::T();
        parser::E_1();
    }
    if (_lexer.peek(1).tokenType == TokenType::SUB)
    {
        parser::SUB();
        parser::T();
        parser::E_1();
    }
    else
    {
    }
} //-> ADD T E' | SUB T E' | ^
void parser::T()
{
    parser::F();
    parser::T_1();
} //-> F T'
void parser::T_1()
{
    if (_lexer.peek(1).tokenType == TokenType::MUL)
    {
        parser::MUL();
        parser::F();
        parser::T_1();
    }
    if (_lexer.peek(1).tokenType == TokenType::DIV)
    {
        parser::DIV();
        parser::F();
        parser::T_1();
    }
    if (_lexer.peek(1).tokenType == TokenType::MOD)
    {
        parser::MOD();
        parser::F();
        parser::T_1();
    }
    else
    {
    }
} //-> MUL F T' | DIV F T' | MOD F T' | ^
void parser::F()
{
    if (_lexer.peek(1).tokenType == TokenType::ID)
    {
        parser::ID();
    }
    else if (_lexer.peek(1).tokenType == TokenType::NL)
    {
        parser::NL();
    }
    else
    {
        syntax_error();
    }
} //-> ID | NL

void parser::RelationalOp()
{ //-> EQ | GT | LT | GE | LE | NE
    if (_lexer.peek(1).tokenType == TokenType::EQ)
    {
        parser::EQ();
    }
    else if (_lexer.peek(1).tokenType == TokenType::GT)
    {
        parser::GT();
    }
    else if (_lexer.peek(1).tokenType == TokenType::LT)
    {
        parser::LT();
    }
    else if (_lexer.peek(1).tokenType == TokenType::GE)
    {
        parser::GE();
    }
    else if (_lexer.peek(1).tokenType == TokenType::LE)
    {
        parser::LE();
    }
    else if (_lexer.peek(1).tokenType == TokenType::NE)
    {
        parser::NE();
    }
    else
    {
        syntax_error();
    }
}

void parser::Input_St()
{
    parser::IN();
    parser::ID();
    parser::SEMICOLON();

} //-> IN ID SEMICOLON

void parser::Call_St()
{
    parser::CALL();
    parser::ID();
    parser::Param_Id();
    parser::SEMICOLON();

} //-> CALL ID Param_Id SEMICOLON
void parser::Param_Id()
{
    if (_lexer.peek(1).tokenType == TokenType::ID)
    {
        parser::ID();
        parser::Param_Id_1();
    }
    else
    {
    }
} //-> ID Param_Id' | ^
void parser::Param_Id_1()
{
    if (_lexer.peek(1).tokenType == TokenType::COMMA)
    {
        parser::COMMA();
        parser::ID();
        parser::Param_Id_1();
    }
    else
    {
    }
} //-> COMMA ID Param_Id' | ^

void parser::A()
{
    if ((_lexer.peek(1).tokenType == TokenType::CL))
        parser::CL();
    else if ((_lexer.peek(1).tokenType == TokenType::NL))
    {
        parser::NL();
    }
}

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

        // string value;
        // if (_lexer.peek(2).tokenType == TokenType::AO)
        // {
        //     value = _lexer.peek(3).lexeme;
        // }
        // else
        // {
        //     value = "None";
        // }
        string entry = "\n" + id + " " + type + " ";// + value + " ";
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