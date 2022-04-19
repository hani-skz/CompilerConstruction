#ifndef _PARSER_H_
#define _PARSER_H_
#include "lexer.h"
#include <unordered_map>

class parser
{
public:
    lexer _lexer;
    token look;
    string currentScope;
    unordered_map<string, string> symbolTable;

public:
    void syntax_error();
    token expect(TokenType expected_type);
    parser(const char filename[]);
    void readAndPrintAllInput();
    void resetPointer();

    void addSymbol(string id);

    /*Terminal functions goes here use peek and expect*/
    void FUNC();  
    void INT_terminal ();        
    void CHAR_terminal();        
    void CALL ();       
    void IF   ();  
    void ELIF ();      
    void ELSE ();       
    void FOR  ();      
    void PRINT ();     
    void PRINTLN();    
    void RETURN ();    
    void IN   ();
    void BEGIN ();  
    void END  ();   
    void AO  ();    
    void ADD ();       
    void SUB ();   
    void MUL ();    
    void DIV ();    
    void MOD ();    
    void EQ  ();    
    void GT  ();    
    void GE  ();    
    void LT  ();    
    void LE  ();    
    void NE  ();   
    void ID  ();   
    void A   ();  
    void NL  ();   
    void CL  ();    
    void STR  ();   
    void COMMA ();      
    void HASH ();       
    void COLON();       
    void SEMICOLON();   
    void CH ();     
    void NUM();     //->      0 | 1 | 2 | 3 | 4 | 5 | 6 | 7 | 8 | 9


    /*use TokenType:: for token names for example
        expect(TokenType::ASSIGN);   //example function call
      */


    //all your parser function goes here
    void S();              //-> FUNC Datatype ID Parameters COLON BEGIN Statement END S'
    void S_1();             //-> FUNC Datatype ID Parameters COLON BEGIN Statement END S' | ^
    void Parameters();    //  -> ID Datatype Parameters' | ^
    void Parameters_1();    //     -> COMMA ID Datatype Parameters' | ^
    void Datatype();        //-> INT | CHAR
    void Datatype_1();        //-> INT | CHAR | ^

    void Statement();       //-> Declaration_St Statement' | For_St Statement' | Print_St Statement' |
                            //Input_St Statement' | If_St Statement' | Return_St Statement' | Call_St Statement'
    void Statement_1();     //-> Declaration_St Statement' | For_St Statement' | Print_St Statement' |
                            //Input_St Statement' | If_St Statement' | Return_St Statement' | Call_St Statement' | ^

    void Declaration_St();  //-> ID Rest_of_Decl
    void Rest_of_Decl();    //-> Init More_Decl Datatype SEMICOLON 

    void More_Decl();   //-> COMMA ID Init More_Decl | ^
    void Init ();       //  -> AO Value | ^
    void Value();       // -> CL | Expression

    void For_St();          //-> FOR For_Init COMMA Condition COMMA For_Init COLON BEGIN Statement END
    void For_Init();        //-> ID AO Expression

    void If_St();           //-> IF Condition COLON BEGIN Statement END Second_Block
    void Second_Block();    //-> Else_St | Elif_St | ^
    void Else_St();         //-> ELSE COLON BEGIN Statement END
    void Elif_St();         //-> ELIF Condition COLON BEGIN Statement END Second_Block

    void Print_St();        //-> PRINT Print_Param SEMICOLON | PRINTLN Print_Param SEMICOLON
    void Print_Param();     //-> STR | Expression 

    void Return_St();       //-> RETURN Return_Param
    void Return_Param();    //-> Expression | CL

    void Condition();       //-> Expression RelationalOp Expression

    void Expression();      //-> T E'
    void E_1();             //-> ADD T E' | SUB T E' | ^
    void T();               //-> F T'
    void T_1();             //-> MUL F T' | DIV F T' | MOD F T' | ^
    void F();               //-> ID | NL

    void RelationalOp();    //-> EQ | GT | LT | GE | LE | NE

    void Input_St();        //-> IN ID SEMICOLON

    void Call_St();         //-> CALL ID Param_Id SEMICOLON
    void Param_Id();        //-> ID Param_Id' | ^
    void Param_Id_1();      //-> COMMA ID Param_Id' | ^

};
#endif
