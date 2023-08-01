#include<bits/stdc++.h>
using namespace std;

struct MyName
{
    string name;
    MyName( string name )
    {
        this->name=name;
        cout<< " starting " <<name << endl;
    }
    
    ~MyName()
    {
        cout << "Finishing " << name << endl;
    }
};

int main()
{
    MyName mn ( "a" );
    
    cout<< " aha" <<endl;
    for(int i=0;i<10;i++)
    {
        string s="";
        s+=( 'b'+i );
        MyName name( s );
        cout<< "keno" <<endl;
    }
}

