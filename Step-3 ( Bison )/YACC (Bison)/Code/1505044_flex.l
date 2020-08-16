%option noyywrap



%{

#include"1505044symbolTable.h"
#include"y.tab.h"



int line_count=1;
//int currentpos=0;
int err=0;
//int sizeable;
//int ind;
//int bucketcnt;
//int in=0;


//FILE *logout;
//FILE *tokenout;
//string s;


%}



WHITESPACE [ \t\f\r\v]+

NEWLINE [\n]

LETTER [a-zA-Z]

DIGIT [0-9]
DIGITS {DIGIT}+
DECP (\.)*

CHAR [ -~]{-}[']
CHARS {CHAR}+
CHARACTERLIT ('({CHAR})')
UNFIN_CHAR	('({CHAR}))
UNFINSP_CHAR	('\\')

FLOAT1		[0-9]+(\.[0-9]+)?(E[+-]?[0-9]+)?
FLOAT2		(\.[0-9]+)(E[+-]?[0-9]+)?
DECIMALERROR {DIGITS}*((\.)+{DIGITS}+)+(E{DECP}[+-]?{DECP}{DIGITS})?{DECP}{DIGITS}*
ILLNUMBER [0-9]*(\.[0-9]+)?(E[+-]?[0-9]*\.[0-9]*)

IDENTIFIERS [A-Z_a-z][A-Za-z_0-9]*

STRING \"([^\"\n]|\\{NEWLINE})*\"
UNFINISHEDSTRING \"([^\"\n]|(\\{NEWLINE}))*

COMMENT	(\/\*([^*]|[\r\n\t]|(\*+([^*\/]|[\r\n\t])))*\*+\/)|(\/\/([^\n]*|([^\n]*\\\n)*)[^\n]*)
M_COMMENT	("/*"([^"*"]|"*"[^"/"])+"*/")
UNFINISHEDCOMMENT	("/*"([^"*"]|"*"[^"/"])+[^"*/"])
SINGLELINE_COMMENT "//"{CHARS}$ 


INVALIDSUFFIX [0-9]+([^;0-9\n\t\f\v ]+)+
MULTICHARACTER ('({CHARS}|['])*')

UNRECOGCHAR ('{CHAR}*[^'\n]?)
UNREG .

%%
{WHITESPACE} {}
{NEWLINE} {line_count++;}

{DIGITS}	{
				SymbolInfo* str=new SymbolInfo(yytext,"CONST_INT");
				yylval.symbolVal=str;
				return CONST_INT;
		}

{FLOAT1}|{FLOAT2}	{	
				SymbolInfo* str= new SymbolInfo(yytext,"CONST_FLOAT");
				yylval.symbolVal=str;
				return CONST_FLOAT;
			}


{DECIMALERROR} {	err++;
			
			}

{ILLNUMBER}	{	err++;
			
			}

{CHARACTERLIT} {		SymbolInfo* str= new SymbolInfo(yytext,"CONST_CHAR");
				yylval.symbolVal=str;
				return CONST_CHAR;
		}


"\'\\n\'" {			yytext[0]='\n';
				yytext[1]='\0';
				SymbolInfo* str= new SymbolInfo(yytext,"CONST_CHAR");
				yylval.symbolVal=str;
				return CONST_CHAR;
		}

"\'\\t\'" {			yytext[0]='\t';
				yytext[1]='\0';
				SymbolInfo* str= new SymbolInfo(yytext,"CONST_CHAR");
				yylval.symbolVal=str;
				return CONST_CHAR;
		}

"\'\\a\'" {			yytext[0]='\a';
				yytext[1]='\0';
				SymbolInfo* str= new SymbolInfo(yytext,"CONST_CHAR");
				yylval.symbolVal=str;
				return CONST_CHAR;
		}

"\'\\f\'" {			yytext[0]='\f';
				yytext[1]='\0';
				SymbolInfo* str= new SymbolInfo(yytext,"CONST_CHAR");
				yylval.symbolVal=str;
				return CONST_CHAR;
		}

"\'\\v\'" {			yytext[0]='\v';
				yytext[1]='\0';
				SymbolInfo* str= new SymbolInfo(yytext,"CONST_CHAR");
				yylval.symbolVal=str;
				return CONST_CHAR;
		}

"\'\\r\'" {			yytext[0]='\v';
				yytext[1]='\0';
				SymbolInfo* str= new SymbolInfo(yytext,"CONST_CHAR");
				yylval.symbolVal=str;
				return CONST_CHAR;
		}

"\'\\b\'" {			yytext[0]='\b';
				yytext[1]='\0';
				SymbolInfo* str= new SymbolInfo(yytext,"CONST_CHAR");
				yylval.symbolVal=str;
				return CONST_CHAR;
		}
"\'\\\"\'"  {			yytext[0]='\"';
				yytext[1]='\0';
				SymbolInfo* str= new SymbolInfo(yytext,"CONST_CHAR");
				yylval.symbolVal=str;
				return CONST_CHAR;
		}
"\'\\\\\'" {			yytext[0]='\\';
				yytext[1]='\0';
				SymbolInfo* str= new SymbolInfo(yytext,"CONST_CHAR");
				yylval.symbolVal=str;
				return CONST_CHAR;
		}

"\'\\0\'" {			
				SymbolInfo* str= new SymbolInfo(yytext,"CONST_CHAR");
				yylval.symbolVal=str;
				return CONST_CHAR;
		}

{MULTICHARACTER} {	err++;
			
			}

{UNFIN_CHAR}|{UNFINSP_CHAR} {err++;
			
		}



{COMMENT}	{
			
			for(int i=0;i<yyleng;i++){	
				if(yytext[i]=='\n') line_count++;
					}
			return COMMENT; 
		}


{M_COMMENT}	{
			for(int i=0;i<yyleng;i++){	
				if(yytext[i]=='\n') line_count++;
					}
			return COMMENT; 
		}


{UNFINISHEDCOMMENT} {	
			for(int i=0;i<yyleng;i++){
				if(yytext[i] == '\n') line_count++;
					}
			err++;

			}

{STRING}  {

        char *stri = new char[1000];
        //fprintf(logout,"%s\n",yytext);
        int ln = strlen(yytext),i,j;
        for(i=1,j=0;i<ln-1;){

            if(yytext[i]!='\\' || (yytext[i]=='\\' && i==ln-2)){

                stri[j] = yytext[i];
                i++;
                j++;
            }
            else if(yytext[i]=='\\' && yytext[i+1]=='\n'){

                i+=2;
            }
            else{

                if(yytext[i+1]=='n'){

                    stri[j] = '\n';

                }

                    else if(yytext[i+1]=='t'){

                    stri[j] = '\t';

                }

                else if(yytext[i+1]=='\\'){

                    stri[j] = '\\';

                }

                else if(yytext[i+1]=='a'){

                    stri[j] = '\a';

                }

                else if(yytext[i+1]=='f'){

                    stri[j] = '\f';

                }

                else if(yytext[i+1]=='v'){

                    stri[j] = '\v';

                }

                else if(yytext[i+1]=='r'){

                    stri[j] = '\r';

                }

                else if(yytext[i+1]=='b'){

                    stri[j] = '\b';

                }
                i+=2;
                j++;

            }
        }
        	stri[j]='\0';
        	SymbolInfo* str= new SymbolInfo(stri,"String");
		yylval.symbolVal=str;
		return STRING;
}

{UNFINISHEDSTRING} {
			for(int i=0;i<yyleng;i++){
				if(yytext[i] == '\n') line_count++;
					}
			err++;

			}


"if"	{
			return IF;
		}


"else"	{
			return ELSE;

		}

"for"	{		return FOR;
		}

"while"	{		return WHILE;

		}

"do"	{		return DO;
		}

"break"	{		return BREAK;

		}

"int"	{		return INT;

		}

"char"	{		return CHAR;
		}

"float" {		return FLOAT;
		}
"double" {		return DOUBLE;
		}

"void" {		return VOID;

		}

"return" { 		return RETURN;

		}

"switch" {		return SWITCH;
		}

"case" {		return CASE;
		}

"default" {		return DEFAULT;

		}

"continue" {		return CONTINUE;
		}



"\+\+"		{		return INCOP;
		}

"\-\-"		{		return DECOP;
		}

"+" |

"-"		{
			SymbolInfo* str= new SymbolInfo(yytext,"ADDOP");
			yylval.symbolVal=str;
			return ADDOP;
		}

"*"	|
"/" 	|
"%"	{		
			SymbolInfo* str= new SymbolInfo(yytext,"MULOP");
			yylval.symbolVal=str;
			return MULOP;
		}



"<"	|
"\<\="	|
">"	|
"\>\="	|
"\=\="	|
"\!\="	{		
			SymbolInfo* str= new SymbolInfo(yytext,"RELOP");
			yylval.symbolVal=str;		
			return RELOP;
		}

"="	{		return ASSIGNOP;
		}

"\&\&"	|
"\|\|"	{
			SymbolInfo* str= new SymbolInfo(yytext,"LOGICOP");
			yylval.symbolVal=str;		
			return LOGICOP;
		}

"&"	|
"|"	|
"^"	|
"\<\<"	|
"\>\>"	{		return BITOP;
		}

"!"	{		return NOT;
		}

"("	{		return LPAREN;
		}

")"	{		return RPAREN;
		}

"{"	{		return LCURL;
		}

"}"	{		return RCURL;
		}

"["	{		return LTHIRD;
		}

"]"	{		return RTHIRD;
		}

","	{		return COMMA;
		}

";"	{		return SEMICOLON;
		}



{IDENTIFIERS}	{		SymbolInfo* str= new SymbolInfo(yytext,"ID");
				yylval.symbolVal=str;
				return ID;
			}







{INVALIDSUFFIX}	{	err++;
			//fprintf(logout,"Line no %d and Error: INVALID SUFFIX %s \n",line_count,yytext);
			}



{UNRECOGCHAR} {		err++;
			//fprintf(logout,"Line no %d and Error: UNFINISHED CHARACTER %s \n",line_count,yytext);
			}

{UNREG} {		err++;
			//fprintf(logout,"Line no %d and Error: UNRECOGNIZED CHARACTER %s \n",line_count,yytext);
			}
%%
