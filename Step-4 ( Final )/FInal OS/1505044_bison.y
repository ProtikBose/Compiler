%{
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <vector>
#include <string>
#include <limits>
#include <sstream>
#include "1505044symbolTable.h"

//#define YYSTYPE SymbolInfo*

using namespace std;

string variable_type;
int yyparse(void);
int yylex(void);
extern FILE *yyin;
string pCode="";
SymbolTable table(13);
int argnum=0;
vector<string>argvalue; 
bool funcflag=false;
extern int line_count;
int errors;
vector<SymbolInfo>parameter; 
string pList="";
string tSpec="";
string dList="";
string cStmt="";

string var_dec="";
string unitG="";
string programG="";
string func_dec="";
string varG="";
string factorG="";
string una_exp="";
string func_def="";
string com_stat="";
string stats="";
string stat="";
string exp_stat="";
string expG="";
string logic_exp="";
string rel_exp="";
string sim_exp="";
string termG="";
string arg_list="";
string argG="";
//string expList="";
vector<string>arrvar;
vector<int>arrvarlen;
vector<string>var;
vector<string>tempvar;
string ret_lab;
int labelCount=0;
int tempCount=0;
int maxTemp = 0;
int pTempCount = 0;
ofstream logout, errorout,asmout;

char *newLabel()
{
	char *lb= new char[4];
	strcpy(lb,"L");
	char b[3];
	sprintf(b,"%d", labelCount);
	labelCount++;
	strcat(lb,b);
	return lb;
}

char *newTemp()
{
	char *t= new char[4];
	strcpy(t,"t");
	char b[3];
	sprintf(b,"%d", tempCount);
	tempCount++;
	if(maxTemp < tempCount) maxTemp = tempCount;
	strcat(t,b);
	return t;
}

char *newPTemp()
{
	char *pt= new char[4];
	strcpy(pt,"tempo");
	char b[3];
	sprintf(b,"%d", pTempCount);
	pTempCount++;
	strcat(pt,b);
	return pt;
}

void yyerror(const char *s)
{
	//write your code
	printf("%s\n",s);
}


%}
%union{
SymbolInfo* symbolVal;
}

%token COMMENT IF ELSE FOR WHILE DO BREAK CONTINUE INT FLOAT CHAR DOUBLE VOID RETURN SWITCH CASE DEFAULT INCOP DECOP ASSIGNOP LPAREN RPAREN LCURL RCURL LTHIRD RTHIRD SEMICOLON COMMA STRING NOT PRINTLN BITOP
%token <symbolVal>ID 
%token <symbolVal>CONST_INT 
%token <symbolVal>CONST_FLOAT 
%token <symbolVal>CONST_CHAR 
%token <symbolVal>ADDOP
%token <symbolVal>MULOP
%token <symbolVal>LOGICOP
%token <symbolVal>RELOP

%type <symbolVal>program unit func_declaration func_definition parameter_list compound_statement var_declaration type_specifier declaration_list statements statement expression_statement variable expression logic_expression rel_expression simple_expression term unary_expression factor argument_list arguments

%error-verbose
%nonassoc second_precedence
%nonassoc ELSE

%%

start : program
		{
			
			//asmout<<1<<endl;
			
			logout<<"At line "<<line_count<<" : start : program\n"<<endl;
			logout<<pCode<<endl<<endl;
			for(int i=0;i<var.size();i++)
			{
				asmout<<var[i]<<" dw ?\n";			
			}

			for(int i=0;i<arrvar.size();i++)
			{
				asmout<<arrvar[i]<<" dw "<<arrvarlen[i]<<" dup(?)\n";
			}
			
			for(int i=0;i<tempvar.size();i++)
			{
				asmout<<tempvar[i]<<" dw ?\n";
			}

			
			asmout<<$1->asmcode<<endl;
		}
		;

program : program unit
		{
			logout<<"At line "<<line_count<<" : program : program unit\n"<<endl;
			programG=pCode+"\n"+unitG;
			pCode=programG;
			$$->setSaveCode(pCode);
			logout<<$$->getSaveCode()<<endl<<endl;
			$$=$1;
			$$->asmcode=$$->asmcode+$2->asmcode;
		} 
		| 
		unit
		{	
			logout<<"At line "<<line_count<<" : program : unit\n"<<endl;
			//pCode=pCode+$$->getSaveCode()+"\n";
			programG=pCode+"\n"+unitG;
			pCode=programG;
			$$->setSaveCode(pCode);
			logout<<$$->getSaveCode()<<endl<<endl;
			$$=$1;
			
		}
		;
	
unit : 	var_declaration
		{
			logout<<"At line "<<line_count<<" : unit : var_declaration\n"<<endl;
			unitG=var_dec;
			logout<<unitG<<endl<<endl;
			$$->setSaveCode(unitG);
			$$=$1;
		}
     	| 
     	func_declaration
     	{
			logout<<"At line "<<line_count<<" : unit : func_declaration\n"<<endl;
			unitG=func_dec;
			logout<<unitG<<endl<<endl;
			$$->setSaveCode(unitG);
			$$=$1;
     	}
     	| 
     	func_definition
     	{
			logout<<"At line "<<line_count<<" : unit : func_definition\n"<<endl;
			//logout<<$$->getSaveCode()<<endl;
			unitG=func_def;
			logout<<unitG<<endl<<endl;
			$$->setSaveCode(unitG);
			$$=$1;
     	}
     	;
     
func_declaration : 	type_specifier ID LPAREN parameter_list RPAREN SEMICOLON
					{
						logout<<"At line "<<line_count<<" : func_declaration : 	type_specifier ID LPAREN parameter_list RPAREN SEMICOLON\n"; 
						//logout<<$2->getValue()<<endl;
						//checking if it exists
						SymbolInfo *tempval=table.lookTable($2->getValue(),"FUNC");
						//if it exists, then error
						if(tempval!=NULL)
						{
							errorout<<"Error at line "<<line_count<<" Function "<<$2->getValue()<<" already declared" <<endl;
							errors++;
						}
						//otherwise it will do perfectly well
						else 
						{
							SymbolInfo* tempval2=table.finalInsert($2->getValue(),"ID");
							tempval2->setReturnType("FUNC");
							tempval2->setFuncRet($1->getKeyType());
							for(int i=0;i<argvalue.size();i++){
								tempval2->pList.push_back(argvalue[i]);					
							}
							argvalue.clear();
							$$->setSaveCode($$->getSaveCode()+" "+$2->getValue()+"("+pList+")"+";"+"\n");
							func_dec=tSpec+" "+$2->getValue()+"("+pList+")"+";";
							logout<<func_dec<<endl<<endl;
							$$->setSaveCode(func_dec);
							tSpec="";
							pList="";
						}
						//funcParam.exitScope();
					}
					|type_specifier ID LPAREN parameter_list RPAREN error
					{
						errorout << "Error at line " << line_count << "; missing" << endl << endl;
						errors++;
					}
		 			;
		 
func_definition : type_specifier ID LPAREN parameter_list RPAREN compound_statement
				{
				logout << "At line " << line_count << " : func_definition : type_specifier ID LPAREN parameter_list RPAREN compound_statement\n";
				//logout << $2->getValue() << endl << endl;
				SymbolInfo *tempval = table.lookTable($2->getValue(), "FUNC");
				if(argvalue.size() != argnum){
					errorout << "Error at line " << line_count << " Parameter mismatch for Function "<< $2->getValue() << endl << endl;
					argvalue.clear(); argnum = 0;
					errors++;
				}												
				if(tempval != NULL){
					//logout << "Function " << $2->getValue() <<" already declared" << endl;
					if(tempval->isFuncDefined()== true){
						errorout << "Error at line " << line_count << "Function "<< $2->getValue() <<" already defined" << endl << endl;
						errors++;
						argvalue.clear();
						argnum = 0;
					}
					else if(tempval->getFuncRet() != $1->getKeyType()){
						errorout << "Error at line " << line_count << "Function "<< $2->getValue() <<" :return type doesn't match declaration" << endl << endl;
						errors++;
						argvalue.clear();argnum = 0; 
					} 
					else if(tempval->pList.size() != argvalue.size()){
						errorout << "Error at line " << line_count << "Function "<< $2->getValue() <<" :Parameter list doesn not match declaration" << endl << endl;
						argvalue.clear();argnum = 0;
						errors++;					
					}
					else{
						for(int i = 0; i<tempval->pList.size(); i++){
							if(tempval->pList[i] != argvalue[i]){
								errorout << "Error at line " << line_count << "Function "<< $2->getValue()<< " :argument mismatch" << endl << endl;
								argvalue.clear();argnum = 0;
								errors++;	
							}
						}				
					}
				}
				else{
					SymbolInfo* tempval = new SymbolInfo();
					tempval = table.finalInsert($2->getValue(), "ID");
					//logout << $2->getValue() << " Function inserted" << endl;
					tempval->setReturnType("FUNC");
					tempval->setFuncRet($1->getKeyType());
					//
					for(int i = 0; i<argvalue.size(); i++){
						tempval->pList.push_back(argvalue[i]);					
					}
					tempval->setFuncDefined();
					$$->setSaveCode($$->getSaveCode()+" "+$2->getValue()+"("+pList+")"+"{"+"\n"+cStmt+"\n"+"}"+"\n");
					//logout<<$$->getSaveCode()<<endl<<endl;
					
					
				}
				argvalue.clear();
				argnum = 0;
				func_def=$1->getValue()+" "+$2->getValue()+"("+pList+")"+com_stat+"\n";
				logout<<func_def<<endl<<endl;
				pList="";
				cStmt="";
				com_stat="";
				$$->setSaveCode(func_def);
				$$->asmcode=$$->asmcode+$6->asmcode;
	
				//funcParam.exitScope();
				}
 		 		;
 		 
parameter_list  : parameter_list COMMA type_specifier ID
				{
					logout << "At line " << line_count << " : parameter_list  : parameter_list COMMA type_specifier ID\n";
					//logout << $4->getValue() << endl << endl;
					argvalue.push_back(variable_type);//changed from $3->getKeyType()
					argnum++;
					//SymbolInfo* tempval = funcParam.finalInsert($4->getValue(), $4->getKeyword());					
					//tempval->setReturnType("VAR");
					//tempval->setkeyType($3->getKeyType());
					$4->setReturnType("VAR");
					$4->setkeyType(variable_type);//changed from $3->getKeyType()
					SymbolInfo* tempval = new SymbolInfo($4->getValue(), $4->getKeyword());
					tempval->setReturnType("VAR");
					
					parameter.push_back(*tempval);
					$$->setSaveCode($$->getSaveCode()+" "+","+tSpec+" "+$4->getValue());
					//logout<<$$->getSaveCode()<<endl<<endl;
					pList=pList+" "+","+tSpec+" "+$4->getValue();
					//pCode=pCode+" "+","+tSpec+" "+$4->getValue();
					logout<<pList<<endl<<endl;
					$$->setSaveCode(pList);
				
				} 
 				| parameter_list COMMA type_specifier	
				{					
					logout << "At line " << line_count << " : parameter_list  : parameter_list COMMA type_specifier\n"<< endl;
					argvalue.push_back($3->getKeyType());
					$$->setSaveCode($$->getSaveCode()+" "+","+tSpec);
					//logout<<$$->getSaveCode()<<endl<<endl;
					pList=pList+" "+","+tSpec;
					logout<<pList<<endl<<endl;
					$$->setSaveCode(pList);
				}
 				| type_specifier ID
				{
					logout << "At line " << line_count << " : parameter_list  : type_specifier ID\n";
					//logout << $2->getValue() << endl << endl;
					//argvalue.clear();
					argvalue.push_back(variable_type);//$1->getKeyType()
					argnum++;
					//SymbolInfo* tempval = funcParam.finalInsert($2->getValue(), $2->getKeyword());
					//tempval->setReturnType("VAR");
					//tempval->setkeyType($1->getKeyType());
					$2->setReturnType("VAR");
					$2->setkeyType(variable_type);//$1->getKeyType()
					parameter.push_back(*$2);
					$$->setSaveCode($$->getSaveCode()+" "+$2->getValue());
					//logout<<$$->getSaveCode()<<endl<<endl;
					pList=pList+" "+tSpec+" "+$2->getValue();
					logout<<pList<<endl<<endl;
					$$->setSaveCode(pList);
				
				}
 				| type_specifier
				{
					logout << "At line " << line_count << " : parameter_list  : type_specifier\n"<< endl;
					//argvalue.clear();
					argvalue.push_back(variable_type);
					$$->setSaveCode($$->getSaveCode());
					//logout<<$$->getSaveCode()<<endl<<endl;
					pList=pList+" "+tSpec;
					logout<<pList<<endl<<endl;
					$$->setSaveCode(pList);
				}
				|{//logout << "Empty parameter " << line_count << endl;
				}
 				;
 		
compound_statement : 	LCURL 
						{
							table.enterScope(); 
							for(int i = 0; i<parameter.size(); i++) table.insertTable(parameter[i]);
							parameter.clear();
						} statements RCURL{table.exitScope();}
						{
							logout << "At line " << line_count << " : compound_statement : LCURL statements RCURL\n"<< endl;
							$$=$3;
							$$->setSaveCode($$->getSaveCode()+" "+"{"+"\n"+stats+"\n"+"}");
							com_stat=com_stat+"{"+"\n"+stats+"\n"+"}";
							logout<<com_stat<<endl<<endl;
							$$->setSaveCode(com_stat);
							//asmout<<$$->asmcode;
							
						}
 		    			| LCURL RCURL
						{
							logout << "At line " << line_count << " : compound_statement : LCURL RCURL\n"<< endl;
							$$->setSaveCode($$->getSaveCode()+" "+"{"+"\n"+"\n"+"}");
							com_stat=com_stat+"{"+"\n"+"\n"+"}";
							logout<<com_stat<<endl<<endl;
							$$->setSaveCode(com_stat);
						}
 		    			;
 		    
var_declaration : type_specifier declaration_list SEMICOLON
			{
				logout << "At line " << line_count << " : var_declaration : type_specifier declaration_list SEMICOLON\n"<< endl;
				//$$->setSaveCode(pCode+";"+"\n");
				//logout<<$$->getSaveCode()<<endl<<endl;
				var_dec=tSpec+" "+dList+" "+";"+"\n";
				
				//tSpec=tSpec+" "+dList+";";
				logout<<var_dec<<endl;
				tSpec="";
				dList="";
				$$->setSaveCode(var_dec);
			}
				|type_specifier declaration_list error
				{
						errorout << "Error at line " << line_count << "; missing" << endl << endl;
						errors++;
				} 		 		
				;
 		 
type_specifier	: INT
				{
					logout<<"At line "<<line_count<<" : type_specifier : INT"<<endl<<endl; 
					SymbolInfo* s=new SymbolInfo("INT");
					variable_type="INT";
					$$=s;
					
					tSpec="int";
					$$->setValue(tSpec);
					logout<<tSpec<<endl<<endl;
					$$->setSaveCode("int");
					
				}
 				| FLOAT
				{	
					logout << "At line " << line_count << " : type_specifier	: FLOAT\n"<< endl;
					SymbolInfo* s= new SymbolInfo("FLOAT");
					variable_type = "FLOAT";
					$$=s;
					tSpec="float";
					$$->setValue(tSpec);
					logout<<tSpec<<endl<<endl;
					$$->setSaveCode("float");
				}
 				| VOID
				{
					logout << "At line " << line_count << " : type_specifier	: VOID\n"<< endl;
					SymbolInfo* s= new SymbolInfo("VOID");
					variable_type = "VOID";
					$$=s;
					tSpec="void";
					$$->setValue(tSpec);
					logout<<tSpec<<endl<<endl;
					$$->setSaveCode("void");
				}
 				;
 		
declaration_list : 	declaration_list COMMA ID
					{
						logout << "At line " << line_count << " : declaration_list : 	declaration_list COMMA ID\n";
						//logout << $3->getValue() << endl << endl;
						if(variable_type == "VOID"){
							errorout << "Error at line " << line_count << " :variable type can't be void" << endl << endl;
							errors++;
						}
						else{
							SymbolInfo* tempval = table.lookTable($3->getValue(), "VAR");
							if(tempval != NULL){
							errorout << "Error at line " << line_count << ": Variable "<< $3->getValue() <<" already declared" << endl << endl;	
							errors++;	
							}
							else
							{
								//SymbolInfo* tempval2 = table.finalInsert($3->getValue(), $3->getKeyword());
								//tempval2->setkeyType(variable_type);
								//tempval2->setReturnType("VAR");
								SymbolInfo* tempval2 = new SymbolInfo($3->getValue(), $3->getKeyword());
								tempval2->setkeyType(variable_type);
								tempval2->setReturnType("VAR");
								table.insertTable(*tempval2);
								//table.printAll(logout);
								//$$=tempval2;
							
								$$->setSaveCode($$->getSaveCode()+" "+","+$3->getValue());
								//logout<<$$->getSaveCode()<<endl<<endl;
								//pCode=pCode+" "+","+$3->getValue();
								dList=dList+" "+","+$3->getValue();
								logout<<dList<<endl<<endl;

								//pCode=pCode+" "+$$->getSaveCode();
								//logout << $$->getValue() << endl << endl;
							}
						}
						
					}
 					| declaration_list COMMA ID LTHIRD CONST_INT RTHIRD
					{
						logout << "At line " << line_count << " : declaration_list : 	declaration_list COMMA ID LTHIRD CONST_INT RTHIRD\n";
						//logout << $3->getValue() << endl;
						//logout << $5->getValue() << endl << endl;
						if(variable_type == "VOID"){
							errorout << "Error at line " << line_count << " : array type can't be void" << endl << endl;
							errors++;
						}
						else{
							SymbolInfo* tempval = table.lookTable($3->getValue(), "ARA");
							if(tempval!= NULL){
							errorout << "Error at line " << line_count << " : Array "<< $3->getValue()<< " already declared" << endl << endl;
								errors++;			
							}
							else{
								SymbolInfo* tempval2 = new SymbolInfo($3->getValue(), $3->getKeyword());
								tempval2->setkeyType(variable_type);
								tempval2->setReturnType("ARA");
								int araSize = atoi(($5->getValue()).c_str());
								tempval2->setAraLength(araSize);
								if(variable_type == "INT"){								
									for(int i = tempval2->intstore.size(); i<araSize; i++){
										tempval2->intstore.push_back(0);
									}							
								}
								else if(variable_type == "FLOAT"){								
									for(int i = tempval2->floatstore.size(); i<araSize; i++){
										tempval2->floatstore.push_back(0);
									}							
								}
								else if(variable_type == "CHAR"){								
									for(int i = tempval2->charstore.size(); i<araSize; i++){
										tempval2->charstore.push_back('\0');
									}							
								}
								table.insertTable(*tempval2);						
								//table.printAll(logout);
								$$->setSaveCode($$->getSaveCode()+" "+","+$3->getValue()+"["+$5->getValue()+"]");
								//logout<<$$->getSaveCode()<<endl<<endl;
								//pCode=pCode+" "+","+$3->getValue()+"["+$5->getValue()+"]";
								dList=dList+" "+","+$3->getValue()+"["+$5->getValue()+"]";
								logout<<dList<<endl<<endl;
							}
						}

					}
 					| ID
					{
						logout << "At line " << line_count << " : declaration_list :	ID\n";
						//logout << $1->getValue() << endl << endl;
						if(variable_type == "VOID"){
							errorout << "Error at line " << line_count << " :variable type can't be void" << endl << endl;
							errors++;
						}
						else{
							SymbolInfo* tempval = table.lookTable($1->getValue(), "ARA");
							if(tempval!= NULL){
							errorout << "Error at line " << line_count << ": Variable "<< $1->getValue() <<" already declared" << endl << endl;	
								errors++;		
							}
							else{
								SymbolInfo* tempval2 = new SymbolInfo($1->getValue(), $1->getKeyword());
								tempval2->setkeyType(variable_type);
								tempval2->setReturnType("VAR");
								table.insertTable(*tempval2);
								//table.printAll(logout);
								$$=tempval2;
								dList=$1->getValue();
								logout<<dList<<endl<<endl;
								$$->setSaveCode($1->getValue());
							}
						}
					}
					| ID LTHIRD CONST_INT RTHIRD
					{
						logout << "At line " << line_count << " : declaration_list :	ID LTHIRD CONST_INT RTHIRD\n";
						//logout << $1->getValue() << endl;
						//logout << $3->getValue() << endl << endl;
						if(variable_type == "VOID"){
							errorout << "Error at line " << line_count << " :array type can't be void" << endl << endl;
							errors++;
						}
						else{
							SymbolInfo* tempval = table.lookTable($1->getValue(), "ARA");
							if(tempval!= NULL){
								errorout << "Error at line " << line_count << ": Array "<< $1->getValue() <<" already declared" << endl << endl;	
								errors++;
							}
							else{
								SymbolInfo* tempval2 = new SymbolInfo($1->getValue(), $1->getKeyword());
								tempval2->setkeyType(variable_type);
								tempval2->setReturnType("ARA");
								int araSize = atoi(($3->getValue()).c_str());
								tempval2->setAraLength(araSize);
								table.insertTable(*tempval2);
								//table.printAll(logout);
								$$->setSaveCode(" "+$1->getValue()+"["+$3->getValue()+"]");
								//logout<<$$->getSaveCode()<<endl<<endl;	
								//pCode=pCode+" "+$1->getValue()+"["+$3->getValue()+"]";
								dList=	" "+$1->getValue()+"["+$3->getValue()+"]";
								logout<<dList<<endl<<endl;	
							}
						}
					}
											
					;
 		  
statements : statement
		{	
			logout<<"At line "<<line_count<< " : statements : statement\n"<< endl;
			stats=stat;
			$$=$1;
			logout<<stats<<endl<<endl;
			$$->setSaveCode(stats);
		}
	   | statements statement
		{
			logout<<"At line "<<line_count<< " : statements : statements statement\n"<< endl;
			$$=$1;
			$$->asmcode=$$->asmcode+$2->asmcode;
			delete $2;
			stats=stats+" "+stat+"\n";
			logout<<stats<<endl<<endl;
			$$->setSaveCode(stats);
			//asmout<<$$->asmcode;
		}
		
	   ;
statement : var_declaration
		{
			logout<<"At line "<<line_count<< " : statement : var_declaration\n"<< endl;
			stat=var_dec;
			logout<<stat<<endl<<endl;
			$$->setSaveCode(stat);
			//asmout<<$$->asmcode;
		}
	  | expression_statement
		{
			logout<<"At line "<<line_count<< " : statement : expression_statement\n"<< endl;
			stat=exp_stat;
			$$=$1;
			logout<<stat<<endl<<endl;
			$$->setSaveCode(stat);
		}
	  | compound_statement
		{
			logout<<"At line "<<line_count<< " : statement : compound_statement\n"<< endl;
			stat=com_stat;
			$$=$1;
			logout<<stat<<endl<<endl;
			$$->setSaveCode(stat);
		}
	  | FOR LPAREN expression_statement expression_statement expression RPAREN statement
		{
			logout<<"At line "<<line_count<< " : statement : FOR LPAREN expression_statement expression_statement expression RPAREN statement\n"<< endl;
			$$=$3;
			stat="for ("+$3->getValue()+" "+$4->getValue()+" "+expG+")"+"\n"+$7->getValue();
			logout<<stat<<endl<<endl;
			$$->setSaveCode(stat);
			char *lab1=newLabel();
			char *lab2=newLabel();
			$$->asmcode=$$->asmcode+" "+string(lab1)+":"+"\n";
			$$->asmcode=$$->asmcode+" "+$4->asmcode;
			$$->asmcode=$$->asmcode+" mov ax , "+$4->getValue()+"\n";
			$$->asmcode=$$->asmcode+" cmp ax , 0\n";
			$$->asmcode=$$->asmcode+" je "+string(lab2)+"\n";
			$$->asmcode=$$->asmcode+" "+ $7->asmcode;
			$$->asmcode=$$->asmcode+" "+ $5->asmcode;
			$$->asmcode=$$->asmcode+" jmp "+string(lab1)+"\n";
			$$->asmcode=$$->asmcode+" "+string(lab2)+":"+"\n";
		}
	  | IF LPAREN expression RPAREN statement %prec second_precedence
		{
			logout<<"At line "<<line_count<< " : statement : IF LPAREN expression RPAREN statement\n"<< endl;
			stat="if ("+expG+" )"+stat;
			$$=$3;
			logout<<stat<<endl<<endl;
			$$->setSaveCode(stat);
			char *label=newLabel();
			$$->asmcode+="mov ax, "+$3->getValue()+"\n";
			$$->asmcode+="cmp ax, 0\n";
			$$->asmcode+="je "+string(label)+"\n";
			$$->asmcode+=" "+$5->asmcode;
			$$->asmcode+=string(label)+":\n";
		}
	  | IF LPAREN expression RPAREN statement ELSE statement
		{
			logout<<"At line "<<line_count<< " : statement : IF LPAREN expression RPAREN statement ELSE statement\n"<< endl;
			stat="if("+expG+")"+"\n"+$5->getValue()+"\n"+"else"+"\n"+$7->getValue();
			$$=$3;
			logout<<stat<<endl<<endl;
			$$->setSaveCode(stat);
			char *lab1=newLabel(); //else
			char *lab2=newLabel();	//exit
			$$->asmcode=$$->asmcode+"mov ax, "+$3->getValue()+"\n";
			$$->asmcode=$$->asmcode+"cmp ax,0\n";
			$$->asmcode=$$->asmcode+"je "+string(lab1)+"\n";
			$$->asmcode=$$->asmcode+" "+$5->asmcode;
			$$->asmcode=$$->asmcode+"jmp "+string(lab2)+"\n";
			$$->asmcode=$$->asmcode+string(lab1)+":\n";
			$$->asmcode=$$->asmcode+" "+$7->asmcode;
			$$->asmcode=$$->asmcode+string(lab2)+":\n";
		}
	  | WHILE LPAREN expression RPAREN statement
		{
			logout<<"At line "<<line_count<< " : statement : WHILE LPAREN expression RPAREN statement\n"<< endl;
			stat="while("+expG+")"+"\n"+$5->getValue();
			$$=new SymbolInfo();
			logout<<stat<<endl<<endl;
			$$->setSaveCode(stat);
			char *lab1=newLabel(); //while
			char *lab2=newLabel();	//exit
			$$->asmcode=string(lab1)+":"+"\n"; 
			$$->asmcode=$$->asmcode+" "+$3->asmcode;
			$$->asmcode=$$->asmcode+"mov ax , "+$3->getValue()+"\n";
			$$->asmcode=$$->asmcode+"cmp ax , 0"+"\n";
			$$->asmcode=$$->asmcode+"je "+string(lab2)+"\n";
			$$->asmcode=$$->asmcode+" "+$5->asmcode;
			$$->asmcode=$$->asmcode+"jmp "+string(lab1)+"\n";
			$$->asmcode=$$->asmcode+string(lab2)+":"+"\n";
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
			stat="return "+expG+";";
			$$=$2;
			logout<<stat<<endl<<endl;
			$$->setSaveCode(stat);
			$$->asmcode=$$->asmcode+"mov dx,"+$2->getValue()+"\n";
			$$->asmcode=$$->asmcode+"jmp   "+string(ret_lab)+"\n";
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
					exp_stat=";";
					logout<<exp_stat<<endl<<endl;
					$$=new SymbolInfo(";","SEMICOLON");
					$$->setSaveCode(exp_stat);
					$$->asmcode="";
				}			
			| expression SEMICOLON 
				{
					logout<<"At line "<<line_count<< " : expression_statement : expression SEMICOLON\n"<< endl;
					exp_stat=expG+";";
					logout<<exp_stat<<endl<<endl;
					$$=$1;
					$$->setSaveCode(exp_stat);
				}
			| expression error
				{
					errorout<<"Error at line "<<line_count<<" : ; missing "<<endl;
					errors++;
				}
			;
	  
variable : 	ID
			{
				logout<<"At line "<<line_count<<" : variable : ID\n";
				//logout << $1->getValue() << endl << endl;
				SymbolInfo* tempval=table.lookTable($1->getValue(),"VAR");
				if(tempval == NULL){
					//logout << "Variable " << $1->getValue() << " doesn't exist" << endl;
					errorout<<"Error at line "<<line_count<<" : "<<$1->getValue()<<" doesn't exist"<<endl;					
					errors++;
				}
				else{
					$$=$1;
					$$->setSaveCode($$->getSaveCode()+""+$1->getValue());
					//logout<<$$->getSaveCode()<<endl<<endl;
					//pCode=pCode+""+$1->getValue();
					//variable_type = tempval->getKeyType();
					varG=$1->getValue();
					logout<<varG<<endl<<endl;
					$$->setSaveCode(varG);
					$$->asmcode="";
					$$->setValue($$->getValue()+to_string(table.scopeNum));
					var.push_back($$->getValue());
					$$->setKeyword("notarray");
				}			
			} 		
	 		| ID LTHIRD expression RTHIRD
			{
				logout << "At line " << line_count << " : variable : ID LTHIRD expression RTHIRD\n";
				//logout << $1->getValue() << endl << endl;
				SymbolInfo* tempval = table.lookTable($1->getValue(),"ARA");
				if(tempval == NULL){
				errorout << "Error at line " << line_count << " : " <<$1->getValue() << " doesn't exist" <<  endl << endl;					
					errors++;
					varG=$1->getValue()+"["+expG+"]";
					logout<<varG<<endl<<endl;
					$$->setValue(varG);
					$$->setSaveCode(varG);				
				}
				else{
					//$$ = tempval;
					
					$$=$1;
					varG=$1->getValue()+"["+expG+"]";
					logout<<varG<<endl<<endl;
					$$->setValue(varG);
					$$->setSaveCode(varG);
					$$->setKeyword("array");
					$$->setValue($$->getValue()+to_string(table.scopeNum));
					arrvar.push_back($$->getValue());
					arrvarlen.push_back($1->getAralength());
					$$->asmcode=$3->asmcode ;
					$$->asmcode=$$->asmcode+" mov bx, " +$3->getValue()+"\n";
					$$->asmcode=$$->asmcode+" add bx, bx\n";
					
					delete $3;
					//$$->setSaveCode($$->getSaveCode()+""+$1->getValue()+"["+expList+"]");
					//logout<<$$->getSaveCode()<<endl<<endl;
					//pCode=pCode+""+$1->getValue()+"["+expList+"]";
					//variable_type = tempval->getKeyType();
				}			
			} 
	 		;
	 
expression : logic_expression	
		{
			logout<<"At line "<<line_count<< " : expression : logic_expression\n"<< endl;
			$$=new SymbolInfo();
			//semantic check			
			//storing semantic value ( logic_expression)
			$$=$1;
			
			//considering it both
			// for next term semantic check
			//varG=$1->getValue()+"["+expList+"]";
			//logout<<varG<<endl<<endl;
			//$$->setSaveCode(varG);
			expG=logic_exp;
			logout<<expG<<endl<<endl;
			$$->setSaveCode(expG);
			
		}
	   | variable ASSIGNOP logic_expression 
		{
			logout<<"At line "<<line_count<< " : expression : variable ASSIGNOP logic_expression\n"<< endl;
			//semantic check
			string st=$1->getKeyType();

			//checking the variable type with the help of keyword
			
			$$=new SymbolInfo();
			//storing semantic value
			$$ = $1;
			//printing the value	
			//table.printAll(logout);	
			expG=$1->getValue()+"="+logic_exp;
			logout<<expG<<endl<<endl;
			$$->setSaveCode(expG);
			$$->asmcode=$3->asmcode+$1->asmcode;
			$$->asmcode+="mov ax, "+$3->getValue()+"\n";
			if($$->getKeyword()=="notarray")
			{ 
				$$->asmcode+= "mov "+$1->getValue()+", ax\n";
			}
				
			else
			{
				$$->asmcode+= "mov  "+$1->getValue()+"[bx], ax\n";
			}
				delete $3;
		}	
	   ;
			
logic_expression : rel_expression 	
			{
				logout<<"At line "<<line_count<< " : logic_expression : rel_expression\n"<< endl;
			
				//semantic check			
				//storing semantic value ( logic_expression)
				$$=$1;
				
				//considering it both
				// for next term semantic check
				logic_exp=rel_exp;
				logout<<logic_exp<<endl<<endl;
				$$->setSaveCode(logic_exp);
				//asmout<<$$->asmcode;
				
			}
		 | rel_expression LOGICOP rel_expression 
			{
				logout<<"At line "<<line_count<< " : logic_expression : rel_expression LOGICOP rel_expression\n"<< endl;
				//ultimate value of this expression will be 0 or 1
				//going to take an object with int keyword
				

				char * lab1=newLabel();
				char * lab2=newLabel();
				char * temp=newPTemp();
				$$=$1;
				$$->asmcode=$$->asmcode+$3->asmcode;
					

				
				string st=$2->getValue(); 
				//if the LOGICOP is &&
				if(st=="&&")
				{
					
					logic_exp=$1->getValue()+"&&"+$3->getValue();
					/* 
						Check whether both operands value is 1. If both are one set value of a temporary variable to 1
						otherwise 0
					*/
					$$->asmcode =$$->asmcode +"mov ax , " + $1->getValue() +"\n";
					$$->asmcode =$$->asmcode +"cmp ax , 0\n";
				 	$$->asmcode =$$->asmcode +"je " + string(lab1) +"\n";
					$$->asmcode =$$->asmcode +"mov ax , " + $3->getValue() +"\n";
					$$->asmcode =$$->asmcode +"cmp ax , 0\n";
					$$->asmcode =$$->asmcode +"je " + string(lab1) +"\n";
					$$->asmcode =$$->asmcode +"mov " + string(temp) + " , 1\n";
					$$->asmcode =$$->asmcode +"jmp " + string(lab2) + "\n";
					$$->asmcode =$$->asmcode +string(lab1) + ":\n" ;
					$$->asmcode =$$->asmcode +"mov " + string(temp) + ", 0\n";
					$$->asmcode =$$->asmcode +string(lab2) + ":\n";
					$$->setValue(temp+to_string(table.scopeNum));
					tempvar.push_back($$->getValue());
				}
				//if the LOGICOP is ||
				else if(st=="||")
				{
					
					logic_exp=$1->getValue()+"||"+$3->getValue();
					$$->asmcode =$$->asmcode +"mov ax , " + $1->getValue() +"\n";
					$$->asmcode =$$->asmcode +"cmp ax , 0\n";
				 	$$->asmcode =$$->asmcode +"jne " + string(lab1) +"\n";
					$$->asmcode =$$->asmcode +"mov ax , " + $3->getValue() +"\n";
					$$->asmcode =$$->asmcode +"cmp ax , 0\n";
					$$->asmcode =$$->asmcode +"jne " + string(lab1) +"\n";
					$$->asmcode =$$->asmcode +"mov " + string(temp) + " , 0\n";
					$$->asmcode =$$->asmcode +"jmp " + string(lab2) + "\n";
					$$->asmcode =$$->asmcode +string(lab1) + ":\n" ;
					$$->asmcode =$$->asmcode +"mov " + string(temp) + ", 1\n";
					$$->asmcode =$$->asmcode +string(lab2) + ":\n";
					$$->setValue(temp);
				}
				//storing the semantic value
				//$$=tempval;
				
				logout<<logic_exp<<endl<<endl;
				$$->setSaveCode(logic_exp);
				delete $3;
			}	
		 ;
			
rel_expression	: simple_expression 
			{
				
				logout<<"At line "<<line_count<< " : rel_expression : simple_expression\n"<< endl;
			
				//semantic check			
				//storing semantic value ( logic_expression)
				$$=$1;
				 
				//considering it both
				// for next term semantic check
				rel_exp=sim_exp;
				$$->setValue(rel_exp);
				logout<<rel_exp<<endl<<endl;
				$$->setSaveCode(rel_exp);
			
			}
		| simple_expression RELOP simple_expression
			{
				logout<<"At line "<<line_count<< " : rel_expression : simple_expression RELOP simple_expression\n"<< endl;
				//the ultimate result will be 0 or 1, that's why it's kept as int varaible
				SymbolInfo* tempval=new SymbolInfo("INT");
				string st=$2->getValue(); //the relop sign
				string var1=$1->getKeyType(); //getting the first simp.expression keyword
				string var2=$3->getKeyType(); //getting the second simp.expression keyword
				$$=$1;
				$$->asmcode=$$->asmcode+$3->asmcode;
				$$->asmcode=$$->asmcode+"mov ax, " + $1->getValue()+"\n";
				$$->asmcode=$$->asmcode+"cmp ax, " + $3->getValue()+"\n";
				char *lab1=newLabel();
				char *lab2=newLabel();
				char *temp=newPTemp();
				
				//if the RELOP is ==
				if(st=="==")
				{
					if(var1!=var2) //this doesn't occur error 
					{
						errorout<<"At line "<<line_count<<" type mismatch"<<endl;
						//type inequality doesn't matter
					}
					//$$=tempval;
					rel_exp=$1->getValue()+"="+$3->getValue();
					logout<<rel_exp<<endl<<endl;
					$$->setSaveCode(rel_exp);
					$$->asmcode=$$->asmcode+"je " + string(lab1)+"\n";
				}
				//if the RELOP is !=
				else if(st=="!=")
				{
					if(var1!=var2) //this doesn't occur error
					{
						errorout<<"At line "<<line_count<<" type mismatch"<<endl;
						//type inequality doesn't matter
					}
					
					rel_exp=$1->getValue()+"!"+$3->getValue();
					logout<<rel_exp<<endl<<endl;
					$$->setSaveCode(rel_exp);
					$$->asmcode=$$->asmcode+"jne "+string(lab1)+"\n";
				}
				//if the RELOP is <= or <
				//both term isn't required to be same keyword
				else if(st=="<"){
					$$->asmcode=$$->asmcode+"jl "+string(lab1)+"\n";
				}
				else if(st=="<="){
					$$->asmcode=$$->asmcode+"jle "+string(lab1)+"\n";
				}
				else if(st==">"){
					$$->asmcode=$$->asmcode+"jg "+string(lab1)+"\n";
				}
				else if(st==">="){
					$$->asmcode=$$->asmcode+"jge "+string(lab1)+"\n";
				}
				//stored in semantic value
				//$$=tempval;
				$$->asmcode=$$->asmcode+"mov "+string(temp) +", 0\n";
				$$->asmcode=$$->asmcode+"jmp "+string(lab2) +"\n";
				$$->asmcode=$$->asmcode+string(lab1)+":\n";
				$$->asmcode=$$->asmcode+"mov "+string(temp)+", 1\n";
				$$->asmcode=$$->asmcode+string(lab2)+":\n";
				$$->setValue(string(temp)+to_string(table.scopeNum));
				tempvar.push_back($$->getValue());
				delete $3;
				
			}	
		;
				
simple_expression : term 
			{
				logout<<"At line "<<line_count<< " : simple_expression : term\n"<< endl;
			
				//semantic check			
				//storing semantic value ( logic_expression)
			
				$$=$1;
				
				//considering it both
				// for next term semantic check
				//logout<<$$->getSaveCode()<< endl<<endl;
				
				sim_exp=termG;
				$$->setValue(sim_exp);
				logout<<sim_exp<<endl<<endl;
				$$->setSaveCode(sim_exp);
			}
		  | simple_expression ADDOP term 
			{
				logout<<"At line "<<line_count<< " : simple_expression : simple_expression ADDOP term\n"<< endl;
				$$=$1;
				$$->asmcode=$$->asmcode+$3->asmcode;
				char* temp = newTemp();
				//ADDOP is '+'
				if($2->getValue()=="+")
				{
					
					sim_exp=$1->getValue()+"+"+$3->getValue();
					logout<<sim_exp<<endl<<endl;
					$$->setSaveCode(sim_exp);
					$$->asmcode=$$->asmcode+"mov ax, "+$1->getValue()+"\n";
					$$->asmcode=$$->asmcode+"add ax, "+$3->getValue()+"\n";
					$$->asmcode=$$->asmcode+"mov "+string(temp)+" , ax\n";
					$$->setValue(string(temp)+to_string(table.scopeNum));
					tempvar.push_back($$->getValue());
				}
				//ADDOP is -
				else if($2->getValue()=="-")
				{
					
					sim_exp=$1->getValue()+"-"+$3->getValue();
					logout<<sim_exp<<endl<<endl;
					$$->asmcode=$$->asmcode+"mov ax, "+$1->getValue()+"\n";
					$$->asmcode=$$->asmcode+"sub ax, "+$3->getValue()+"\n";
					$$->asmcode=$$->asmcode+"mov "+string(temp)+" , ax\n";
					$$->setValue(string(temp)+to_string(table.scopeNum));
					tempvar.push_back($$->getValue());
				}
			
				$$->setSaveCode(sim_exp);
				delete $3;
			}
		  ;
					
term :	unary_expression
		{
			logout<<"At line "<<line_count<< " : term : unary_expression\n"<< endl;
			
			//semantic check			
			//storing semantic value ( logic_expression)
			$$=$1;
			
			//considering it both
			// for next term semantic check
			//logout<<$$->getSaveCode()<< endl<<endl;
			termG=una_exp;
			$$->setValue(termG);
			logout<<termG<<endl<<endl;
			$$->setSaveCode(termG);
			//asmout<<$$->asmcode;
		}
     |  term MULOP unary_expression
		{
			logout<<"At line "<<line_count<< " : term : term MULOP unary_expression\n"<< endl;
			$$=$1;
			char *temp=newTemp();
			$$->asmcode=$$->asmcode+ $3->asmcode;
			
			//MULOP is *
			if($2->getValue()=="*")
			{
					
					
			
				termG=termG+"*"+una_exp;
				$$->setValue(termG);
				logout<<termG<<endl<<endl;
				$$->setSaveCode(termG);
				$$->asmcode=$$->asmcode+"mov ax, "+$1->getValue()+"\n";
				$$->asmcode=$$->asmcode+"mov bx, "+$3->getValue()+"\n";
				$$->asmcode=$$->asmcode+"mul bx\n";
				$$->asmcode=$$->asmcode+"mov "+ string(temp) + ", ax\n";
				$$->setValue(string(temp)+to_string(table.scopeNum));
				tempvar.push_back($$->getValue());
			}
			//MULOP is /
			else if($2->getValue()=="/")
			{
				
				termG=termG+"\\"+una_exp;
				logout<<termG<<endl<<endl;
				$$->setSaveCode(termG);
				$$->asmcode=$$->asmcode+"mov ax, "+$1->getValue()+"\n";
				$$->asmcode=$$->asmcode+"mov bx, "+$3->getValue()+"\n";
				$$->asmcode=$$->asmcode+"xor dx , dx\n";
				$$->asmcode=$$->asmcode+"div bx\n";
				$$->asmcode=$$->asmcode+"mov "+string(temp)+" , ax\n";
				$$->setValue(string(temp)+to_string(table.scopeNum));
				tempvar.push_back($$->getValue());
			}
			//MULOP is %
			else if($2->getValue()=="%")
			{
				
				termG=termG+"%"+una_exp;
				logout<<termG<<endl<<endl;
				$$->setSaveCode(termG);
				$$->asmcode=$$->asmcode+"mov ax, "+$1->getValue()+"\n";
				$$->asmcode=$$->asmcode+"mov bx, "+$3->getValue()+"\n";
				$$->asmcode=$$->asmcode+"xor dx , dx\n";
				$$->asmcode=$$->asmcode+"div bx\n";
				$$->asmcode=$$->asmcode+"mov "+string(temp)+" , dx\n";
				$$->setValue(string(temp)+to_string(table.scopeNum));
				tempvar.push_back($$->getValue());
			}
			//cout << endl << $$->code << endl;
			delete $3;
		}
     ;
unary_expression : ADDOP unary_expression  
			{
				logout<<"At line "<<line_count<< " : unary_expression : ADDOP unary_expression\n"<< endl;
				//in this case, only ADDOP - is need
				$$=$2;
				if($1->getValue()=="-")
				{
					
					una_exp="-"+una_exp;
					logout<<una_exp<<endl<<endl;
					$$->setSaveCode(una_exp);
					$$->asmcode=$$->asmcode+"mov ax, "+$2->getValue()+"\n";
					$$->asmcode=$$->asmcode+"neg ax\n";
					$$->asmcode=$$->asmcode+"mov "+$2->getValue()+" , ax\n";
				}
				//ultimate value is stored
				//$$=$2;
			
			}
		 | NOT unary_expression 
			{
				logout<<"At line "<<line_count<< " : unary_expression : NOT unary_expression \n"<< endl;
				
				una_exp="!"+una_exp;
				logout<<una_exp<<endl<<endl;
				$$->setSaveCode(una_exp);
				char *temp=newTemp();
				$$=$2;
				$$->asmcode="\tmov ax, "+$2->getValue()+"\n";
				$$->asmcode=$$->asmcode+"not ax\n";
				$$->asmcode=$$->asmcode+"mov "+string(temp)+", ax";
				$$->setValue(string(temp)+to_string(table.scopeNum));
				tempvar.push_back($$->getValue());
			}
		 | factor 
			{
				logout<<"At line "<<line_count<< " : unary_expression : factor\n"<< endl;
			
				//semantic check			
				//storing semantic value 
				
				
				// for next term semantic check
				//logout<<$$->getSaveCode()<< endl<<endl;
				una_exp=factorG;
				logout<<una_exp<<endl<<endl;
				$$->setSaveCode(una_exp);
				$$=$1;
				//asmout<<$$->asmcode;
			}
		 ;
	
	
factor	: variable 
		{
			logout<<"At line "<<line_count<< " : factor : variable\n"<< endl;
			//logout<<$$->getSaveCode()<< endl<<endl;
			factorG=varG;
			
			char *temp=newTemp();
			logout<<factorG<<endl<<endl;
			$$->setSaveCode(factorG);
			$$=$1;
			if($$->getKeyword()=="notarray"){}
			else {
				$$->asmcode=$$->asmcode+"mov ax, "+$1->getValue()+"[bx]\n";
				$$->asmcode=$$->asmcode+"mov "+string(temp)+", ax\n";
				$$->setValue(string(temp)+to_string(table.scopeNum));
				tempvar.push_back($$->getValue());
			}
			
			
		}
		| ID LPAREN argument_list RPAREN
		{
			logout<<"At line "<<line_count<< " : factor : ID LPAREN argument_list RPAREN\n"<< endl;
			//it's for a function call which returns something
			//printing the id
			//logout<<$1->getValue()<<endl;
			//an object is ready for checking
			SymbolInfo *tempval=new SymbolInfo();
			//checking the function name
			tempval=table.lookTable($1->getValue(),"FUNC");
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
					
					$$=$1;
					factorG=$1->getValue()+"("+arg_list+")";
					logout<<factorG<<endl<<endl;
					$$->setSaveCode(factorG);
				}
			}
		}
		| LPAREN expression RPAREN
		{
			logout<<"At line "<<line_count<< " : factor : LPAREN expression RPAREN\n"<< endl;
			$$=$2;
			factorG="("+expG+")";
			logout<<factorG<<endl<<endl;
			$$->setSaveCode(factorG);
		}
		| CONST_INT 
		{
			logout<<"At line "<<line_count<< " : factor : CONST_INT\n"<< endl;
			//the number is printed out
			//logout<<$1->getValue()<<endl;
			
			$$=$1;
			factorG=$1->getValue();
			logout<<factorG<<endl<<endl;
			$$->setSaveCode(factorG);
			//asmout<<$$->asmcode;
			
		}
		| CONST_FLOAT 
		{
			logout<<"At line "<<line_count<<" : factor : CONST_FLOAT\n";
			//the number is printed out
			//logout<<$1->getValue()<<endl;
			
			$$=$1;
			//logout <<"AT CONST_FLOAT , value" <<  $$->floatstore[0]<< " Type = " << $$->getKeyType() << endl;
			factorG=$1->getValue();
			logout<<factorG<<endl<<endl;
			$$->setSaveCode(factorG);
		}
		
		| variable INCOP 
		{
			logout<<"At line "<<line_count<< " : factor : variable INCOP\n"<< endl;
			//value can be array or variable
			
			$$=$1;
			factorG=varG+"++";
			logout<<factorG<<endl<<endl;
			$$->setSaveCode(factorG);
			$$->asmcode=$$->asmcode+"mov ax , "+$$->getValue()+"\n";
			$$->asmcode=$$->asmcode+"add ax , 1\n";
			$$->asmcode=$$->asmcode+"mov "+$$->getValue()+" , ax\n";
		}
		| variable DECOP
		{
			logout<<"At line "<<line_count<< " : factor : variable DECOP\n"<< endl;
			//value can be array or variable
			
			
			$$=$1;
			factorG=varG+"--";
			logout<<factorG<<endl<<endl;
			$$->setSaveCode(factorG);
			$$->asmcode=$$->asmcode+"mov ax , "+$$->getValue()+"\n";
			$$->asmcode=$$->asmcode+"sub ax , 1\n";
			$$->asmcode=$$->asmcode+"mov " +$$->getValue()+" , ax\n";
		}
		;
	
argument_list : arguments
			{
				logout<<"At line "<<line_count<< " : argument_list : arguments\n"<< endl;
				arg_list=argG;
				logout<<arg_list<<endl<<endl;
				$$->setSaveCode(arg_list);
			}
			  
			  ;
	
arguments : arguments COMMA logic_expression
		{
			logout<<"At line "<<line_count<< " : arguments : arguments COMMA logic_expression\n"<< endl;
			argG=argG+","+logic_exp;
			logout<<argG<<endl<<endl;
			$$->setSaveCode(argG);
		}
	      | logic_expression
			{
				logout<<"At line "<<line_count<< " : arguments : logic_expression\n"<< endl;
				argG=logic_exp;
				logout<<argG<<endl<<endl;
				$$->setSaveCode(argG);
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
	asmout.open("code.asm");
	
	yyparse();
	
	logout<<"Total Lines : "<<line_count<<endl; 
	//logFile << "Total Errors : " << semErrors << endl;
	logout.close();
	errorout.close();
	asmout.close();

	return 0;
}

