#include<bits/stdc++.h>
#include<string>
using namespace std;

int currentpos;
int sizeable;
int index,bucketcnt;

class SymbolInfo
{

private:
    string keyword;
    string value;
public:
    SymbolInfo *next;

    void setterKeyword(string s)
    {
        keyword=s;
    }

    void setterValue(string s)
    {
        value=s;
    }

    string getterKeyword()
    {
        return keyword;
    }

    string getterValue()
    {
        return value;
    }


};


class ScopeTable
{

public:

    int tablesize;
    static const int SIZE=10000;

    SymbolInfo *hashset[SIZE];

    ScopeTable()
    {

        tablesize=sizeable;
        //SymbolInfo *hashset[tablesize];
        //cout<<tablesize<<endl;
        for(int i=0; i<tablesize; i++)
        {

            hashset[i]=new SymbolInfo;
            hashset[i]->setterKeyword("");
            hashset[i]->setterValue("");
            hashset[i]->next=NULL;

        }

    }

    void insertchain(string name,string name2);
    bool findchain(string name,string name2);
    bool lookup(string name2);
    void removechain(string name2);

    unsigned long hashfunc1(string key)
    {
        unsigned long h = 5381;

        for(int i=0; i<key.length(); i++)
        {
            h = ((h << 5) + h) + (int)key[i];
        }



        return (h%tablesize);
    }

    void printIndexchain(int x)
    {
        SymbolInfo *ptr=hashset[x];
        // cout<<3<<endl;
        if(ptr->getterKeyword()=="")
        {
        }
        else
        {
            // cout<<x<<endl;
            while(ptr!=NULL)
            {
                //  cout<<1<<endl;
                cout<<ptr->getterKeyword();
                if(ptr->next!=NULL)
                    cout<<" --> ";
                ptr=ptr->next;
                // cout<<2<<endl;
            }
        }
    }

    void printchain()
    {
        cout<<""<<endl;
        //int number;
        for(int i=0; i<tablesize; i++)
        {
            // number=numbereachchain(i);
            cout<<i<<" --> ";
            printIndexchain(i);

            // cout<<"Total "<<number<<endl;
            cout<<endl;
        }
    }



};

void ScopeTable::insertchain(string name,string name2)
{

    //int index;


    index=hashfunc1(name);
    bucketcnt=0;


    if(hashset[index]->getterKeyword()=="")
    {
        hashset[index]->setterKeyword("< " +name2+" : "+name+" >");
        hashset[index]->setterValue(name2);
    }

    else
    {


        SymbolInfo *ptr=hashset[index];
        SymbolInfo *n=new SymbolInfo;
        n->setterKeyword("< " +name2+" : "+name+" >");
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

bool ScopeTable::findchain(string name,string name2)
{

    int index;



    index=hashfunc1(name);

    // cout<<"NO1"<<endl;


    bool flag=false;

    string store;
    SymbolInfo *ptr=hashset[index];

    // cout<<"NO2"<<endl;

    while(ptr!=NULL)
    {
        if(ptr->getterKeyword()=="< " +name2+" : "+name+" >")
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

void ScopeTable::removechain(string name2)
{


    SymbolInfo *temp;
    SymbolInfo *temp1;
    SymbolInfo *temp2;


    if(hashset[index]->getterValue()==name2 && hashset[index]->next==NULL)
    {
        hashset[index]->setterKeyword("");
        hashset[index]->setterValue("");
        //cout<<name <<" is removed"<<endl;
    }

    else if(hashset[index]->getterValue()==name2 )
    {
        temp=hashset[index];
        hashset[index]=hashset[index]->next;
        delete temp;
        //cout<<name <<" is removed"<<endl;
    }

    else
    {

        temp1=hashset[index]->next;
        temp2=hashset[index];
        while(temp1 != NULL && temp1->getterValue()!=name2)
        {
            temp2=temp1;
            temp1=temp1->next;
        }
        if(temp1==NULL)
        {
            cout<<name2<<"Doesn't Exist !!!!"<<endl;
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

bool ScopeTable::lookup(string name2)
{


//int index;



    // index=hashfunc1(name);

    // cout<<"NO1"<<endl;

    // bucketcnt=0;
    bool flag=false;

    string store;

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
                index=i;
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


    vector<ScopeTable>h1;
    SymbolTable()
    {

        //vector<ScopeTable>h1;
        ScopeTable c;
        h1.push_back(c);
    }

    void insertTable(string namebro,string typenam)
    {

        if(h1[currentpos].lookup(namebro)==false)
        {

            if(h1[currentpos].findchain(typenam,namebro)==false)
            {
                // cout<<"NO"<<endl;
                h1[currentpos].insertchain(typenam,namebro);
                cout<<"Inserted in ScopeTable # "<<currentpos+1<<" at position "<<index<<","<<bucketcnt<<endl;
                cout<<""<<endl;
            }

            else
            {
                cout<<"Already exists in current ScopeTable"<<endl;
                cout<<""<<endl;
            }

        }

        else{
            cout<<"It already exists !!!! " <<endl;
        }

    }

    void printTable(string ch1)
    {

        if(ch1=="C")
        {
            cout<<"ScopeTable "<<"# "<<currentpos+1<<endl;
            h1[currentpos].printchain();
            cout<<""<<endl;
        }

        else if(ch1=="A")
        {
            int pos;
            //cout<<"ScopeTable "<<"# "<<pos+1<<endl;
            for(int pos=0; pos<=currentpos; pos++)
            {
                cout<<"ScopeTable "<<"# "<<pos+1<<endl;
                h1[pos].printchain();
                cout<<""<<endl;
            }
        }

    }

    void lookTable(string namebar)
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
            cout<<"Not Found !!"<<endl;
            cout<<""<<endl;
        }

        else if(flag==2)
        {
            cout<<"Found in ScopeTable # "<<store+1<<" at position "<<index<<","<<bucketcnt<<endl;
            cout<<""<<endl;
        }

        else
        {
            cout<<"Found in ScopeTable # "<<store+1<<" at position "<<index<<","<<bucketcnt<<endl;
            cout<<""<<endl;
        }

    }

    void deleteTable(string namebar)
    {

        if(h1[currentpos].lookup(namebar)==false)
        {
            cout<<"Not Found !!"<<endl;
            cout<<""<<endl;
        }

        else
        {
            cout<<"Found in ScopeTable # "<<currentpos+1<<" at position "<<index<<","<<bucketcnt<<endl;
            cout<<""<<endl;
            h1[currentpos].removechain(namebar);
            cout<<"Deleted entry at "<<index<<","<<bucketcnt<<" from current ScopeTable"<<endl;
            cout<<""<<endl;
        }

    }

    void newTable()
    {

        ScopeTable a;
        h1.push_back(a);

    }

    void prevTable()
    {
        h1.pop_back();
    }

};

int main()
{

    freopen("input.txt","r",stdin);
    int n;
   // cout<<"Enter total size: "<<endl;

    cin>>n;
    sizeable=n;
    currentpos=0;

    SymbolTable st;

    while(true)
    {
        string ch;
        cin>>ch;

        if(ch=="I")
        {

            string fullname;
            string typenam,namebro;
            cin>>namebro>>typenam;



            st.insertTable(namebro,typenam);

            // cout<<typenam<<endl;
            //cout<<"NO"<<endl;
            // cout<<namebro<<endl;

        }

        else if(ch=="P")
        {
            string ch1;
            cin>>ch1;

            st.printTable(ch1);

        }

        else if(ch=="L")
        {
            string namebar;
            cin>>namebar;

            st.lookTable(namebar);

        }

        else if(ch=="D")
        {
            string namebar;
            cin>>namebar;

            st.deleteTable(namebar);
        }

        else if(ch=="S")
        {
            currentpos++;
            st.newTable();
            // cout<<h1[currentpos].tablesize<<endl;
        }

        else if(ch=="E")
        {
            currentpos--;
            //cout<<"hi"<<endl;
            st.prevTable();
           // cout<<"hi1"<<endl;

            if(currentpos<0)
            {
                cout<<"Return 0 found"<<endl;
                break;
            }

           // break;
        }
    }


    return 0;
}
