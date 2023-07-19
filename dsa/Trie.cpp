
/*
    trie is from the idea of bst of string
    bst of string works in O( m*log(n) ) where m is pattern length
    n is the number of words in which to be searched for
    when trie works in O(m)
*/
struct TrieNode
{
    TrieNode( char c='\0', bool isend=false )
    {
        val=c;
        isEnd=isend;
        child=vector<TrieNode*> (26);
    }
    char val='\0';
    bool isEnd=false;
    vector<TrieNode*> child;
};

struct Trie
{

    void insert_(string s)
    {
        TrieNode* now=root;
        for(int i=0; i<s.length(); i++)
        {
            int key=s[i]-'a';
            if(!now->child[key])  now->child[key]=new TrieNode( s[i] ) ;
            now= now->child[key];
        }
        now->isEnd=true;
    }

    void print()
    {
        dfsPrint( "", root );
    }

    void delet(string x)
    {
        TrieNode* now=root;
        for(int i=0; i<x.length(); i++)
        {
            int key=x[i]-'a';
            if(now->child[key]) now=now->child[key];
            else return;
        }
        now->isEnd=false;
    }

    bool search_(string x)
    {
        TrieNode* now=root;
        for(int i=0; i<x.length(); i++)
        {
            int key=x[i]-'a';
            if(now->child[key]) now=now->child[key];
            else return false;
        }
        return now->isEnd;
    }

private:
    TrieNode* root=new TrieNode();
    void dfsPrint( string s, TrieNode* now )
    {
        if( now->isEnd ) cout<<s<<N;
        for(int i=0; i<26; i++)
        {
            if( now->child[i] )
            {
                string y=s+(char) ( 'a'+i );
                dfsPrint(y,now->child[i]);
            }
        }
    }
};
