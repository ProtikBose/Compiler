#include<iostream>
#include<vector>
#include<fstream>
#include<string>

using namespace std;


class SymbolInfo{
private:
	string value;
    	string keyword;
	string returnType;				//VAR, ARA, FUNC
	string keyType;				//INT, FLOAT, CHAR
	int aralength; 				//CONST_INT
	string FuncRet;				//INT, FLOAT, VOID
	int araIndex;	
	bool FuncDefined=false;	//true, false	//true,false
	

public:
	string savecode;
	string asmcode;
	vector<string>pList;	//INT, FLOAT, STRING, CHAR
	//vector AraElem;	//INT, FLOAT, STRING, CHAR
	vector<int>intstore; 
	vector<float>floatstore;
	vector<char>charstore; 
		

	SymbolInfo()
	{
		
	}
   
	
	SymbolInfo(string tye)
	{
		keyType=tye;
		if(tye=="INT") intstore.push_back(0);
		else if(tye=="FLOAT") floatstore.push_back(0);
		savecode="";
    	}

    	SymbolInfo(string nme, string tye){
        	value=nme;
        	keyword=tye;
    	}

	void setSaveCode(string scode)
	{
		savecode=scode;	
	}
	
	string getSaveCode()
	{
		return savecode;
	}

    	void setValue(string nme)
	{	
		value=nme;
	}

    	void setKeyword(string tye)
	{ 	
		keyword=tye;
	}

	void setReturnType(string tye)
	{
		returnType=tye;
	}

	void setkeyType(string tye)
	{
		keyType=tye;	
		if(tye=="INT") intstore.push_back(0);
		else if(tye=="FLOAT") floatstore.push_back(0);
	}

	void setAraLength(int size)
	{	
		aralength=size;
	}

	void setFuncRet(string tye)
	{
		FuncRet=tye;
	}

	void setFuncDefined()
	{
		 FuncDefined=true;
	}

	void setAraIndex(int index)
	{
		araIndex=index;
	}
	
    	string getValue()
	{ 
		return value;
	}

	string getKeyword()
	{ 
		return keyword;
	}

	string getReturnType()
	{
		return returnType;
	}

	string getKeyType()
	{
		return keyType;
	}

	int getAralength()
	{
		return aralength;
	}

	string getFuncRet()
	{
		return FuncRet;
	}
	
	bool isFuncDefined()
	{
		return FuncDefined;
	}

	int getAraIndex()
	{	
		return araIndex;
	}

   	 SymbolInfo operator = (const SymbolInfo &symTable){
        	this->value=symTable.value;
        	this->keyword=symTable.keyword;
		
        	return *this;
    	}
	
	void printTable(ofstream& filename)
	{
		if(returnType=="VAR")
		{
			filename<<" , ";
			if(keyType=="INT") filename<<intstore[0];
			else filename<<floatstore[0];		
		}
		else if(returnType=="ARA")
		{
			filename<<" , { ";			
			if(keyType=="INT")
			{	
				for(int i=0;i<aralength;i++) filename<<intstore[i]<<" ";
			}
			else if(keyType=="FLOAT")
			{
				for(int i=0;i<aralength;i++) filename<<floatstore[i]<<" ";
			}
			filename<<"}";
		}
		else if(returnType=="FUNC")
		{
			
		}
	}

};

class ScopeTable
{
private:

    ScopeTable* parentScope;
    vector<SymbolInfo>* scope;
    
    int hashtableNum;
    int scopesize;
    

public:

    ScopeTable()
    {
        parentScope=NULL;
    }

    ScopeTable(int mod,int idNum)
    {
        scopesize=mod;
        scope=new vector<SymbolInfo>[scopesize];
        parentScope=new ScopeTable;
        parentScope=NULL;
        hashtableNum=idNum;
    }

   

    int hashFunc(SymbolInfo symTable){
        
        string nme = symTable.getValue();
	int k=0;
        for(int i=0;i<nme.size();i++)
            k=k+(int)nme[i];
        return (k% scopesize);
    }

    int hashFunc(string nme){
        int k=0;
        for(int i=0;i<nme.size();i++)
            k=k+(int)nme[i];
        return (k%scopesize);
    }


	
    void PrintScope(ofstream& filename)
	{
	        filename<<" ScopeTable# "<<hashtableNum<<endl;        
		for(int i=0;i<scopesize;i++)
		{
			if(scope[i].size()!=0)
			{           	
				filename<<" "<<i<<" -->";
           		for(int j=0;j<scope[i].size();j++)
			{
	               		filename<<" < "<<scope[i][j].getValue()<<" : "<<scope[i][j].getKeyword();
				scope[i][j].printTable(filename); 
				filename<<" > ";
           		}
         			filename<<endl;
			}
       	}
		filename<<endl;
    }

	SymbolInfo* lookTable(string nme,string tye)
		{
        		int k=hashFunc(nme);
		        for(int i=0;i< scope[k].size();i++)
			{
		            if(scope[k][i].getValue()==nme && scope[k][i].getReturnType()==tye)
				{
                
                		return &scope[k][i];
	           		}
        		}
        		return NULL;
    		}

    SymbolInfo* lookTable(SymbolInfo symTable)
	{
	        int k=hashFunc(symTable.getValue());
        	for(int i = 0; i< scope[k].size();i++)
		{
	            	if(scope[k][i].getValue()==symTable.getValue() && scope[k][i].getReturnType()==symTable.getReturnType())
			{
                	
		                return &scope[k][i];
	            	}
	        }
	        return NULL;
	}

     SymbolInfo* insertTable(SymbolInfo symTable)
    {
        scope[hashFunc(symTable)].push_back(symTable);
        return &scope[hashFunc(symTable)][scope[hashFunc(symTable)].size()-1];
    }

    int getHashNum()
	{
		 return hashtableNum;
	}


   

    void Delete(string nme)
	{
	        int k=hashFunc(nme);
        	int s=scope[k].size();
        	for(int i=0;i<s;i++)
		{
	            if(scope[k][i].getValue()==nme)
		    {
	                if(s==1)
			{
	                    scope[k].clear();

          	      	}
                    else
		   {
                   	 for(int j=i;j<s-1;j++){
                   	     scope[k][j]=scope[k][j+1];
                   }
                   scope[k].erase(scope[k].begin()+s-1);
                   scope[k].resize(s-1);


                }

                

                return;
            	}
        }
    }
};

class SymbolTable
{

private:
    vector<ScopeTable>tableStack;
int scopesize;
    
   
    
    int size;
int crnt;

public:

	 int scopeNum;
    SymbolTable(int M)
    {
	scopesize=M;
        scopeNum=1;
        
        ScopeTable newScope(scopesize, scopeNum);
        tableStack.push_back(newScope);
	size=1;
        crnt=0;
	

    }

   void enterScope()
	{
	        ScopeTable newScope(scopesize,++scopeNum);
		size++;
	        crnt++;
	        tableStack.push_back(newScope);
        
   	 }

    void exitScope(){
        tableStack.erase(tableStack.begin()+ crnt--);
        
		
        tableStack.resize(--size);
    }

	 void printCurrentTable(ofstream& filename)
	{
	        tableStack[crnt].PrintScope(filename);
	}

    void printAllTable(ofstream& filename)
	{
	        for(int i=crnt;i>=0;i--)
		{
	            tableStack[i].PrintScope(filename);
	        }
        
    }

	   SymbolInfo* lookTable(string nme,string tye)
	{
        	for(int i=crnt;i>=0;i--)
		{
	            SymbolInfo* tempval=new SymbolInfo;
	            tempval=tableStack[i].lookTable(nme,tye);
	            if(tempval!=NULL)
			{
                
		                return tempval;
		            }
        	}
        return NULL;

    	}


	SymbolInfo* insertTable(SymbolInfo symTable)
	{
		return tableStack[crnt].insertTable(symTable);
	}

	bool insertTable(string nme,string tye)
	{
		
	        SymbolInfo* tempval=new SymbolInfo;
		SymbolInfo symTable(nme,tye);
	        tempval=tableStack[crnt].lookTable(symTable);
	        if(tempval==NULL)
		{
         	   tableStack[crnt].insertTable(symTable);
            
            	   return true;
        	}
        	else{
            
            		return false;
        	}
    	}

	SymbolInfo* finalInsert(string nme, string tye)
	{
		SymbolInfo* tempval=new SymbolInfo(nme, tye);
		SymbolInfo* tempval2=tableStack[crnt].insertTable(*tempval);
		return tempval2;
	}

 

   

    bool Remove(string nme)
	{
	        SymbolInfo* tempval=new SymbolInfo;
	        tempval=tableStack[crnt].lookTable(nme);
	        if(tempval==NULL)
		{
	            cout << "Not found" << endl;
	            return false;
	        }
	        else
		{
            

            		tableStack[crnt].Delete(nme);
        	}
    	}

 

};

//SymbolTable table(8);
