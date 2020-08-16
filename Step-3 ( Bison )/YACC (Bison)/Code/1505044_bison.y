%{
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <vector>
#include <string>
#include <limits>
#include "1505044symbolTable.h"


using namespace std;
int yyparse(void);
int yylex(void);
extern FILE *yyin;
SymbolTable symbltable(13);
string vtype;
extern int line_count;
int errors=0;
int argnum = 0;
vector<string>argvalue;
vector<SymbolInfo>parameter; 
ofstream logout, errorout;

void yyerror(const char *s)
{
	printf("%d --- > %s\n",line_count,s);
}

%}

%union{
SymbolInfo* symbolVal;
}


%token <symbolVal>ID
%token <symbolVal>CONST_INT
%token <symbolVal>CONST_FLOAT
%token <symbolVal>CONST_CHAR
%token <symbolVal>ADDOP
%token <symbolVal>MULOP
%token <symbolVal>LOGICOP
%token <symbolVal>RELOP
%token COMMENT IF ELSE FOR WHILE DO BREAK CONTINUE INT FLOAT CHAR DOUBLE VOID RETURN SWITCH CASE DEFAULT INCOP DECOP ASSIGNOP LPAREN RPAREN LCURL RCURL LTHIRD RTHIRD SEMICOLON COMMA STRING NOT PRINTLN BITOP 

%type <symbolVal>type_specifier expression logic_expression rel_expression simple_expression term unary_expression factor variable

%nonassoc second_precedence
%nonassoc ELSE
%error-verbose
%%

start : program { 

			logout<<"At line "<<line_count<<" : start : program\n"<< endl;
		}
		;

program : program unit
		{
			logout<<"At line "<<line_count<<" : program : program unit\n"<< endl;
		}
		
	| unit
		{
			logout<<"At line "<<line_count<<" : program : unit\n"<< endl;
		}		
		;

unit : var_declaration
		{
			logout<<"At line "<<line_count<<" unit : var_declaration\n"<< endl;	
		}
		
    	| func_declaration
		{	
			logout<<"At line "<<line_count<<" unit : func_declaration\n"<< endl;
		}	
			
     	| func_definition
		{
			logout<<"At line "<<line_count<<" unit : func_definition\n"<< endl;
		}
		;	

func_declaration : 	type_specifier ID LPAREN parameter_list RPAREN SEMICOLON
					{
						logout<<"At Line "<<line_count<<" : func_declaration : 	type_specifier ID LPAREN parameter_list RPAREN SEMICOLON\n"; 
						logout<<$2->getValue()<<endl;
						SymbolInfo *tempval=symbltable.lookTable($2->getValue(),"FUNC");
						if(tempval!=NULL)
						{
							errorout<<"Error at line "<<line_count<<" Function "<<$2->getValue()<<" already declared" << endl;
							errors++;
	
						}
						else
						{
							SymbolInfo* tempval2=symbltable.finalInsert($2->getValue(),"ID");
							tempval2->setkeyType("FUNC");
							tempval2->setFuncRet($1->getReturnType());
							for(int i = 0; i<argvalue.size(); i++){
								tempval2->pList.push_back(argvalue[i]);					
							}
							argvalue.clear();
						}
						//funcParam.exitScope();
					}
					|type_specifier ID LPAREN parameter_list RPAREN error
					{
						errorout<<"Error at line "<<line_count<<" ; missing"<<endl;
						errors++;
					}
		 			;
func_definition : type_specifier ID LPAREN parameter_list RPAREN compound_statement
				{
					logout<<"At Line "<<line_count<<" : func_definition : type_specifier ID LPAREN parameter_list RPAREN compound_statement\n"<<endl;
					logout<<$2->getValue()<<endl;
					SymbolInfo *tempval=symbltable.lookTable($2->getValue(),"FUNC");
					if(argvalue.size()!=argnum)
					{
						errorout<<"Error at line "<<line_count<<" Parameter mismatch for Function "<<$2->getValue()<< endl;
						argvalue.clear();
						argnum=0;
						errors++;
					}												
					if(tempval!=NULL)
					{
					//logFile << "Function " << $2->getValue() <<" already declared" << endl;
						if(tempval->isFuncDefined()==true)
						{
							errorout<<"Error at line "<<line_count<<"Function "<< $2->getValue()<<" already defined" << endl;
							errors++;
							argvalue.clear();
							argnum=0;
						}
						else if(tempval->getFuncRet()!=$1->getReturnType())
						{
							errorout<<"Error at line "<<line_count<<"Function "<<$2->getValue()<<" :return type doesn't match declaration"<<endl;
							errors++;
							argvalue.clear();
							argnum=0; 
						} 
						else if(tempval->pList.size()!=argvalue.size())
						{
							errorout<<"Error at line "<<line_count<<"Function "<<$2->getValue()<<" :Parameter list doesn not match declaration"<<endl;
							errors++;
							argvalue.clear();
							argnum=0;					
						}
						else
						{
							for(int i=0;i<tempval->pList.size();i++)
							{
								if(tempval->pList[i]!=argvalue[i])
								{
									errorout<<"Error at line "<<line_count<<"Function "<< $2->getValue()<< " :argument mismatch"<<endl;
									errors++;
									argvalue.clear();
									argnum=0;	
								}
							}				
						}
					}
					else
					{
						SymbolInfo* tempval=new SymbolInfo();
						tempval=symbltable.finalInsert($2->getValue(),"ID");
						//logFile << $2->getValue() << " Function inserted" << endl;
						tempval->setkeyType("FUNC");
						tempval->setFuncRet($1->getReturnType());
					//
						for(int i=0;i<argvalue.size(); i++){
						tempval->pList.push_back(argvalue[i]);					
					}
					tempval->setFuncDefined();
				}
				argvalue.clear();
				argnum=0;
				
	
				//funcParam.exitScope();
				}
 		 		;
 		 
parameter_list  : parameter_list COMMA type_specifier ID
				{
					logout<<"At Line "<<line_count<<" : parameter_list  : parameter_list COMMA type_specifier ID\n";
					logout<<$4->getValue()<<endl;
					argvalue.push_back(vtype);//changed from $3->getReturnType()
					argnum++;
					//SymbolInfo* temp = funcParam.finalInsert($4->getValue(), $4->getKeyword());					
					//temp->setkeyType("VAR");
					//temp->setReturnType($3->getReturnType());
					$4->setkeyType("VAR");
					$4->setReturnType(vtype);//changed from $3->getReturnType()
					SymbolInfo* tempval=new SymbolInfo($4->getValue(),$4->getKeyword());
					tempval->setkeyType("VAR");
					
					parameter.push_back(*tempval);
				
				} 
 				| parameter_list COMMA type_specifier	
				{					
					logout<<"At Line "<<line_count<<" : parameter_list  : parameter_list COMMA type_specifier\n"<< endl;
					argvalue.push_back($3->getReturnType());
				}
 				| type_specifier ID
				{
					logout<<"At Line "<<line_count<<" : parameter_list  : type_specifier ID\n";
					logout<<$2->getValue()<<endl;
					//args.clear();
					argvalue.push_back(vtype);//$1->getReturnType()
					argnum++;
					//SymbolInfo* temp = funcParam.finalInsert($2->getValue(), $2->getKeyword());
					//temp->setkeyType("VAR");
					//temp->setReturnType($1->getReturnType());
					$2->setkeyType("VAR");
					$2->setReturnType(vtype);//$1->getReturnType()
					parameter.push_back(*$2);
				
				}
 				| type_specifier
				{
					logout<<"At Line "<<line_count<<" : parameter_list  : type_specifier\n"<< endl;
					//args.clear();
					argvalue.push_back(vtype);
				}
				|{//logFile << "Empty parameter " << lCount << endl;
				}
 				;
 		
compound_statement : LCURL
			{	symbltable.enterScope();
				for(int i=0;i<parameter.size();i++) 
					symbltable.insertTable(parameter[i]);
				parameter.clear();
			} statements {
				symbltable.printAllTable(logout);
			} RCURL
			{
				symbltable.exitScope();	
			} { logout<<"At line "<<line_count<< " : compound_statement : LCURL statements RCURL\n"<< endl; }
			|
			LCURL RCURL 
			{ 
				logout<<"At line "<<line_count<< " : compound_statement : LCURL RCURL\n"<< endl; 
			}
			
			;

var_declaration : type_specifier declaration_list SEMICOLON
			{
				logout<<"At line "<<line_count<< " : var_declaration : type_specifier declaration_list SEMICOLON\n"<< endl;
				
			}
		| type_specifier declaration_list error
			{
				errorout<<"Error at line "<<line_count<<" ';' missing " <<endl;
				errors++;
			}
 		 ;

type_specifier	: INT { 	logout<<"At line "<<line_count<< " : type_specifier : INT\n"<< endl;
			SymbolInfo* str=new SymbolInfo("INT");
			vtype="INT";
			$$=str;

			}
		| 
		FLOAT { logout<<"At line "<<line_count<< " : type_specifier : FLOAT\n"<< endl;
			SymbolInfo* str=new SymbolInfo("FLOAT");
			vtype="FLOAT";
			$$=str;

			} 
		|
		VOID {  logout<<"At line "<<line_count<< " : type_specifier : VOID\n"<< endl;
			SymbolInfo* str=new SymbolInfo("VOID");
			vtype="VOID";
			$$=str;
		}
			;

declaration_list : 	declaration_list COMMA ID
					{
						logout<<"At Line "<<line_count<<" : declaration_list : 	declaration_list COMMA ID\n";
						logout<<$3->getValue()<<endl;
						if(vtype=="VOID")
						{
							errorout<<"Error at line "<<line_count<<" :variable type can't be void" << endl;
							errors++;
						}
						else
						{
							SymbolInfo* tempval=symbltable.lookTable($3->getValue(),"VAR");
							if(tempval!=NULL)
							{
								errorout<<"Error at line "<<line_count<<": Variable "<<$3->getValue()<<" already declared"<<endl;	
								errors++;	
							}
							else
							{
								//SymbolInfo* tempval2 = symbltable.finalInsert($3->getValue(), $3->getKeyword());
								//tempval2->setReturnType(vtype);
								//tempval2->setkeyType("VAR");
								SymbolInfo* tempval2=new SymbolInfo($3->getValue(),$3->getKeyword());
								tempval2->setReturnType(vtype);
								tempval2->setkeyType("VAR");
								symbltable.insertTable(*tempval2);
								//symbltable.printAllTable(logFile);
							}
						}
					}
 					| declaration_list COMMA ID LTHIRD CONST_INT RTHIRD
					{
						logout<<"At Line "<<line_count<<" : declaration_list : 	declaration_list COMMA ID LTHIRD CONST_INT RTHIRD\n";
						logout<<$3->getValue()<<endl;
						logout<<$5->getValue()<<endl;
						if(vtype=="VOID")
						{
							errorout<<"Error at line "<<line_count<<" : array type can't be void"<<endl;
							errors++;
						}
						else
						{
							SymbolInfo* tempval=symbltable.lookTable($3->getValue(),"ARA");
							if(tempval!=NULL)
							{
								errorout<<"Error at line "<<line_count<<" : Array "<<$3->getValue()<< " already declared"<<endl;
								errors++;			
							}
							else
							{
								SymbolInfo* tempval2=new SymbolInfo($3->getValue(),$3->getKeyword());
								tempval2->setReturnType(vtype);
								tempval2->setkeyType("ARA");
								int araSize=atoi(($5->getValue()).c_str());
								tempval2->setAraLength(araSize);
								if(vtype=="INT")			  {								
									for(int i=tempval2->intstore.size();i<araSize;i++)
									{
										tempval2->intstore.push_back(0);
									}							
								}
								else if(vtype=="FLOAT")	{								
									for(int i=tempval2->floatstore.size();i<araSize;i++)
									{
										tempval2->floatstore.push_back(0);
									}							
								}
								else if(vtype=="CHAR"){								
									for(int i=tempval2->charstore.size();i<araSize;i++){
										tempval2->charstore.push_back('\0');
									}							
								}
								symbltable.insertTable(*tempval2);						
								//symbltable.printAllTable(logFile);
							}
						}

					}
 					| ID
					{
						logout<<"At Line "<<line_count<<" : declaration_list :	ID\n";
						logout<<$1->getValue()<<endl;
						if(vtype=="VOID")
						{
							errorout<<"Error at line "<<line_count<<" :variable type can't be void"<<endl;
							errors++;
						}
						else
						{
							SymbolInfo* temp=symbltable.lookTable($1->getValue(), "ARA");
							if(temp!=NULL)
							{
								errorout<<"Error at line "<<line_count<<": Variable "<< $1->getValue() <<" already declared"<<endl;	
								errors++;		
							}
							else
							{
								SymbolInfo* tempval2=new SymbolInfo($1->getValue(),$1->getKeyword());
								tempval2->setReturnType(vtype);
								tempval2->setkeyType("VAR");
								symbltable.insertTable(*tempval2);
								//symbltable.printAllTable(logFile);		
							}
						}
					}
					| ID LTHIRD CONST_INT RTHIRD
					{
						logout<<"At Line "<<line_count<<" : declaration_list :	ID LTHIRD CONST_INT RTHIRD\n";
						logout<<$1->getValue()<<endl;
						logout<<$3->getValue()<<endl;
						if(vtype=="VOID")
						{
							errorout<<"Error at line "<<line_count<<" :array type can't be void"<<endl;
							errors++;
						}
						else
						{
							SymbolInfo* temp=symbltable.lookTable($1->getValue(),"ARA");
							if(temp!=NULL)
							{
								errorout<<"Error at line "<<line_count<<": Array "<<$1->getValue()<<" already declared"<<endl;	
								errors++;
							}
							else
							{
								SymbolInfo* tempval2=new SymbolInfo($1->getValue(),$1->getKeyword());
								tempval2->setReturnType(vtype);
								tempval2->setkeyType("ARA");
								int araSize=atoi(($3->getValue()).c_str());
								tempval2->setAraLength(araSize);
								symbltable.insertTable(*tempval2);
								//symbltable.printAllTable(logFile);			
							}
						}
					}						
					;
statements : statement
		{	
			logout<<"At line "<<line_count<< " : statements : statement\n"<< endl;
		}
	   | statements statement
		{
			logout<<"At line "<<line_count<< " : statements : statements statement\n"<< endl;
		}
		
	   ;
statement : var_declaration
		{
			logout<<"At line "<<line_count<< " : statement : var_declaration\n"<< endl;
		}
	  | expression_statement
		{
			logout<<"At line "<<line_count<< " : statement : expression_statement\n"<< endl;
		}
	  | compound_statement
		{
			logout<<"At line "<<line_count<< " : statement : compound_statement\n"<< endl;
		}
	  | FOR LPAREN expression_statement expression_statement expression RPAREN statement
		{
			logout<<"At line "<<line_count<< " : statement : FOR LPAREN expression_statement expression_statement expression RPAREN statement\n"<< endl;
		}
	  | IF LPAREN expression RPAREN statement %prec second_precedence
		{
			logout<<"At line "<<line_count<< " : statement : IF LPAREN expression RPAREN statement\n"<< endl;
		}
	  | IF LPAREN expression RPAREN statement ELSE statement
		{
			logout<<"At line "<<line_count<< " : statement : IF LPAREN expression RPAREN statement ELSE statement\n"<< endl;
		}
	  | WHILE LPAREN expression RPAREN statement
		{
			logout<<"At line "<<line_count<< " : statement : WHILE LPAREN expression RPAREN statement\n"<< endl;
		}
	  | PRINTLN LPAREN ID RPAREN SEMICOLON
		{
			logout<<"At line "<<line_count<< " : statement : PRINTLN LPAREN ID RPAREN SEMICOLON\n"<< endl;
		}
	| PRINTLN LPAREN ID RPAREN error
		{
			errorout<<" Error at line "<<line_count<<" : ; missing "<<endl;
			errors++;
		}
	  | RETURN expression SEMICOLON
		{
			logout<<"At line "<<line_count<< " : statement : RETURN expression SEMICOLON\n"<< endl;
		}
	| RETURN expression error 
		{
			errorout<<"Error at line "<<line_count<<" : ; missing "<<endl;
			errors++;
		}
	
	  ;
	  
expression_statement 	: SEMICOLON
				{
					logout<<"At line "<<line_count<< " : expression_statement 	: SEMICOLON\n"<< endl;	
				}			
			| expression SEMICOLON 
				{
					logout<<"At line "<<line_count<< " : expression_statement 	: expression SEMICOLON\n"<< endl;
				}
			| expression error
				{
					errorout<<"Error at line "<<line_count<<" : ; missing "<<endl;
					errors++;
				}
			;
	  
variable : 	ID
			{
				logout<<"At Line "<<line_count<<" : variable : ID\n";
				logout<<$1->getValue()<<endl;
				SymbolInfo* tempval=symbltable.lookTable($1->getValue(),"VAR");
				if(tempval==NULL)
				{
					//logFile << "Variable " << $1->getValue() << " doesn't exist" << endl;
					errorout<<"Error at line "<<line_count<<" : "<<$1->getValue()<<" doesn't exist"<< endl;					
					errors++;
				}
				else
				{
					$$=tempval;
					//vtype = temp->getReturnType();
				}			
			} 		
	 		| ID LTHIRD expression RTHIRD
			{
				logout<<"Line "<<line_count<<" : variable : ID LTHIRD expression RTHIRD\n";
				logout<<$1->getValue()<<endl;
				SymbolInfo* tempval=symbltable.lookTable($1->getValue(),"ARA");
				if(tempval==NULL)
				{
					errorout<<"Error at line "<<line_count<<" : " <<$1->getValue()<<" doesn't exist"<< endl;					
					errors++;				
				}
				else
				{
					//$$ = temp;
					if($3->intstore[0]>=tempval->getAralength())
					{
						errorout<<"Error at line "<<line_count<<" : " <<$1->getValue()<<" array index out of bounds"<<  endl;				
						errors++;
						//temp->setAraIndex(0);
					} 
					else 
						tempval->setAraIndex($3->intstore[0]);
					if(tempval->getReturnType()=="INT")
					{
						while(tempval->intstore.size()<=tempval->getAraIndex())
						{
							tempval->intstore.push_back(0);
						}
					}
					else if(tempval->getReturnType()=="FLOAT")
					{
						while(tempval->floatstore.size()<=tempval->getAraIndex())
						{
							tempval->floatstore.push_back(0);
						}
					}
					else if(tempval->getReturnType()=="CHAR")
					{
						while(tempval->charstore.size()<=tempval->getAraIndex())
						{
							tempval->charstore.push_back('\0');
						}
					}
					$$=tempval;
					//vtype = temp->getReturnType();
				}			
			} 
	 		;
	 
 expression : logic_expression	
		{
			logout<<"At line "<<line_count<< " : expression : logic_expression\n"<< endl;
			
			//semantic check			
			//storing semantic value ( logic_expression)
			$$=$1;
			$$->intstore.push_back(0); //if the term is int
			$$->floatstore.push_back(0); //if the term is float 
			//considering it both
			// for next term semantic check
		}
	   | variable ASSIGNOP logic_expression 
		{
			logout<<"At line "<<line_count<< " : expression : variable ASSIGNOP logic_expression\n"<< endl;
			//semantic check
			string st=$1->getReturnType();

			//checking the variable type with the help of keyword
			if(st=="INT")
			{
				// varaible or array 
				if($1->getKeyType()=="VAR")
				{
					$1->intstore.push_back(0);

					//checking the logical_expression keyword
					if($3->getReturnType()=="INT")
					{
					
					}
					//logical expression isn't int
					else
					{
						errorout<<"Error at line " <<line_count<<" : Assigning float value to integer"<<endl;
						//semantic correction
						//making the float value into int
						if($3->getKeyType()=="VAR")  //logical expression is varaible
							$1->intstore[0]=(int)$3->floatstore[0];
						//logical expression is array
						else 
							$1->intstore[0]=(int)$3->floatstore[$3->getAraIndex()];
					}
				}
				//the $1 variable is array
				else if($1->getKeyType()=="ARA")
				{
					$1->intstore.push_back(0);
					//checking the logical_expression keyword  
					if($3->getReturnType()=="INT")
					{
					
					}
					//logical expression isn't int
					else
					{
						errorout<<"Error at line " <<line_count<<" : Assigning float value to integer"<<endl;
						//semantic correction
						//making the float value into int
						if($3->getKeyType()=="VAR")  //logical expression is varaible
							$1->intstore[$1->getAraIndex()]=(int)$3->floatstore[0];
						//logical expression is array
						else 
							$1->intstore[$1->getAraIndex()]=(int)$3->floatstore[$3->getAraIndex()];
					}
				}
			}
			
			else if(st=="FLOAT")
			{
				// varaible or array
				if($1->getKeyType()=="VAR")
				{
					$1->floatstore.push_back(0);
					//checking the logical_expression keyword
					if($3->getReturnType()=="INT")
					{
						errorout<<"Error at line " <<line_count<<" : Assigning integer value to float"<<endl;
						//semantic correction
						//making the int value into float
						if($3->getKeyType()=="VAR") //logical expression is varaible
							$1->floatstore[0]=(float)$3->intstore[0];
						//logical expression is array
						else 
							$1->floatstore[0]=(float)$3->intstore[$3->getAraIndex()];
					}
					else
					{
						
					}
				
				}
				else if($1->getKeyType()=="ARA")
				{
					$1->floatstore.push_back(0);
					//if the logical_expression is variable
					if($3->getReturnType()=="INT")
					{
					
					}
					else
					{
						errorout<<"Error at line " <<line_count<<" : Assigning integer value to float"<<endl;
						//semantic correction
						//making the int value into float
						if($3->getKeyType()=="VAR")
							$1->floatstore[$1->getAraIndex()] = $3->floatstore[0]; //logical expression is varaible
						//logical expression is array
						else 
							$1->floatstore[$1->getAraIndex()] = $3->floatstore[$3->getAraIndex()];
					}
				}
			}
			//storing semantic value
			$$ = $1;
			//printing the value	
			symbltable.printAllTable(logout);	
			
		}	
	   ;
			
logic_expression : rel_expression 	
			{
				logout<<"At line "<<line_count<< " : logic_expression : rel_expression\n"<< endl;
			
				//semantic check			
				//storing semantic value ( logic_expression)
				$$=$1;
				$$->intstore.push_back(0); //if the term is int
				$$->floatstore.push_back(0); //if the term is float 
				//considering it both
				// for next term semantic check
			}
		 | rel_expression LOGICOP rel_expression 
			{
				logout<<"At line "<<line_count<< " : logic_expression : rel_expression LOGICOP rel_expression\n"<< endl;
				//ultimate value of this expression will be 0 or 1
				//going to take an object with int keyword
				
				SymbolInfo* tempval=new SymbolInfo("INT");

				//if $1 or $3 is character keyword , then there will be no logical operation
				if($1->getReturnType()=="CHAR"||$3->getReturnType()=="CHAR")
				{
					//errorout<<"Error at line " <<line_count<<" : invalid keyword"<<endl;
					tempval->intstore.push_back(0);
				}
				string st=$2->getValue(); 
				//if the LOGICOP is &&
				if(st=="&&")
				{
					//if the term is float keyword
					if($1->getReturnType()=="FLOAT")
					{
						$1->floatstore.push_back(0); //indicating float varaible
						//if any term is 0, then the ans will be 0
						if($1->floatstore[0]==0)
						{
							tempval->intstore[0]=0; //	answer is zero							
						}
						//if the second term is float, then this term will be added to float array 
						else if($3->getReturnType()=="FLOAT")
						{
							$3->floatstore.push_back(0); //added
							if($3->floatstore[0]==0)  // the term is zero
								tempval->intstore[0]=0;
							else 
								tempval->intstore[0]=1; //otherwise the term will be one
						}
						//if the second term is int, then this term will be added to int array 
						else if($3->getReturnType()=="INT")
						{
							$3->intstore.push_back(0); //added 
							if($3->intstore[0]==0)   //the term is zero
								tempval->intstore[0]=0;
							else 
								tempval->intstore[0]=1; //otherwise the term will be one
						}
					}
					//if the term is int keyword
					else if($1->getReturnType()=="INT")
					{
						$1->intstore.push_back(0); //indicating int variable
						//if any term is 0, then the ans will be 0
						if($1->intstore[0]==0) 
							tempval->intstore[0]=0; //	answer is zero
						//if the second term is float, then this term will be added to float array
						else if($3->getReturnType()=="FLOAT")
						{
							$3->floatstore.push_back(0); //added
							if($3->floatstore[0]==0) // the term is zero
								tempval->intstore[0]=0;
							else 
								tempval->intstore[0]=1; //otherwise the term will be one
						}
						//if the second term is int, then this term will be added to int array 
						else if($3->getReturnType() == "INT")
						{
							$3->intstore.push_back(0); //added 
							if($3->intstore[0]==0) //the term is zero
								tempval->intstore[0]=0;
							else 
								tempval->intstore[0]=1; //otherwise the term will be one
						}
					}
				}
				//if the LOGICOP is ||
				else if(st=="||")
				{
					//if the term is float keyword
					if($1->getReturnType()=="FLOAT")
					{
						$1->floatstore.push_back(0); //indicating float varaible
						//if both term is 0, then the ans will be 1
						if($1->floatstore[0]!=0)
						{
							tempval->intstore[0]=1; //	answer is one							
						}
						//if the second term is float, then this term will be added to float array
						else if($3->getReturnType()=="FLOAT")
						{
							$3->floatstore.push_back(0); //added
							if($3->floatstore[0]!=0)  //the term is one
								tempval->intstore[0]=1;
							else 
								tempval->intstore[0]=0; //otherwise the term will be zero
						}
						//if the second term is int, then this term will be added to int array 
						else if($3->getReturnType()=="INT")
						{
							$3->intstore.push_back(0); //added
							if($3->intstore[0]!=0)  //the term is one
								tempval->intstore[0]=1;
							else 
								tempval->intstore[0] =0; //otherwise the term will be zero
						}
					}
					//if the term is int keyword
					else if($1->getReturnType()=="INT")
					{
						$1->intstore.push_back(0); //indicating float varaible
						//if both term is 0, then the ans will be 1
						if($1->intstore[0]!=0) 
							tempval->intstore[0]=1; //	answer is one
						//if the second term is float, then this term will be added to float array
						else if($3->getReturnType()=="FLOAT")
						{
							$3->floatstore.push_back(0); //added 									
							if($3->floatstore[0]!=0) //the term is one
								 tempval->intstore[0]=1;
							else 
								tempval->intstore[0] =0; //otherwise the term will be zero
						}
						//if the second term is int, then this term will be added to int array
						else if($3->getReturnType()=="INT")
						{
							$3->intstore.push_back(0); //added
							if($3->intstore[0]!=0)  //the term is one
								tempval->intstore[0]=1;
							else 
								tempval->intstore[0]=0; //otherwise the term will be zero
						}
					}
				}
				//storing the semantic value
				$$=tempval;
				
			}	
		 ;
			
rel_expression	: simple_expression 
			{
				
				logout<<"At line "<<line_count<< " : rel_expression : simple_expression\n"<< endl;
			
				//semantic check			
				//storing semantic value ( logic_expression)
				$$=$1;
				$$->intstore.push_back(0); //if the term is int
				$$->floatstore.push_back(0); //if the term is float 
				//considering it both
				// for next term semantic check
			
			}
		| simple_expression RELOP simple_expression
			{
				logout<<"At line "<<line_count<< " : simple_expression RELOP simple_expression\n"<< endl;
				//the ultimate result will be 0 or 1, that's why it's kept as int varaible
				SymbolInfo* tempval=new SymbolInfo("INT");
				string st=$2->getValue(); //the relop sign
				string var1=$1->getReturnType(); //getting the first simp.expression keyword
				string var2=$3->getReturnType(); //getting the second simp.expression keyword
				//if the RELOP is ==
				if(st=="==")
				{
					if(var1!=var2) //this doesn't occur error 
					{
						//errorout<<"At line "<<line_count<<" type mismatch"<<endl;
						//type inequality doesn't matter
					}
					else if(var1=="INT") //the first term is of int keyword
					{
						//both term is equal, so the result will be one
						if($1->intstore[0]==$3->intstore[0]) 
							tempval->intstore[0]=1;  //result added
						else
							tempval->intstore[0]=0;  //otherwise result will be zero
					}
					//the first term is of float keyword
					else if(var1=="FLOAT")
					{
						//both term is equal, so the result will be one
						if($1->floatstore[0]==$3->floatstore[0]) 
							tempval->intstore[0]=1; //result added
						else 
							tempval->intstore[0]=0; //otherwise result will be zero		
					}
					//the first term is of character keyword
					else if(var1=="CHAR")
					{
						//both term is equal, so the result will be one
						if($1->charstore[0]==$3->charstore[0]) 
							tempval->intstore[0]=1; //result added
						else 
							tempval->intstore[0]=0; //otherwise result will be zero		
					}
				}
				//if the RELOP is !=
				else if(st=="!=")
				{
					if(var1!=var2) //this doesn't occur error
					{
						//errorout<<"At line "<<line_count<<" type mismatch"<<endl;
						//type inequality doesn't matter
					}
					else if(var1=="INT") //the first term is of int keyword
					{
						//both term is not equal, so the result will be one
						if($1->intstore[0]!=$3->intstore[0]) 
							tempval->intstore[0]=1; //result added
						else 
							tempval->intstore[0]=0; //otherwise result will be zero
					}
					//the first term is of float keyword
					else if(var1=="FLOAT")
					{
						//both term is not equal, so the result will be one
						if($1->floatstore[0]!=$3->floatstore[0]) 
							tempval->intstore[0]=1; //result added
						else 
							tempval->intstore[0]=0; //otherwise result will be zero	
					}
					//the first term is of char keyword
					else if(var1=="CHAR")
					{
						//both term is not equal, so the result will be one
						if($1->charstore[0]!=$3->charstore[0])
							tempval->intstore[0]=1; //result added
						else 
							tempval->intstore[0]=0; //otherwise result will be zero	
					}
				}
				//if the RELOP is <= or <
				//both term isn't required to be same keyword
				else if(st=="<="||st=="<")
				{
					if(var1=="INT") //the first term is int keyword
					{
						if(var2=="INT") //the second one is also int keyword
						{
							if($1->intstore[0]<$3->intstore[0]) // less than
								tempval->intstore[0]=1;
							else if($1->intstore[0]==$3->intstore[0]) //equal
								tempval->intstore[0]=1;
							else
								tempval->intstore[0]=0; //greater than
						}
						//second term is float keyword
						else if(var2=="FLOAT")
						{
							if($1->intstore[0]<$3->floatstore[0]) //less than
								 tempval->intstore[0]=1;
							else if($1->intstore[0]==$3->floatstore[0]) //equal
								 tempval->intstore[0]=1;
							else
								 tempval->intstore[0]=0; //greater than
						}
					}
					//the first term is float
					else if(var1=="FLOAT")
					{
						if(var2=="INT")  //the second term is int keyword
						{
							if($1->floatstore[0]<$3->intstore[0]) //less than
								 tempval->intstore[0]=1;
							else if($1->floatstore[0]==$3->intstore[0]) //equal
								tempval->intstore[0]=1;
							else
								 tempval->intstore[0]=0;	//greater than
						}
						//the second term is float keyword
						else if(var2=="FLOAT")
						{
							if($1->floatstore[0]<$3->floatstore[0]) //less than
								 tempval->intstore[0]=1;
							else if($1->floatstore[0]==$3->floatstore[0]) //equal
								 tempval->intstore[0]=1;
							else
								 tempval->intstore[0]=0; //greater than
						}
					}
					//the first term is character keyword
					else if(var1=="CHAR")
					{
					}

				}
				//if the relop is >= or >
				//true for both type of keywords
				else if(st==">="||st==">")
				{
					if(var1=="INT") //the first term is int keyword
					{
						if(var2=="INT") //the second term is int keyword
						{
							if($1->intstore[0]>$3->intstore[0]) //greater than
						        	tempval->intstore[0]=1;
							else if($1->intstore[0]==$3->intstore[0]) //equal
								tempval->intstore[0]=1;
							else
								 tempval->intstore[0]=0; //less than
						}
						//the second term is float keyword
						else if(var2=="FLOAT")
						{
							//greater than
							if($1->intstore[0]>$3->floatstore[0])
								 tempval->intstore[0]=1;
							//equal
							else if($1->intstore[0]==$3->floatstore[0])
								 tempval->intstore[0]=1;
							//less than
							else
								 tempval->intstore[0]=0;
						}
					}
					//the first term is float keyword
					else if(var1=="FLOAT")
					{
						if(var2=="INT") //the second term is int keyword
						{
							if($1->floatstore[0]>$3->intstore[0]) //greater than
								 tempval->intstore[0]=1;
							else if($1->floatstore[0]==$3->intstore[0]) //equal
								 tempval->intstore[0]=1;
							else
								 tempval->intstore[0]=0; //less than
						}
						//the second term is float keyword
						else if(var2=="FLOAT")
						{
							if($1->floatstore[0]>$3->floatstore[0]) //greater than
								 tempval->intstore[0]=1;
							else if($1->floatstore[0]==$3->floatstore[0]) //equal
								 tempval->intstore[0]=1;
							else
								 tempval->intstore[0]=0; //less than
						}
					}
					//the first term is character keyword
					else if(var1=="CHAR")
					{
					}

				}
				//stored in semantic value
				$$=tempval;
				
			}	
		;
				
simple_expression : term 
			{
				logout<<"At line "<<line_count<< " : simple_expression : term\n"<< endl;
			
				//semantic check			
				//storing semantic value ( logic_expression)
				$$=$1;
				$$->intstore.push_back(0); //if the term is int
				$$->floatstore.push_back(0); //if the term is float 
				//considering it both
				// for next term semantic check
			}
		  | simple_expression ADDOP term 
			{
				logout<<"At line "<<line_count<< " : simple_expression : simple_expression ADDOP term\n"<< endl;
				//ADDOP is '+'
				if($2->getValue()=="+")
				{
					//variable or array
					//at first, it may be variable
					if($1->getKeyType()=="VAR")
					{
						//second term is variable
						if($3->getKeyType()=="VAR")
						{	
							//if the first term is float, then the answer will be float					
							if($1->getReturnType()=="FLOAT")
							{
								//the answer is kept as a float number
								SymbolInfo* tempval=new SymbolInfo("FLOAT");
								//the second term is int keyword
								// a float and an int keyword is being added
								if($3->getReturnType()=="INT")
								{
									tempval->floatstore[0]=$1->floatstore[0]+$3->intstore[0];							
								}
								//the second term is float keyword
								//a float and a float keyword value is being added
								else
								{
									tempval->floatstore[0]=$1->floatstore[0]+$3->floatstore[0];
								}
								//the ultimate value is being stored 
								$$=tempval;
							}
							//if the second term is float, then the answer will be float					
							else if($3->getReturnType()=="FLOAT")
							{
								//the answer is kept as a float number
								SymbolInfo* tempval=new SymbolInfo("FLOAT");
								//the first term is int keyword
								// a float and an int keyword is being added
								if($1->getReturnType()=="INT")
								{
									tempval->floatstore[0]=$1->intstore[0]+$3->floatstore[0];							
								}
								//the first term is float keyword
								// a float and a float keyword is being added
								else
								{
									tempval->floatstore[0]=$1->floatstore[0]+$3->floatstore[0];
								}
								//the ultimate value is being stored 
								$$=tempval;
							}
							//if both values is int keyword
							else if($3->getReturnType()=="INT"&&$1->getReturnType()=="INT")
							{
								//the result will be int
								SymbolInfo* tempval=new SymbolInfo("INT");
								tempval->intstore[0]=$1->intstore[0]+$3->intstore[0];
								$$=tempval; //value is stored 
							}
						}
						//second term is an array
						else if($3->getKeyType()=="ARA")
						{	
							//if the first term is float, then the answer will be					
							if($1->getReturnType()=="FLOAT")
							{
								//the ultimate result will be float
								SymbolInfo* tempval=new SymbolInfo("FLOAT");
								//second term is int keyword
								//an int and a float will make a float value as result
								if($3->getReturnType()=="INT")
								{
									tempval->floatstore[0]=$1->floatstore[0]+$3->intstore[$3->getAraIndex()];							
								}
								//second term is float keyword
								//a float and a float will make a float value as result 
								else
								{
									tempval->floatstore[0]=$1->floatstore[0]+$3->floatstore[$3->getAraIndex()];
								}
								//the ultimate result is stored
								$$=tempval;
							}
							//if the second term is float, then the answer will be
							else if($3->getReturnType()=="FLOAT")
							{
								//the ultimate result will be float
								SymbolInfo* tempval=new SymbolInfo("FLOAT");
								//first term is int keyword
								//an int and a float will make a float value as result
								if($1->getReturnType()=="INT")
								{
									tempval->floatstore[0]=$1->intstore[0]+$3->floatstore[$3->getAraIndex()];							
								}
								//first term is float keyword
								//a float and a float will make a float value as result
								else
								{
									tempval->floatstore[0]=$1->floatstore[0]+$3->floatstore[$3->getAraIndex()];
								}
								//the ultimate result is stored
								$$=tempval;
							}
							//both terms is int keyword
							else if($3->getReturnType()=="INT"&&$1->getReturnType()=="INT")
							{
								//the answer will be int
								SymbolInfo* tempval=new SymbolInfo("INT");
								tempval->intstore[0]=$1->intstore[0]+$3->intstore[$3->getAraIndex()];
								//the ultimate result is stored
								$$=tempval;
							}
						}
					}
					// if it is an array
					else if($1->getKeyType()=="ARA")
					{
						//second term is variable
						if($3->getKeyType()=="VAR")
						{			
							//the first term is float
							//the answer will be float			
							if($1->getReturnType()=="FLOAT")
							{
								//the answer is kept in a float value
								SymbolInfo* tempval=new SymbolInfo("FLOAT");
								//the second term is int
								//answer is kept in float
								if($3->getReturnType()=="INT")
								{
									tempval->floatstore[0]=$1->floatstore[$1->getAraIndex()]+$3->intstore[0];							
								}
								//the second value is int
								else
								{
									tempval->floatstore[0]=$1->floatstore[$1->getAraIndex()]+$3->floatstore[0];
								}
								//the ultimate answer is stored
								$$=tempval;
							}
							//the second term is float
							//the answer will be float
							else if($3->getReturnType()=="FLOAT")
							{
								//the answer is kept in a float value
								SymbolInfo* tempval=new SymbolInfo("FLOAT");
								//the first term is int
								//the answer is kept in float
								if($1->getReturnType()=="INT")
								{
									tempval->floatstore[0]=$1->intstore[$1->getAraIndex()]+$3->floatstore[0];							
								}
								//the second term is float
								else
								{
									tempval->floatstore[0]=$1->floatstore[$1->getAraIndex()]+$3->floatstore[0];
								}
								//the ultimate answer is stored
								$$=tempval;
							}
							//both terms is int
							//the answer will be int
							else if($3->getReturnType()=="INT"&&$1->getReturnType()=="INT")
							{
								SymbolInfo* tempval=new SymbolInfo("INT");
								tempval->intstore[0]=$1->intstore[$1->getAraIndex()]+$3->intstore[0];
								//the ultimate answer is stored
								$$=tempval;
							}
						}
						//if the second term is an array
						else if($3->getKeyType()=="ARA")
						{		
							//the first term is float
							//the answer will be float				
							if($1->getReturnType()=="FLOAT")
							{
								//the answer is kept in a float value
								SymbolInfo* tempval=new SymbolInfo("FLOAT");
								//the second term is int
								//the answer is kept in float
								if($3->getReturnType()=="INT")
								{
									tempval->floatstore[0]=$1->floatstore[$1->getAraIndex()]+$3->intstore[$3->getAraIndex()];
								}
								//the second term is float
								else
								{
									tempval->floatstore[0]=$1->floatstore[$1->getAraIndex()]+$3->floatstore[$3->getAraIndex()];
								}
								//the ultimate answer is stored
								$$=tempval;
							}
							//the second term is float
							//the answer will be float
							else if($3->getReturnType()=="FLOAT")
							{
								//the answer is kept in a float value
								SymbolInfo* tempval=new SymbolInfo("FLOAT");
								//the first term is int
								//the answer is kept in float
								if($1->getReturnType()=="INT")
								{
									tempval->floatstore[0]=$1->intstore[$1->getAraIndex()]+$3->floatstore[$3->getAraIndex()];
								}
								//the first term is float
								else
								{
									tempval->floatstore[0]=$1->floatstore[$1->getAraIndex()]+$3->floatstore[$3->getAraIndex()];
								}
								//the ultimate answer is stored
								$$=tempval;
							}
							//both terms is int
							//the answer will be int
							else if($3->getReturnType()=="INT"&&$1->getReturnType()=="INT")
							{
								SymbolInfo* tempval=new SymbolInfo("INT");
								tempval->intstore[0]=$1->intstore[$1->getAraIndex()]+$3->intstore[$3->getAraIndex()];
								//the ultimate answer is stored
								$$=tempval;
							}
						}
					}
				}
				//ADDOP is -
				else if($2->getValue()=="-")
				{
					//first term is varaible
					if($1->getKeyType()=="VAR")
					{
						//second term is varaible
						if($3->getKeyType()=="VAR")
						{			
							//first term keyword is float
							//the answer will be float			
							if($1->getReturnType()=="FLOAT")
							{
								//the float value is ready to store
								SymbolInfo* tempval=new SymbolInfo("FLOAT");
								//the second term is int
								if($3->getReturnType()=="INT")
								{
									tempval->floatstore[0]=$1->floatstore[0]-$3->intstore[0];							
								}
								//the second term is float
								else
								{
									tempval->floatstore[0]=$1->floatstore[0]-$3->floatstore[0];
								}
								//the ultimate value is stored
								$$=tempval;
							}
							//second term keyword is float
							//the answer will be float
							else if($3->getReturnType()=="FLOAT")
							{
								//the float value is ready to store
								SymbolInfo* tempval=new SymbolInfo("FLOAT");
								//the first term is int
								if($1->getReturnType()=="INT")
								{
									tempval->floatstore[0]=$1->intstore[0]-$3->floatstore[0];							
								}
								//the first team is float
								else
								{
									tempval->floatstore[0]=$1->floatstore[0]-$3->floatstore[0];
								}
								//the ultimate result is stored
								$$=tempval;
							}
							//both result is int
							//the answer will be int
							else if($3->getReturnType()=="INT"&&$1->getReturnType()=="INT")
							{
								//an int keyword is ready to store
								SymbolInfo* tempval=new SymbolInfo("INT");
								tempval->intstore[0]=$1->intstore[0]-$3->intstore[0];
								//ultimate value is stored
								$$=tempval;
							}
						}
						//if the second term is array
						else if($3->getKeyType()=="ARA")
						{			
							//if the first term is float
							//the result will be float			
							if($1->getReturnType()=="FLOAT")
							{
								//the value will be float, ready to store
								SymbolInfo* tempval=new SymbolInfo("FLOAT");
								//the second term is int
								if($3->getReturnType()=="INT")
								{
									tempval->floatstore[0]=$1->floatstore[0]-$3->intstore[$3->getAraIndex()];							
								}
								//the second term is float
								else
								{
									tempval->floatstore[0]=$1->floatstore[0]-$3->floatstore[$3->getAraIndex()];
								}
								//the ultimate value is stored
								$$=tempval;
							}
							//if the second term is float
							//the result will be float
							else if($3->getReturnType()=="FLOAT")
							{
								//the value will be float, ready to store
								SymbolInfo* tempval=new SymbolInfo("FLOAT");
								//the second term is int
								if($1->getReturnType()=="INT")
								{
									tempval->floatstore[0]=$1->intstore[0]-$3->floatstore[$3->getAraIndex()];							
								}
								//the second term is float
								else
								{
									tempval->floatstore[0]=$1->floatstore[0]-$3->floatstore[$3->getAraIndex()];
								}
								//the ultimate result is stored
								$$=tempval;
							}
							//both result is int
							//the result will be int
							else if($3->getReturnType()=="INT"&&$1->getReturnType()=="INT")
							{
								
								SymbolInfo* tempval=new SymbolInfo("INT");
								tempval->intstore[0]=$1->intstore[0]-$3->intstore[$3->getAraIndex()];
								//the ultimate result is stored
								$$=tempval;
							}
						}
					}
					//if first term is array
					else if($1->getKeyType()=="ARA")
					{
						//the second term is variable
						if($3->getKeyType()=="VAR")
						{				
							//the first term is float
							//so the answer will be float		
							if($1->getReturnType()=="FLOAT")
							{
								//float value is ready to store
								SymbolInfo* tempval=new SymbolInfo("FLOAT");
								//second term is int
								if($3->getReturnType()=="INT")
								{
									tempval->floatstore[0]=$1->floatstore[$1->getAraIndex()]-$3->intstore[0];							
								}
								//second term is int
								else
								{
									tempval->floatstore[0]=$1->floatstore[$1->getAraIndex()]-$3->floatstore[0];
								}
								//the ultimate result is stored
								$$ =tempval;
							}
							//the second term is float
							//so the answer will be float
							else if($3->getReturnType()=="FLOAT")
							{
								//float value is ready to store
								SymbolInfo* tempval=new SymbolInfo("FLOAT");
								//the first value is int
								if($1->getReturnType()=="INT")
								{
									tempval->floatstore[0]=$1->intstore[$1->getAraIndex()]-$3->floatstore[0];							
								}
								//the first value is float
								else
								{
									tempval->floatstore[0]=$1->floatstore[$1->getAraIndex()]-$3->floatstore[0];
								}
								//the ultimate value is stored
								$$=tempval;
							}
							//both values are int
							//the answer will be int
							else if($3->getReturnType()=="INT"&&$1->getReturnType()=="INT")
							{
								SymbolInfo* tempval=new SymbolInfo("INT");
								tempval->intstore[0]=$1->intstore[$1->getAraIndex()]-$3->intstore[0];
								//the ultimate result is stored
								$$=tempval;
							}
						}
						//the second term is array
						else if($3->getKeyType()=="ARA")
						{	
							//the first term is float
							//the answer will be float					
							if($1->getReturnType()=="FLOAT")
							{
								//float value is ready to store
								SymbolInfo* tempval=new SymbolInfo("FLOAT");
								//the second term is int
								if($3->getReturnType()=="INT")
								{
									tempval->floatstore[0]=$1->floatstore[$1->getAraIndex()]-$3->intstore[$3->getAraIndex()];
								}
								//the second term is float
								else
								{
									tempval->floatstore[0]=$1->floatstore[$1->getAraIndex()]-$3->floatstore[$3->getAraIndex()];
								}
								//the ultimate result is stored
								$$=tempval;
							}
							//the second term is float
							//the answer will be float
							else if($3->getReturnType()=="FLOAT")
							{
								//float value is ready to stored
								SymbolInfo* tempval=new SymbolInfo("FLOAT");
								//first term is int
								if($1->getReturnType()=="INT")
								{
									tempval->floatstore[0]=$1->intstore[$1->getAraIndex()]-$3->floatstore[$3->getAraIndex()];
								}
								//first term is float
								else
								{
									tempval->floatstore[0]=$1->floatstore[$1->getAraIndex()]-$3->floatstore[$3->getAraIndex()];
								}
								//the ultimate value is stored
								$$=tempval;
							}
							//both values is int
							//the answer will be int
							else if($3->getReturnType()=="INT"&&$1->getReturnType()=="INT")
							{
								SymbolInfo* tempval=new SymbolInfo("INT");
								tempval->intstore[0]=$1->intstore[$1->getAraIndex()]-$3->intstore[$3->getAraIndex()];
								//the ultimate result is stored
								$$=tempval;
							}
						}
					}
				}
			}
		  ;
					
term :	unary_expression
		{
			logout<<"At line "<<line_count<< " : term : unary_expression\n"<< endl;
			
			//semantic check			
			//storing semantic value ( logic_expression)
			$$=$1;
			$$->intstore.push_back(0); //if the term is int
			$$->floatstore.push_back(0); //if the term is float 
			//considering it both
			// for next term semantic check
		}
     |  term MULOP unary_expression
		{
			logout<<"At line "<<line_count<< " : term : term MULOP unary_expression\n"<< endl;
			//MULOP is *
			if($2->getValue()=="*")
			{
				//the first term is variable
				if($1->getKeyType()=="VAR")
				{	
					//second value is variable 
					if($3->getKeyType()=="VAR")
					{		
						//the first value is float
						//the result will be float
						if($1->getReturnType()=="FLOAT")
						{
							
							SymbolInfo* tempval=new SymbolInfo("FLOAT");
							//the second value is int
							if($3->getReturnType()=="INT")
							{
								tempval->floatstore[0]=$1->floatstore[0]*$3->intstore[0];							
							}
							//the second value is float
							else
							{
								tempval->floatstore[0]=$1->floatstore[0]*$3->floatstore[0];
							}
							//ultimate value is stored
							$$=tempval;
						}
						//second value is float
						//the result will be float
						else if($3->getReturnType()=="FLOAT")
						{
							SymbolInfo* tempval=new SymbolInfo("FLOAT");
							//the first value is int
							if($1->getReturnType()=="INT")
							{
								tempval->floatstore[0]=$1->intstore[0]*$3->floatstore[0];							
							}
							//the first value is float
							else
							{
								tempval->floatstore[0]=$1->floatstore[0]*$3->floatstore[0];
							}
							//ultimate result is stored
							$$=tempval;
						}
						//both value is int
						//result is int
						else if($3->getReturnType()=="INT"&&$1->getReturnType()=="INT")
						{
							SymbolInfo* tempval=new SymbolInfo("INT");
							tempval->intstore[0]=$1->intstore[0]*$3->intstore[0];
							//ultimate value is stored
							$$=tempval;
						}
					}
					//the second value is array
					else if($3->getKeyType()=="ARA")
					{		
						//the first value is float
						//result will be float
						if($1->getReturnType()=="FLOAT")
						{
							SymbolInfo* tempval=new SymbolInfo("FLOAT");
							//the second value is int
							if($3->getReturnType()=="INT")
							{
								tempval->floatstore[0]=$1->floatstore[0]*$3->intstore[$3->getAraIndex()];							
							}
							//the second value is int
							else
							{
								tempval->floatstore[0]=$1->floatstore[0]*$3->floatstore[$3->getAraIndex()];
							}
							//ultimate value is stored
							$$=tempval;
						}
						//the second value is float
						//result will be float
						else if($3->getReturnType()=="FLOAT")
						{
							SymbolInfo* tempval=new SymbolInfo("FLOAT");
							//first value is int
							if($1->getReturnType()=="INT")
							{
								tempval->floatstore[0]=$1->intstore[0]*$3->floatstore[$3->getAraIndex()];							
							}
							//first value is int
							else
							{
								tempval->floatstore[0]=$1->floatstore[0]*$3->floatstore[$3->getAraIndex()];
							}
							//ultimate value is stored
							$$=tempval;
						}
						//both value is int
						//result will be int
						else if($3->getReturnType()=="INT"&&$1->getReturnType()=="INT")
						{
							SymbolInfo* tempval=new SymbolInfo("INT");
							tempval->intstore[0]=$1->intstore[0]*$3->intstore[0];
							//ultimate value is stored
							$$=tempval;
						}
					}
				}
				//the first value is array
				else if($1->getKeyType()=="ARA")
				{	
					//the second value is variable
					if($3->getKeyType()=="VAR")
					{		
						//the first value is float
						//the answer will be float
						if($1->getReturnType()=="FLOAT")
						{
							SymbolInfo* tempval=new SymbolInfo("FLOAT");
							//the second value is int
							if($3->getReturnType()=="INT")
							{
								tempval->floatstore[0]=$1->floatstore[$1->getAraIndex()]*$3->intstore[0];							
							}
							//the second value is float
							else
							{
								tempval->floatstore[0]=$1->floatstore[$1->getAraIndex()]*$3->floatstore[0];
							}
							//ultimate value is stored
							$$=tempval;
						}
						//the second value is float
						//the answer will be float
						else if($3->getReturnType()=="FLOAT")
						{
							SymbolInfo* tempval=new SymbolInfo("FLOAT");
							//first value is int
							if($1->getReturnType()=="INT")
							{
								tempval->floatstore[0]=$1->intstore[$1->getAraIndex()]*$3->floatstore[0];							
							}
							//first value is float
							else
							{
								tempval->floatstore[0]=$1->floatstore[$1->getAraIndex()]*$3->floatstore[0];
							}
							//the ultimate value is stored
							$$=tempval;
						}
						//both value is int
						//result is int
						else if($3->getReturnType()=="INT"&&$1->getReturnType()=="INT")
						{
							SymbolInfo* tempval=new SymbolInfo("INT");
							tempval->intstore[0]=$1->intstore[$1->getAraIndex()]*$3->intstore[0];
							//ultimate value is stored
							$$=tempval;
						}
					}
					//the second value is array
					else if($3->getKeyType()=="ARA")
					{		
						//the first value is float
						//the result will be float
						if($1->getReturnType()=="FLOAT")
						{
							SymbolInfo* tempval=new SymbolInfo("FLOAT");
							//second value is int
							if($3->getReturnType()=="INT")
							{
								tempval->floatstore[0]=$1->floatstore[$1->getAraIndex()]*$3->intstore[$3->getAraIndex()];
							}
							//second value is int
							else
							{
								tempval->floatstore[0]=$1->floatstore[$1->getAraIndex()]*$3->floatstore[$3->getAraIndex()];
							}
							//ultimate value is stored
							$$=tempval;
						}
						//the second value is float
						//the result will be float
						else if($3->getReturnType()=="FLOAT")
						{
							SymbolInfo* tempval=new SymbolInfo("FLOAT");
							//the first value is int
							if($1->getReturnType()=="INT")
							{
								tempval->floatstore[0]=$1->intstore[$1->getAraIndex()]*$3->floatstore[$3->getAraIndex()];
							}
							//the first value is float
							else
							{
								tempval->floatstore[0]=$1->floatstore[$1->getAraIndex()]*$3->floatstore[$3->getAraIndex()];
							}
							//ultimate value is stored
							$$=tempval;
						}
						//both value is int
						//answer will be int
						else if($3->getReturnType()=="INT"&&$1->getReturnType()=="INT")
						{
							SymbolInfo* tempval=new SymbolInfo("INT");
							tempval->intstore[0]=$1->intstore[$1->getAraIndex()]*$3->intstore[0];
							//ultimate value is stored
							$$=tempval;
						}
					}
				}
			}
			//MULOP is /
			else if($2->getValue()=="/")
			{
				//the first value is float
				//answer will be float
				if($1->getReturnType()=="FLOAT")
				{
					SymbolInfo* tempval=new SymbolInfo("FLOAT");
					//second value is int
					if($3->getReturnType()=="INT")
					{
						//first value can be varaible or array
						//if it is variable
						if($1->getKeyType()=="VAR")
						{
							//the second value can be variable or array
							//if it is varaible
							if($3->getKeyType()=="VAR")
							{
								//if the second value is not zero, the answer will be nonzero
								if($3->intstore[0]!=0)
									tempval->floatstore[0]=$1->floatstore[0]/$3->intstore[0];
								//otherwise there will be an error
								else
								{
									//tempval->floatstore[0]=numeric_limits<float>::infinity();
									errorout<<"Error at line "<<line_count<<" : Divide by zero"<<endl;
									errors++; 
								}							
							}
							//the second value is array
							else if($3->getKeyType() == "ARA")
							{
								//the second value is nonzero
								//answer will be nonzero
								if($3->intstore[$3->getAraIndex()]!=0)
									tempval->floatstore[0]=$1->floatstore[0]/$3->intstore[$3->getAraIndex()];
								//otherwise an error
								else
								{
									//temp->floatstore[0]=numeric_limits<float>::infinity();
									errorout<<"Error at line "<<line_count<<" : Divide by zero"<<endl;
									errors++; 
								}
							}
						}
						//first value is array
						else if($1->getKeyType()=="ARA")
						{
							//second value is variable
							if($3->getKeyType()=="VAR")
							{
								//nonzero value will result nonzero
								if($3->intstore[0]!=0)
									tempval->floatstore[0]=$1->floatstore[$1->getAraIndex()]/$3->intstore[0];
								//otherwise an error
								else
								{
									//tempval->floatstore[0]=numeric_limits<float>::infinity();
									errorout<<"Error at line "<<line_count<<" : Divide by zero"<<endl;
									errors++; 
								}							
							}
							//second value is array
							else if($3->getKeyType()=="ARA")
							{
								//nonzero value will result nonzero 
								if($3->intstore[$3->getAraIndex()]!=0)
								{
									tempval->floatstore[0]=$1->floatstore[$1->getAraIndex()]/$3->intstore[$3->getAraIndex()];
								}
								//otherwise an error will occur
								else
								{
									//tempval->floatstore[0]=numeric_limits<float>::infinity();
									errorout<<"Error at line "<<line_count<<" : Divide by zero"<<endl;
									errors++; 
								}
							}
						}
					}
					//the second value is float
					else if($3->getReturnType()=="FLOAT")
					{
						//the first value is variable
						if($1->getKeyType()=="VAR")
						{
							//the second value is variable or array
							//if it is variable
							if($3->getKeyType()=="VAR")
							{
								//nonzero value will give nonzero result
								if($3->floatstore[0]!=0)
									tempval->floatstore[0]=$1->floatstore[0]/$3->floatstore[0];
								//otherwise it will occur an error
								else
								{
									//temp->floatstore[0]=numeric_limits<float>::infinity();
									errorout<<"Error at line "<<line_count<<" : Divide by zero"<<endl;
									errors++; 
								}							
							}
							//if second value is array
							else if($3->getKeyType()=="ARA")
							{
								//nonzero value, nonzero result
								if($3->floatstore[$3->getAraIndex()]!=0)
									tempval->floatstore[0]=$1->floatstore[0]/$3->floatstore[$3->getAraIndex()];
								//otherwise an error
								else
								{
									//temp->floatstore[0]=numeric_limits<float>::infinity();
									errorout<<"Error at line "<<line_count<<" : Divide by zero"<<endl;
									errors++; 
								}
							}
						}
						//first value is an aray
						else if($1->getKeyType()=="ARA")
						{
							//second value is variable
							if($3->getKeyType()=="VAR")
							{
								//nonzero value, nonzero result
								if($3->floatstore[0]!=0)
									tempval->floatstore[0]=$1->floatstore[$1->getAraIndex()]/$3->floatstore[0];
								//otherwise an error will occur
								else
								{
									//tempval->floatstore[0]=numeric_limits<float>::infinity();
									errorout<<"Error at line "<<line_count<<" : Divide by zero"<<endl;
									errors++; 
								}							
							}
							//second value is array
							else if($3->getKeyType()=="ARA")
							{
								//nonzero value,nonzero result
								if($3->floatstore[$3->getAraIndex()]!=0)
								{
									tempval->floatstore[0]=$1->floatstore[$1->getAraIndex()]/$3->floatstore[$3->getAraIndex()];
								}
								//otherwise there will be an error
								else
								{
									//tempval->floatstore[0]=numeric_limits<float>::infinity();
									errorout<<"Error at line "<<line_count<<" : Divide by zero"<<endl;
									errors++; 
								}
							}
						}
					}
					//ultimate value is stored
					$$=tempval;
				}
				//second value is float
				//the answer will be float
				else if($3->getReturnType()=="FLOAT")
				{
					//float value is ready to store
					SymbolInfo* tempval=new SymbolInfo("FLOAT");
					//first value is int
					if($1->getReturnType()=="INT")
					{
						//first value is variable
						if($1->getKeyType()=="VAR")
						{
							//second value is variable
							if($3->getKeyType()=="VAR")
							{
								//nonzero value, nonzero result
								if($3->floatstore[0]!=0)
									tempval->floatstore[0]=$1->intstore[0]/$3->floatstore[0];
								//otherwise there will be an error
								else
								{
									//tempval->floatstore[0]=numeric_limits<float>::infinity();
									errorout<<"Error at line "<<line_count<<" : Divide by zero"<<endl;
									errors++; 
								}							
							}
							//second value is array
							else if($3->getKeyType()=="ARA")
							{
								//nonzero value,nonzero result
								if($3->floatstore[$3->getAraIndex()]!=0)
									tempval->floatstore[0]=$1->intstore[0]/$3->floatstore[$3->getAraIndex()];
								//otherwise there will be an error
								else
								{
									//tempval->floatstore[0]=numeric_limits<float>::infinity();
									errorout<<"Error at line "<<line_count<<" : Divide by zero"<<endl;
									errors++; 
								}
							}
						}
						//first value is array
						else if($1->getKeyType()=="ARA")
						{
							//second value is variable
							if($3->getKeyType()=="VAR")
							{
								//nonzero value, nonzero result
								if($3->floatstore[0]!=0)
									tempval->floatstore[0]=$1->intstore[$1->getAraIndex()]/$3->floatstore[0];
								//otherwise there will be an error
								else
								{
									//temp->floatstore[0]=numeric_limits<float>::infinity();
									errorout<<"Error at line "<<line_count<<" : Divide by zero"<<endl;
									errors++; 
								}							
							}
							//second value is array
							else if($3->getKeyType()=="ARA")
							{
								//nonzero value,nonzero result
								if($3->floatstore[$3->getAraIndex()]!=0)
								{
									tempval->floatstore[0]=$1->intstore[$1->getAraIndex()]/$3->floatstore[$3->getAraIndex()];
								}
								//otherwise there will be an error
								else
								{
									//tempval->floatstore[0]=numeric_limits<float>::infinity();
									errorout<<"Error at line "<<line_count<<" : Divide by zero"<<endl;
									errors++; 	
								}
							}
						}
					}
					//first value is float
					else if($1->getReturnType()=="FLOAT")
					{
						//first value is variable
						if($1->getKeyType()=="VAR")
						{
							//second value is variable
							if($3->getKeyType()=="VAR")
							{
								//nonzero value, nonzero result
								if($3->floatstore[0]!=0)
									tempval->floatstore[0]=$1->floatstore[0]/$3->floatstore[0];
								//otherwise there will be an error
								else
								{
									//tempval->floatstore[0]=numeric_limits<float>::infinity();
									errorout<<"Error at line "<<line_count<<" : Divide by zero"<<endl;
									errors++; 
								}							
							}
							//second value is array
							else if($3->getKeyType()=="ARA")
							{
								//nonzero value, nonzero result
								if($3->floatstore[$3->getAraIndex()]!=0)
									tempval->floatstore[0]=$1->floatstore[0]/$3->floatstore[$3->getAraIndex()];
								//otherwise there will be an error
								else
								{
									//tempval->floatstore[0]=numeric_limits<float>::infinity();
									errorout<<"Error at line "<<line_count<<" : Divide by zero"<<endl;
									errors++; 
								}
							}
						}
						//first value is array
						else if($1->getKeyType()=="ARA")
						{
							//second value is variable
							if($3->getKeyType()=="VAR")
							{
								//nonzero value, nonzero result
								if($3->floatstore[0]!=0)
									tempval->floatstore[0]=$1->floatstore[$1->getAraIndex()]/$3->floatstore[0];
								//otherwise there will be an error
								else
								{
									//tempval->floatstore[0]=numeric_limits<float>::infinity();
									errorout<<"Error at line "<<line_count<<" : Divide by zero"<<endl;
									errors++; 
								}							
							}
							//second value is array
							else if($3->getKeyType()=="ARA")
							{
								//nonzero value, nonzero result
								if($3->floatstore[$3->getAraIndex()]!=0)
								{
									tempval->floatstore[0]=$1->floatstore[$1->getAraIndex()]/$3->floatstore[$3->getAraIndex()];
								}
								//otherwise there will be an error
								else
								{
									//tempval->floatstore[0]=numeric_limits<float>::infinity();
									errorout<<"Error at line "<<line_count<<" : Divide by zero"<<endl;
									errors++; 
								}
							}
						}
					}	
					//ultimate value is stored			
					$$=tempval;
				}
				//both values is int
				//the answer will be int
				else if($3->getReturnType()=="INT"&&$1->getReturnType()=="INT")
				{
					//int value is ready to store
					SymbolInfo* tempval=new SymbolInfo("INT");
					//first value is variable
					if($1->getKeyType()=="VAR")
					{	
						//second value is variable
						if($3->getKeyType()=="VAR")
						{		
							//nonzero value,nonzero result	
							if($3->intstore[0]!=0)
								tempval->intstore[0]=$1->intstore[0]/$3->intstore[0];
							//otherwise there will be an error
							else
							{
								//tempval->intstore[0]=numeric_limits<int>::max();
								errorout<<"Error at line "<<line_count<<" : Divide by zero"<<endl;
								errors++; 
							}
						}
						//second value is array
						else if($3->getKeyType()=="ARA")
						{
							//nonzero value,nonzero result
							if($3->intstore[$3->getAraIndex()]!=0)
								tempval->intstore[0]=$1->intstore[0]/$3->intstore[$3->getAraIndex()];
							//otherwise there will be an error
							else
							{
								//tempval->intstore[0]=numeric_limits<int>::max();
								errorout<<"Error at line "<<line_count<<" : Divide by zero"<<endl;
								errors++; 
							}
						}
					}
					//first value is array
					else if($1->getKeyType()=="ARA")
					{
						//second value is variable
						if($3->getKeyType()=="VAR")
						{			
							//nonzero value,nonzero result
							if($3->intstore[0]!=0)
								tempval->intstore[0]=$1->intstore[$1->getAraIndex()]/$3->intstore[0];
							//otherwise there will be an error
							else
							{
								//tempval->intstore[0]=numeric_limits<int>::max();
								errorout<<"Error at line "<<line_count<<" : Divide by zero"<<endl;
								errors++; 
							}
						}
						//second value is array
						else if($3->getKeyType()=="ARA")
						{
							//nonzero value,nonzero result
							if($3->intstore[$3->getAraIndex()]!=0)
							{
								tempval->intstore[0]=$1->intstore[$1->getAraIndex()]/$3->intstore[$3->getAraIndex()];
							}
							//otherwise there will be an error
							else
							{
								//tempval->floatstore[0]=numeric_limits<int>::max();
								errorout<<"Error at line "<<line_count<<" : Divide by zero"<<endl;
								errors++; 
							}
						}
					}
					//ultimate value is stored
					$$=tempval;
				}
			}
			//MULOP is %
			else if($2->getValue()=="%")
			{
				//answer will be int keyword
				//int value is ready to store
				SymbolInfo* tempval=new SymbolInfo("INT");
				//variable or array type
				//this requires a variable type
				//not sure, is this necessary ?
				tempval->setkeyType("VAR");
				//values should be int keyword
				//otherwise an error
				if($1->getReturnType()=="FLOAT"||$3->getReturnType()=="FLOAT")
				{
					errorout<<"Error at line "<<line_count<<" : Unsuported operand for mod operator"<<endl;
					errors++; 
				}
				else if($1->getReturnType()=="INT"&&$3->getReturnType()=="INT")
				{
					//first value is variable
					if($1->getKeyType()=="VAR")
					{
						//second value is variable
						if($3->getKeyType()=="VAR")
							tempval->intstore[0]=($1->intstore[0])%($3->intstore[0]);
						//second value is array
						else 
							tempval->intstore[0]=($1->intstore[0])%($3->intstore[$3->getAraIndex()]);					
					}
					//first value is array
					else
					{
						//second value is variable
						if($3->getKeyType()=="VAR")
							tempval->intstore[0]=($1->intstore[$1->getAraIndex()])%($3->intstore[0]);
						//second value is array
						else 
							tempval->intstore[0]=($1->intstore[$1->getAraIndex()])%($3->intstore[$3->getAraIndex()]);					
					}
				}
				//ultimate result is stored
				$$=tempval;
			}
		}
     ;

unary_expression : ADDOP unary_expression  
			{
				logout<<"At line "<<line_count<< " : unary_expression : ADDOP unary_expression\n"<< endl;
				//in this case, only ADDOP - is need
				if($1->getValue()=="-")
				{
					//value can be array or variable
					//if the value is variable
					if($2->getReturnType()=="VAR")
					{	
						//int value
						if($2->getReturnType()=="INT")
							$2->intstore[0]=(-1)*($2->intstore[0]); //the value is changed
						//float value
						else
							$2->floatstore[0]=(-1)*($2->floatstore[0]); //the value is changed
					}
					else if($2->getReturnType()=="ARA")
					{
						//int value
						if($2->getReturnType()=="INT")
							$2->intstore[$2->getAraIndex()] = (-1)*($2->intstore[$2->getAraIndex()]); //the value is changed
						//float value
						else
							$2->floatstore[$2->getAraIndex()] = (-1)*($2->floatstore[$2->getAraIndex()]); //the value is changed
					}
				}
				//ultimate value is stored
				$$=$2;
			}
		 | NOT unary_expression 
			{
				logout<<"At line "<<line_count<< " : unary_expression : NOT unary_expression \n"<< endl;
				//answer will 0 or 1
				//answer will be int
				//int value is ready to store
				SymbolInfo* tempval=new SymbolInfo("INT");
				//variable or array type
				//this requires a variable type
				//not sure, is this necessary ?
				tempval->setkeyType("VAR");
				int val;
				//both int and float value can access this process
				//if the value is int
				if($2->getReturnType()=="INT")
				{
					//if the value is variable
					if($2->getKeyType()=="VAR")
						val=$2->intstore[0];
					//if the value is array
					else if($2->getKeyType()=="ARA")
						val=$2->intstore[$2->getAraIndex()];
				}
				//if the value is float
				else if($2->getReturnType()=="FLOAT")
				{
					//if the value is variable
					if($2->getKeyType()=="VAR")
						 val=(int)$2->floatstore[0];
					//if the value is array
					else if($2->getKeyType()=="ARA")
						 val=(int)$2->floatstore[$2->getAraIndex()];
				} 
				//not process
				if(val!=0)
					 val=0;
				else
					 val=1;
				//int value is stored
				//0 or 1
				tempval->intstore[0]=val;
				//the ultimate value is stored
				$$=tempval;
			}
		 | factor 
			{
				logout<<"At line "<<line_count<< " : unary_expression : factor\n"<< endl;
			
				//semantic check			
				//storing semantic value 
				$$=$1;
				$$->intstore.push_back(0); //if the term is int
				$$->floatstore.push_back(0); //if the term is float 
				//considering it both
				// for next term semantic check
			}
		 ;
	
factor	: variable 
		{
			logout<<"At line "<<line_count<< " : factor : variable\n"<< endl;
		}
	| ID LPAREN argument_list RPAREN
		{
			logout<<"At line "<<line_count<< " : factor : variable\n"<< endl;
			//it's for a function call which returns something
			//printing the id
			logout<<$1->getValue()<<endl;
			//an object is ready for checking
			SymbolInfo *tempval=new SymbolInfo();
			//checking the function name
			tempval=symbltable.lookTable($1->getValue(),"FUNC");
			//if the function doesn't exist
			if(tempval==NULL)
			{
				errorout<<"Error at line "<< line_count<<" : Function "<<$1->getValue()<<" doesn't exist"<<endl;
			}
			//if the function exist
			else
			{
				//the factor is in previous grammer ADDOP something, that means it will return something
				//if we get void, then there will occur a problem
				if(tempval->getFuncRet()=="VOID")
				{
					errorout<<"Error at line "<<line_count<<" : Function " <<$1->getValue()<<" returns void"<<endl;
				} 
				else
				{ 
					// an object is ready to store which contains the return type keyword
					SymbolInfo *tempval2=new SymbolInfo($1->getFuncRet());
					//values are kept for future semantic check
					//if it is int
					if(tempval2->getReturnType()=="INT")
						tempval2->intstore[0]=0;
					//if it is float
					else if(tempval2->getReturnType()=="FLOAT")
						tempval2->floatstore[0]=0;
					//if it is char
					else if(tempval2->getReturnType()=="CHAR")
						tempval2->charstore[0]='\0';
					$$=tempval2;
				}
			}
		}
	| LPAREN expression RPAREN
		{
			logout<<"At line "<<line_count<< " : factor : LPAREN expression RPAREN\n"<< endl;
			$$=$2;
		}
	| CONST_INT 
		{
			logout<<"At line "<<line_count<< " : factor : CONST_INT\n"<< endl;
			//the number is printed out
			logout<<$1->getValue()<<endl;
			//the number is set as an int
			$1->setReturnType("INT");
			//type is set as an varaible
			//not sure is it necessary(have to check)
			$1->setkeyType("VAR");
			//atoi works as an conversion of array of character to int
			//string is converted to int			
			$1->intstore[0]=atoi($1->getValue().c_str());
			//ultimate value is stored
			$$=$1;
		}
	| CONST_FLOAT
		{
			logout<<"At line "<<line_count<< " : factor : CONST_FLOAT\n"<< endl;
			//the number is printed out
			logout<<$1->getValue()<<endl;
			//the number is set as an int
			$1->setReturnType("FLOAT");
			//type is set as an varaible
			//not sure is it necessary(have to check)
			$1->setkeyType("VAR");
			//atof works as an conversion of array of character to float
			//string is converted to float			
			$1->intstore[0]=atof($1->getValue().c_str());
			//ultimate value is stored
			$$=$1;
		}
	| variable INCOP 
		{
			logout<<"At line "<<line_count<< " : factor : variable INCOP\n"<< endl;
			//value can be array or variable
			if($1->getKeyType()=="ARA")
			{
				//first value is int
				if($1->getReturnType()=="INT")
				{
					$1->intstore[$1->getAraIndex()]=$1->intstore[$1->getAraIndex()]+1; 
				}
				//first value is float
				else if($1->getReturnType()=="FLOAT")
				{
					$1->floatstore[$1->getAraIndex()]=$1->floatstore[$1->getAraIndex()]+1.0; 
				}			
			}
			//value is array
			else if($1->getKeyType()=="VAR")
			{
				//first value is int
				if($1->getReturnType()=="INT")
				{
					$1->intstore[0]=$1->intstore[0]+1; 
				}
				//first value is float
				else if($1->getReturnType()=="FLOAT"){
					$1->floatstore[0]=$1->floatstore[0]+1.0; 
				}					
			}
			//value is character
			//error
			else if($1->getKeyType()=="CHAR")
			{
				//errorout<<"Error at line "<<line_count<<" Character varaible can't increase "<<endl; 
			}
			//value is stored
			$$=$1;
		}
	| variable DECOP
		{
			logout<<"At line "<<line_count<< " : factor : variable DECOP\n"<< endl;
			//value can be array or variable
			if($1->getKeyType()=="ARA")
			{
				//first value is int
				if($1->getReturnType()=="INT")
				{
					$1->intstore[$1->getAraIndex()]=$1->intstore[$1->getAraIndex()]-1; 
				}
				//first value is float
				else if($1->getReturnType()=="FLOAT")
				{
					$1->floatstore[$1->getAraIndex()]=$1->floatstore[$1->getAraIndex()]-1.0; 
				}			
			}
			//value is array
			else if($1->getKeyType()=="VAR")
			{
				//first value is int
				if($1->getReturnType()=="INT")
				{
					$1->intstore[0]=$1->intstore[0]-1; 
				}
				//first value is float
				else if($1->getReturnType()=="FLOAT"){
					$1->floatstore[0]=$1->floatstore[0]-1.0; 
				}					
			}
			//value is character
			//error
			else if($1->getKeyType()=="CHAR")
			{
				//errorout<<"Error at line "<<line_count<<" Character varaible can't increase "<<endl; 
			}
			//value is stored
			$$=$1;
		}
	;
	
argument_list : arguments
			{
				logout<<"At line "<<line_count<< " : argument_list : arguments\n"<< endl;
			}
			  |
			  ;
	
arguments : arguments COMMA logic_expression
		{
			logout<<"At line "<<line_count<< " : arguments : arguments COMMA logic_expression\n"<< endl;
		}
	      | logic_expression
			{
				logout<<"At line "<<line_count<< " : arguments : logic_expression\n"<< endl;
			}
	      ;
 

%%

int main(int argc,char *argv[])
{

	if((yyin=fopen(argv[1],"r"))==NULL)
	{
		printf("Cannot Open Input File.\n");
		exit(1);
	}

	logout.open("1505044_log.txt");
	errorout.open("1505044_errors.txt");
	
	
	yyparse();
	
	logout<<"Total Lines : "<<line_count<<endl; 
	
	logout.close();
	errorout.close();

	return 0;
}
