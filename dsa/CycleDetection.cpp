// cycle detection in directed graph


struct CycleDet
{
    int n;
    vector< vector<int> > adj;
    vector<int> vis, active;
    bool hasCycle=false;

    CycleDet(int n, vector<vector<int>> adj)
    {
        this->n=n;
        this->adj=adj;
        vis=vector<int> (n+1);
        active=vector<int> (n+1);
        for(int i=0; i<=n; i++)
        {
            if( !vis[i] && dfs( i ) ) hasCycle=true;
        }
    }

    bool dfs(int nd)
    {
        vis[nd]=1;
        active[nd]=1;

        for( auto nei: adj[nd] )
        {
            if( !vis[nei] && dfs(nei) )return true;
            else if( active[nei] ) return true;
        }

        active[nd]=0;
        return false;
    }
};

