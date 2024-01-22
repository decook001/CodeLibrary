
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
        int par, val;
        TrieNode(int par=-1, int val=0)
        {
            child=vector<int> (28, -1);
            this->par=par;
            this->val=val;
        }
    };
    
    vector<TrieNode> con;
    Trie ()
    {
        con= vector<TrieNode> (1);
    }
 
    void insert( VIN ara )
    {
        int now=0;
        for(auto x: ara)
        {
            if( con[now].child[x]==-1 )
            {
                con[now].child[x]=con.size();
                TrieNode tn( now, 0 );
                con.push_back( tn );
            }
            now=con[now].child[x];
            con[now].val++;
            //cout<< now <<S<< con[now].val <<E;
        }
    }
 
    ll qry( VIN& ara, int n, ll tot )
    {
        ll eij=ara.size();
        ll ans= eij*n+tot , sum=0, pre=n, len=0;
        int now=0;
        VIN aha(1,n);
        for(auto x: ara)
        {
            //cout<<x<<D;
            if( con[now].child[x]==-1 ) break;
            now=con[now].child[x];
            len++;
            aha.push_back( con[now].val );
        }
        //cout<< ans <<D;

        for( int i=1;i< aha.size();i++  )
        {
            //cout<< aha[i] <<SS;
            ll var1=aha[i];
            if( i<aha.size()-1 )
            {
                var1-=aha[i+1];
            }
            ans-=var1*i*2;
        }
        //cout<<F;
        return ans;
    }
};
