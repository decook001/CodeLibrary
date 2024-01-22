
/*
    trie is from the idea of bst of string
    bst of string works in O( m*log(n) ) where m is pattern length
    n is the number of words in which to be searched for
    when trie works in O(m)
*/
 
struct Trie
{
    struct TrieNode
    {
        vector<int> child;
        int par=-1, val=-1;
        TrieNode(int par=-1, int val=-1)
        {
            child=vector<int> (10, -1);
            this->par=par;
            this->val=val;
        }
    };
    
    vector<TrieNode> con;
    Trie ()
    {
        con= vector<TrieNode> (1);
    }
 
    void insert( vi ara )
    {
        int now=0;
        for(auto x: ara)
        {
            if( con[now].child[x]==-1 )
            {
                con[now].child[x]=con.size();
                TrieNode tn( now, x );
                con.push_back( tn );
            }
            now=con[now].child[x];
        }
    }
 
    int check( vi ara )
    {
        int now=0, ans=0;
        for(auto x: ara)
        {
            //cout<<x<<D;
            if( con[now].child[x]==-1 ) break;
            ans++;
            now=con[now].child[x];
        }
        return ans;
    }
};

