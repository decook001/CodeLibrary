// multi pattern string search
// pre-process patterns


struct TrieNode
{
    TrieNode( int parent= -1, int val= -1 )
    {
        this->parent=parent;
        this->val=val;
        child=vector<int> (26,-1);
    }
    int parent=-1, link=-1, val=-1;
    vector<int> child, endpoint ;
};

struct AhoCorasick
{
    AhoCorasick( vector<string> patterns )
    {
        trie=vector<TrieNode> (1);
        this->patterns=patterns;
        int n=patterns.size();
        build_trie();
        build_links();
        build_end_point();
    }
    
    void call(string txt)
    {
        ans=vector<int> (patterns.size());
        int now=0;
        for(auto c: txt )
        {
            int ind=c-'a';
            while( now>0 && trie[now].child[ind]<1 ) now=trie[now].link;
            if( trie[now].child[ind]>0 ) now=trie[now].child[ind];
            for(auto x: trie[now].endpoint) ans[x]++;
        }
    }
    
    vector<int> ans;
private:
    vector<TrieNode> trie;
    vector<string> patterns;
    
    void build_end_point()
    {
        queue<int> q;
        q.push(0);
        while(q.size())
        {
            int now=q.front();
            q.pop();
            int fail=trie[now].link;
            for(auto x: trie[fail].endpoint) trie[now].endpoint.push_back(x);
            for(int i=0; i<26; i++)
                if( trie[now].child[i]>0 ) q.push( trie[now].child[i] );
        }
    }

    void build_links( )
    {
        trie[0].link=0;
        queue<int> q;
        q.push(0);
        while(q.size())
        {
            int now=q.front();
            q.pop();
            if( now==0 || trie[now].parent==0 ) trie[now].link=0;
            else
            {
                int ind=trie[now].val;
                int fail=trie[trie[now].parent].link;
                while(fail>0 && trie[fail].child[ind]<1 ) fail=trie[fail].link;
                if( trie[fail].child[ind]>0 ) fail=trie[fail].child[ind];
                trie[now].link=fail;
            }
            for(int i=0; i<26; i++)
                if( trie[now].child[i]>0 ) q.push( trie[now].child[i] );
        }
    }

    void build_trie()
    {
        int n=0;
        for(auto s: patterns)
        {
            int now=0;
            for(char c: s)
            {
                int ind=c-'a';
                if( trie[now].child[ind]==-1 )
                {
                    trie[now].child[ind]=trie.size();
                    trie.push_back( TrieNode( now, ind ) );
                }
                now=trie[now].child[ind];
            }
            trie[now].endpoint.push_back(n);
            n++;
        }
    }
};

