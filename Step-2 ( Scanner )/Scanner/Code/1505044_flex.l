%option noyywrap



%{
#include<bits/stdc++.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>


int line_count=1;
int currentpos=0;
int err=0;
int sizeable;
int ind;
int bucketcnt;
int in=0;


FILE *logout;
FILE *tokenout;
//string s;


class SymbolInfo
{

private:
    char* keyword ;
    char* value ;
public:
    SymbolInfo *next;
	SymbolInfo()
	{
		keyword =new char[100];
    		value =new char[100];
	}

    void setterKeyword(char* s)
    {
	//keyword = new char[100];
	strcpy(keyword,s);
       // keyword=s;
    }

    void setterValue(char* s)
    {
	//value = new char[100];
	strcpy(value,s);
       // value=s;
    }

    char* getterKeyword()
    {
        return keyword;
    }

    char* getterValue()
    {
        return value;
    }


};

class ScopeTable
{

public:

    int tablesize;
    static const int SIZE=10;

    SymbolInfo *hashset[SIZE];

    ScopeTable()
    {

        tablesize=SIZE;
        //SymbolInfo *hashset[tablesize];
        //cout<<tablesize<<endl;
        for(int i=0; i<tablesize; i++)
        {
		char *s = new char[100];
		s[0] = '\0';

            hashset[i]=new SymbolInfo;
            hashset[i]->setterKeyword(s);
            hashset[i]->setterValue(s);
            hashset[i]->next=NULL;

        }

    }

    void insertchain(char* name,char* name2);
    bool findchain(char* name,char* name2);
    bool lookup(char* name2);
    void removechain(char* name2);

    unsigned long hashfunc1(const char* key)
    {
        unsigned long h = 5381;

        for(int i=0; i<strlen(key); i++)
        {
            h = ((h << 5) + h) + (int)key[i];
        }



        return (h%tablesize);
    }

    void printIndexchain(int x)
    {
        SymbolInfo *ptr=hashset[x];
        // cout<<3<<endl;
        if(ptr->getterKeyword()=='\0')
        {
        }
        else
        {
            // cout<<x<<endl;
            while(ptr!=NULL)
            {
                //  cout<<1<<endl;
		//fprintf(logout,"Line no %d: TOKEN <DO> Lexeme %s found\n",line_count,yytext);
                fprintf(logout,"%s",ptr->getterKeyword());
                if(ptr->next!=NULL)
                    fprintf(logout,"-->");
                ptr=ptr->next;
                // cout<<2<<endl;
            }
        }
    }

    void printchain()
    {
        fprintf(logout,"\n");
        //int number;
        for(int i=0; i<tablesize; i++)
        {
            // number=numbereachchain(i);
            //cout<<i<<" --> ";
	    fprintf(logout,"%d -->",i);
            printIndexchain(i);

            // cout<<"Total "<<number<<endl;
	    fprintf(logout,"\n");
            
        }
    }



};

void ScopeTable::insertchain(char* name,char* name2)
{

    //int index;

    char *save;
    save = new char[100];
    ind=hashfunc1(name);
    bucketcnt=0;


    if(hashset[ind]->getterKeyword()=='\0')
    {
	strcpy(save,"< ");
	strcat(save,name2);
	strcat(save," : ");
	strcat(save,name);
	strcat(save," >");
        hashset[ind]->setterKeyword(save);
        hashset[ind]->setterValue(name2);
    }

    else
    {


        SymbolInfo *ptr=hashset[ind];
        SymbolInfo *n=new SymbolInfo;
	strcpy(save,"< ");
	strcat(save,name2);
	strcat(save," : ");
	strcat(save,name);
	strcat(save," >");
        n->setterKeyword(save);
        //n->setterKeyword(strcat("< ",strcat(name2,(strcat(" : ",strcat(name," >"))))));
        n->setterValue(name2);
        n->next=NULL;
        bucketcnt=1;
        while(ptr->next!=NULL)
        {
            ptr=ptr->next;
            bucketcnt++;
        }
        ptr->next=n;

    }
}

bool ScopeTable::findchain(char* name,char* name2)
{

   // int ind;

    char *save;
    save = new char[100];
    ind=hashfunc1(name);

    // cout<<"NO1"<<endl;


    bool flag=false;

    char* store;
    store = new char[100];
    SymbolInfo *ptr=hashset[ind];

    // cout<<"NO2"<<endl;

    while(ptr!=NULL)
    {
       strcpy(save,"< ");
	strcat(save,name2);
	strcat(save," : ");
	strcat(save,name);
	strcat(save," >");

        if(ptr->getterKeyword()==save)
        {
            flag=true;
            store=ptr->getterValue();
        }
        ptr=ptr->next;
    }

    if(flag)
        return true;
    else return false;

}

void ScopeTable::removechain(char* name2)
{


    SymbolInfo *temp;
    SymbolInfo *temp1;
    SymbolInfo *temp2;


    if(hashset[ind]->getterValue()==name2 && hashset[ind]->next==NULL)
    {
        hashset[ind]->setterKeyword('\0');
        hashset[ind]->setterValue('\0');
        //cout<<name <<" is removed"<<endl;
    }

    else if(hashset[ind]->getterValue()==name2 )
    {
        temp=hashset[ind];
        hashset[ind]=hashset[ind]->next;
        delete temp;
        //cout<<name <<" is removed"<<endl;
    }

    else
    {

        temp1=hashset[ind]->next;
        temp2=hashset[ind];
        while(temp1 != NULL && temp1->getterValue()!=name2)
        {
            temp2=temp1;
            temp1=temp1->next;
        }
        if(temp1==NULL)
        {
            //cout<<name2<<"Doesn't Exist !!!!"<<endl;
        }
        else
        {
            temp=temp1;
            temp1=temp1->next;
            temp2->next=temp1;
            delete temp;
            // cout<<name<<" is removed"<<endl;
        }

    }

}

bool ScopeTable::lookup(char* name2)
{


//int index;



    // index=hashfunc1(name);

    // cout<<"NO1"<<endl;

    // bucketcnt=0;
    bool flag=false;

    char* store;
    store = new char[100];
    for(int i=0; i<tablesize; i++)
    {
        SymbolInfo *ptr=hashset[i];
        bucketcnt=0;
        // cout<<"NO2"<<endl;

        while(ptr!=NULL)
        {
            if(ptr->getterValue()==name2)
            {
                flag=true;
                ind=i;
                return true;
                //store=ptr->value;
            }
            ptr=ptr->next;
            bucketcnt++;
        }


    }
    return false;

}

class SymbolTable
{

public:
   
    ScopeTable h1[100];
    SymbolTable()
    {

        //vector<ScopeTable>h1;
        ScopeTable c;
        h1[in]=c;
    }

    void insertTable(char* namebro,char* typenam)
    {

        if(h1[currentpos].lookup(namebro)==false)
        {

            if(h1[currentpos].findchain(typenam,namebro)==false)
            {
                // cout<<"NO"<<endl;
                h1[currentpos].insertchain(typenam,namebro);
               // cout<<"Inserted in ScopeTable # "<<currentpos+1<<" at position "<<index<<","<<bucketcnt<<endl;
               // cout<<""<<endl;
            }

            else
            {
               // cout<<"Already exists in current ScopeTable"<<endl;
               // cout<<""<<endl;
            }

        }

        else{
           // cout<<"It already exists !!!! " <<endl;
        }

    }

    void printTable(/*char* ch1*/)
    {

       // if(ch1=="C")
     //   {
           // cout<<"ScopeTable "<<"# "<<currentpos+1<<endl;
            h1[currentpos].printchain();
           // cout<<""<<endl;
      //  }

      /*  else if(ch1=="A")
        {
            int pos;
            //cout<<"ScopeTable "<<"# "<<pos+1<<endl;
            for(int pos=0; pos<=currentpos; pos++)
            {
                //cout<<"ScopeTable "<<"# "<<pos+1<<endl;
                h1[pos].printchain();
              //  cout<<""<<endl;
            }
        }*/

    }

    void lookTable(char* namebar)
    {

        int flag=0,store=currentpos;

        for(int i=currentpos; i>=0; i--)
        {
            if(h1[i].lookup(namebar)==true && i==currentpos)
            {
                flag=1;
                store=i;
            }
            else if(h1[i].lookup(namebar)==true)
            {
                flag=2;
                store=i;
            }

        }
        if(flag==0)
        {
           // cout<<"Not Found !!"<<endl;
           // cout<<""<<endl;
        }

        else if(flag==2)
        {
           // cout<<"Found in ScopeTable # "<<store+1<<" at position "<<index<<","<<bucketcnt<<endl;
           // cout<<""<<endl;
        }

        else
        {
           // cout<<"Found in ScopeTable # "<<store+1<<" at position "<<index<<","<<bucketcnt<<endl;
           // cout<<""<<endl;
        }

    }

    void deleteTable(char* namebar)
    {

        if(h1[currentpos].lookup(namebar)==false)
        {
           // cout<<"Not Found !!"<<endl;
           // cout<<""<<endl;
        }

        else
        {
           // cout<<"Found in ScopeTable # "<<currentpos+1<<" at position "<<index<<","<<bucketcnt<<endl;
          //  cout<<""<<endl;
            h1[currentpos].removechain(namebar);
          //  cout<<"Deleted entry at "<<index<<","<<bucketcnt<<" from current ScopeTable"<<endl;
          //  cout<<""<<endl;
        }

    }

    void newTable()
    {

        ScopeTable a;
        h1[++in]=a;

    }

    void prevTable()
    {
        in--;
    }

} ;

SymbolTable st;
//vector<ScopeTable>h1;

%}



WHITESPACE [ \t\f\r\v]+ 
LETTER [a-zA-Z]
DIGIT [0-9]
NEWLINE [\n]
FLOATPOINT [0-9]*\.[0-9]+([eE][+-]?[0-9]+)?
IDENTIFIERS [A-Z_a-z][A-Za-z_0-9]*
CHARACTERLIT \'[^'\n]\'
STRING \"([^\"\n]|\\{NEWLINE})*\"
COMMENT (\/\*([^*]|[\r\n\t]|(\*+([^*\/]|[\r\n\t])))*\*+\/)|(\/\/([^\n]|(\\\n))*)
DECIMALERROR ([0-9eE]*)?[\.][0-9eE]*[\.][0-9eE]*[\.0-9eE]*
ILLNUMBER [0-9]*[a-zA-Z]+[0-9]*[\.][\.0-9a-zA-z]*$|[0-9]*[a-zA-Z]*[0-9]*[\.][0-9]*[\.a-zA-z][\.a-zA-Z]+[0-9]*[\.0-9a-zA-Z]*$
INVALIDSUFFIX [0-9]+([^;0-9\n\t\f\v ]+)+
MULTICHARACTER [\'][^'][^']+[\']
UNFINISHEDCOMMENT (\/\*([^*]|[\r\n\t]|(\*+([^*\/]|[\r\n\t])))*)
UNFINISHEDSTRING (\"([^"\\\n]|\\(.|\r?\n))*)|(([^"\\\n]|\\(.|\r?\n))*\")
CHAR [ -~]{-}[']
UNRECOGCHAR ('{CHAR}*[^'\n]?)
UNREG .

%%
{WHITESPACE} {}
{NEWLINE} {line_count++;}

"if"	{
			fprintf(tokenout,"<IF>");
			fprintf(logout,"Line no %d: TOKEN <IF> Lexeme %s found			\n",line_count,yytext);
		}

		
"else"	{
			fprintf(tokenout,"<ELSE>");
			fprintf(logout,"Line no %d: TOKEN <ELSE> Lexeme %s found\n",line_count,yytext);

		}

"for"	{		fprintf(tokenout,"<FOR>");
			fprintf(logout,"Line no %d: TOKEN <FOR> Lexeme %s found\n",line_count,yytext);

		}

"while"	{		fprintf(tokenout,"<WHILE>");
			fprintf(logout,"Line no %d: TOKEN <WHILE> Lexeme %s found\n",line_count,yytext);

		}

"do"	{		fprintf(tokenout,"<DO>");
			fprintf(logout,"Line no %d: TOKEN <DO> Lexeme %s found\n",line_count,yytext);

		}

"break"	{		fprintf(tokenout,"<BREAK>");
			fprintf(logout,"Line no %d: TOKEN <BREAK> Lexeme %s found\n",line_count,yytext);

		}

"int"	{		fprintf(tokenout,"<INT>");
			fprintf(logout,"Line no %d: TOKEN <INT> Lexeme %s found\n",line_count,yytext);

		}

"char"	{		fprintf(tokenout,"<CHAR>");
			fprintf(logout,"Line no %d: TOKEN <CHAR> Lexeme %s found\n",line_count,yytext);

		}

"float" {		fprintf(tokenout,"<FLOAT>");
			fprintf(logout,"Line no %d: TOKEN <FLOAT> Lexeme %s found\n",line_count,yytext);

		}
"double" {		fprintf(tokenout,"<DOUBLE>");
			fprintf(logout,"Line no %d: TOKEN <DOUBLE> Lexeme %s found\n",line_count,yytext);

		}

"void" {		fprintf(tokenout,"<VOID>");
			fprintf(logout,"Line no %d: TOKEN <VOID> Lexeme %s found\n",line_count,yytext);

		}

"return" { 		fprintf(tokenout,"<RETURN>");
			fprintf(logout,"Line no %d: TOKEN <RETURN> Lexeme %s found\n",line_count,yytext);

		}

"switch" {		fprintf(tokenout,"<SWITCH>");
			fprintf(logout,"Line no %d: TOKEN <SWITCH> Lexeme %s found\n",line_count,yytext);

		}

"case" {		fprintf(tokenout,"<CASE>");
			fprintf(logout,"Line no %d: TOKEN <CASE> Lexeme %s found\n",line_count,yytext);

		}

"default" {		fprintf(tokenout,"<DEFAULT>");
			fprintf(logout,"Line no %d: TOKEN <DEFAULT> Lexeme %s found\n",line_count,yytext);

		}

"continue" {		fprintf(tokenout,"<CONTINUE>");
			fprintf(logout,"Line no %d: TOKEN <CONTINUE> Lexeme %s found\n",line_count,yytext);

		}

{DIGIT}+ 	{
				fprintf(tokenout,"<CONST_INT,%s>",yytext);
				fprintf(logout,"Line no %d: TOKEN <CONST_INT> Lexeme %s found\n",line_count,yytext);
				char *instore;
				instore = new char[100];
				strcpy(instore,"CONST_INT");
				
				st.insertTable(yytext,instore);
				st.printTable();
			}

{FLOATPOINT}	{		fprintf(tokenout,"<CONST_FLOAT,%s>",yytext);
				fprintf(logout,"Line no %d: TOKEN <CONST_FLOAT> Lexeme %s found\n",line_count,yytext);
				char *instore;
				instore = new char[100];
				strcpy(instore,"CONST_FLOAT");
				
				st.insertTable(yytext,instore);
				st.printTable();
			}

{IDENTIFIERS}	{		fprintf(tokenout,"<ID,%s>",yytext);
				fprintf(logout,"Line no %d: TOKEN <ID> Lexeme %s found\n",line_count,yytext);
				char *instore;
				instore = new char[100];
				strcpy(instore,"ID");
				
				st.insertTable(yytext,instore);
				st.printTable();
			}

{CHARACTERLIT} {		fprintf(tokenout,"<CONST_CHAR,%s>",yytext);
				fprintf(logout,"Line no %d: TOKEN <CONST_CHAR> Lexeme %s found\n",line_count,yytext);
				char *instore;
				instore = new char[100];
				strcpy(instore,"CONST_CHAR");
				st.insertTable(yytext,instore);
				st.printTable();
		}
"\'\\n\'" {			char ch='\n';			
				fprintf(tokenout,"<CONST_CHAR,%c>",ch);
				fprintf(logout,"Line no %d: TOKEN <CONST_CHAR> Lexeme %s found\n",line_count,yytext);
				char *instore;
				instore = new char[100];
				strcpy(instore,"CONST_CHAR");
				st.insertTable(yytext,instore);
				st.printTable();
		}
"\'\\t\'" {			char ch='\t';			
				fprintf(tokenout,"<CONST_CHAR,%c>",ch);
				fprintf(logout,"Line no %d: TOKEN <CONST_CHAR> Lexeme %s found\n",line_count,yytext);
				char *instore;
				instore = new char[100];
				strcpy(instore,"CONST_CHAR");
				st.insertTable(yytext,instore);
				st.printTable();
		}
"\'\\a\'" {			char ch='\a';			
				fprintf(tokenout,"<CONST_CHAR,%c>",ch);
				fprintf(logout,"Line no %d: TOKEN <CONST_CHAR> Lexeme %s found\n",line_count,yytext);
				char *instore;
				instore = new char[100];
				strcpy(instore,"CONST_CHAR");
				st.insertTable(yytext,instore);
				st.printTable();
		}
"\'\\f\'" {			char ch='\f';			
				fprintf(tokenout,"<CONST_CHAR,%c>",ch);
				fprintf(logout,"Line no %d: TOKEN <CONST_CHAR> Lexeme %s found\n",line_count,yytext);
				char *instore;
				instore = new char[100];
				strcpy(instore,"CONST_CHAR");
				st.insertTable(yytext,instore);
				st.printTable();
		}
"\'\\v\'" {			char ch='\v';			
				fprintf(tokenout,"<CONST_CHAR,%c>",ch);
				fprintf(logout,"Line no %d: TOKEN <CONST_CHAR> Lexeme %s found\n",line_count,yytext);
				char *instore;
				instore = new char[100];
				strcpy(instore,"CONST_CHAR");
				st.insertTable(yytext,instore);
				st.printTable();
		}
"\'\\r\'" {			char ch='\r';			
				fprintf(tokenout,"<CONST_CHAR,%c>",ch);
				fprintf(logout,"Line no %d: TOKEN <CONST_CHAR> Lexeme %s found\n",line_count,yytext);
				char *instore;
				instore = new char[100];
				strcpy(instore,"CONST_CHAR");
				st.insertTable(yytext,instore);
				st.printTable();
		}
"\'\\b\'" {			char ch='\b';			
				fprintf(tokenout,"<CONST_CHAR,%c>",ch);
				fprintf(logout,"Line no %d: TOKEN <CONST_CHAR> Lexeme %s found\n",line_count,yytext);
				char *instore;
				instore = new char[100];
				strcpy(instore,"CONST_CHAR");
				st.insertTable(yytext,instore);
				st.printTable();
		}
"\'\\\"\'"  {			char ch='\"';			
				fprintf(tokenout,"<CONST_CHAR,%c>",ch);
				fprintf(logout,"Line no %d: TOKEN <CONST_CHAR> Lexeme %s found\n",line_count,yytext);
				char *instore;
				instore = new char[100];
				strcpy(instore,"CONST_CHAR");
				st.insertTable(yytext,instore);
				st.printTable();
		}
"\'\\\\\'" {			char ch='\\';			
				fprintf(tokenout,"<CONST_CHAR,%c>",ch);
				fprintf(logout,"Line no %d: TOKEN <CONST_CHAR> Lexeme %s found\n",line_count,yytext);
				char *instore;
				instore = new char[100];
				strcpy(instore,"CONST_CHAR");
				st.insertTable(yytext,instore);
				st.printTable();
		}

"\'\\0\'" {			fprintf(tokenout,"<CONST_CHAR,%s>",yytext);
				fprintf(logout,"Line no %d: TOKEN <CONST_CHAR> Lexeme %s found\n",line_count,yytext);
				char *instore;
				instore = new char[100];
				strcpy(instore,"CONST_CHAR");
				st.insertTable(yytext,instore);
				st.printTable();
		}

{STRING}  {
       
        char *str = new char[1000];
        //fprintf(logout,"%s\n",yytext);       
        int ln = strlen(yytext),i,j;
        for(i=1,j=0;i<ln-1;){
       
            if(yytext[i]!='\\' || (yytext[i]=='\\' && i==ln-2)){
           
                str[j] = yytext[i];
                i++;
                j++;       
            }
            else if(yytext[i]=='\\' && yytext[i+1]=='\n'){
           
                i+=2;  
            }
            else{
           
                if(yytext[i+1]=='n'){
               
                    str[j] = '\n';
                   
                }
               
                    else if(yytext[i+1]=='t'){
               
                    str[j] = '\t';
                   
                }
               
                else if(yytext[i+1]=='\\'){
               
                    str[j] = '\\';
                   
                }
 
                else if(yytext[i+1]=='a'){
               
                    str[j] = '\a';
                   
                }
 
                else if(yytext[i+1]=='f'){
               
                    str[j] = '\f';
                   
                }
 
                else if(yytext[i+1]=='v'){
               
                    str[j] = '\v';
                   
                }
 
                else if(yytext[i+1]=='r'){
               
                    str[j] = '\r';
                   
                }
 
                else if(yytext[i+1]=='b'){
               
                    str[j] = '\b';
                   
                }
                i+=2;
                j++;
 
            }      
        }
        str[j] ='\0';
        fprintf(tokenout,"<STRING,%s>",str);
        fprintf(logout,"Line no %d: TOKEN <STRING> Lexeme %s found\n",line_count,str);
}

{COMMENT} {		fprintf(logout,"This is a comment\n");
		}

"\+\+"	|
"\-\-"	{		fprintf(tokenout,"<INCOP,%s>",yytext);
			fprintf(logout,"Line no %d: TOKEN <INCOP> Lexeme %s found\n",line_count,yytext);
			//insert in symbol table and print symbol table content(only non empty buckets)
			// There is a '|' in "+"'s rule, this means match execute the action for following rule
		}

"+" |

"-"		{
			fprintf(tokenout,"<ADDOP,%s>",yytext);
			fprintf(logout,"Line no %d: TOKEN <ADDOP> Lexeme %s found\n",line_count,yytext);
			//insert in symbol table and print symbol table content(only non empty buckets)
			// There is a '|' in "+"'s rule, this means match execute the action for following rule
		}

"*"	|
"/" 	|
"%"	{		fprintf(tokenout,"<MULOP,%s>",yytext);
			fprintf(logout,"Line no %d: TOKEN <MULOP> Lexeme %s found\n",line_count,yytext);
			//insert in symbol table and print symbol table content(only non empty buckets)
			// There is a '|' in "+"'s rule, this means match execute the action for following rule
		}



"<"	|
"\<\="	|
">"	|
"\>\="	|
"\=\="	|
"\!\="	{		fprintf(tokenout,"<RELOP,%s>",yytext);
			fprintf(logout,"Line no %d: TOKEN <RELOP> Lexeme %s found\n",line_count,yytext);
			//insert in symbol table and print symbol table content(only non empty buckets)
			// There is a '|' in "+"'s rule, this means match execute the action for following rule
		}

"="	{		fprintf(tokenout,"<ASSIGNOP,%s>",yytext);
			fprintf(logout,"Line no %d: TOKEN <ASSIGNOP> Lexeme %s found\n",line_count,yytext);
			//insert in symbol table and print symbol table content(only non empty buckets)
			// There is a '|' in "+"'s rule, this means match execute the action for following rule
		}

"\&\&"	|
"\|\|"	{		fprintf(tokenout,"<LOGICOP,%s>",yytext);
			fprintf(logout,"Line no %d: TOKEN <LOGICOP> Lexeme %s found\n",line_count,yytext);
			//insert in symbol table and print symbol table content(only non empty buckets)
			// There is a '|' in "+"'s rule, this means match execute the action for following rule
		}

"&"	|
"|"	|
"^"	|
"\<\<"	|
"\>\>"	{		fprintf(tokenout,"<BITOP,%s>",yytext);
			fprintf(logout,"Line no %d: TOKEN <BITOP> Lexeme %s found\n",line_count,yytext);
			//insert in symbol table and print symbol table content(only non empty buckets)
			// There is a '|' in "+"'s rule, this means match execute the action for following rule
		}

"!"	{		fprintf(tokenout,"<NOT,%s>",yytext);
			fprintf(logout,"Line no %d: TOKEN <NOT> Lexeme %s found\n",line_count,yytext);
			//insert in symbol table and print symbol table content(only non empty buckets)
			// There is a '|' in "+"'s rule, this means match execute the action for following rule
		}

"("	{		fprintf(tokenout,"<LPAREN,%s>",yytext);
			fprintf(logout,"Line no %d: TOKEN <LPAREN> Lexeme %s found\n",line_count,yytext);
			//insert in symbol table and print symbol table content(only non empty buckets)
			// There is a '|' in "+"'s rule, this means match execute the action for following rule
		}

")"	{		fprintf(tokenout,"<RPAREN,%s>",yytext);
			fprintf(logout,"Line no %d: TOKEN <RPAREN> Lexeme %s found\n",line_count,yytext);
			//insert in symbol table and print symbol table content(only non empty buckets)
			// There is a '|' in "+"'s rule, this means match execute the action for following rule
		}

"{"	{		fprintf(tokenout,"<LCURL,%s>",yytext);
			fprintf(logout,"Line no %d: TOKEN <LCURL> Lexeme %s found\n",line_count,yytext);
			//insert in symbol table and print symbol table content(only non empty buckets)
			// There is a '|' in "+"'s rule, this means match execute the action for following rule
		}

"}"	{		fprintf(tokenout,"<RCURL,%s>",yytext);
			fprintf(logout,"Line no %d: TOKEN <RCURL> Lexeme %s found\n",line_count,yytext);
			//insert in symbol table and print symbol table content(only non empty buckets)
			// There is a '|' in "+"'s rule, this means match execute the action for following rule
		}

"["	{		fprintf(tokenout,"<LTHIRD,%s>",yytext);
			fprintf(logout,"Line no %d: TOKEN <LTHIRD> Lexeme %s found\n",line_count,yytext);
			//insert in symbol table and print symbol table content(only non empty buckets)
			// There is a '|' in "+"'s rule, this means match execute the action for following rule
		}

"]"	{		fprintf(tokenout,"<RTHIRD,%s>",yytext);
			fprintf(logout,"Line no %d: TOKEN <RTHIRD> Lexeme %s found\n",line_count,yytext);
			//insert in symbol table and print symbol table content(only non empty buckets)
			// There is a '|' in "+"'s rule, this means match execute the action for following rule
		}

","	{		fprintf(tokenout,"<COMMA,%s>",yytext);
			fprintf(logout,"Line no %d: TOKEN <COMMA> Lexeme %s found\n",line_count,yytext);
			//insert in symbol table and print symbol table content(only non empty buckets)
			// There is a '|' in "+"'s rule, this means match execute the action for following rule
		}

";"	{		fprintf(tokenout,"<SEMICOLON,%s>",yytext);
			fprintf(logout,"Line no %d: TOKEN <SEMICOLON> Lexeme %s found\n",line_count,yytext);
			//insert in symbol table and print symbol table content(only non empty buckets)
			// There is a '|' in "+"'s rule, this means match execute the action for following rule
		}

{DECIMALERROR} {	err++;
			fprintf(logout,"Line no %d : TOO MANY DECIMAL POINT %s \n",line_count,yytext);
			}

{ILLNUMBER}	{	err++;
			fprintf(logout,"Line no %d: ILL FORMED NUMBER %s \n",line_count,yytext);
			}

{INVALIDSUFFIX}	{	err++;
			fprintf(logout,"Line no %d: INVALID SUFFIX %s \n",line_count,yytext);
			}

{MULTICHARACTER} {	err++;
			fprintf(logout,"Line no %d: MULTI CHARACTER CONSTANT %s \n",line_count,yytext);
			}

{UNFINISHEDCOMMENT} {	err++;
			fprintf(logout,"Line no %d: UNFINISHED COMMENT %s \n",line_count,yytext);
			}

{UNFINISHEDSTRING} {		
			err++;
			fprintf(logout,"Line no %d: UNFINISHED STRING %s \n",line_count,yytext);
			}

{UNRECOGCHAR} {		err++;
			fprintf(logout,"Line no %d: UNFINISHED CHARACTER %s \n",line_count,yytext);
			}	

{UNREG} {		err++;
			fprintf(logout,"Line no %d: UNRECOGNIZED CHARACTER %s \n",line_count,yytext);
			}	

<<EOF>> {printf("Total Line Number: %d and error number: %d\n",line_count,err); return 0;}

%%

int main(int argc,char *argv[]){
	
	if(argc!=2){
		printf("Please provide input file name and try again\n");
		return 0;
	}
	
	FILE *fin=fopen(argv[1],"r");
	if(fin==NULL){
		printf("Cannot open specified file\n");
		return 0;
	}

	
	
	logout= fopen("1505044_log.txt","w");
	tokenout= fopen("1505044_token.txt","w");

	yyin= fin;
	yylex();
	
	fclose(yyin);
	fclose(tokenout);
	fclose(logout);
	return 0;
}
