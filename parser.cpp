#include "parser.h"
//#include "lexer.h"

void parser::syntax_error()
{
    cout << "SYNTAX ERROR\n";
    exit(1);
}
token parser::expect(TokenType expected_type)
{
    token t = _lexer.getNextToken();
    while (t.tokenType == TokenType::COMM){
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
void parser::readAndPrintAllInput() //read and print allinputs (provided)
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
    void parser::FUNC(){
        //cout<<"Hello Func\n";
        //cout<<"Token: "<<int(_lexer.peek(1).tokenType)<<endl;
        if( (_lexer.peek(1).tokenType == TokenType::FUNC)||(_lexer.peek(1).tokenType == TokenType::COMM)){
            expect(TokenType::FUNC);
            //cout<<"Bye Func\n";
        }
        /*else if(_lexer.peek(1).tokenType == TokenType::COMM){
            parser::expect(TokenType::COMM);
            FUNC();
        }*/
        else{
            syntax_error();
        }
    } 
    void parser::INT_terminal (){
        if( (_lexer.peek(1).tokenType == TokenType::INT)||(_lexer.peek(1).tokenType == TokenType::COMM)){
            expect(TokenType::INT);
        }
        else{
            syntax_error();
        }

    }        
    void parser::CHAR_terminal(){
        if( (_lexer.peek(1).tokenType == TokenType::CHAR)||(_lexer.peek(1).tokenType == TokenType::COMM)){
            expect(TokenType::CHAR);
        }
        else{
            syntax_error();
        }
    }        
    void parser::CALL (){
        if( (_lexer.peek(1).tokenType == TokenType::CALL)||(_lexer.peek(1).tokenType == TokenType::COMM)){
            expect(TokenType::CALL);
        }
        else{
            syntax_error();
        }
    }       
    void parser::IF(){
        if( (_lexer.peek(1).tokenType == TokenType::IF)||(_lexer.peek(1).tokenType == TokenType::COMM)){
            expect(TokenType::IF);
        }
        else{
            syntax_error();
        }
    }  
    void parser::ELIF (){
        if( (_lexer.peek(1).tokenType == TokenType::ELIF)||(_lexer.peek(1).tokenType == TokenType::COMM)){
            expect(TokenType::ELIF);
        }
        else{
            syntax_error();
        }
    }     
    void parser::ELSE (){
        if( (_lexer.peek(1).tokenType == TokenType::ELSE)||(_lexer.peek(1).tokenType == TokenType::COMM)){
            expect(TokenType::ELSE);
        }
        else{
            syntax_error();
        }
    }       
    void parser::FOR  () {
        if( (_lexer.peek(1).tokenType == TokenType::FOR)||(_lexer.peek(1).tokenType == TokenType::COMM)){
            expect(TokenType::FOR);
        }
        else{
            syntax_error();
        }
    }     
    void parser::PRINT (){
        if( (_lexer.peek(1).tokenType == TokenType::PRINT)||(_lexer.peek(1).tokenType == TokenType::COMM)){
            expect(TokenType::PRINT);
        }
        else{
            syntax_error();
        }
    }     
    void parser::PRINTLN(){
        if( (_lexer.peek(1).tokenType == TokenType::PRINTLN)||(_lexer.peek(1).tokenType == TokenType::COMM)){
            expect(TokenType::PRINTLN);
        }
        else{
            syntax_error();
        }
    }    
    void parser::RETURN (){
        if( (_lexer.peek(1).tokenType == TokenType::RETURN)||(_lexer.peek(1).tokenType == TokenType::COMM)){
            expect(TokenType::RETURN);
        }
        else{
            syntax_error();
        }
    }    
    void parser::IN   (){
        if( (_lexer.peek(1).tokenType == TokenType::IN)||(_lexer.peek(1).tokenType == TokenType::COMM)){
            expect(TokenType::IN);
        }
        else{
            syntax_error();
        }
    }
    void parser::BEGIN (){
        if( (_lexer.peek(1).tokenType == TokenType::BEGIN)||(_lexer.peek(1).tokenType == TokenType::COMM)){
            expect(TokenType::BEGIN);
        }
        else{
            syntax_error();
        }
    } 
    void parser::END  (){
        if( (_lexer.peek(1).tokenType == TokenType::END)||(_lexer.peek(1).tokenType == TokenType::COMM)){
            expect(TokenType::END);
        }
        else{
            syntax_error();
        }
    }   
    void parser::AO  (){
        if( (_lexer.peek(1).tokenType == TokenType::AO)||(_lexer.peek(1).tokenType == TokenType::COMM)){
            expect(TokenType::AO);
        }
        else{
            syntax_error();
        }
    }  
    void parser::ADD (){
        if( (_lexer.peek(1).tokenType == TokenType::ADD)||(_lexer.peek(1).tokenType == TokenType::COMM)){
            expect(TokenType::ADD);
        }
        else{
            syntax_error();
        }
    }     
    void parser::SUB (){
        if( (_lexer.peek(1).tokenType == TokenType::SUB)||(_lexer.peek(1).tokenType == TokenType::COMM)){
            expect(TokenType::SUB);
        }
        else{
            syntax_error();
        }
    }  
    void parser::MUL (){
        if( (_lexer.peek(1).tokenType == TokenType::MUL)||(_lexer.peek(1).tokenType == TokenType::COMM)){
            expect(TokenType::MUL);
        }
        else{
            syntax_error();
        }
    }    
    void parser::DIV (){
        if( (_lexer.peek(1).tokenType == TokenType::DIV)||(_lexer.peek(1).tokenType == TokenType::COMM)){
            expect(TokenType::DIV);
        }
        else{
            syntax_error();
        }
    }    
    void parser::MOD (){
        if( (_lexer.peek(1).tokenType == TokenType::MOD)||(_lexer.peek(1).tokenType == TokenType::COMM)){
            expect(TokenType::MOD);
        }
        else{
            syntax_error();
        }
    }    
    void parser::EQ  (){
        if( (_lexer.peek(1).tokenType == TokenType::EQ)||(_lexer.peek(1).tokenType == TokenType::COMM)){
            expect(TokenType::EQ);
        }
        else{
            syntax_error();
        }
    }    
    void parser::GT  (){
        if( (_lexer.peek(1).tokenType == TokenType::GT)||(_lexer.peek(1).tokenType == TokenType::COMM)){
            expect(TokenType::GT);
        }
        else{
            syntax_error();
        }
    }    
    void parser::GE  (){
        if( (_lexer.peek(1).tokenType == TokenType::GE)||(_lexer.peek(1).tokenType == TokenType::COMM)){
            expect(TokenType::GE);
        }
        else{
            syntax_error();
        }
    }    
    void parser::LT  (){
        if( (_lexer.peek(1).tokenType == TokenType::LT)||(_lexer.peek(1).tokenType == TokenType::COMM)){
            expect(TokenType::LT);
        }
        else{
            syntax_error();
        }
    }    
    void parser::LE  (){
        if( (_lexer.peek(1).tokenType == TokenType::LE)||(_lexer.peek(1).tokenType == TokenType::COMM)){
            expect(TokenType::LE);
        }
        else{
            syntax_error();
        }
    }    
    void parser::NE  (){
        if( (_lexer.peek(1).tokenType == TokenType::NE)||(_lexer.peek(1).tokenType == TokenType::COMM)){
            expect(TokenType::NE);
        }
        else{
            syntax_error();
        }
    }   
    void parser::ID  (){
        if( (_lexer.peek(1).tokenType == TokenType::ID)||(_lexer.peek(1).tokenType == TokenType::COMM)){
            expect(TokenType::ID);
        }
        else{
            syntax_error();
        }
    }    
    void parser::NL  (){
        if( (_lexer.peek(1).tokenType == TokenType::NL)||(_lexer.peek(1).tokenType == TokenType::COMM)){
            expect(TokenType::NL);
        }
        else{
            syntax_error();
        }
    }   
    void parser::CL  (){
        if( (_lexer.peek(1).tokenType == TokenType::CL)||(_lexer.peek(1).tokenType == TokenType::COMM)){
            expect(TokenType::CL);
        }
        else{
            syntax_error();
        }
    }    
    void parser::STR  (){
        if( (_lexer.peek(1).tokenType == TokenType::STR)||(_lexer.peek(1).tokenType == TokenType::COMM)){
            expect(TokenType::STR);
        }
        else{
            syntax_error();
        }
    }   
    void parser::COMMA (){
        if( (_lexer.peek(1).tokenType == TokenType::COMMA)||(_lexer.peek(1).tokenType == TokenType::COMM)){
            expect(TokenType::STR);
        }
        else{
            syntax_error();
        }
    }      
    //void parser::HASH ();       
    void parser::COLON(){
        if( (_lexer.peek(1).tokenType == TokenType::COLON)||(_lexer.peek(1).tokenType == TokenType::COMM)){
            expect(TokenType::COLON);
        }
        else{
            syntax_error();
        }
    }       
    void parser::SEMICOLON(){
        if( (_lexer.peek(1).tokenType == TokenType::SEMICOLON)||(_lexer.peek(1).tokenType == TokenType::COMM)){
            expect(TokenType::SEMICOLON);
        }
        else{
            syntax_error();
        }
    }  
    /*void parser::CH (){
        if( (_lexer.peek(1).tokenType == TokenType::CH)||(_lexer.peek(1).tokenType == TokenType::COMM)){
            expect(TokenType::CH);
        }
        else{
            syntax_error();
        }
    }*/     
    /*void parser::NUM(){
        if( (_lexer.peek(1).tokenType == TokenType::NUM)||(_lexer.peek(1).tokenType == TokenType::COMM)){
            expect(TokenType::NUM);
        }
        else{
            syntax_error();
        }
    }*/  

//---------------------------------------------------------------------
//all your parser function goes here
    void parser::S(){
        cout<<"Init State\n";
        parser::FUNC(); parser::Datatype(); parser::ID(); parser::Parameters(); parser::COLON(); 
        parser::BEGIN();parser::Statement(); parser::END(); parser::S_1();
    }
    void parser::S_1(){
        if( (_lexer.peek(1).tokenType == TokenType::FUNC)||(_lexer.peek(1).tokenType == TokenType::COMM)){
            parser::FUNC(); parser::Datatype(); parser::ID(); parser::Parameters(); parser::COLON(); 
            parser::BEGIN();parser::Statement(); parser::END(); parser::S_1();
        }
        else{//Null

        }
    }             
    
    void parser::Parameters(){
        if( (_lexer.peek(1).tokenType == TokenType::ID)||(_lexer.peek(1).tokenType == TokenType::COMM)){
            parser::ID(); parser::Datatype(); parser::Parameters_1();
        }
        else{

        }

    }    //  -> ID Datatype Parameters' | ^
    void parser::Parameters_1(){
        if( (_lexer.peek(1).tokenType == TokenType::COMMA)||(_lexer.peek(1).tokenType == TokenType::COMM)){
            parser::COMMA();parser::ID(); parser::Datatype(); parser::Parameters_1();
        }
        else{
            
        }
    }    //     -> COMMA ID Datatype Parameters' | ^
    void parser::Datatype(){
        if( (_lexer.peek(1).tokenType == TokenType::CHAR)||(_lexer.peek(1).tokenType == TokenType::COMM))
            parser::CHAR_terminal();
        else 
            parser::INT_terminal();
    }       
    
    void parser::Statement(){       //-> Declaration_St Statement' | For_St Statement' | Print_St Statement' |
                            //Input_St Statement' | If_St Statement' | Return_St Statement' | Call_St Statement'
        cout<<"Hello Statement\n";
        if(_lexer.peek(1).tokenType == TokenType::ID){
            Declaration_St(); Statement_1();
        }
        else if(_lexer.peek(1).tokenType == TokenType::FOR){
            For_St(); Statement_1();
        }
        else if((_lexer.peek(1).tokenType == TokenType::PRINT)||((_lexer.peek(1).tokenType == TokenType::PRINTLN))) {
            Print_St(); Statement_1();
        }
        else if(_lexer.peek(1).tokenType == TokenType::IN){
            Input_St();
            Statement_1();
        }
        else if(_lexer.peek(1).tokenType == TokenType::IF){
            If_St();
            Statement_1();
        }
        else if(_lexer.peek(1).tokenType == TokenType::RETURN){
            Return_St();
            Statement_1();
        }
        else if(_lexer.peek(1).tokenType == TokenType::COMM){
            cout<<"Comment\n";
            look = _lexer.getNextToken();
            Statement();
        }
        else//(_lexer.peek(1).tokenType == TokenType::CALL)
        {
            Call_St();
            Statement_1();
        }
    }
    void parser::Statement_1()     //-> Declaration_St Statement' | For_St Statement' | Print_St Statement' |
                            //Input_St Statement' | If_St Statement' | Return_St Statement' | Call_St Statement' | ^
    {
        cout<<"Hello Statement-1\n";
        if(_lexer.peek(1).tokenType == TokenType::ID){
            Declaration_St(); Statement_1();
        }
        else if(_lexer.peek(1).tokenType == TokenType::FOR){
            For_St(); Statement_1();
        }
        else if((_lexer.peek(1).tokenType == TokenType::PRINT)||((_lexer.peek(1).tokenType == TokenType::PRINTLN))) {
            Print_St(); Statement_1();
        }
        else if(_lexer.peek(1).tokenType == TokenType::IN){
            Input_St();
            Statement_1();
        }
        else if(_lexer.peek(1).tokenType == TokenType::IF){
            If_St();
            Statement_1();
        }
        else if(_lexer.peek(1).tokenType == TokenType::RETURN){
            Return_St();
            Statement_1();
        }
        else if(_lexer.peek(1).tokenType == TokenType::COMM){
            cout<<"Comment\n";
            look = _lexer.getNextToken();
            Statement_1();
        }
        else if(_lexer.peek(1).tokenType == TokenType::CALL){
            Call_St();
            Statement_1();
        }
    }
    void parser::Declaration_St(){  //-> ID Rest_of_Decl
        cout<<"Hello Decl"<<endl;
        parser::ID();
        parser::Rest_of_Decl();
    }
    void parser::Rest_of_Decl()    //-> Int_Init More_Int_Decl INT SEMICOLON | Char_Init More_Char_Decl CHAR SEMICOLON
    {
        if(_lexer.peek(2).tokenType == TokenType::CL){
            Char_Init(); More_Char_Decl(); CHAR_terminal();SEMICOLON(); 
        }
        else{
            Int_Init(); More_Int_Decl(); parser::INT_terminal(); SEMICOLON();   
        }
    }
    void parser::More_Int_Decl(){   //-> COMMA ID Int_Init More_Int_Decl | ^
        if(_lexer.peek(1).tokenType == TokenType::COMMA){
            parser::COMMA(); parser::ID(); 
            parser::Int_Init(); parser::More_Int_Decl();
        }
    }
    void parser::More_Char_Decl(){  //-> COMMA ID Char_Init More_Char_Decl | ^
        if(_lexer.peek(1).tokenType == TokenType::COMMA){
            parser::COMMA(); parser::ID(); 
            parser::Char_Init(); parser::More_Char_Decl();
        }
    }
    void parser::Int_Init (){       //  -> AO Expression | ^
        if(_lexer.peek(1).tokenType == TokenType::AO){
            parser::AO();
            parser::Expression(); 
        }
    }
    void parser::Char_Init(){       //-> AO CL | ^
        if(_lexer.peek(1).tokenType == TokenType::AO){
            parser::AO(); 
            parser::CL();
        }
    }

    void parser::For_St(){          //-> FOR For_Init COMMA Condition COMMA For_Init COLON BEGIN Statement END
        parser::FOR ();
        parser::For_Init(); parser::COMMA(); 
        parser::Condition(); parser::COMMA(); 
        parser::For_Init(); parser::COLON(); 
        parser::BEGIN(); parser::Statement(); parser::END();
    }
    void parser::For_Init(){        //-> ID AO Expression
        parser::ID();  parser::AO();  parser::Expression(); 
    }

    void parser::If_St(){           //-> IF Condition COLON BEGIN Statement END Second_Block
        cout<<"Hello If\n";
        parser::IF(); 
        parser::Condition(); 
        parser::COLON(); parser::BEGIN(); 
        parser::Statement(); parser::END(); parser::Second_Block();
        cout<<"Bye If\n";
    }
    void parser::Second_Block(){    //-> Else_St | Elif_St | ^
        if(_lexer.peek(1).tokenType == TokenType::ELSE){
            parser::Else_St();
        }
        else if(_lexer.peek(1).tokenType == TokenType::ELIF){
            parser::Elif_St();
        }
    }
    void parser::Else_St(){         //-> ELSE COLON BEGIN Statement END
        parser::ELSE(); parser::COLON(); parser::BEGIN(); 
        parser::Statement(); parser::END();
    }
    void parser::Elif_St(){         //-> ELIF Condition COLON BEGIN Statement END Second_Block
        parser::ELIF(); 
        parser::Condition(); parser::COLON(); parser::BEGIN(); 
        parser::Statement(); parser::END(); parser::Second_Block();
    }

    void parser::Print_St(){        //-> PRINT Print_Param SEMICOLON | PRINTLN Print_Param SEMICOLON
        if(_lexer.peek(1).tokenType == TokenType::PRINT){
            parser::PRINT(); parser::Print_Param(); parser::SEMICOLON(); 
        }
        else{
            parser::PRINTLN(); parser::Print_Param(); parser::SEMICOLON();
        }
    }
    void parser::Print_Param(){     //-> STR | Expression 
        if(_lexer.peek(1).tokenType == TokenType::STR){
            parser::STR();
        }
        else{
            parser::Expression();
        }
    }
    void parser::Return_St(){       //-> 
        parser::RETURN();
        parser::Return_Param();
    }
    void parser::Return_Param(){    //-> Expression | CL
        if(_lexer.peek(1).tokenType == TokenType::CL){
            parser::CL();
        }
        else{
            parser::Expression();
        }

    }
    void parser::Condition(){       //
        parser::Expression();
        parser::RelationalOp();
        parser::Expression();
    }

        //------------------Expressions------------------------------------------
    void parser::Expression(){
        parser::T();
        parser::E_1();
    }      //-> T E'
    void parser::E_1(){
        if(_lexer.peek(1).tokenType == TokenType::ADD){
            parser::ADD();
            parser::T();
            parser::E_1();
        }
        if(_lexer.peek(1).tokenType == TokenType::SUB){
            parser::SUB();
            parser::T();
            parser::E_1();
        }
    }             //-> ADD T E' | SUB T E' | ^
    void parser::T(){
        parser::F();
        parser::T_1();
    }               //-> F T'
    void parser::T_1(){
        if(_lexer.peek(1).tokenType == TokenType::MUL){
            parser::MUL();
            parser::F();
            parser::T_1();
        }
        if(_lexer.peek(1).tokenType == TokenType::DIV){
            parser::DIV();
            parser::F();
            parser::T_1();
        }
        if(_lexer.peek(1).tokenType == TokenType::MOD){
            parser::MOD();
            parser::F();
            parser::T_1();
        }
    }             //-> MUL F T' | DIV F T' | MOD F T' | ^
    void parser::F(){
        if(_lexer.peek(1).tokenType == TokenType::ID){
            parser::ID();
        }
        else{
            parser::NL();
        }
    }               //-> ID | NL

    void parser::RelationalOp() {   //-> EQ | GT | LT | GE | LE | NE
        if(_lexer.peek(1).tokenType == TokenType::EQ){
            parser::EQ();
        }
        if(_lexer.peek(1).tokenType == TokenType::GT){
            parser::GT();
        }
        if(_lexer.peek(1).tokenType == TokenType::LT){
            parser::LT();
        }
        if(_lexer.peek(1).tokenType == TokenType::GE){
            parser::GE();
        }
        if(_lexer.peek(1).tokenType == TokenType::LE){
            parser::LE();
        }
        if(_lexer.peek(1).tokenType == TokenType::NE){
            parser::NE();
        }
    }

    void parser::Input_St(){
        cout<<"Input_St\n";
        parser::IN();
        parser::ID();
        parser::SEMICOLON();
        cout<<"Bye Input_St\n";

    }        //-> IN ID SEMICOLON

    void parser::Call_St(){
        parser::CALL();
        parser::ID();
        parser::Param_Id();
        parser::SEMICOLON();

    }         //-> CALL ID Param_Id SEMICOLON
    void parser::Param_Id(){
        if(_lexer.peek(1).tokenType == TokenType::ID){
            parser::ID();
            parser::Parameters_1();
        }
    }        //-> ID Param_Id' | ^
    void parser::Param_Id_1(){
        if(_lexer.peek(1).tokenType == TokenType::COMMA){
            parser::COMMA();
            parser::ID();
            parser::Parameters_1();
        }
    }      //-> COMMA ID Param_Id' | ^
    void parser::A   (){
        if( (_lexer.peek(1).tokenType == TokenType::CL))
            parser::CL();
        else if ( (_lexer.peek(1).tokenType == TokenType::NL)){
            parser::NL();
        }
    } 
    

//this function is for sample purposes only
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