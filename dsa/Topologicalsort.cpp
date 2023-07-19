
// works on directed acyclic graph DAG

struct TopSort
{

    TopSort( vector< vector< int > > adm, int n )
    {
        this->adm=adm;
        this->n=n;
        visited=vector<int> (n+1);
        for(int i=1; i<=n; i++)
            if(!visited[i]) dfs(i);
        reverse( ans.begin(), ans.end() );
    }

    vector<int> visited,ans;
private:

    vector< vector<int> > adm;
    int n;

    void dfs(int node)
    {
        visited[node]=1;
        for( auto x: adm[node] )
        {
            if( !visited[x] ) dfs(x);
        }
        ans.push_back( node );
    }
};

